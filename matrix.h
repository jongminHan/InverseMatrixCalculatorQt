#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>

namespace Ui
{
    class Matrix;
}

class Matrix : public QWidget
{
    Q_OBJECT
public:
    explicit Matrix(QWidget* parent = nullptr);
    ~Matrix();

private:
    Ui::Matrix* ui;
};

#endif // MATRIX_H
