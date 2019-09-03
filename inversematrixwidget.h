#pragma once
#include <QTextEdit>

namespace Ui
{
    class InverseMatrixWidget;
}

class InverseMatrixWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InverseMatrixWidget(QWidget* parent, double* inverseMatrix, int dimension);
    ~InverseMatrixWidget();

private:
    Ui::InverseMatrixWidget* ui;
    QTextEdit** mTextGrid;
    int mDimension;
};
