#ifndef ROBOTGRAPHICSITEM_H
#define ROBOTGRAPHICSITEM_H

#include <QGraphicsSvgItem>

#include "mapgraphicsscene.h"

class RobotGraphicsItem : public QGraphicsSvgItem
{
public:
    RobotGraphicsItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    friend class MapGraphicsScene;

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

};

#endif // ROBOTGRAPHICSITEM_H
