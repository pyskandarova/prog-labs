#include <iostream>

class Vector {
private:
    double x;
    double y;
    double z;

public:
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    Vector operator*(double scalar) const {
        return Vector(x * scalar, y * scalar, z * scalar);
    }

    Vector operator/(double scalar) const {
        return Vector(x / scalar, y / scalar, z / scalar);
    }

    void display() const {
        std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
    }
};

int main() {
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    Vector sum = v1 + v2;
    Vector diff = v1 - v2;
    Vector scalarMul = v1 * 2.0;
    Vector scalarDiv = v2 / 2.0;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    std::cout << "Scalar Multiplication: ";
    scalarMul.display();

    std::cout << "Scalar Division: ";
    scalarDiv.display();

    return 0;
}