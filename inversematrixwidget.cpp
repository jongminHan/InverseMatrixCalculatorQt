#include "inversematrixwidget.h"
#include "ui_inversematrixwidget.h"

InverseMatrixWidget::InverseMatrixWidget(QWidget* parent, double* inverseMatrix, int dimension)
    : QWidget(parent)
    , ui(new Ui::InverseMatrixWidget)
    , mDimension(dimension)
{
    ui->setupUi(this);
    mTextGrid = new QTextEdit*[dimension * dimension];

    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            mTextGrid[i * mDimension + j] = new QTextEdit(this);
            mTextGrid[i * mDimension + j]->resize(100, 30);
            int xPos = 20 + 110 * i;
            int yPos = 20 + 40 * j;
            mTextGrid[i * mDimension + j]->move(xPos, yPos);
            mTextGrid[i * mDimension + j]->setText(QString::number(inverseMatrix[i * mDimension + j]));
        }
    }
}

InverseMatrixWidget::~InverseMatrixWidget()
{
    delete ui;

    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            delete mTextGrid[i * mDimension + j];
        }
    }

    delete[] mTextGrid;
}
