#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSliderBotPosAngle, &QSlider::valueChanged,
            this, &MainWindow::onHorizSliderBotPosAngleValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHorizSliderBotPosAngleValueChanged(int angle_deg)
{
    blockSignals(true);
    ui->lineEditBotPosAngle->setText(QString::number(angle_deg));
    blockSignals(false);

    ui->graphicsView->robotRotate(angle_deg);
}

void MainWindow::on_actionZoomFit_triggered()
{
    ui->graphicsView->zoomFit();
}
