#include "mapgraphicsscene.h"

#include "robotgraphicsitem.h"

MapGraphicsScene::MapGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
    , m_robotItem(NULL)
{
}

void MapGraphicsScene::setRobotItem(RobotGraphicsItem * robot)
{
    m_robotItem = robot;
}
