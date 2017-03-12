#include "robotgraphicsitem.h"

#include <QDebug>
#include "robotpropswidget.h"

RobotGraphicsItem::RobotGraphicsItem(RobotPropsWidget *widget)
    : QGraphicsSvgItem(":/svg/cortex.svg")
    , m_props(widget)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemIsSelectable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);

    // as opacity is changed in paint(), we filter the related event
//    setFlag(QGraphicsItem::ItemOpacityChange, false);
//    setFlag(QGraphicsItem::ItemOpacityHasChanged, false);

    setTransformOriginPoint(boundingRect().width() / 2, boundingRect().height() / 2);
}

RobotGraphicsItem::~RobotGraphicsItem()
{
}

void RobotGraphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsSvgItem::paint(painter, option, widget);

    setOpacity(isSelected() ? 1.0 : 0.3);
}

void RobotGraphicsItem::setPos(const QPointF &pos)
{
    QPointF itemAbsPos = QPointF(pos.x() - round(boundingRect().width() / 2),
                                 pos.y() - round(boundingRect().height() / 2));

    QGraphicsItem::setPos(itemAbsPos);
}

QVariant RobotGraphicsItem::itemChange(GraphicsItemChange change, const QVariant &value)
{
    if (change == ItemPositionHasChanged || change == ItemRotationHasChanged) {

        QPointF itemAbsPos = QPointF(pos().x() + round(boundingRect().width() / 2),
                                     pos().y() + round(boundingRect().height() / 2));

        m_props->robotMoved(itemAbsPos.x(), itemAbsPos.y(), rotation());
    }

    return QGraphicsItem::itemChange(change, value);
}
