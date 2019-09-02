#include "matrixwidget.h"
#include "ui_matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget* parent, int dimension)
    : QWidget(parent)
    , ui(new Ui::MatrixWidget)
    , mDimension(dimension)
{
    ui->setupUi(this);
    mMatrixGrid = new QTextEdit*[mDimension * mDimension];

    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            mMatrixGrid[i * mDimension + j] = new QTextEdit(this);
            mMatrixGrid[i * mDimension + j]->resize(30, 30);
            int xPos = 20 + 40 * i;
            int yPos = 20 + 40 * j;
            mMatrixGrid[i * mDimension + j]->move(xPos, yPos);
            std::cout << "(" << xPos << ", " << yPos << ")" << std::endl;
        }

    }
}

MatrixWidget::~MatrixWidget()
{
    delete ui;

    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            delete mMatrixGrid[i * mDimension + j];
        }
    }

    delete[] mMatrixGrid;
}
