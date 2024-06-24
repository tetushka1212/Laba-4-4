#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
private:
    vector< vector<double>> matrix;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t rows = 0, size_t cols = 0)
    {
        this->rows = rows;
        this->cols = cols;
        matrix = vector< vector<double>> (rows);
        for (size_t i = 0; i < rows; ++i) {
            matrix[i] =  vector<double>(cols);
        }
    }

    Matrix(const vector< vector<double>>& mat) {
        this->rows = mat.size();
        this->cols = mat[0].size();
        this->matrix = mat;

    }
 
    ~Matrix() {}

    size_t GetRows() { return rows; }
    
    size_t GetCols() { return cols; }
    
    Matrix Add(const Matrix& other);

    Matrix MultiplyByScalar(double scalar);

    Matrix Multiply(const Matrix& other);

    void setElement(int row, int col, double value) { matrix[row][col] = value; }
    
    double CalculateDeterminant();

    double& operator()(int i, int j)  {
        return matrix[i][j];
    }
    const double& operator()(int i, int j) const {
        return matrix[i][j];
    }
    friend std::ostream& operator<< (std::ostream& os, const Matrix& mat) {
        for (size_t i = 0; i < mat.rows; ++i) {
            for (size_t j = 0; j < mat.cols; ++j) {
                os << mat(i, j) << " ";
            }
            os << "\n";
        }
        return os;

    }
    void Print();
};


