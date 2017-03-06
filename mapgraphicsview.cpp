#include "mapgraphicsview.h"

#include <qmath.h>
#include <QDebug>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsSvgItem>

#include "robotgraphicsitem.h"

MapGraphicsView::MapGraphicsView(QWidget *parent)
    : QGraphicsView(parent)
    , m_backgroundItem(NULL)
    , m_robotItem(NULL)
{
    setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing |
                   QPainter::HighQualityAntialiasing | QPainter::SmoothPixmapTransform);
    setTransformationAnchor(AnchorUnderMouse);
    setInteractive(true);
    //setViewportUpdateMode(FullViewportUpdate);

//    // Enable a selection mode while clicking+mouseMove
//    setDragMode(QGraphicsView::RubberBandDrag);
//    // Enable a view movement while clicking+mouseMove
//    setDragMode(ScrollHandDrag);

    setScene(new QGraphicsScene(this));

    m_backgroundItem = new QGraphicsSvgItem(":/svg/playing_area.svg");
    scene()->setSceneRect(m_backgroundItem->boundingRect());
    scene()->addItem(m_backgroundItem);

    m_robotItem = new RobotGraphicsItem();
    scene()->addItem(m_robotItem);

    // Maybe we should rotate the view?
    //rotate(180);
}

MapGraphicsView::~MapGraphicsView()
{
    delete m_robotItem;
    delete m_backgroundItem;
    delete scene();
}

void MapGraphicsView::wheelEvent(QWheelEvent *e)
{
    if (e->modifiers() & Qt::ShiftModifier) {
        // ignore default shift + wheel event (fast vert. scroll)
        e->ignore();
    } else if (e->modifiers() & Qt::ControlModifier) {
        // ctrl+wheel is catch to perform (un)zoom of the view
        qreal factor = qPow(1.2, e->delta() / 240.0);
        scale(factor, factor);
        e->accept();
    } else {
        QGraphicsView::wheelEvent(e);
    }
}

void MapGraphicsView::zoomFit()
{
    Q_ASSERT(m_backgroundItem);

    fitInView(m_backgroundItem->boundingRect(), Qt::KeepAspectRatio);
}

void MapGraphicsView::robotRotate(int angle_deg)
{
    m_robotItem->setRotation(angle_deg);
    //qDebug() << m_robotItem->pos() + m_robotItem->transformOriginPoint();
}