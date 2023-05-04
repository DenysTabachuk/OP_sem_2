#include <iostream>
#include <iomanip>
#include <math.h>
#include "header.h"

#define M_PI 3.14159265358979323846

using namespace std;

//Методи
void vector::degree_to_360() {
	
	cout << "\n" << setw(4) << azimuth_angle << " azimuth angle coverted to ";
	
	while (azimuth_angle > 360) {
		azimuth_angle -= 360;
	}

	while (azimuth_angle < 0) {
		azimuth_angle += 360;
	}

	cout << setw(3) << azimuth_angle << endl;
}

void vector::degree_to_180() {

	cout << "\n" << setw(4) <<  polar_angle << " polar angle converted to ";

	while (polar_angle > 180) {
		polar_angle -= 180;
	}

	while (polar_angle < 0) {
		polar_angle += 180;
	}

	cout << setw(3) << polar_angle << endl;

}

void vector::find_cartesian_coordinates() {
	if (azimuth_angle > 360 ||azimuth_angle < 0)	
		degree_to_360();
	if (polar_angle > 180 || polar_angle < 0) 
		degree_to_180();

	double radians_theta = polar_angle * M_PI / 180.0; //перетворення градусів у радіани
	double radians_phi = azimuth_angle * M_PI / 180.0;  
	x = radius * sin(radians_theta) * cos(radians_phi); // x = r * sin(θ) * cos(φ)
	y = radius * sin(radians_theta) * sin(radians_phi); //  y = r * sin(θ) * sin(φ)
	z = radius * cos(radians_theta); //  z = r * cos(θ)
}

void vector::print_cartesian_coordinates() {
	cout << "\nCoordinates of the vector in the Cartesian coordinate system:\n";
	cout << "x: " << x << " y: " << y << " z:" << z << endl;
}

void vector::print_spherical_coordinates(){
	cout << "\nSpherical coordinates of the vector:\n";
	cout << "radius: " << radius << " azimuthal angle: " << azimuth_angle << " polar angle: " << polar_angle << endl;
}

bool vector::is_zero_vector() {
	return (x == 0 && y == 0 && z == 0);
}

//Перевантаження операторів
void vector::operator += (double increment) {
	polar_angle += increment;
	find_cartesian_coordinates();
}

bool vector::operator != (vector& other) { // перевірка не колінеарності

	if (is_zero_vector() || other.is_zero_vector()) { // перевірка на нуль-вектор
		return false;
	}

	vector temp;
	temp.x = y * other.z - z * other.y;
	temp.y = z * other.x - x * other.z;
	temp.z = x * other.y - y * other.x;


	if (temp.is_zero_vector())
		return false;

	return true;
}

//Конструктори
vector::vector(double r, double a_angle, double p_angle) {  //конструктор з параметрами
	polar_angle = p_angle;
	azimuth_angle = a_angle;
	radius = r;
	find_cartesian_coordinates();
	
}

vector::vector(const vector& other) { //конструктор копіювання
	polar_angle = other.polar_angle;
	azimuth_angle = other.azimuth_angle;
	radius = other.radius;
	x = other.x;
	y = other.y;
	z = other.z;
}

vector::vector() {
	polar_angle = azimuth_angle = radius = x = y = z = 0;
}



// Гетери
double vector::get_polar_angle() {
	return polar_angle;
}

double vector::get_azimuth_angle(){
	return azimuth_angle;
}

double vector::get_radius()  {
	return radius;
}

double vector::get_x()  {
	return x;
}

double vector::get_y()  {
	return y;
}

double vector::get_z()  {
	return z;
}



// Сетери
void vector::set_polar_angle(double p_angle) {
	polar_angle = p_angle;
}

void vector::set_azimuth_angle(double a_angle) {
	azimuth_angle = a_angle;
}

void vector::set_radius(double r) {
	radius = r;
}

void vector::set_x(double x_value) {
	x = x_value;
}

void vector::set_y(double y_value) {
	y = y_value;
}

void vector::set_z(double z_value) {
	z = z_value;
}