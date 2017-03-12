#include "robotpropswidget.h"
#include "ui_robotpropswidget.h"

RobotPropsWidget::RobotPropsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RobotPropsWidget)
{
    ui->setupUi(this);
}

RobotPropsWidget::~RobotPropsWidget()
{
    delete ui;
}
