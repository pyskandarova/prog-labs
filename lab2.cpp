#include <iostream>
#include <vector>

class Vector {
private:
    std::vector<int> elements;

public:
    Vector(std::vector<int> values) : elements(values) {}

    Vector operator+(const Vector& other) const {
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.push_back(elements[i] + other.elements[i]);
        }
        return Vector(result);
    }

    Vector operator-(const Vector& other) const {
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.push_back(elements[i] - other.elements[i]);
        }
        return Vector(result);
    }

    Vector operator*(int scalar) const {
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.push_back(elements[i] * scalar);
        }
        return Vector(result);
    }

    Vector operator/(int scalar) const {
        std::vector<int> result;
        for (size_t i = 0; i < elements.size(); i++) {
            result.push_back(elements[i] / scalar);
        }
        return Vector(result);
    }

    void print() const {
        std::cout << "[ ";
        for (const auto& element : elements) {
            std::cout << element << " ";
        }
        std::cout << "]" << std::endl;
    }
};

int main() {
    std::vector<int> values1 = {1, 2, 3};
    std::vector<int> values2 = {4, 5, 6};

    Vector v1(values1);
    Vector v2(values2);

    Vector sum = v1 + v2;
    Vector difference = v1 - v2;
    Vector scaled = v1 * 3;
    Vector divided = v2 / 2;

    std::cout << "v1: ";
    v1.print();

    std::cout << "v2: ";
    v2.print();

    std::cout << "Sum: ";
    sum.print();

    std::cout << "Difference: ";
    difference.print();

    std::cout << "Scaled: ";
    scaled.print();

    std::cout << "Divided: ";
    divided.print();

    return 0;
}
