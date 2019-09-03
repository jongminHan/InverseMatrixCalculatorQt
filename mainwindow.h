#pragma once
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
    virtual ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow* ui;
    std::shared_ptr<MatrixWidget> mMatrixWidget;
    int mDimension;
};
