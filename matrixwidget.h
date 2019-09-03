#pragma once
#include "singularmatrixdialog.h"
#include "inversematrixwidget.h"
#include <QTextEdit>
#include <QPushButton>
#include <iostream>
#include <QDoubleSpinBox>
#include <memory>

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
    void GetCofactor(int* mat, int* temp, int p, int q, int n);
    int GetDeterminantRecursive(int* mat, int n);
    void Adjoint(int* mat, double* adj);
    bool Inverse(int* mat, double* inverse);
private slots:
    void updateMatrix();
private:
    Ui::MatrixWidget* ui;
    int mDimension;
    QSpinBox** mMatrixTextGrid;
    int* mMatrix;
    QPushButton* mCalButton;
    std::shared_ptr<SingularMatrixDialog> mSingularMatrixDialog;
    std::shared_ptr<InverseMatrixWidget> mInverseMatrixWidget;
};
