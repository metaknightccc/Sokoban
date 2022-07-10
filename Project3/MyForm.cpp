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
	int x, y,man_pos_x,man_pos_y;
	x = Convert::ToInt32(textBox1->Text);
	y = Convert::ToInt32(textBox2->Text);
	MessageBox^ nmsl2;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (mapArray[i, j]->Equals(4)) {
				man_pos_x = i;
				man_pos_y = j;
			}
			//Console::WriteLine(mapArray[i, j]);

		}
		//Console::WriteLine("----");
	}

	

	//Console::WriteLine("-====-");
	//Console::WriteLine("-====-");


	System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
	Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);
	Image^ img_brick = cli::safe_cast<Image^>(rm->GetObject("brick"));
	Image^ img_box = cli::safe_cast<Image^>(rm->GetObject("box"));
	Image^ img_box_target = cli::safe_cast<Image^>(rm->GetObject("box_target"));
	Image^ img_man = cli::safe_cast<Image^>(rm->GetObject("man"));
	Image^ img_ground = cli::safe_cast<Image^>(rm->GetObject("ground"));
	Image^ img_target = cli::safe_cast<Image^>(rm->GetObject("groundWithDot"));

	Console::WriteLine(man_pos_y);
	Console::WriteLine(man_pos_x);

	


	// mapArray 1:brick 2:box 3:box_target 4:man 5:ground 6:target
	// manposx&j sync with maparray
	if (e->KeyCode == Keys::W && man_pos_x-1 != -1) {
		// man behind a box
		if (mapArray[man_pos_x - 1, man_pos_y]->Equals(2)) {
			// exceed the border and won't meet a brick
			if (man_pos_x - 2 != -1 && !mapArray[man_pos_x - 2, man_pos_y]->Equals(1) && !mapArray[man_pos_x - 2, man_pos_y]->Equals(2))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				dataGridView1[man_pos_y, man_pos_x - 1]->Value = img_man;
				dataGridView1[man_pos_y, man_pos_x - 2]->Value = img_box;
				mapArray[man_pos_x, man_pos_y] = 5;
				mapArray[man_pos_x - 1, man_pos_y] = 4;
				mapArray[man_pos_x - 2, man_pos_y] = 2;
				man_pos_x -= 1;
			}
		}
		// no box
		else {
			if (!mapArray[man_pos_x - 1, man_pos_y]->Equals(1))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				mapArray[man_pos_x, man_pos_y] = 5;
				man_pos_x -= 1;
				dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
				mapArray[man_pos_x, man_pos_y] = 4;
				Console::WriteLine(man_pos_y);
				Console::WriteLine(man_pos_x);
			}
		}
	}
	if (e->KeyCode == Keys::S && man_pos_x + 1 != y) {
		// man behind a box
		if (mapArray[man_pos_x + 1, man_pos_y]->Equals(2)) {
			// exceed the border and won't meet a brick
			if (man_pos_x + 2 != y && !mapArray[man_pos_x + 2, man_pos_y]->Equals(1) && !mapArray[man_pos_x + 2, man_pos_y]->Equals(2))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				dataGridView1[man_pos_y, man_pos_x + 1]->Value = img_man;
				dataGridView1[man_pos_y, man_pos_x + 2]->Value = img_box;
				mapArray[man_pos_x, man_pos_y] = 5;
				mapArray[man_pos_x + 1, man_pos_y] = 4;
				mapArray[man_pos_x + 2, man_pos_y] = 2;
				man_pos_x += 1;
			}
		}
		// no box
		else {
			if (!mapArray[man_pos_x + 1, man_pos_y]->Equals(1))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				mapArray[man_pos_x, man_pos_y] = 5;
				man_pos_x += 1;
				dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
				mapArray[man_pos_x, man_pos_y] = 4;
			}
		}
	}
	if (e->KeyCode == Keys::A && man_pos_y - 1 != -1) {
		// man behind a box
		if (mapArray[man_pos_x, man_pos_y - 1]->Equals(2)) {
			// exceed the border and won't meet a brick
			if (man_pos_y - 2 != -1 && !mapArray[man_pos_x, man_pos_y - 2]->Equals(1) && !mapArray[man_pos_x, man_pos_y - 2]->Equals(2))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				dataGridView1[man_pos_y - 1, man_pos_x]->Value = img_man;
				dataGridView1[man_pos_y - 2, man_pos_x]->Value = img_box;
				mapArray[man_pos_x, man_pos_y] = 5;
				mapArray[man_pos_x, man_pos_y - 1] = 4;
				mapArray[man_pos_x, man_pos_y - 2] = 2;
				man_pos_y -= 1;
			}
		}
		// no box
		else {
			if (!mapArray[man_pos_x, man_pos_y - 1]->Equals(1))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				mapArray[man_pos_x, man_pos_y] = 5;
				man_pos_y -= 1;
				dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
				mapArray[man_pos_x, man_pos_y] = 4;
			}
		}
	}
	if (e->KeyCode == Keys::D && man_pos_y + 1 != x) {
		// man behind a box
		if (mapArray[man_pos_x, man_pos_y + 1]->Equals(2)) {
			// exceed the border and won't meet a brick
			if (man_pos_y + 2 != x && !mapArray[man_pos_x, man_pos_y + 2]->Equals(1) && !mapArray[man_pos_x, man_pos_y + 2]->Equals(2))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				dataGridView1[man_pos_y + 1, man_pos_x]->Value = img_man;
				dataGridView1[man_pos_y + 2, man_pos_x]->Value = img_box;
				mapArray[man_pos_x, man_pos_y] = 5;
				mapArray[man_pos_x, man_pos_y + 1] = 4;
				mapArray[man_pos_x, man_pos_y + 2] = 2;
				man_pos_y += 1;
			}
		}
		// no box
		else {
			if (!mapArray[man_pos_x, man_pos_y + 1]->Equals(1))
			{
				dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
				mapArray[man_pos_x, man_pos_y] = 5;
				man_pos_y += 1;
				dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
				mapArray[man_pos_x, man_pos_y] = 4;
			}
		}
	}

	for (int i = 0; i < target_index; i++) {
		int tempx = cli::safe_cast<int>(targetArray[i, 0]);
		int tempy = cli::safe_cast<int>(targetArray[i, 1]);
		if (!(mapArray[tempx, tempy]->Equals(3) || mapArray[tempx, tempy]->Equals(2) || mapArray[tempx, tempy]->Equals(4)))
		{
			dataGridView1[tempy, tempx]->Value = img_target;
		}
		if (mapArray[tempx, tempy]->Equals(2)) {
			dataGridView1[tempy, tempx]->Value = img_box_target;
		}
	}

}



