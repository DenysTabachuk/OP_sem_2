#include <iostream>
#include <conio.h>
#include "header.h"
using namespace std;

void print_info() {
	std::cout << "\t\t\t\tInfo\n\n"
		<< "This program creates 3 vectors B1, B2, B3 using 3 different constructors.\n"
		<< "We enter the spherical coordinates of the vector and calculate the coordinates \nin the Cartesian system. "
		<< "Using the overloaded operator \" += \", we increase \nthe value of the polar angle of vector B1"
		<< " and recalculate the coordinates in theCartesian system. Using the overloaded operator"
		<< "\" != \" we check whether \nvectors B2 and B3 are non - collinear.\n\n\n\n\n";
}


// Функція для створення вектора B1 з допомогою конструктора з параметрами
vector create_vector_with_parameters() {
    double radius, p_angle, a_angle;
    cout << "\nEnter the radius, azimuthal angle, polar angle of vector B1 through a space \nin the order:" << endl;
    cin >> radius >> a_angle >> p_angle;
    vector B1(radius, a_angle, p_angle);
    B1.print_cartesian_coordinates();
    return B1;
}


// Функція для створення вектора B2 з допомогою конструктора за замовчуванням
vector create_vector_with_default_constructor() {
    double radius, p_angle, a_angle;
    cout << "\nEnter the radius, azimuthal angle, polar angle of vector B2 through a space \nin the order:" << endl;
    cin >> radius >> a_angle >> p_angle;
    vector B2;
    B2.set_radius(radius);
    B2.set_azimuth_angle(a_angle);
    B2.set_polar_angle(p_angle);
    B2.find_cartesian_coordinates();
    B2.print_cartesian_coordinates();
    return B2;
}


// Функція для створення вектора B3 з допомогою конструктора копіювання
vector create_vector_with_copy_constructor(vector B1) {
    double radius, p_angle, a_angle;
    cout << "\nVector B3 will be created using the copy constructor. Now it has the same spherical coordinates as vector B1.\n"
        << "If you want to change them, press enter, otherwise esc.\n";

    vector B3;
    if (_getch() == 13) {
        cout << "\nEnter the radius, azimuthal angle, polar angle of vector B2 through a space \nin the order:" << endl;
        cin >> radius >> a_angle >> p_angle;
        B3 = vector(radius, a_angle, p_angle);
        B3.find_cartesian_coordinates();
        B3.print_cartesian_coordinates();
    }
    else {
        B3 = vector(B1); // конструктор копіювання
    }
    B3.print_cartesian_coordinates();
    return B3;
}


// Функція для збільшення полярного кута вектора B1
void increment_polar_angle(vector& B1) {
    double increment;
    cout << "\nEnter the amount by which you want to increase the polar angle of vector B1:\n";
    cin >> increment;
    B1 += increment;
    B1.find_cartesian_coordinates();
    B1.print_spherical_coordinates();
    B1.print_cartesian_coordinates();
}