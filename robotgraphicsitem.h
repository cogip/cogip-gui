#ifndef ROBOTGRAPHICSITEM_H
#define ROBOTGRAPHICSITEM_H

#include <QGraphicsSvgItem>

class RobotGraphicsItem : public QGraphicsSvgItem
{
public:
    RobotGraphicsItem();
    ~RobotGraphicsItem();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setPos(const QPointF &pos);

protected:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

private:
    QWidget *m_props;
};

#endif // ROBOTGRAPHICSITEM_H
