#include "StartScreen.h"

//#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	DogfightCourseProject::StartScreen form;
	Application::Run(% form);
}