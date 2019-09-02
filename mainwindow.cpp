#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mDimension(0)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    mMatrixWidget = std::make_shared<MatrixWidget>(nullptr, mDimension);
    mMatrixWidget->show();
}

void MainWindow::on_spinBox_valueChanged(int dimension)
{
    mDimension = dimension;

    std::cout << mDimension << std::endl;

}
