#include "classTriangle.h"


//перевірка чи лежать точки на одній прямій
bool triangle_square::Triangle::are_points_collinear(const Point& point1, const Point& point2, const Point& point3) {
    return (point2.y - point1.y) * (point3.z - point1.z) == (point2.z - point1.z) * (point3.y - point1.y) &&
        (point2.z - point1.z) * (point3.x - point1.x) == (point2.x - point1.x) * (point3.z - point1.z) &&
        (point2.x - point1.x) * (point3.y - point1.y) == (point2.y - point1.y) * (point3.x - point1.x);
}

//обчислення сторін трикутника за координатами вершин
double triangle_square::Triangle::calculate_sides(const Point& point1, const Point& point2) {
    return std::sqrt(std::pow(point2.x - point1.x, 2) + std::pow(point2.y - point1.y, 2) + std::pow(point2.z - point1.z, 2));
}



//обчислення площі
double triangle_square::Triangle::calculate_square() {
    if (points_set_manually && are_points_collinear(pointA, pointB, pointC)) {
        throw gcnew System::ArgumentException("Неможливо обчислити площу: точки лежать на одній прямій.");
    }


    if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
        throw gcnew System::ArgumentException("Неможливо обчислити площу: сторона трикутника менша або дорівнює нулю.");
    }
    else if (side1 + side2 <= side3 || side2 + side3 <= side1 || side3 + side1 <= side2) {
        throw gcnew System::ArgumentException("Неможливо обчислити площу: з цих сторін неможливо побудувати трикутник.");
    }

  
    double semiPerimeter = (side1 + side2 + side3) / 2;
    double area = std::sqrt(semiPerimeter * (semiPerimeter - side1) * (semiPerimeter - side2) * (semiPerimeter - side3));
    return area;
}





//конструктори
triangle_square::Triangle::Triangle(double side1, double side2, double side3) {
    this->pointA = { 0, 0, 0 };
    this->pointB = { 0, 0, 0 };
    this->pointC = { 0, 0, 0 };
    points_set_manually = false;


    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}


triangle_square::Triangle::Triangle(const Point& point1, const Point& point2, const Point& point3) {
    this->pointA = point1;
    this->pointB = point2;
    this->pointC = point3;
    points_set_manually = true;

    this->side1 = calculate_sides(pointA, pointB);
    this->side2 = calculate_sides(pointB, pointC);
    this->side3 = calculate_sides(pointC, pointA);
}


triangle_square::Triangle::Triangle(const Triangle& other) {
    this->pointA = other.pointA;
    this->pointB = other.pointB;
    this->pointC = other.pointC;
    points_set_manually = true;

    this->side1 = other.side1;
    this->side2 = other.side2;
    this->side3 = other.side3;
}

