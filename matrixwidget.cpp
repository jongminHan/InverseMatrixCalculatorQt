#include "matrixwidget.h"
#include "ui_matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget* parent, int dimension)
    : QWidget(parent)
    , ui(new Ui::MatrixWidget)
    , mDimension(dimension)
{
    ui->setupUi(this);
    mMatrixTextGrid = new QTextEdit*[mDimension * mDimension];
    mMatrix = new double[mDimension * mDimension] { 0 };


    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            mMatrixTextGrid[i * mDimension + j] = new QTextEdit(this);
            mMatrixTextGrid[i * mDimension + j]->resize(30, 30);
            int xPos = 20 + 40 * i;
            int yPos = 20 + 40 * j;
            mMatrixTextGrid[i * mDimension + j]->move(xPos, yPos);
            std::cout << "(" << xPos << ", " << yPos << ")" << std::endl;
        }
    }

    mCalButton = new QPushButton(this);
    mCalButton->setText("Calculate");
    mCalButton->resize(100, 30);
    mCalButton->move(20 + 40 * (mDimension), 20 + 40 * (mDimension - 1));
    connect(mCalButton, SIGNAL(clicked()), this, SLOT(updateMatrix()));
}

MatrixWidget::~MatrixWidget()
{
    delete ui;
    delete mCalButton;

    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            delete mMatrixTextGrid[i * mDimension + j];
        }
    }

    delete[] mMatrixTextGrid;
    delete[] mMatrix;
}

void MatrixWidget::updateMatrix()
{
    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            mMatrix[i * mDimension + j] = mMatrixTextGrid[i * mDimension + j]->toPlainText().toDouble();
        }
    }
}
