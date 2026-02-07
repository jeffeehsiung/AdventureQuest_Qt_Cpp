#ifndef AQ_CORE_EVENT_H
#define AQ_CORE_EVENT_H

#include <functional>
#include <vector>
#include <unordered_map>
#include <string>
#include <any>
#include <typeindex>
#include <algorithm>
#include <memory>

namespace AQ {

// Type-safe event bus for decoupled communication between game systems.
// Replaces tight signal/slot coupling with a publish-subscribe model.

using ListenerId = uint64_t;

class EventBus {
public:
    static EventBus& instance() {
        static EventBus bus;
        return bus;
    }

    template<typename EventT>
    ListenerId subscribe(std::function<void(const EventT&)> handler) {
        auto id = nextId_++;
        auto wrapper = [handler](const std::any& event) {
            handler(std::any_cast<const EventT&>(event));
        };
        listeners_[std::type_index(typeid(EventT))].push_back({id, std::move(wrapper)});
        return id;
    }

    template<typename EventT>
    void publish(const EventT& event) {
        auto key = std::type_index(typeid(EventT));
        auto it = listeners_.find(key);
        if (it != listeners_.end()) {
            for (auto& [id, handler] : it->second) {
                handler(event);
            }
        }
    }

    void unsubscribe(ListenerId id) {
        for (auto& [key, vec] : listeners_) {
            vec.erase(
                std::remove_if(vec.begin(), vec.end(),
                    [id](const Entry& e) { return e.id == id; }),
                vec.end());
        }
    }

    void clear() {
        listeners_.clear();
    }

private:
    EventBus() = default;

    struct Entry {
        ListenerId id;
        std::function<void(const std::any&)> handler;
    };

    std::unordered_map<std::type_index, std::vector<Entry>> listeners_;
    ListenerId nextId_ = 1;
};

// ---------- Game Events ----------

struct EntityMovedEvent {
    int entityId;
    Vec2i from;
    Vec2i to;
};

struct EntityDamagedEvent {
    int entityId;
    float damage;
    float remainingHealth;
};

struct EntityDiedEvent {
    int entityId;
    EnemyType type;
};

struct HealthChangedEvent {
    int health;
    float energy;
};

struct LevelChangedEvent {
    int newLevel;
};

struct GameOverEvent {
    bool won;
};

struct CombatEvent {
    int attackerId;
    int defenderId;
    float damage;
};

struct InputEvent {
    InputAction action;
    Vec2i position; // for touch/click input
};

} // namespace AQ

#endif // AQ_CORE_EVENT_H
