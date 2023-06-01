#include "MyForm.h"

using namespace System;
using namespace  System::Windows::Forms;

[STAThreadAttribute]// окремий потік даних
int main(array<String^>^ args){
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	lab78::MyForm form;
	Application::Run(% form);
}
