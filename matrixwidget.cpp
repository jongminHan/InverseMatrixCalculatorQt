#include "matrixwidget.h"
#include "ui_matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MatrixWidget)
{
    ui->setupUi(this);
}

MatrixWidget::~MatrixWidget()
{
    delete ui;
}
