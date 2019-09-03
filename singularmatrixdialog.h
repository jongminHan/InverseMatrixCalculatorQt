#pragma once
#include <QDialog>

namespace Ui
{
    class SingularMatrixDialog;
}

class SingularMatrixDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SingularMatrixDialog(QWidget* parent = nullptr);
    ~SingularMatrixDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SingularMatrixDialog *ui;
};
