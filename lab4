#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class Vector;  // Предварительное объявление класса Vector

class Matrix {
private:
    int data[MAX_SIZE][MAX_SIZE];
    int rows;
    int columns;

public:
    Matrix(int rows, int columns) : rows(rows), columns(columns) {
        // Инициализируем матрицу нулями
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                data[i][j] = 0;
            }
        }
    }

    int getRows() const {
        return rows;
    }

    int getColumns() const {
        return columns;
    }

    void setData(int i, int j, int value) {
        data[i][j] = value;
    }

    int getData(int i, int j) const {
        return data[i][j];
    }

    Vector operator*(const Vector& vector) const;  // Объявление оператора умножения
};

class Vector {
private:
    int data[MAX_SIZE];
    int size;

public:
    Vector(int size) : size(size) {
        // Инициализируем вектор нулями
        for (int i = 0; i < size; ++i) {
            data[i] = 0;
        }
    }

    int getSize() const {
        return size;
    }

    void setData(int i, int value) {
        data[i] = value;
    }

    int getData(int i) const {
        return data[i];
    }

    friend class Matrix;  // Дружественное объявление класса Matrix
};

// Определение оператора умножения для класса Matrix
Vector Matrix::operator*(const Vector& vector) const {
    if (columns != vector.getSize()) {
        cout << "Matrix and vector dimensions are not compatible for multiplication\n";
        return Vector(0);
    }

    Vector result(rows);
    for (int i = 0; i < rows; ++i) {
        int sum = 0;
        for (int j = 0; j < columns; ++j) {
            sum += data[i][j] * vector.getData(j);
        }
        result.setData(i, sum);
    }
    return result;
}

int main() {
    int matrixRows, matrixColumns;

    cout << "Введите количество строк матрицы: ";
    cin >> matrixRows;
    cout << "Введите количество столбцов матрицы: ";
    cin >> matrixColumns;

    Matrix matrix(matrixRows, matrixColumns);

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < matrixRows; ++i) {
        for (int j = 0; j < matrixColumns; ++j) {
            int value;
            cin >> value;
            matrix.setData(i, j, value);
        }
    }

    int vectorSize;

    cout << "Введите размер вектора: ";
    cin >> vectorSize;

    Vector vector(vectorSize);

    cout << "Введите элементы вектора:\n";
    for (int i = 0; i < vectorSize; ++i) {
        int value;
        cin >> value;
        vector.setData(i, value);
    }

    Vector result = matrix * vector;

    cout << "Результат умножения матрицы на вектор:\n";
    for (int i = 0; i < result.getSize(); ++i) {
        cout << result.getData(i) << "\n";
    }

    return 0;
}
