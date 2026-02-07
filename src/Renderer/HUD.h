#ifndef AQ_RENDERER_HUD_H
#define AQ_RENDERER_HUD_H

#include "Core/Types.h"
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QPixmap>
#include <vector>

namespace AQ {

// HUD (Heads-Up Display) renders health hearts and energy bar.
// Adapts layout for both desktop (horizontal bar) and iOS (compact overlay).

class HUD : public QWidget {
    Q_OBJECT

public:
    explicit HUD(QWidget* parent = nullptr);

    void updateStatus(int health, float energy);
    void setCompactMode(bool compact);

private:
    void setupUI();
    void rebuildHearts();

    QHBoxLayout* layout_ = nullptr;
    std::vector<QLabel*> hearts_;
    QLabel* energyLabel_ = nullptr;
    QLabel* energyValue_ = nullptr;

    QPixmap heartPixmap_;
    int currentHealth_ = Constants::MaxHealth;
    bool compact_ = false;
};

} // namespace AQ

#endif // AQ_RENDERER_HUD_H
