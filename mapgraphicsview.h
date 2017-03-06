#ifndef MAPGRAPHICSVIEW_H
#define MAPGRAPHICSVIEW_H

#include <QGraphicsView>

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

    void zoomFit();

public slots:
    void robotRotate(int angle_deg);

protected:
    void wheelEvent(QWheelEvent *) override;

private:
    QGraphicsSvgItem * m_backgroundItem;
    QGraphicsSvgItem * m_robotItem;
};

#endif // MAPGRAPHICSVIEW_H
