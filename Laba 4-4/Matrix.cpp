#include "Matrix.h"

Matrix Matrix::Add(const Matrix& other)
{
        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
}

Matrix Matrix::MultiplyByScalar(double scalar)
{
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) 
    {
        for (size_t j = 0; j < cols; ++j) {
            result.matrix[i][j] = matrix[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::Multiply(const Matrix& other)
{
    if (cols != other.rows) 
    {
        throw invalid_argument("U cant multiply that matrixes, check out their sizes");
    }

    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            for (size_t k = 0; k < cols; ++k) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }
    return result;
}

double Matrix::CalculateDeterminant()
{

    /*���� ����� �� ���������.���� ������ ������������,��� ����� �� �������������.
    ���������������� ��������� n^3, ������ n!*/

    size_t n = this->rows;
    double det = 1.0;

    for (int i = 0; i < n; ++i) {
        // ����� ������ � ��������� ��������� �� ������� i
        int pivot_row = i;
        while (pivot_row < n && matrix[pivot_row][i] == 0) {
            pivot_row++;
        }

        if (pivot_row == n) {
            return 0.0; // ���� �� ������ ��������� ������� �� ������ �������, ������ ������������ ����� 0
        }

        if (pivot_row != i) {
            swap(matrix[pivot_row], matrix[i]); // �������� ������ �������
            det *= -1; // ��� ������ ����� �������� ���� ������������
        }

        double pivot = matrix[i][i]; // �������� (�������) �������

        det *= pivot; // �������� ������������ �� �������� �������

        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / pivot; // ����������� ��� ���������
            for (int k = i; k < n; ++k) {
                matrix[j][k] -= factor * matrix[i][k]; // �������� �� j-� ������ i-� ������, ���������� �� �����������
            }
        }
    }
}

void Matrix::Print()
 {
    for (size_t i = 0; i < rows; ++i) 
    {
        for (size_t j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
    cout << endl;
    }
 }
