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
	void find_cartesian_coordinates(); //����� ��������� � ��������� ������
	void print_cartesian_coordinates();//��������� ��������� � ��������� ������
	void print_spherical_coordinates();//��������� ��������� ���������
	bool is_zero_vector(); //�������� �� �������� ������
	


	//�� ��� ������ ������ ��� ������� ��������� ���������� ���������� � �������������
	void degree_to_360();// ��� ������������ ������� � ������� �� 0 �� 360 �������
	void degree_to_180();//��� ������������ ������� � ������� �� 0 �� 180 �������


	vector();// ����������� �� ������������
	vector(double r, double a_angle, double p_angle);  //����������� � �����������
	vector(const vector& other); //����������� ���������
	
	~vector(){} //���������� �� �������������


	  // ������
	double get_polar_angle();
	double get_azimuth_angle();
	double get_radius();
	double get_x();
	double get_y();
	double get_z();

	// ������
	void set_polar_angle(double p_angle);
	void set_azimuth_angle(double a_angle);
	void set_radius(double r);
	void set_x(double x_coord);
	void set_y(double y_coord);
	void set_z(double z_coord);


	//�������������� ���������
	void operator += (double increment); //��������� ��������� ���� �� ������� ��������
	bool operator != (vector& other); //������� �� �������������
};


void print_info();
vector create_vector_with_parameters();
vector create_vector_with_default_constructor();
vector create_vector_with_copy_constructor(vector B1);
void increment_polar_angle(vector& B1);