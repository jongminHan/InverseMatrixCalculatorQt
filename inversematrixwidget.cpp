#include "inversematrixwidget.h"
#include "ui_inversematrixwidget.h"

InverseMatrixWidget::InverseMatrixWidget(QWidget* parent, double* inverseMatrix)
    : QWidget(parent)
    , ui(new Ui::InverseMatrixWidget)
{
    ui->setupUi(this);
}

InverseMatrixWidget::~InverseMatrixWidget()
{
    delete ui;
}
