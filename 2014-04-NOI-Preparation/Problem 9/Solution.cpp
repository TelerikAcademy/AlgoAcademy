#include<cmath>
#include<iostream>
#include<iterator>
#include<string>
#include<vector>
#include<map>
#include<ctime>

using namespace std;

const double PI = 3.14159265359;

class Vector2D
{
public:
    double x, y;

    Vector2D(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};

class Matrix
{
private:
    static const int TransformMatrixRows = 3;
    static const int TransformMatrixCols = 3;
public:
    double ** matrix;
    int rows;
    int cols;

public:
    Matrix()
    {
        this->rows = 0;
        this->cols = 0;
        this->matrix = NULL;
    }

    Matrix(int rows, int cols, const double * data = NULL)
    {
        this->rows = rows;
        this->cols = cols;

        this->matrix = new double*[rows];

        for(int row = 0; row < rows; row++)
        {
            this->matrix[row] = new double[cols];

            if(data != NULL)
            {
                for(int col = 0; col < cols; col++)
                {
                    this->matrix[row][col] = data[row * cols + col];
                }
            }
        }
    }

    Matrix operator *(const Matrix &other) const
    {
        double *resultMatrix = new double[this->rows * other.cols];
        for(int row = 0; row < this->rows; row++)
        {
            for(int col = 0; col < other.cols; col++)
            {
                resultMatrix[row * other.cols + col] = CellValueFromMultiplication(row, col, *this, other);
            }
        }

        return Matrix(this->rows, other.cols, resultMatrix);
    }

    Vector2D operator *(const Vector2D &v) const
    {
        double vectorData[TransformMatrixRows][1] =
        {
            {v.x},
            {v.y},
            {1.0}
        };

        Matrix m(TransformMatrixRows, 1, &vectorData[0][0]);
        Matrix transformedVectorMatrix = (*this) * m;

        return Vector2D(transformedVectorMatrix.matrix[0][0], transformedVectorMatrix.matrix[1][0]);
    }

    static double CellValueFromMultiplication(int cellRow, int cellCol, const Matrix &a, const Matrix &b)
    {
        int numMultiplicationsForCell = a.rows;

        double cellValue = 0;
        for(int i = 0; i < numMultiplicationsForCell; i++)
        {
            cellValue += a.matrix[cellRow][i] * b.matrix[i][cellCol];
        }

        return cellValue;
    }

    static Matrix GetIdentityMatrix()
    {
        double matrix[TransformMatrixRows][TransformMatrixCols] =
        {
            {1, 0, 0},
            {0, 1, 0},
            {0, 0, 1},
        };

        return Matrix(TransformMatrixRows, TransformMatrixCols, &matrix[0][0]);
    }

    static Matrix GetTranslationMatrix(double transX, double transY)
    {
        double matrix[TransformMatrixRows][TransformMatrixCols] =
        {
            {1, 0, transX},
            {0, 1, transY},
            {0, 0, 1},
        };

        return Matrix(TransformMatrixRows, TransformMatrixCols, &matrix[0][0]);
    }

    static Matrix GetRotationMatrix(double angleRadians)
    {
        double matrix[TransformMatrixRows][TransformMatrixCols] =
        {
            {cos(angleRadians), -sin(angleRadians), 0},
            {sin(angleRadians), cos(angleRadians), 0},
            {0, 0, 1},
        };

        return Matrix(TransformMatrixRows, TransformMatrixCols, &matrix[0][0]);
    }
};

class TransformMatrix2D
{
    static const int Rows = 3;
    static const int Cols = 3;
public:

};

double DistanceToCenterSq(Vector2D v)
{
    return v.x * v.x + v.y * v.y;
}

int main()
{
//#define DEBUG

#ifdef DEBUG
    long long start = clock();
#endif

    map<string, Matrix> transforms;

    ios_base::sync_with_stdio(false);

    int numTransformGroups = 0;
    cin>>numTransformGroups;

    for(int groupInd = 0; groupInd < numTransformGroups; groupInd++)
    {
        string groupName;
        cin>>groupName;

        int numTransforms = 0;
        cin>>numTransforms;

        Matrix groupTransform = Matrix::GetIdentityMatrix();
        vector<Matrix> currentTransforms;
        for(int transInd = 0; transInd < numTransforms; transInd++)
        {
            string transName;
            cin>>transName;

            if(transName == "move")
            {
                double x, y;
                cin>>x>>y;

                Matrix currentTransform  = Matrix::GetTranslationMatrix(x, y);
                groupTransform = currentTransform * groupTransform;
            }
            else if(transName == "rotate")
            {
                double angleDeg;
                cin>>angleDeg;

                Matrix currentTransform  = Matrix::GetRotationMatrix(angleDeg * PI / 180.0);
                groupTransform = currentTransform * groupTransform;
            }
        }

        transforms[groupName] = groupTransform;
    }

    int numPoints = 0;
    cin>>numPoints;

    vector<Vector2D> points;
    for(int i=0; i<numPoints; i++)
    {
        double x, y;
        cin>>x>>y;

        Vector2D point(x, y);
        points.push_back(point);
    }

    int numTransformIntervals = 0;
    cin>>numTransformIntervals;
    for(int i=0; i<numTransformIntervals; i++)
    {
        int intervalFirst, intervalLast;
        string transformName;
        cin>>transformName;
        cin>>intervalFirst>>intervalLast;

        Matrix currentTransform = transforms[transformName];

        for(int pointInd = intervalFirst; pointInd <= intervalLast; pointInd++)
        {
            points[pointInd] = currentTransform * points[pointInd];
        }
    }

    double minDist = DistanceToCenterSq(points[0]);
    for(int i=0; i<points.size(); i++)
    {
        double currentDist = DistanceToCenterSq(points[i]);
        if(currentDist < minDist)
        {
            minDist = currentDist;
        }
    }

    cout<<minDist<<endl;
#ifdef DEBUG
    long long stop = clock();

    cout<<(stop - start)/(double)CLOCKS_PER_SEC<<endl;
#endif
}

/*
1
test
3
move 5 5
rotate 45
move -5 -7
1
0 0
1
test 0 0
*/
