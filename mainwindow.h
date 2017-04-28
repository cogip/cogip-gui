#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QItemSelection>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void changePropsWidget(QWidget *w);
    void routeSelectionChanged(const QItemSelection & selected, const QItemSelection & deselected);
    void cellActivated(int row, int col);

private slots:
    void on_actionZoomFit_triggered();

private:
    Ui::MainWindow *ui;

    QWidget *m_currentDockedChild;
};

#endif // MAINWINDOW_H
