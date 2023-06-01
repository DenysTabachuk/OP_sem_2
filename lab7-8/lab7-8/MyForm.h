#pragma once
#include "classTriangle.h"
#include  <cmath>//для заокруглення

namespace lab78 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
	private:
		triangle_square::Triangle createTriangleFromCoordinates(System::Windows::Forms::TextBox^ textBoxX1, System::Windows::Forms::TextBox^ textBoxY1, System::Windows::Forms::TextBox^ textBoxZ1,
			System::Windows::Forms::TextBox^ textBoxX2, System::Windows::Forms::TextBox^ textBoxY2, System::Windows::Forms::TextBox^ textBoxZ2,
			System::Windows::Forms::TextBox^ textBoxX3, System::Windows::Forms::TextBox^ textBoxY3, System::Windows::Forms::TextBox^ textBoxZ3)
		{
			double x1 = Convert::ToDouble(textBoxX1->Text);
			double x2 = Convert::ToDouble(textBoxX2->Text);
			double x3 = Convert::ToDouble(textBoxX3->Text);

			double y1 = Convert::ToDouble(textBoxY1->Text);
			double y2 = Convert::ToDouble(textBoxY2->Text);
			double y3 = Convert::ToDouble(textBoxY3->Text);

			double z1 = Convert::ToDouble(textBoxZ1->Text);
			double z2 = Convert::ToDouble(textBoxZ2->Text);
			double z3 = Convert::ToDouble(textBoxZ3->Text);

			return triangle_square::Triangle(triangle_square::Point(x1, y1, z1),
				triangle_square::Point(x2, y2, z2),
				triangle_square::Point(x3, y3, z3));
		}

	private:
		triangle_square::Triangle createTriangleFromSides(System::Windows::Forms::TextBox^ textBoxSide1, System::Windows::Forms::TextBox^ textBoxSide2, System::Windows::Forms::TextBox^ textBoxSide3)
		{
			double side1 = Convert::ToDouble(textBoxSide1->Text);
			double side2 = Convert::ToDouble(textBoxSide2->Text);
			double side3 = Convert::ToDouble(textBoxSide3->Text);

			return triangle_square::Triangle(side1, side2, side3);
		}

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_pointA;
	protected:
	private: System::Windows::Forms::Label^ label_pointB;
	private: System::Windows::Forms::Label^ label_pointC;

	private: System::Windows::Forms::TextBox^ textBox_pointA1x;
	private: System::Windows::Forms::TextBox^ textBox_pointA1y;
	private: System::Windows::Forms::TextBox^ textBox_pointA1z;
	private: System::Windows::Forms::TextBox^ textBox_pointB1z;




	private: System::Windows::Forms::TextBox^ textBox_pointB1y;

	private: System::Windows::Forms::TextBox^ textBox_pointB1x;
	private: System::Windows::Forms::TextBox^ textBox_pointC1z;


	private: System::Windows::Forms::TextBox^ textBox_pointC1y;

	private: System::Windows::Forms::TextBox^ textBox_pointC1x;

	private: System::Windows::Forms::Button^ button_calculate_square;
	private: System::Windows::Forms::TextBox^ textBox_pointA2z;

	private: System::Windows::Forms::TextBox^ textBox_pointA2y;

	private: System::Windows::Forms::TextBox^ textBox_pointA2x;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_pointB2z;

	private: System::Windows::Forms::TextBox^ textBox_pointB2y;

	private: System::Windows::Forms::TextBox^ textBox_pointB2x;

	private: System::Windows::Forms::Label^ label_pointB2;
	private: System::Windows::Forms::TextBox^ textBox_pointC2z;




	private: System::Windows::Forms::TextBox^ textBox_pointC2y;

	private: System::Windows::Forms::TextBox^ textBox_pointC2x;

	private: System::Windows::Forms::Label^ label_pointC2;

	private: System::Windows::Forms::Label^ label_S1;
	private: System::Windows::Forms::Label^ label_S2;

	private: System::Windows::Forms::Label^ label_a1_lenght;

	private: System::Windows::Forms::Label^ label_b1_lenght;
	private: System::Windows::Forms::Label^ label_c1_lenght;
	private: System::Windows::Forms::TextBox^ textBox_a1_lenght;
	private: System::Windows::Forms::TextBox^ textBox_b1_lenght;
	private: System::Windows::Forms::TextBox^ textBox_c1_lenght;
	private: System::Windows::Forms::TextBox^ textBox_c2_lenght;






	private: System::Windows::Forms::TextBox^ textBox_b2_lenght;

	private: System::Windows::Forms::TextBox^ textBox_a2_lenght;

	private: System::Windows::Forms::Label^ label_c2_lenght;
	private: System::Windows::Forms::Label^ label_b2_lenght;
	private: System::Windows::Forms::Label^ label_a2_lenght;
	private: System::Windows::Forms::RadioButton^ radioButton_coordinates1;
	private: System::Windows::Forms::RadioButton^ radioButton_lenght1;
	private: System::Windows::Forms::RadioButton^ radioButton_coordinates2;
	private: System::Windows::Forms::RadioButton^ radioButton_lenght2;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label_result;
