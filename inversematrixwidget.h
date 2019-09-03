#pragma once
#include <QWidget>

namespace Ui
{
    class InverseMatrixWidget;
}

class InverseMatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InverseMatrixWidget(QWidget* parent = nullptr, double* inverseMatrix = nullptr);
    virtual ~InverseMatrixWidget();

private:
    Ui::InverseMatrixWidget* ui;
};
