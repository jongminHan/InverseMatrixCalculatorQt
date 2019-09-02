#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "matrixwidget.h"
#include <iostream>
#include <QMainWindow>
#include <memory>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow* ui;
    std::shared_ptr<MatrixWidget> mMatrixWidget;
    int mDimension;
};

#endif // MAINWINDOW_H
