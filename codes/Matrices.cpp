#include "Matrices.h"
namespace Matrices
{

    Matrix::Matrix(int _rows, int _cols)
    {
        rows = _rows;
        cols = _cols;
    
        a.resize(rows);    //remake each col into actual size.
        for (int i = 0; i < rows; ++i) 
        {
            a.at(i).resize(cols);
        }
    }

    ///Add each corresponding element.
    ///usage:  c = a + b;
    Matrix operator+(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getCols() || a.getRows() != b.getRows()) {
            throw runtime_error("Error: dimensions must agree");
        }
        
        Matrix c(a.getRows(), a.getCols());
        for (int i = 0; i < a.getRows(); ++i) 
        {
            for (int j = 0; j < a.getCols(); ++j) 
            {
                c(i, j) = a(i, j) + b(i, j); 
            }
        }
        return c;
    }

    ///Matrix multiply.  See description.
    ///usage:  c = a * b;
    Matrix operator*(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getRows()) {
            throw runtime_error("Error: dimensions must agree");
        }

        Matrix c(a.getRows(), b.getCols());
        for (int k = 0; k < b.getCols(); ++k) {
            for (int i = 0; i < a.getRows(); ++i) {
                for (int j = 0; j < a.getCols(); ++j) {
                    c(i, k) += a(i, j) * b(j, k);
                }
            }
        }
        return c;
    }

    ///Matrix comparison.  See description.
    ///usage:  a == b
    bool operator==(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getCols() || a.getRows() != b.getRows()) {
            return false;
        }

        for (int i = 0; i < a.getRows(); ++i) {
            for (int j = 0; j < a.getCols(); ++j) {
                if (abs(a(i, j) - b(i, j)) >= 0.001) {
                    return false;
                }
            }
        }      
        return true;
    }

    ///Matrix comparison.  See description.
    ///usage:  a != b
    bool operator!=(const Matrix& a, const Matrix& b)
    {
        if (a.getCols() != b.getCols() || a.getRows() != b.getRows()) {
            return true;
        }

        for (int i = 0; i < a.getRows(); ++i) {
            for (int j = 0; j < a.getCols(); ++j) {
                if (abs(a(i, j) - b(i, j)) >= 0.001) {
                    return true;
                }
            }
        }
        return false;
    }

    ///Output matrix.
    ///Separate columns by ' ' and rows by '\n'
    ostream& operator<<(ostream& os, const Matrix& a)
    {
        for (int i = 0; i < a.getRows(); ++i) {
            for (int j = 0; j < a.getCols(); ++j) {
                os << setw(10) << right << a(i, j) << ' ';
            }
            os << '\n';
        }
        os << '\n' << '\n' << '\n' << '\n';
        return os;
    }

    ///2D rotation matrix
    ///usage:  A = R * A rotates A theta radians counter-clockwise
    RotationalMatrix::RotationMatrix(double theta) : Matrix(2, 2)
    {
        A_matrix.at(0,0) = cos(theta);
        A_matrix.at(0,1) = -sin(theta);
        A_matrix.at(1,0) = sin(theta);
        A_matrix.at(1,1) = cos(theta);
    }

    ScalingMatrix::ScalingMatrix(double scale) : Matrix(2,2)
    {
        A_matrix.at(0,0) = scale;
        A_matrix.at(0,1) = 0;
        A_matrix.at(1,0) = 0;
        A_matrix.at(1,1) = scale;
    }

    TranslationMatrix::TranslationMatrix(double xShift, double yShift, int nCols) : Matrix(2,nCols)
    {
        for (int j = 0; j < nCols; ++j)
        {
                a.at(0).at(j) = xShift;
                a.at(1).at(j) = yShift;
        }
    }

}


