#include "Renderer/HUD.h"

namespace AQ {

HUD::HUD(QWidget* parent)
    : QWidget(parent)
{
    heartPixmap_.load(":/images/healthpack/Idle/2.png");
    setupUI();
}

void HUD::setupUI() {
    layout_ = new QHBoxLayout(this);
    layout_->setContentsMargins(4, 4, 4, 4);
    layout_->setSpacing(2);

    QSize heartSize = compact_ ? QSize(20, 20) : QSize(30, 30);

    for (int i = 0; i < Constants::MaxHealth; ++i) {
        auto* label = new QLabel(this);
        label->setPixmap(heartPixmap_.scaled(heartSize, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        hearts_.push_back(label);
        layout_->addWidget(label);
    }

    energyLabel_ = new QLabel("Energy:", this);
    energyValue_ = new QLabel(QString::number(Constants::MaxEnergy, 'f', 1), this);

    if (compact_) {
        energyLabel_->setStyleSheet("color: white; font-size: 12px;");
        energyValue_->setStyleSheet("color: white; font-size: 12px; font-weight: bold;");
    }

    layout_->addWidget(energyLabel_);
    layout_->addWidget(energyValue_);
    layout_->addStretch();

    setLayout(layout_);
}

void HUD::updateStatus(int health, float energy) {
    currentHealth_ = health;

    for (int i = 0; i < static_cast<int>(hearts_.size()); ++i) {
        hearts_[i]->setVisible(i < health);
    }

    energyValue_->setText(QString::number(energy, 'f', 1));
}

void HUD::setCompactMode(bool compact) {
    if (compact_ != compact) {
        compact_ = compact;
        // Rebuild UI with new sizing
        QLayoutItem* child;
        while ((child = layout_->takeAt(0)) != nullptr) {
            delete child->widget();
            delete child;
        }
        hearts_.clear();
        setupUI();
    }
}

void HUD::rebuildHearts() {
    updateStatus(currentHealth_, energyValue_->text().toFloat());
}

} // namespace AQ
