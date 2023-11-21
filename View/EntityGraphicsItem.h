#ifndef ENTITYGRAPHICSITEM_H
#define ENTITYGRAPHICSITEM_H

#include <QDir>
#include <QDebug>
#include <QGraphicsItem>
#include <QStyleOptionGraphicsItem>
#include <QRectF>
#include <QStringList>
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QtCore/QObject>
#include "QtCore/qtimer.h"
#include "Model/Entity.h"
#include <vector>

class EntityGraphicsItem : public QGraphicsItem, public QObject {

protected:
    Entity* entity;  // Pointer to the entity model
    QPixmap image;   // Image representing the entity

    // Animation properties
    enum AnimationState { IDLE, MOVING, ATTACK, HURT, DYING, HEAL };
    AnimationState animationState;
    QTimer animationTimer;
    std::vector<QPixmap> idleFrames;
    std::vector<QPixmap> hurtFrames;
    std::vector<QPixmap> dyingFrames;
    std::vector<QPixmap> attackFrames;
    std::vector<QPixmap> healFrames;
    int currentFrameIndex;

public:
    explicit EntityGraphicsItem(Entity* entity, const QString& imagePath, const QString& idleFramesDir, const QString& hurtFramesDir, const QString& dyingFramesDir, const QString& attackFramesDir, const QString& healFramesDir, QGraphicsItem* parent = nullptr): QGraphicsItem(parent), entity(entity), image(imagePath), animationState(IDLE), currentFrameIndex(0){
        // Load animation frames from specified directories
        loadFramesFromDirectory(idleFramesDir, idleFrames);
        loadFramesFromDirectory(hurtFramesDir, hurtFrames);
        loadFramesFromDirectory(dyingFramesDir, dyingFrames);
        loadFramesFromDirectory(attackFramesDir, attackFrames);
        loadFramesFromDirectory(healFramesDir, healFrames);
    }

    // Virtual destructor for dynamic binding
    virtual ~EntityGraphicsItem() {}

    /**
     * The following methods are virtual and will be dynamically bound at runtime
    */

    // These methods are virtual and will be dynamically bound at runtime

    // Pure virtual functions for animations
    virtual void animateIdle() {
        animateFrames(idleFrames);
    }

    virtual void animateHurt() {
        animateFrames(hurtFrames);
    }

    virtual void animateDying() {
        animateFrames(dyingFrames);
    }

    virtual void animateAttack() {
        animateFrames(attackFrames);
    }

    virtual void animateHeal() {
        animateFrames(healFrames);
    }

    // the following methods are not virtual and will be statically bound at compile time
    QRectF boundingRect() const override {
        return QRectF(0, 0, image.width(), image.height());
    }

    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->drawPixmap(0, 0, image);
    }

private:
    // Helper function to load animation frames from a directory
    void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames) {
        // frames are named sequentially from states in the animation state eunum with suffix _000.png to animation state eunum with suffix numbering to the number of frames in the animation
        QDir dir(dirPath);
        QStringList filters;
        filters << "*.png";
        dir.setNameFilters(filters);
        dir.setSorting(QDir::Name);

        // Load frames from directory
        QStringList frameFiles = dir.entryList();
        for (const QString& frameFile : frameFiles) {
            QString framePath = dirPath + "/" + frameFile;
            QPixmap frame(framePath);

            // Check if frame was loaded successfully
            if (frame.isNull()) {
                qDebug() << "Failed to load frame: " << framePath;
                continue;
            }

            // Add frame to vector
            frames.push_back(frame);
        }
    }

    // Helper function to animate frames for the current state
    void animateFrames(std::vector<QPixmap>& frames) {
        if (frames.empty()) {
            return;
        }

        animationState = static_cast<AnimationState>(frames.size() - 1);
        currentFrameIndex = 0;

        // Set up a timer to update the animation
        connect(&animationTimer, &QTimer::timeout, this, &EntityGraphicsItem::animateStep);
        animationTimer.start(100); // 100 ms between frames
    }

private slots:
    // Animation timer slot
    void animateStep() {
        if (animationState != currentFrameIndex) {
            // Animation state has changed, stop animating
            animationTimer.stop();
            return;
        }

        // Update the image
        if (static_cast<size_t>(currentFrameIndex) < idleFrames.size()) {
            image = idleFrames[currentFrameIndex];
            currentFrameIndex++;
            update(); // Trigger a repaint of the graphics item
        }
    }
};

#endif // ENTITYGRAPHICSITEM_H
