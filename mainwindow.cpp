#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "mapgraphicsscene.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setPropsWidgetContainer(ui->dockWidget);

    connect(ui->graphicsView, &MapGraphicsView::displayPropsWidget,
            this, &MainWindow::changePropsWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changePropsWidget(QWidget *w)
{
    if (w) {
        ui->dockWidget->setWidget(w);
        w->show();
    } else {
        ui->dockWidget->setWidget(ui->dockWidgetContents);
    }
}

void MainWindow::on_actionZoomFit_triggered()
{
    ui->graphicsView->zoomFit();
}
