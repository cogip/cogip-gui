#ifndef MAPGRAPHICSSCENE_H
#define MAPGRAPHICSSCENE_H

#include <QGraphicsScene>

class RobotGraphicsItem;

class MapGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MapGraphicsScene(QObject *parent = NULL);

public slots:
    void onParentSceneSelectionChanged();

signals:
    void selectionChanged();
};

#endif // MAPGRAPHICSSCENE_H
