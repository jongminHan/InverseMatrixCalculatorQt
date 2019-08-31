#include "matrix.h"
#include "ui_matrix.h"

Matrix::Matrix(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Matrix)
{
    ui->setupUi(this);
}

Matrix::~Matrix()
{
    delete ui;
}
