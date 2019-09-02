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

// Function to get cofactor of mat[p][q] in temp[][]. n is current
// dimension of mat[][]
void MatrixWidget::GetCofactor(double* mat, double* temp, int p, int q, int n)
{
    int i = 0, j = 0;

    // Looping for each element of the matrix
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            //  Copying into temporary matrix only those element
            //  which are not in given row and column
            if (row != p && col != q)
            {
                temp[i * mDimension +j++] = mat[row * mDimension + col];

                // Row is filled, so increase row index and
                // reset col index
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of mat[][]. */
double MatrixWidget::GetDeterminantRecursive(double* mat, int n)
{
    int D = 0; // Initialize result

    //  Base case : if matrix contains single element
    if (n == 1)
    {
        return mat[0];
    }

    double* temp = new double[mDimension * mDimension]; // To store cofactors

    int sign = 1;  // To store sign multiplier

     // Iterate for each element of first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
        GetCofactor(mat, temp, 0, f, n);
        D += sign * mat[f] * GetDeterminantRecursive(temp, n - 1);

        // terms are to be added with alternate sign
        sign = -sign;
    }

    delete[] temp;
    return D;
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

    std::cout << GetDeterminantRecursive(mMatrix, mDimension) << std::endl;
}
