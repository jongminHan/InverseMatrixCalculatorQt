#include "matrixwidget.h"
#include "ui_matrixwidget.h"

typedef union
{
    double d;
    struct
    {
        unsigned long long int mantissa : 52;
        unsigned long long int exponent : 11;
        unsigned long long int sign :     1;
    } parts;
} double_cast;


bool IsZero(double num)
{
    double_cast data;
    data.d = num;

    // Check both exponent and mantissa parts
    if(data.parts.exponent == 0u && data.parts.mantissa == 0u)
    {
       return true;
    }
    else
    {
       return false;
    }
}


MatrixWidget::MatrixWidget(QWidget* parent, int dimension)
    : QWidget(parent)
    , ui(new Ui::MatrixWidget)
    , mDimension(dimension)
{
    ui->setupUi(this);
    mMatrixTextGrid = new QDoubleSpinBox*[mDimension * mDimension];
    mMatrix = new double[mDimension * mDimension] { 0 };


    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            mMatrixTextGrid[i * mDimension + j] = new QDoubleSpinBox(this);
            mMatrixTextGrid[i * mDimension + j]->resize(100, 30);
            int xPos = 20 + 110 * i;
            int yPos = 20 + 40 * j;
            mMatrixTextGrid[i * mDimension + j]->move(xPos, yPos);
            mMatrixTextGrid[i * mDimension + j]->setMinimum(static_cast<double>(-100));
            mMatrixTextGrid[i * mDimension + j]->setMaximum(static_cast<double>(100));
        }
    }

    mCalButton = new QPushButton(this);
    mCalButton->setText("Calculate");
    mCalButton->resize(100, 30);
    mCalButton->move(20 + 110 * mDimension, 20 + 40 * (mDimension - 1));
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

// mat의 여인수를 temp에 저장해주는 함수. n은 현재 mat의 차원
void MatrixWidget::GetCofactor(double* mat, double* temp, int p, int q, int n)
{
    int i = 0;
    int j = 0;

    // 행렬의 모든 요소를 탐색
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // 주어진 행과 열에 해당하지 않는 요소만 temp로 복사
            if (row != p && col != q)
            {
                temp[i * mDimension + j++] = mat[row * mDimension + col];

                // 행이 모두 채워졌으면, 행의 인덱스를 1 증가.
                // 열의 인덱스는 0으로 초기화
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}

// 행렬식을 반환하는 재귀 함수
double MatrixWidget::GetDeterminantRecursive(double* mat, int n)
{
    // 반환값 초기화
    double D = 0;

    // 주어진 행렬의 요소가 한 개 밖에 없을 경우 해당 요소의 값을 반환
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

// Function to get adjoint of A[N][N] in adj[N][N].
void MatrixWidget::Adjoint(double* mat, double* adj)
{
    if (mDimension == 1)
    {
        adj[0] = 1;
        return;
    }

    // temp is used to store cofactors of A[][]
    int sign = 1;
    double* temp = new double[mDimension * mDimension];

    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            // Get cofactor of A[i][j]
            GetCofactor(mat, temp, i, j, mDimension);

            // sign of adj[j][i] positive if sum of row
            // and column indexes is even.
            sign = ((i + j) % 2 == 0) ? 1 : -1;

            // Interchanging rows and columns to get the
            // transpose of the cofactor matrix
            adj[j * mDimension + i] = sign * GetDeterminantRecursive(temp, mDimension - 1);
        }
    }

    delete[] temp;
}

// Function to calculate and store inverse, returns false if
// matrix is singular
bool MatrixWidget::Inverse(double* mat, double* inverse)
{
    // Find determinant of A[][]
    double det = GetDeterminantRecursive(mat, mDimension);

    if (IsZero(det))
    {
        return false;
    }

    // Find adjoint
    double* adj = new double[mDimension * mDimension];

    Adjoint(mat, adj);

    // Find Inverse using formula "inverse(A) = adj(A)/det(A)"
    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            inverse[i * mDimension + j] = adj[i * mDimension + j] / det;
        }
    }

    delete[] adj;
    return true;
}

void MatrixWidget::updateMatrix()
{
    for (int i = 0; i < mDimension; i++)
    {
        for (int j = 0; j < mDimension; j++)
        {
            mMatrix[i * mDimension + j] = mMatrixTextGrid[i * mDimension + j]->value();
        }
    }

    double* adj = new double[mDimension * mDimension];  // To store adjoint of A[][]

    double* inv = new double[mDimension * mDimension];  // To store inverse of A[][]


    Adjoint(mMatrix, adj);


    if (Inverse(mMatrix, inv))
    {
        for (int i = 0; i < mDimension; i++)
        {
            for (int j = 0; j < mDimension; j++)
            {
                mMatrixTextGrid[i * mDimension + j]->setValue(inv[i * mDimension + j]);
            }
        }
    }
    else
    {
        mSingularMatrixDialog = std::make_shared<SingularMatrixDialog>();
        mSingularMatrixDialog->show();
    }

    delete[] adj;
    delete[] inv;
}
