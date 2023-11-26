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
    Q_OBJECT
protected:
    Entity* entity;  // Pointer to the entity model
    QPixmap image;   // Image representing the entity

    // Animation properties
    enum AnimationState { IDLE, MOVING, ATTACK, HURT, DYING, HEAL };
    AnimationState animationState;
    QTimer* animationTimer;
    std::vector<QPixmap> idleFrames;
    std::vector<QPixmap> moveFrames;
    std::vector<QPixmap> hurtFrames;
    std::vector<QPixmap> dyingFrames;
    std::vector<QPixmap> attackFrames;
    std::vector<QPixmap> healFrames;
    std::vector<QPixmap>::size_type currentFrameIndex;

    // Image Directories
    static QString baseFramesDir;
    static QString idleDir;
    static QString moveDir;
    static QString hurtDir;
    static QString dyingDir;
    static QString attackDir;
    static QString healDir;

public:
    explicit EntityGraphicsItem(Entity* entity, const QString& imagePath, const QString& idleFramesDir, const QString& moveFramesDir, const QString& hurtFramesDir, const QString& dyingFramesDir, const QString& attackFramesDir, const QString& healFramesDir, QGraphicsItem* parent = nullptr): QGraphicsItem(parent), entity(entity), image(imagePath), animationState(IDLE), currentFrameIndex(0){
        baseFramesDir = imagePath;
        idleDir = idleFramesDir;
        moveDir = moveFramesDir;
        hurtDir = hurtFramesDir;
        dyingDir = dyingFramesDir;
        attackDir = attackFramesDir;
        healDir = healFramesDir;
        // Load animation frames from specified directories
        loadFramesFromDirectory(idleDir, idleFrames);
        loadFramesFromDirectory(moveDir, moveFrames);
        loadFramesFromDirectory(hurtDir, hurtFrames);
        loadFramesFromDirectory(dyingDir, dyingFrames);
        loadFramesFromDirectory(attackDir, attackFrames);
        loadFramesFromDirectory(healDir, healFrames);
        // Initiate a timer to contorl the timing of the frame updates
        animationTimer = new QTimer(this);
        connect(animationTimer, &QTimer::timeout, this, &EntityGraphicsItem::nextFrame);
    }

    // Virtual destructor for dynamic binding
    virtual ~EntityGraphicsItem() {}

    /**
     * The following methods are virtual and will be dynamically bound at runtime
    */

    // These methods are virtual and will be dynamically bound at runtime

    // Pure virtual functions for animations
    inline void setPosition(const coordinate& newPosition){
        // Set the position based on the 'newPosition' coordinate
        setPos(newPosition.xCoordinate, newPosition.yCoordinate);
    }

    inline void nextFrame() {
        std::vector<QPixmap>* currentFrames;
        switch (animationState) {
        case IDLE:
            currentFrames = &idleFrames;
            break;
        case MOVING:
            currentFrames = &moveFrames;
            break;
        case ATTACK:
            currentFrames = &attackFrames;
            break;
        case HURT:
            currentFrames = &hurtFrames;
            break;
        case DYING:
            currentFrames = &dyingFrames;
            break;
        case HEAL:
            currentFrames = &healFrames;
            break;
        }

        // Check if we reached the end of the animation
        if (currentFrameIndex >= currentFrames->size()) {
            // Handle the end of the animation
            switch (animationState) {
            case IDLE:
            case MOVING:
            case HEAL:
                // Looping animations: reset to the first frame
                currentFrameIndex = 0;
                break;
            case ATTACK:
            case HURT:
            case DYING:
                // One-time animations: stop the animation and possibly switch state
                animationTimer->stop();
                emit animationFinished(animationState);
                animationState = IDLE; // Switch to idle or another appropriate state
                return; // Early exit to avoid updating the image below
            }
        }

        // Set the current frame to the next frame in the animation sequence
        image = (*currentFrames)[currentFrameIndex];
        update(); // Trigger a repaint of the graphics item

        // Increment the frame index for the next timer tick
        currentFrameIndex++;
    }

    inline void startAnimation() {
        if (!animationTimer->isActive()) {
            animationTimer->start(100); // You can adjust the interval as needed
        }
    }

    inline void changeAnimationState(AnimationState newState) {
        if (animationState != newState) {
            animationState = newState;
            currentFrameIndex = 0; // Reset frame index for the new animation

            // Load frames for the new state if not already loaded
            switch (newState) {
            case IDLE:
                if (idleFrames.empty()) loadFramesFromDirectory(idleDir, idleFrames);
                break;
            case MOVING:
                if (moveFrames.empty()) loadFramesFromDirectory(moveDir, moveFrames);
                break;
            case ATTACK:
                if (attackFrames.empty()) loadFramesFromDirectory(attackDir, attackFrames);
                break;
            case HURT:
                if (hurtFrames.empty()) loadFramesFromDirectory(hurtDir, hurtFrames);
                break;
            case DYING:
                if (dyingFrames.empty()) loadFramesFromDirectory(dyingDir, dyingFrames);
                break;
            case HEAL:
                if (healFrames.empty()) loadFramesFromDirectory(healDir, healFrames);
                break;
            }

            if (!animationTimer->isActive()) {
                startAnimation(); // Start the timer if not already running
            }
        }
    }

    // the following methods are not virtual and will be statically bound at compile time
    inline QRectF boundingRect() const override {
        return QRectF(0, 0, image.width(), image.height());
    }

    inline void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
        Q_UNUSED(option);
        Q_UNUSED(widget);
        painter->drawPixmap(0, 0, image);
    }

private:
    // Helper function to load animation frames from a directory
    inline void loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames) {
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

signals:
    void animationFinished(AnimationState state);

};

#endif // ENTITYGRAPHICSITEM_H
