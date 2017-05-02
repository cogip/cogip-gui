#include "mapgraphicsscene.h"

#include "mapgraphicsview.h"
#include "robotgraphicsitem.h"

MapGraphicsScene::MapGraphicsScene(QObject *parent)
    : QGraphicsScene(parent)
{
    connect(this, &QGraphicsScene::selectionChanged,
            this, &MapGraphicsScene::onParentSceneSelectionChanged);
}

void MapGraphicsScene::onParentSceneSelectionChanged()
{
    // does support only one view.
    // this may change if we implement some "modes" as prepare vs. play route?
    if (views().length() != 1)
        return;

    MapGraphicsView *view = dynamic_cast<MapGraphicsView *>(views()[0]);
    Q_ASSERT(view);

    // current supported selection is one item at a time
    if(selectedItems().length() != 1) {
        emit view->displayPropsWidget();
        return;
    }

    RobotGraphicsItem *item = dynamic_cast<RobotGraphicsItem *>(selectedItems()[0]);
    Q_ASSERT(item);
    //emit view->displayPropsWidget((QWidget *)item->getPropsRef());
}
