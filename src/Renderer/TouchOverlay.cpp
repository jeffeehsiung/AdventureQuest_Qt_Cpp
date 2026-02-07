#include "Renderer/TouchOverlay.h"
#include <QApplication>
#include <cmath>

namespace AQ {

TouchOverlay::TouchOverlay(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_AcceptTouchEvents);
    setAttribute(Qt::WA_TranslucentBackground);
    setAutoFillBackground(false);
    layoutControls();
}

void TouchOverlay::layoutControls() {
    // D-pad in bottom-left corner
    float margin = 20.0f;
    float dpadCenterX = margin + dpadRadius_;
    float dpadCenterY = height() - margin - dpadRadius_;

    dpadBounds_ = QRectF(dpadCenterX - dpadRadius_, dpadCenterY - dpadRadius_,
                          dpadRadius_ * 2, dpadRadius_ * 2);

    float zoneSize = dpadRadius_ * 0.7f;
    dpadZones_.clear();
    dpadZones_.push_back({QRectF(dpadCenterX - zoneSize/2, dpadCenterY - dpadRadius_, zoneSize, zoneSize), Direction::Up});
    dpadZones_.push_back({QRectF(dpadCenterX - zoneSize/2, dpadCenterY + dpadRadius_ - zoneSize, zoneSize, zoneSize), Direction::Down});
    dpadZones_.push_back({QRectF(dpadCenterX - dpadRadius_, dpadCenterY - zoneSize/2, zoneSize, zoneSize), Direction::Left});
    dpadZones_.push_back({QRectF(dpadCenterX + dpadRadius_ - zoneSize, dpadCenterY - zoneSize/2, zoneSize, zoneSize), Direction::Right});

    // Action buttons in bottom-right corner
    float btnY = height() - margin - buttonRadius_;
    float rightEdge = width() - margin;

    actionButtons_.clear();
    actionButtons_.push_back({
        QRectF(rightEdge - buttonRadius_ * 2, btnY - buttonRadius_, buttonRadius_ * 2, buttonRadius_ * 2),
        InputAction::Attack, "ATK"
    });
    actionButtons_.push_back({
        QRectF(rightEdge - buttonRadius_ * 5, btnY - buttonRadius_, buttonRadius_ * 2, buttonRadius_ * 2),
        InputAction::TakeItem, "TAKE"
    });
    actionButtons_.push_back({
        QRectF(rightEdge - buttonRadius_ * 2, btnY - buttonRadius_ * 4, buttonRadius_ * 2, buttonRadius_ * 2),
        InputAction::AutoPlay, "AUTO"
    });
}

void TouchOverlay::paintEvent(QPaintEvent*) {
    // Recalculate layout on every paint to handle resize
    layoutControls();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setOpacity(opacity_);

    // Draw D-pad background
    painter.setBrush(QColor(40, 40, 40));
    painter.setPen(Qt::NoPen);
    painter.drawEllipse(dpadBounds_);

    // Draw D-pad arrows
    painter.setBrush(QColor(200, 200, 200));
    for (const auto& zone : dpadZones_) {
        painter.drawRoundedRect(zone.rect, 5, 5);
    }

    // Draw D-pad direction labels
    painter.setOpacity(opacity_ * 1.5);
    painter.setPen(QColor(60, 60, 60));
    QFont font = painter.font();
    font.setPixelSize(static_cast<int>(buttonRadius_ * 0.5f));
    font.setBold(true);
    painter.setFont(font);

    static const QString dpadLabels[] = {"U", "D", "L", "R"};
    for (size_t i = 0; i < dpadZones_.size(); ++i) {
        painter.drawText(dpadZones_[i].rect, Qt::AlignCenter, dpadLabels[i]);
    }

    // Draw action buttons
    painter.setOpacity(opacity_);
    for (const auto& btn : actionButtons_) {
        painter.setBrush(QColor(80, 120, 200));
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(btn.rect, buttonRadius_ * 0.3f, buttonRadius_ * 0.3f);

        painter.setPen(Qt::white);
        painter.drawText(btn.rect, Qt::AlignCenter, btn.label);
    }
}

bool TouchOverlay::event(QEvent* event) {
    switch (event->type()) {
        case QEvent::TouchBegin:
        case QEvent::TouchUpdate:
        case QEvent::TouchEnd: {
            auto* te = static_cast<QTouchEvent*>(event);
            if (!te->points().isEmpty()) {
                handleTouch(te->points().first().position());
            }
            return true;
        }
        case QEvent::MouseButtonPress: {
            auto* me = static_cast<QMouseEvent*>(event);
            handleTouch(me->position());
            return true;
        }
        default:
            break;
    }
    return QWidget::event(event);
}

void TouchOverlay::handleTouch(const QPointF& pos) {
    // Check D-pad zones
    for (const auto& zone : dpadZones_) {
        if (zone.rect.contains(pos)) {
            InputAction action;
            switch (zone.dir) {
                case Direction::Up:    action = InputAction::MoveUp; break;
                case Direction::Down:  action = InputAction::MoveDown; break;
                case Direction::Left:  action = InputAction::MoveLeft; break;
                case Direction::Right: action = InputAction::MoveRight; break;
            }
            if (actionCb_) actionCb_(action);
            return;
        }
    }

    // Check action buttons
    for (const auto& btn : actionButtons_) {
        if (btn.rect.contains(pos)) {
            if (actionCb_) actionCb_(btn.action);
            return;
        }
    }

    // Tap on game area -> position callback
    if (tapCb_) {
        tapCb_({static_cast<int>(pos.x()), static_cast<int>(pos.y())});
    }
}

} // namespace AQ
