#include <iostream>

using namespace std;

const int max_size=3; //Максимально возможный размер массива

////////////////
// МОЙ ВЕКТОР //
////////////////
class MyVector {
private:
    int* elements; // Массив элементов
public:
    MyVector(int* values) : elements(values) {}

    MyVector operator+(const MyVector& other) const {
        int* result {new int[max_size]};
        for (int i = 0; i < max_size; i++) {
            result[i] = elements[i] + other.elements[i];
        }
        return MyVector(result);
    }

    MyVector operator-(const MyVector& other) const {
        int* result {new int[max_size]};
        for (int i = 0; i < max_size; i++) {
            result[i] = elements[i] - other.elements[i];
        }
        return MyVector(result);
    }

    MyVector operator*(int scalar) const {
        int* result {new int[max_size]};
        for (int i = 0; i < max_size; i++) {
            result[i] = elements[i] * scalar;
        }
        return MyVector(result);
    }

    MyVector operator/(int scalar) const {
        int* result {new int[max_size]};
        for (int i = 0; i < max_size; i++) {
            result[i] = elements[i] / scalar;
        }
        return MyVector(result);
    }

    void print(){
        cout << "[ ";
        for (int i = 0; i < max_size; i++) {
            cout << elements[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main() {
    int *arr1 {new int[max_size]{ 1, 2, 3}};
    int *arr2 {new int[max_size]{ 4, 5, 6}};

    MyVector v1(arr1);
    MyVector v2(arr2);

    MyVector sum = v1 + v2;
    MyVector difference = v1 - v2;
    MyVector scaled = v1 * 3;
    MyVector divided = v2 / 2;

    cout << "v1: ";
    v1.print();

    cout << "v2: ";
    v2.print();

    cout << "Sum: ";
    sum.print();

    cout << "Difference: ";
    difference.print();

    cout << "Scaled: ";
    scaled.print();

    cout << "Divided: ";
    divided.print();

    return 0;
}
