#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QWidget>
#include <QTextEdit>
#include <QPushButton>
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
    void GetCofactor(double* mat, double* temp, int p, int q, int n);
    double GetDeterminantRecursive(double* mat, int n);
    void Adjoint(double* mat, double* adj);
    bool Inverse(double* mat, double* inverse);
private slots:
    void updateMatrix();
private:
    Ui::MatrixWidget* ui;
    int mDimension;
    QTextEdit** mMatrixTextGrid;
    double* mMatrix;
    QPushButton* mCalButton;
};

#endif // MATRIXWIDGET_H
