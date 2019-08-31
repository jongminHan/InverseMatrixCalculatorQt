#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QWidget>

namespace Ui
{
    class MatrixWidget;
}

class MatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MatrixWidget(QWidget* parent = nullptr);
    ~MatrixWidget();

private:
    Ui::MatrixWidget* ui;
};

#endif // MATRIXWIDGET_H
