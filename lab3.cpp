#include <iostream>

using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int columns;

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[columns];
        }
    }

    void setData(int** values) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                data[i][j] = values[i][j];
            }
        }
    }

    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }

    Matrix operator*(const Matrix& other) const {
        Matrix result(rows, other.columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.columns; ++j) {
                result.data[i][j] = 0;
                for (int k = 0; k < columns; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator/(const Matrix& other) const {
        Matrix result(rows, columns);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                result.data[i][j] = data[i][j] / other.data[i][j];
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    const int rows = 2;
    const int columns = 2;
    int** values1 = new int*[rows];
    int** values2 = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        values1[i] = new int[columns];
        values2[i] = new int[columns];
    }
    
    // Вводим элементы первой матрицы
    cout << "Введите элементы первой матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> values1[i][j];
        }
    }

    // Вводим элементы второй матрицы
    cout << "Введите элементы второй матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cin >> values2[i][j];
        }
    }

    Matrix m1(rows, columns);
    m1.setData(values1);

    Matrix m2(rows, columns);
    m2.setData(values2);

    Matrix sum = m1 + m2;
    cout << "Сумма:\n";
    sum.print();

    Matrix diff = m1 - m2;
    cout << "Разность:\n";
    diff.print();

    Matrix product = m1 * m2;
    cout << "Произведение:\n";
    product.print();

    Matrix quotient = m1 / m2;
    cout << "Частное:\n";
    quotient.print();

    // Освобождаем память
    for (int i = 0; i < rows; ++i) {
        delete[] values1[i];
        delete[] values2[i];
    }
    delete[] values1;
    delete[] values2;

    return 0;
}
