#ifndef ROBOTPROPSWIDGET_H
#define ROBOTPROPSWIDGET_H

#include <QWidget>

namespace Ui {
class RobotPropsWidget;
}

class RobotPropsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RobotPropsWidget(QWidget *parent = 0);
    ~RobotPropsWidget();

private:
    Ui::RobotPropsWidget *ui;
};

#endif // ROBOTPROPSWIDGET_H
