#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H

#include <QGraphicsView>

class RobotGraphicsItem;

QT_BEGIN_NAMESPACE
class QGraphicsSvgItem;
//class QSvgRenderer;
class QWheelEvent;
//class QPaintEvent;
QT_END_NAMESPACE


class MapGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MapGraphicsView(QWidget *parent = NULL);
    ~MapGraphicsView();

    void sceneSelectionChanged();
    void robotMoved(qreal x, qreal y, qreal a);

    void zoomFit();

public slots:
    void robotRotate(int angle_deg);

protected:
    void wheelEvent(QWheelEvent *) override;

private:
    QGraphicsSvgItem * m_backgroundItem;
    RobotGraphicsItem * m_robotItem;
};

#endif // MAPGRAPHICSVIEW_H
