#ifndef MAPGRAPHICSSCENE_H
#define MAPGRAPHICSSCENE_H

#include <QGraphicsScene>

class RobotGraphicsItem;

class MapGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapGraphicsScene(QObject *parent = NULL);
};

#endif // MAPGRAPHICSSCENE_H
