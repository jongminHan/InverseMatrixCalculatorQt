#include "singularmatrixdialog.h"
#include "ui_singularmatrixdialog.h"

SingularMatrixDialog::SingularMatrixDialog(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::SingularMatrixDialog)
{
    ui->setupUi(this);
}

SingularMatrixDialog::~SingularMatrixDialog()
{
    delete ui;
}

void SingularMatrixDialog::on_pushButton_clicked()
{
    this->close();
}
