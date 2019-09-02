#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <iostream>

namespace Ui
{
    class MatrixWidget;
}

class MatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixWidget(QWidget* parent = nullptr, int dimension = 0);
    ~MatrixWidget();

private:
    Ui::MatrixWidget* ui;
    int mDimension;
    QTextEdit** mMatrixGrid;
};

#endif // MATRIXWIDGET_H
