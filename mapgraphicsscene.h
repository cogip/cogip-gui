#ifndef MAPGRAPHICSSCENE_H
#define MAPGRAPHICSSCENE_H

#include <QGraphicsScene>

class RobotGraphicsItem;

class MapGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapGraphicsScene(QObject *parent = NULL);

    void setRobotItem(RobotGraphicsItem * robot);

signals:
    void robotMoved(qreal, qreal, qreal);

private:
    RobotGraphicsItem *m_robotItem;
};

#endif // MAPGRAPHICSSCENE_H
