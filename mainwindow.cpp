#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStandardItemModel>
#include "mapgraphicsscene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_currentDockedChild(NULL)
{
    ui->setupUi(this);
    ui->graphicsView->setPropsWidgetContainer(ui->dockWidget);

    QStandardItemModel *model = new QStandardItemModel(0/*row*/, 4/*cols*/, this);
    model->setHeaderData(0, Qt::Horizontal, tr("Visible"));
    model->setHeaderData(1, Qt::Horizontal, tr("X"));
    model->setHeaderData(2, Qt::Horizontal, tr("Y"));
    model->setHeaderData(3, Qt::Horizontal, tr("Angle"));

    QStandardItem *item = new QStandardItem;
    item->setCheckable(true);
    item->setCheckState(Qt::Checked);
    item->setEditable(false);
    model->setItem(0,0,item);

    ui->tableView->setModel(model);
    connect(ui->tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::routeSelectionChanged);

//    ui->tableWidget->setColumnCount(1);
//    ui->tableWidget->setRowCount(2);

//    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Visible"));

//    QTableWidgetItem *item = new QTableWidgetItem;
//    item->setCheckState(Qt::Checked);
//    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled);
//    item->setTextAlignment(Qt::AlignCenter);
//    ui->tableWidget->setItem(0, 0, item);
//    ui->tableWidget->setItem(1, 0, item);

//    ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Visible"));

//    connect(ui->tableWidget, &QTableWidget::cellEntered,
//            this, &MainWindow::cellActivated);

    connect(ui->graphicsView, &MapGraphicsView::displayPropsWidget,
            this, &MainWindow::changePropsWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <QDebug>

void MainWindow::routeSelectionChanged(const QItemSelection & selected, const QItemSelection & deselected)
{
    //
    qDebug() << selected;
}

void MainWindow::cellActivated(int row, int col)
{
    qDebug() << "row" << row << "col" << col;
}

void MainWindow::changePropsWidget(QWidget *w)
{
    if (w) {
        ui->verticalLayoutDocked->addWidget(w);
        w->show();

        m_currentDockedChild = w;
    } else {
        ui->verticalLayoutDocked->removeWidget(m_currentDockedChild);
        m_currentDockedChild->hide();

        m_currentDockedChild = NULL;
    }
}

void MainWindow::on_actionZoomFit_triggered()
{
    ui->graphicsView->zoomFit();
}
