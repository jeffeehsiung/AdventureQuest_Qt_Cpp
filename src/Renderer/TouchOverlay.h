#ifndef AQ_RENDERER_TOUCH_OVERLAY_H
#define AQ_RENDERER_TOUCH_OVERLAY_H

#include "Core/Types.h"
#include "Platform/IInputHandler.h"
#include <QWidget>
#include <QPainter>
#include <QTouchEvent>
#include <QPointF>
#include <functional>

namespace AQ {

// TouchOverlay provides on-screen D-pad and action buttons for iOS/touch devices.
// It renders a semi-transparent control overlay and maps touch events to game actions.
// On desktop, this widget is hidden and keyboard input is used instead.

class TouchOverlay : public QWidget, public IInputHandler {
    Q_OBJECT

public:
    explicit TouchOverlay(QWidget* parent = nullptr);

    // IInputHandler
    void setActionCallback(ActionCallback cb) override { actionCb_ = std::move(cb); }
    void setTapCallback(PositionCallback cb) override { tapCb_ = std::move(cb); }
    bool isTouch() const override { return true; }

protected:
    void paintEvent(QPaintEvent* event) override;
    bool event(QEvent* event) override;

private:
    struct DPadZone {
        QRectF rect;
        Direction dir;
    };

    struct ActionButton {
        QRectF rect;
        InputAction action;
        QString label;
    };

    void handleTouch(const QPointF& pos);
    void layoutControls();

    ActionCallback actionCb_;
    PositionCallback tapCb_;

    std::vector<DPadZone> dpadZones_;
    std::vector<ActionButton> actionButtons_;

    QRectF dpadBounds_;
    float buttonRadius_ = 30.0f;
    float dpadRadius_ = 60.0f;
    float opacity_ = 0.35f;
};

} // namespace AQ

#endif // AQ_RENDERER_TOUCH_OVERLAY_H
