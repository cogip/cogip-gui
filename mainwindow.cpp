#include <QDebug>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapgraphicsscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setPropsWidgetContainer(this);

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
        //ui->verticalLayoutDocked->addWidget(w);
        w->show();

        m_currentDockedChild = w;
    } else {
        //ui->verticalLayoutDocked->removeWidget(m_currentDockedChild);
        m_currentDockedChild->hide();

        m_currentDockedChild = NULL;
    }
}

void MainWindow::on_actionZoomFit_triggered()
{
    ui->graphicsView->zoomFit();
}
