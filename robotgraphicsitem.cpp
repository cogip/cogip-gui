#include "robotgraphicsitem.h"

RobotGraphicsItem::RobotGraphicsItem()
    : QGraphicsSvgItem(":/svg/cortex.svg")
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
}

void RobotGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsSvgItem::paint(painter, option, widget);

    setOpacity(isSelected() ? 1.0 : 0.3);
}
