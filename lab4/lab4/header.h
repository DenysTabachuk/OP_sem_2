#pragma once
#include <math.h>

class vector {
private:

	double polar_angle;
	double azimuth_angle;
	double radius;

	double x;
	double y;
	double z;
	

public:
	void find_cartesian_coordinates(); //пошук координат у декартовій системі
	void print_cartesian_coordinates();//виведення координат у декартовій системі
	void print_spherical_coordinates();//виведення сферичних координат
	bool is_zero_vector(); //перевірка на нульовий вектор
	


	//ці два методи потрібні для кращого порівняння результатів обчислення з калькулятором
	void degree_to_360();// щоб конвертувати градуси у діапазон від 0 до 360 градусів
	void degree_to_180();//щоб конвертувати градуси у діапазон від 0 до 180 градусів


	vector();// конструктор за замовчування
	vector(double r, double a_angle, double p_angle);  //конструктор з параметрами
	vector(const vector& other); //конструктор копіювання
	
	~vector(){} //деструктор за замовчуванням


	  // гетери
	double get_polar_angle();
	double get_azimuth_angle();
	double get_radius();
	double get_x();
	double get_y();
	double get_z();

	// сетери
	void set_polar_angle(double p_angle);
	void set_azimuth_angle(double a_angle);
	void set_radius(double r);
	void set_x(double x_coord);
	void set_y(double y_coord);
	void set_z(double z_coord);


	//перевантаження операторів
	void operator += (double increment); //збільшення полярного кута на вказану величину
	bool operator != (vector& other); //первірка на неколінеарність
};


void print_info();
vector create_vector_with_parameters();
vector create_vector_with_default_constructor();
vector create_vector_with_copy_constructor(vector B1);
void increment_polar_angle(vector& B1);