#ifndef ROBOTGRAPHICSITEM_H
#define ROBOTGRAPHICSITEM_H

#include <QGraphicsSvgItem>

class RobotGraphicsItem : public QGraphicsSvgItem
{
public:
    RobotGraphicsItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ROBOTGRAPHICSITEM_H
