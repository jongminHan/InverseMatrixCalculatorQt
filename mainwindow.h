#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "matrixwidget.h"
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

private:
    Ui::MainWindow* ui;
    std::shared_ptr<MatrixWidget> mMatrixWidget;
};

#endif // MAINWINDOW_H
