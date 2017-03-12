#ifndef ROBOTPROPSWIDGET_H
#define ROBOTPROPSWIDGET_H

#include <QWidget>

class RobotGraphicsItem;

namespace Ui {
class RobotPropsWidget;
}

class RobotPropsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RobotPropsWidget(QWidget *parent = 0);
    ~RobotPropsWidget();

    inline RobotGraphicsItem * getItemRef() const {
        return m_item;
    }

protected:
    void robotMoved(qreal, qreal, qreal);

private slots:
    void on_lineEditPosX_returnPressed();
    void on_lineEditPosY_returnPressed();
    void on_lineEditAngle_returnPressed();
    void on_horizontalSliderAngle_valueChanged(int angle);

private:
    Ui::RobotPropsWidget *ui;

    RobotGraphicsItem *m_item;

    friend class RobotGraphicsItem;
};

#endif // ROBOTPROPSWIDGET_H
