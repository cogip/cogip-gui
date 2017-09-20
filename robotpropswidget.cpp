#include "robotpropswidget.h"
#include "ui_robotpropswidget.h"

#include <QDebug>
#include "robotgraphicsitem.h"

RobotPropsWidget::RobotPropsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RobotPropsWidget)
    , m_item(new RobotGraphicsItem(this))
{
    ui->setupUi(this);

    hide();
}

RobotPropsWidget::~RobotPropsWidget()
{
    delete ui;
    delete m_item;
}

// From View to Widget
void RobotPropsWidget::robotMoved(qreal x, qreal y, qreal /*a*/)
{
    blockSignals(true);
    ui->lineEditPosX->setText(QString::number(x));
    ui->lineEditPosY->setText(QString::number(y));
    blockSignals(false);
}

// From Widget to View
void RobotPropsWidget::on_lineEditPosX_returnPressed()
{
    blockSignals(true);
    qreal value = ui->lineEditPosX->text().toDouble();
    m_item->setPos(QPointF(value, ui->lineEditPosY->text().toDouble()));
    blockSignals(false);
}

void RobotPropsWidget::on_lineEditPosY_returnPressed()
{
    blockSignals(true);
    qreal value = ui->lineEditPosY->text().toDouble();
    m_item->setPos(QPointF(ui->lineEditPosX->text().toDouble(), value));
    blockSignals(false);
}

void RobotPropsWidget::on_lineEditAngle_returnPressed()
{
    blockSignals(true);
    qreal angle = ui->lineEditAngle->text().toInt();
    ui->horizontalSliderAngle->setValue(angle);
    m_item->setRotation(angle);
    blockSignals(false);
}

void RobotPropsWidget::on_horizontalSliderAngle_valueChanged(int angle)
{
//    qDebug() << __func__ << angle;
    blockSignals(true);
    ui->lineEditAngle->setText(QString::number(angle));
    m_item->setRotation(90-angle);
    blockSignals(false);
}