private: System::IO::Ports::SerialPort^ serialPort1;
private: System::Windows::Forms::Label^ label1;
private: System::ComponentModel::IContainer^ components;






	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label_pointA = (gcnew System::Windows::Forms::Label());
			this->label_pointB = (gcnew System::Windows::Forms::Label());
			this->label_pointC = (gcnew System::Windows::Forms::Label());
			this->textBox_pointA1x = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointA1y = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointA1z = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointB1z = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointB1y = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointB1x = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointC1z = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointC1y = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointC1x = (gcnew System::Windows::Forms::TextBox());
			this->button_calculate_square = (gcnew System::Windows::Forms::Button());
			this->textBox_pointA2z = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointA2y = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointA2x = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_pointB2z = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointB2y = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointB2x = (gcnew System::Windows::Forms::TextBox());
			this->label_pointB2 = (gcnew System::Windows::Forms::Label());
			this->textBox_pointC2z = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointC2y = (gcnew System::Windows::Forms::TextBox());
			this->textBox_pointC2x = (gcnew System::Windows::Forms::TextBox());
			this->label_pointC2 = (gcnew System::Windows::Forms::Label());
			this->label_S1 = (gcnew System::Windows::Forms::Label());
			this->label_S2 = (gcnew System::Windows::Forms::Label());
			this->label_a1_lenght = (gcnew System::Windows::Forms::Label());
			this->label_b1_lenght = (gcnew System::Windows::Forms::Label());
			this->label_c1_lenght = (gcnew System::Windows::Forms::Label());
			this->textBox_a1_lenght = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b1_lenght = (gcnew System::Windows::Forms::TextBox());
			this->textBox_c1_lenght = (gcnew System::Windows::Forms::TextBox());
			this->textBox_c2_lenght = (gcnew System::Windows::Forms::TextBox());
			this->textBox_b2_lenght = (gcnew System::Windows::Forms::TextBox());
			this->textBox_a2_lenght = (gcnew System::Windows::Forms::TextBox());
			this->label_c2_lenght = (gcnew System::Windows::Forms::Label());
			this->label_b2_lenght = (gcnew System::Windows::Forms::Label());
			this->label_a2_lenght = (gcnew System::Windows::Forms::Label());
			this->radioButton_coordinates1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_lenght1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_coordinates2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_lenght2 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label_result = (gcnew System::Windows::Forms::Label());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_pointA
			// 
			this->label_pointA->AutoSize = true;
			this->label_pointA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_pointA->Location = System::Drawing::Point(17, 87);
			this->label_pointA->Name = L"label_pointA";
			this->label_pointA->Size = System::Drawing::Size(250, 25);
			this->label_pointA->TabIndex = 0;
			this->label_pointA->Text = L"A1 = {          ;        ;         }";
			this->label_pointA->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_pointB
			// 
			this->label_pointB->AutoSize = true;
			this->label_pointB->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_pointB->Location = System::Drawing::Point(17, 129);
			this->label_pointB->Name = L"label_pointB";
			this->label_pointB->Size = System::Drawing::Size(250, 25);
			this->label_pointB->TabIndex = 1;
			this->label_pointB->Text = L"B1 = {          ;        ;         }";
			// 
			// label_pointC
			// 
			this->label_pointC->AutoSize = true;
			this->label_pointC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_pointC->Location = System::Drawing::Point(16, 174);
			this->label_pointC->Name = L"label_pointC";
			this->label_pointC->Size = System::Drawing::Size(251, 25);
			this->label_pointC->TabIndex = 2;
			this->label_pointC->Text = L"C1 = {          ;        ;         }";
			// 
			// textBox_pointA1x
			// 
			this->textBox_pointA1x->Location = System::Drawing::Point(90, 91);
			this->textBox_pointA1x->Name = L"textBox_pointA1x";
			this->textBox_pointA1x->Size = System::Drawing::Size(40, 20);
			this->textBox_pointA1x->TabIndex = 4;
			// 
			// textBox_pointA1y
			// 
			this->textBox_pointA1y->Location = System::Drawing::Point(148, 91);
			this->textBox_pointA1y->Name = L"textBox_pointA1y";
			this->textBox_pointA1y->Size = System::Drawing::Size(40, 20);
			this->textBox_pointA1y->TabIndex = 5;
			// 
			// textBox_pointA1z
			// 
			this->textBox_pointA1z->Location = System::Drawing::Point(204, 91);
			this->textBox_pointA1z->Name = L"textBox_pointA1z";
			this->textBox_pointA1z->Size = System::Drawing::Size(39, 20);
			this->textBox_pointA1z->TabIndex = 6;
			// 
			// textBox_pointB1z
			// 
			this->textBox_pointB1z->Location = System::Drawing::Point(204, 134);
			this->textBox_pointB1z->Name = L"textBox_pointB1z";
			this->textBox_pointB1z->Size = System::Drawing::Size(39, 20);
			this->textBox_pointB1z->TabIndex = 9;
			// 
			// textBox_pointB1y
			// 
			this->textBox_pointB1y->Location = System::Drawing::Point(148, 133);
			this->textBox_pointB1y->Name = L"textBox_pointB1y";
			this->textBox_pointB1y->Size = System::Drawing::Size(40, 20);
			this->textBox_pointB1y->TabIndex = 8;
			// 
			// textBox_pointB1x
			// 
			this->textBox_pointB1x->Location = System::Drawing::Point(90, 133);
			this->textBox_pointB1x->Name = L"textBox_pointB1x";
			this->textBox_pointB1x->Size = System::Drawing::Size(40, 20);
			this->textBox_pointB1x->TabIndex = 7;
			// 
			// textBox_pointC1z
			// 
			this->textBox_pointC1z->Location = System::Drawing::Point(204, 174);
			this->textBox_pointC1z->Name = L"textBox_pointC1z";
			this->textBox_pointC1z->Size = System::Drawing::Size(39, 20);
			this->textBox_pointC1z->TabIndex = 12;
			// 
			// textBox_pointC1y
			// 
			this->textBox_pointC1y->Location = System::Drawing::Point(147, 175);
			this->textBox_pointC1y->Name = L"textBox_pointC1y";
			this->textBox_pointC1y->Size = System::Drawing::Size(40, 20);
			this->textBox_pointC1y->TabIndex = 11;
			// 
			// textBox_pointC1x
			// 
			this->textBox_pointC1x->Location = System::Drawing::Point(89, 174);
			this->textBox_pointC1x->Name = L"textBox_pointC1x";
			this->textBox_pointC1x->Size = System::Drawing::Size(40, 20);
			this->textBox_pointC1x->TabIndex = 10;
			// 
			// button_calculate_square
			// 
			this->button_calculate_square->Location = System::Drawing::Point(18, 509);
			this->button_calculate_square->Name = L"button_calculate_square";
			this->button_calculate_square->Size = System::Drawing::Size(170, 52);
			this->button_calculate_square->TabIndex = 13;
			this->button_calculate_square->Text = L"Обчислити площу";
			this->button_calculate_square->UseVisualStyleBackColor = true;
			this->button_calculate_square->Click += gcnew System::EventHandler(this, &MyForm::button_calculate_square_Click);
			// 
			// textBox_pointA2z
			// 
			this->textBox_pointA2z->Location = System::Drawing::Point(203, 323);
			this->textBox_pointA2z->Name = L"textBox_pointA2z";
			this->textBox_pointA2z->Size = System::Drawing::Size(39, 20);
			this->textBox_pointA2z->TabIndex = 19;
			// 
			// textBox_pointA2y
			// 
			this->textBox_pointA2y->Location = System::Drawing::Point(145, 323);
			this->textBox_pointA2y->Name = L"textBox_pointA2y";
			this->textBox_pointA2y->Size = System::Drawing::Size(40, 20);
			this->textBox_pointA2y->TabIndex = 18;
			// 
			// textBox_pointA2x
			// 
			this->textBox_pointA2x->Location = System::Drawing::Point(90, 323);
			this->textBox_pointA2x->Name = L"textBox_pointA2x";
			this->textBox_pointA2x->Size = System::Drawing::Size(40, 20);
			this->textBox_pointA2x->TabIndex = 17;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(17, 318);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(250, 25);
			this->label3->TabIndex = 14;
			this->label3->Text = L"A2 = {          ;        ;         }";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox_pointB2z
			// 
			this->textBox_pointB2z->Location = System::Drawing::Point(203, 364);
			this->textBox_pointB2z->Name = L"textBox_pointB2z";
			this->textBox_pointB2z->Size = System::Drawing::Size(39, 20);
			this->textBox_pointB2z->TabIndex = 23;
			// 
			// textBox_pointB2y
			// 
			this->textBox_pointB2y->Location = System::Drawing::Point(145, 364);
			this->textBox_pointB2y->Name = L"textBox_pointB2y";
			this->textBox_pointB2y->Size = System::Drawing::Size(40, 20);
			this->textBox_pointB2y->TabIndex = 22;
			// 
			// textBox_pointB2x
			// 
			this->textBox_pointB2x->Location = System::Drawing::Point(90, 364);
			this->textBox_pointB2x->Name = L"textBox_pointB2x";
			this->textBox_pointB2x->Size = System::Drawing::Size(40, 20);
			this->textBox_pointB2x->TabIndex = 21;
			// 
			// label_pointB2
			// 
			this->label_pointB2->AutoSize = true;
			this->label_pointB2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_pointB2->Location = System::Drawing::Point(17, 359);
			this->label_pointB2->Name = L"label_pointB2";
			this->label_pointB2->Size = System::Drawing::Size(250, 25);
			this->label_pointB2->TabIndex = 20;
			this->label_pointB2->Text = L"B2 = {          ;        ;         }";
			this->label_pointB2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox_pointC2z
			// 
			this->textBox_pointC2z->Location = System::Drawing::Point(203, 406);
			this->textBox_pointC2z->Name = L"textBox_pointC2z";
			this->textBox_pointC2z->Size = System::Drawing::Size(39, 20);
			this->textBox_pointC2z->TabIndex = 27;
			// 
			// textBox_pointC2y
			// 
			this->textBox_pointC2y->Location = System::Drawing::Point(145, 406);
			this->textBox_pointC2y->Name = L"textBox_pointC2y";
			this->textBox_pointC2y->Size = System::Drawing::Size(40, 20);
			this->textBox_pointC2y->TabIndex = 26;
			// 
			// textBox_pointC2x
			// 
			this->textBox_pointC2x->Location = System::Drawing::Point(90, 406);
			this->textBox_pointC2x->Name = L"textBox_pointC2x";
			this->textBox_pointC2x->Size = System::Drawing::Size(40, 20);
			this->textBox_pointC2x->TabIndex = 25;
			// 
			// label_pointC2
			// 
			this->label_pointC2->AutoSize = true;
			this->label_pointC2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_pointC2->Location = System::Drawing::Point(15, 400);
			this->label_pointC2->Name = L"label_pointC2";
			this->label_pointC2->Size = System::Drawing::Size(251, 25);
			this->label_pointC2->TabIndex = 24;
			this->label_pointC2->Text = L"C2 = {          ;        ;         }";
			this->label_pointC2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_S1
			// 
			this->label_S1->AutoSize = true;
			this->label_S1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_S1->Location = System::Drawing::Point(15, 230);
			this->label_S1->Name = L"label_S1";
			this->label_S1->Size = System::Drawing::Size(56, 25);
			this->label_S1->TabIndex = 28;
			this->label_S1->Text = L"S1 =";
			// 
			// label_S2
			// 
			this->label_S2->AutoSize = true;
			this->label_S2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_S2->Location = System::Drawing::Point(17, 472);
			this->label_S2->Name = L"label_S2";
			this->label_S2->Size = System::Drawing::Size(56, 25);
			this->label_S2->TabIndex = 29;
			this->label_S2->Text = L"S1 =";
			// 
			// label_a1_lenght
			// 
			this->label_a1_lenght->AutoSize = true;
			this->label_a1_lenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_a1_lenght->Location = System::Drawing::Point(361, 90);
			this->label_a1_lenght->Name = L"label_a1_lenght";
			this->label_a1_lenght->Size = System::Drawing::Size(54, 25);
			this->label_a1_lenght->TabIndex = 31;
			this->label_a1_lenght->Text = L"a1 =";
			this->label_a1_lenght->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_b1_lenght
			// 
			this->label_b1_lenght->AutoSize = true;
			this->label_b1_lenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_b1_lenght->Location = System::Drawing::Point(361, 131);
			this->label_b1_lenght->Name = L"label_b1_lenght";
			this->label_b1_lenght->Size = System::Drawing::Size(54, 25);
			this->label_b1_lenght->TabIndex = 32;
			this->label_b1_lenght->Text = L"b1 =";
			this->label_b1_lenght->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_c1_lenght
			// 
			this->label_c1_lenght->AutoSize = true;
			this->label_c1_lenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_c1_lenght->Location = System::Drawing::Point(362, 171);
			this->label_c1_lenght->Name = L"label_c1_lenght";
			this->label_c1_lenght->Size = System::Drawing::Size(53, 25);
			this->label_c1_lenght->TabIndex = 33;
			this->label_c1_lenght->Text = L"c1 =";
			this->label_c1_lenght->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox_a1_lenght
			// 
			this->textBox_a1_lenght->Location = System::Drawing::Point(420, 93);
			this->textBox_a1_lenght->Name = L"textBox_a1_lenght";
			this->textBox_a1_lenght->Size = System::Drawing::Size(100, 20);
			this->textBox_a1_lenght->TabIndex = 34;
			// 
			// textBox_b1_lenght
			// 
			this->textBox_b1_lenght->Location = System::Drawing::Point(419, 137);
			this->textBox_b1_lenght->Name = L"textBox_b1_lenght";
			this->textBox_b1_lenght->Size = System::Drawing::Size(100, 20);
			this->textBox_b1_lenght->TabIndex = 35;
			// 
			// textBox_c1_lenght
			// 
			this->textBox_c1_lenght->Location = System::Drawing::Point(419, 174);
			this->textBox_c1_lenght->Name = L"textBox_c1_lenght";
			this->textBox_c1_lenght->Size = System::Drawing::Size(100, 20);
			this->textBox_c1_lenght->TabIndex = 36;
			// 
			// textBox_c2_lenght
			// 
			this->textBox_c2_lenght->Location = System::Drawing::Point(419, 400);
			this->textBox_c2_lenght->Name = L"textBox_c2_lenght";
			this->textBox_c2_lenght->Size = System::Drawing::Size(100, 20);
			this->textBox_c2_lenght->TabIndex = 42;
			// 
			// textBox_b2_lenght
			// 
			this->textBox_b2_lenght->Location = System::Drawing::Point(420, 360);
			this->textBox_b2_lenght->Name = L"textBox_b2_lenght";
			this->textBox_b2_lenght->Size = System::Drawing::Size(100, 20);
			this->textBox_b2_lenght->TabIndex = 41;
			// 
			// textBox_a2_lenght
			// 
			this->textBox_a2_lenght->Location = System::Drawing::Point(419, 319);
			this->textBox_a2_lenght->Name = L"textBox_a2_lenght";
			this->textBox_a2_lenght->Size = System::Drawing::Size(100, 20);
			this->textBox_a2_lenght->TabIndex = 40;
			// 
			// label_c2_lenght
			// 
			this->label_c2_lenght->AutoSize = true;
			this->label_c2_lenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_c2_lenght->Location = System::Drawing::Point(361, 396);
			this->label_c2_lenght->Name = L"label_c2_lenght";
			this->label_c2_lenght->Size = System::Drawing::Size(59, 25);
			this->label_c2_lenght->TabIndex = 39;
			this->label_c2_lenght->Text = L"c2 = ";
			this->label_c2_lenght->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_b2_lenght
			// 
			this->label_b2_lenght->AutoSize = true;
			this->label_b2_lenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_b2_lenght->Location = System::Drawing::Point(361, 359);
			this->label_b2_lenght->Name = L"label_b2_lenght";
			this->label_b2_lenght->Size = System::Drawing::Size(60, 25);
			this->label_b2_lenght->TabIndex = 38;
			this->label_b2_lenght->Text = L"b2 = ";
			this->label_b2_lenght->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_a2_lenght
			// 
			this->label_a2_lenght->AutoSize = true;
			this->label_a2_lenght->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->label_a2_lenght->Location = System::Drawing::Point(362, 318);
			this->label_a2_lenght->Name = L"label_a2_lenght";
			this->label_a2_lenght->Size = System::Drawing::Size(60, 25);
			this->label_a2_lenght->TabIndex = 37;
			this->label_a2_lenght->Text = L"a2 = ";
			this->label_a2_lenght->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// radioButton_coordinates1
			// 
			this->radioButton_coordinates1->AutoSize = true;
			this->radioButton_coordinates1->Checked = true;
			this->radioButton_coordinates1->Location = System::Drawing::Point(48, 9);
			this->radioButton_coordinates1->Name = L"radioButton_coordinates1";
			this->radioButton_coordinates1->Size = System::Drawing::Size(193, 17);
			this->radioButton_coordinates1->TabIndex = 43;
			this->radioButton_coordinates1->TabStop = true;
			this->radioButton_coordinates1->Text = L"Використати координати вершин";
			this->radioButton_coordinates1->UseVisualStyleBackColor = true;
			// 
			// radioButton_lenght1
			// 
			this->radioButton_lenght1->AutoSize = true;
			this->radioButton_lenght1->Location = System::Drawing::Point(365, 9);
			this->radioButton_lenght1->Name = L"radioButton_lenght1";
			this->radioButton_lenght1->Size = System::Drawing::Size(171, 17);
			this->radioButton_lenght1->TabIndex = 44;
			this->radioButton_lenght1->Text = L"Використати довжини сторін";
			this->radioButton_lenght1->UseVisualStyleBackColor = true;
			// 
			// radioButton_coordinates2
			// 
			this->radioButton_coordinates2->AutoSize = true;
			this->radioButton_coordinates2->Checked = true;
			this->radioButton_coordinates2->Location = System::Drawing::Point(48, 10);
			this->radioButton_coordinates2->Name = L"radioButton_coordinates2";
			this->radioButton_coordinates2->Size = System::Drawing::Size(193, 17);
			this->radioButton_coordinates2->TabIndex = 45;
			this->radioButton_coordinates2->TabStop = true;
			this->radioButton_coordinates2->Text = L"Використати координати вершин";
			this->radioButton_coordinates2->UseVisualStyleBackColor = true;
			// 
			// radioButton_lenght2
			// 
			this->radioButton_lenght2->AutoSize = true;
			this->radioButton_lenght2->Location = System::Drawing::Point(365, 10);
			this->radioButton_lenght2->Name = L"radioButton_lenght2";
			this->radioButton_lenght2->Size = System::Drawing::Size(171, 17);
			this->radioButton_lenght2->TabIndex = 46;
			this->radioButton_lenght2->Text = L"Використати довжини сторін";
			this->radioButton_lenght2->UseVisualStyleBackColor = true;
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox1->Controls->Add(this->radioButton_coordinates1);
			this->groupBox1->Controls->Add(this->radioButton_lenght1);
			this->groupBox1->Location = System::Drawing::Point(1, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(577, 32);
			this->groupBox1->TabIndex = 47;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->groupBox2->Controls->Add(this->radioButton_coordinates2);
			this->groupBox2->Controls->Add(this->radioButton_lenght2);
			this->groupBox2->Location = System::Drawing::Point(1, 258);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(577, 33);
			this->groupBox2->TabIndex = 48;
			this->groupBox2->TabStop = false;
			// 
			// label_result
			// 
			this->label_result->AutoSize = true;
			this->label_result->BackColor = System::Drawing::SystemColors::ControlLight;
			this->label_result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_result->Location = System::Drawing::Point(254, 531);
			this->label_result->Name = L"label_result";
			this->label_result->Size = System::Drawing::Size(96, 25);
			this->label_result->TabIndex = 49;
			this->label_result->Text = L"              ";
			this->label_result->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(140, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(320, 25);
			this->label1->TabIndex = 50;
			this->label1->Text = L"Обчислення площі трикутників";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(580, 573);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label_result);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->textBox_c2_lenght);
			this->Controls->Add(this->textBox_b2_lenght);
			this->Controls->Add(this->textBox_a2_lenght);
			this->Controls->Add(this->label_c2_lenght);
			this->Controls->Add(this->label_b2_lenght);
			this->Controls->Add(this->label_a2_lenght);
			this->Controls->Add(this->textBox_c1_lenght);
			this->Controls->Add(this->textBox_b1_lenght);
			this->Controls->Add(this->textBox_a1_lenght);
			this->Controls->Add(this->label_c1_lenght);
			this->Controls->Add(this->label_b1_lenght);
			this->Controls->Add(this->label_a1_lenght);
			this->Controls->Add(this->label_S2);
			this->Controls->Add(this->label_S1);
			this->Controls->Add(this->textBox_pointC2z);
			this->Controls->Add(this->textBox_pointC2y);
			this->Controls->Add(this->textBox_pointC2x);
			this->Controls->Add(this->label_pointC2);
			this->Controls->Add(this->textBox_pointB2z);
			this->Controls->Add(this->textBox_pointB2y);
			this->Controls->Add(this->textBox_pointB2x);
			this->Controls->Add(this->label_pointB2);
			this->Controls->Add(this->textBox_pointA2z);
			this->Controls->Add(this->textBox_pointA2y);
			this->Controls->Add(this->textBox_pointA2x);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button_calculate_square);
			this->Controls->Add(this->textBox_pointC1z);
			this->Controls->Add(this->textBox_pointC1y);
			this->Controls->Add(this->textBox_pointC1x);
			this->Controls->Add(this->textBox_pointB1z);
			this->Controls->Add(this->textBox_pointB1y);
			this->Controls->Add(this->textBox_pointB1x);
			this->Controls->Add(this->textBox_pointA1z);
			this->Controls->Add(this->textBox_pointA1y);
			this->Controls->Add(this->textBox_pointA1x);
			this->Controls->Add(this->label_pointC);
			this->Controls->Add(this->label_pointB);
			this->Controls->Add(this->label_pointA);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"Калькулятор площі трикутників";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button_calculate_square_Click(System::Object^ sender, System::EventArgs^ e) {
	triangle_square::Triangle triangle1, triangle2;

	try {
		if (radioButton_coordinates1->Checked) {
			triangle1 = createTriangleFromCoordinates(textBox_pointA1x, textBox_pointA1y, textBox_pointA1z,
				textBox_pointB1x, textBox_pointB1y, textBox_pointB1z,
				textBox_pointC1x, textBox_pointC1y, textBox_pointC1z);
		}
		else {
			triangle1 = createTriangleFromSides(textBox_a1_lenght, textBox_b1_lenght, textBox_c1_lenght);
		}

		if (radioButton_coordinates2->Checked) {
			triangle2 = createTriangleFromCoordinates(textBox_pointA2x, textBox_pointA2y, textBox_pointA2z,
				textBox_pointB2x, textBox_pointB2y, textBox_pointB2z,
				textBox_pointC2x, textBox_pointC2y, textBox_pointC2z);
		}
		else {
			triangle2 = createTriangleFromSides(textBox_a2_lenght, textBox_b2_lenght, textBox_c2_lenght);
		}

		double S1 = triangle1.calculate_square();
		double S2 = triangle2.calculate_square();

		label_S1->Text = "S1 = " + Convert::ToString(S1);
		label_S2->Text = "S2 = " + Convert::ToString(S2);

		if (S1 > S2) {
			label_result->Text = "S1 > S2";
		}
		else if (S1 < S2) {
			label_result->Text = "S1 < S2";
		}
		else {
			label_result->Text = "S1 = S2";
		}
	}
	catch (FormatException^) {
		MessageBox::Show("Неправильний формат введених координат або пуста комірка.", "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		label_S1->Text = "0";
		label_S2->Text = "0";
	}
	catch (System::ArgumentException^ e) {
		label_S1->Text = "0";
		label_S2->Text = "0";
		String^ errorMessage = e->Message;
		MessageBox::Show(errorMessage, "Помилка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}


}


};
}
