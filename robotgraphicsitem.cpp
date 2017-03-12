#include "robotgraphicsitem.h"

#include <QDebug>

RobotGraphicsItem::RobotGraphicsItem()
    : QGraphicsSvgItem(":/svg/cortex.svg")
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);

    // as opacity is changed in paint(), we filter the related event
//    setFlag(QGraphicsItem::ItemOpacityChange, false);
//    setFlag(QGraphicsItem::ItemOpacityHasChanged, false);

    setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
}

void RobotGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsSvgItem::paint(painter, option, widget);

    setOpacity(isSelected() ? 1.0 : 0.3);
}

QVariant RobotGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    //qDebug() << change;
    if (scene() && (change == ItemPositionHasChanged || change == ItemRotationHasChanged)) {

        MapGraphicsScene *sc = dynamic_cast<MapGraphicsScene *>(scene());
        QPointF itemAbsPos = QPointF(pos().x() + round(boundingRect().width() / 2),
                                     pos().y() + round(boundingRect().height() / 2));
//        qDebug() << itemAbsPos;

        if (sc)
            emit sc->robotMoved(itemAbsPos.x(), itemAbsPos.y(), rotation());
    }

    return QGraphicsItem::itemChange(change, value);
}
