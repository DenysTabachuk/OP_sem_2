#include <iostream>
#include <cmath>

namespace triangle_square {

    struct Point {
        double x;
        double y;
        double z;

        Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    };

    class Triangle {
    private:
        Point pointA;
        Point pointB;
        Point pointC;

        double side1, side2, side3;

        bool points_set_manually;


        bool  are_points_collinear(const Point& point1, const Point& point2, const Point& point3);
        double calculate_sides(const Point& point1, const Point& point2);
    public:
        Triangle() {}
        Triangle(const Point& point1, const Point& point2, const Point& point3);
        Triangle(double side1, double side2, double side3);
        Triangle(const Triangle& other);


        ~Triangle() {}







        // Гетери
        Point getPointA() const { return pointA; }
        Point getPointB() const { return pointB; }
        Point getPointC() const { return pointC; }

        double getSide1() const { return side1; }
        double getSide2() const { return side2; }
        double getSide3() const { return side3; }

        bool arePointsSetManually() const { return points_set_manually; }

        // Сетери
        void setPointA(const Point& point) { points_set_manually = true, pointA = point; }
        void setPointB(const Point& point) { points_set_manually = true, pointB = point; }
        void setPointC(const Point& point) { points_set_manually = true, pointC = point; }

        void setSide1(double side) { side1 = side; }
        void setSide2(double side) { side2 = side; }
        void setSide3(double side) { side3 = side; }



        double calculate_square();
    };

}