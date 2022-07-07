#include "MyForm.h"

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
	MessageBox^ nmsl2;
	nmsl2->Show(Convert::ToString(mapArray[2, 2]));
	if(e->KeyCode==Keys::F1)
		nmsl2->Show("f1,你妈");

}
