//WorldView.h
#ifndef WorldVIEW_H
#define WorldVIEW_H

#include "world_global.h"
#include <QGraphicsView>
class WorldModel;

class WORLDSHARED_EXPORT WorldView : public QGraphicsView {
    Q_OBJECT

public:
    explicit WorldView(WorldModel *model, QWidget *parent = nullptr);

public slots:
    void updateView();

private:
    WorldModel *worldModel;
};

#endif // WorldVIEW_H
