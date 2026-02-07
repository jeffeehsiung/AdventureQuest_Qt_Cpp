#ifndef AQ_CORE_SERVICE_LOCATOR_H
#define AQ_CORE_SERVICE_LOCATOR_H

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <stdexcept>

namespace AQ {

// Service Locator pattern - replaces singletons with injectable services.
// Services are registered by interface type and retrieved by consumers.
// This enables testing, platform swapping, and loose coupling.

class ServiceLocator {
public:
    static ServiceLocator& instance() {
        static ServiceLocator loc;
        return loc;
    }

    template<typename InterfaceT>
    void provide(std::shared_ptr<InterfaceT> service) {
        services_[std::type_index(typeid(InterfaceT))] = std::move(service);
    }

    template<typename InterfaceT>
    std::shared_ptr<InterfaceT> get() const {
        auto it = services_.find(std::type_index(typeid(InterfaceT)));
        if (it == services_.end()) {
            return nullptr;
        }
        return std::static_pointer_cast<InterfaceT>(it->second);
    }

    template<typename InterfaceT>
    InterfaceT& resolve() const {
        auto svc = get<InterfaceT>();
        if (!svc) {
            throw std::runtime_error("Service not registered");
        }
        return *svc;
    }

    void clear() {
        services_.clear();
    }

private:
    ServiceLocator() = default;
    std::unordered_map<std::type_index, std::shared_ptr<void>> services_;
};

} // namespace AQ

#endif // AQ_CORE_SERVICE_LOCATOR_H
