#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
    vector<vector<int>> data;
    int rows;
    int columns;

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        data.resize(rows, vector<int>(columns, 0));
    }

    void setData(const vector<vector<int>>& input) {
        if (input.size() != rows || input[0].size() != columns) {
            cout << "Invalid input size for matrix\n";
            return;
        }
        data = input;
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Matrix dimensions are not compatible for addition\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || columns != other.columns) {
            cout << "Matrix dimensions are not compatible for subtraction\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (columns != other.rows) {
            cout << "Matrix dimensions are not compatible for multiplication\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, other.columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.columns; j++) {
                for (int k = 0; k < columns; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }

        return result;
    }

    Matrix operator/(const Matrix& other) const {
        if (other.rows != other.columns || other.rows != 1) {
            cout << "Matrix dimensions are not compatible for division\n";
            return Matrix(0, 0);
        }

        if (other.data[0][0] == 0) {
            cout << "Division by zero error\n";
            return Matrix(0, 0);
        }

        Matrix result(rows, columns);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                result.data[i][j] = data[i][j] / other.data[0][0];
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    Matrix m1(2, 2);
    m1.setData({{1, 2}, {3, 4}});

    Matrix m2(2, 2);
    m2.setData({{5, 6}, {7, 8}});

    Matrix sum = m1 + m2;
    cout << "Sum:\n";
    sum.print();

    Matrix diff = m1 - m2;
    cout << "Difference:\n";
    diff.print();

    Matrix product = m1 * m2;
    cout << "Product:\n";
    product.print();

    Matrix quotient = m1 / m2;
    cout << "Quotient:\n";
    quotient.print();

    return 0;
}
