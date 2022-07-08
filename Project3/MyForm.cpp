#include "MyForm.h"
#include <utility>
#include <math.h>
using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project3::MyForm form;
	Application::Run(% form);
	
}

//在主界面获取键盘输入
void Project3::MyForm::OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	mapArray[2, 2] = 10;
	MessageBox^ nmsl2;
	nmsl2->Show(Convert::ToString(mapArray[2, 2]));
	if(e->KeyCode==Keys::A)
		nmsl2->Show("A你妈");
}



