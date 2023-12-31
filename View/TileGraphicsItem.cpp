#include "TileGraphicsItem.h"

//const int DURATION = 100;
//const int indexScale = 3;
//const int idleOffset = 15;

// the naming should be changed to TileGraphicsItem

TileGraphicsItem::TileGraphicsItem(const TileModel& tileModel, const QString& baseFramesDir, QGraphicsRectItem* parent)
    : EntityGraphicsItem(tileModel, parent), baseFramesDir(baseFramesDir)  {
    loadAnimationFrames();
//    animationTimer = new QTimer(this);
//    connect(animationTimer, &QTimer::timeout, this, &TileGraphicsItem::nextFrame);
}

void TileGraphicsItem::loadAnimationFrames() {
    // Load the frames for each animation state
    loadFramesFromDirectory(baseFramesDir + "Idle/", idleFrames);
    loadFramesFromDirectory(baseFramesDir + "Moving/", moveFrames);
    loadFramesFromDirectory(baseFramesDir + "Attack/", attackFrames);
    loadFramesFromDirectory(baseFramesDir + "Dying/", attackFrames);
}

void TileGraphicsItem::loadFramesFromDirectory(const QString& dirPath, std::vector<QPixmap>& frames) {
    QDir dir(dirPath);
    QStringList fileNames = dir.entryList(QStringList() << "*.png", QDir::Files, QDir::Name);
    for (const QString& fileName : fileNames) {
        QPixmap frame(dirPath + fileName);
        if (!frame.isNull()) {
            // Pre-scale the image here
            QPixmap scaledFrame = frame.scaled(EntityGraphicsItem::tileWidth, EntityGraphicsItem::tileHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            frames.push_back(scaledFrame);
        } else {
            qDebug() << "Failed to load frame:" << dirPath + fileName;
        }
    }
}

QRectF TileGraphicsItem::boundingRect() const {
    return QRectF(0, 0, tileWidth, tileHeight);
}


void TileGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) {
    const TileModel* tileModel = dynamic_cast<const TileModel*>(&getEntity());
    if (tileModel) {
        if(!image.isNull()){
            painter->drawPixmap(0, 0, image);
        }

    }else{
        qDebug() << "TileGraphicsItem::paint() - tileModel is null";
    }

}


//// Utility function to add leading zeros to the image file name if necessary
//QString addLeadingZeros(int number, int desiredLength) {
//    QString numberAsString = QString::number(number);
//    while (numberAsString.length() < desiredLength) {
//        numberAsString = "0" + numberAsString;
//    }
//    return numberAsString;
//}

//QPixmap TileGraphicsItem::loadImageForValue(int index) {
//    // Create the file name based on the index
//    QString filename = addLeadingZeros(index, 2) + ".png"; // Ensures two digits in the filename (00, 01, ..., 14)

//    // Assuming 'baseFramesDir' points to the directory where your images are stored
//    // and that directory contains subdirectories for each animation state
//    QString filePath = baseFramesDir + "YourSubdirectory/" + filename; // Replace 'YourSubdirectory' with the actual directory name if needed

//    QPixmap pixmap(filePath);

//    // Check if the image was loaded successfully
//    if (pixmap.isNull()) {
//        qDebug() << "Failed to load image for value:" << filePath;
//        return QPixmap(); // Return an empty QPixmap if the image loading failed
//    }

//    // If the image is loaded successfully, return the scaled version
//    return pixmap.scaled(EntityGraphicsItem::tileWidth, EntityGraphicsItem::tileHeight, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//}

//void TileGraphicsItem::startAnimation() {
//    if (!animationTimer->isActive()) {
//        animationTimer->start(100);
//    }
//}

//void TileGraphicsItem::handleAnimationEnd() {
//    switch (entity.getState()) {
//    case MOVING:
//    case ATTACK:
//        currentFrameIndex = 0;
//        break;
//    case IDLE:
//        animationTimer->stop();
//        break;
//    }
//}

//void TileGraphicsItem::nextFrame() {
//    const state entityState = getEntity().getState();
//    const TileModel* tileModel = dynamic_cast<const TileModel*>(&getEntity());
//    std::vector<QPixmap>* currentFrames = nullptr;
//    int animationDuration = 100; // default duration
//    switch (entityState) {
//    case IDLE:
//        currentFrames = &idleFrames;
//        if(tileModel){
//            int value = tileModel->getValue();
//            // Map the value to the range of images
//            currentFrameIndex = ((static_cast<int>((static_cast<double>(value) + idleOffset)) * indexScale) % this->idleFrames.size());
//            // Make sure we do not exceed the range of available images
//            currentFrameIndex = qMin(currentFrameIndex, static_cast<unsigned long>(this->idleFrames.size()) - 1);
//            image = (*currentFrames)[currentFrameIndex];
//            update();
//            return;
//        }
//        break;
//    case MOVING:
//        currentFrames = &moveFrames;
//        animationDuration = DURATION;
//        break;
//    case ATTACK:
//        currentFrames = &attackFrames;
//        animationDuration = DURATION;
//        break;
//    }

//    // Update timer interval for the current state
//    if (animationTimer->interval() != animationDuration) {
//        animationTimer->setInterval(animationDuration);
//    }

//    if (!currentFrames || currentFrames->empty()) return;

//    // Check if we reached the end of the animation
//    if (currentFrameIndex >= currentFrames->size()) {
//        handleAnimationEnd();
//        return;
//    }

//    image = (*currentFrames)[currentFrameIndex++];

//    update();
//}




