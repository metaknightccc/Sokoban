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

//���������ȡ��������
void Project3::MyForm::OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
{
	//int x, y,man_pos_x,man_pos_y;
	//x = Convert::ToInt32(textBox1->Text);
	//y = Convert::ToInt32(textBox2->Text);
	//MessageBox^ nmsl2;
	//for (int i = 0; i < y; i++) {
	//	for (int j = 0; j < x; j++) {
	//		if (mapArray[i, j]->Equals(4)) {
	//			man_pos_x = i;
	//			man_pos_y = j;
	//		}
	//		//Console::WriteLine(mapArray[i, j]);

	//	}
	//	//Console::WriteLine("----");
	//}

	//

	////Console::WriteLine("-====-");
	////Console::WriteLine("-====-");


	//System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
	//Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);
	//Image^ img_brick = cli::safe_cast<Image^>(rm->GetObject("brick"));
	//Image^ img_box = cli::safe_cast<Image^>(rm->GetObject("box"));
	//Image^ img_box_target = cli::safe_cast<Image^>(rm->GetObject("box_target"));
	//Image^ img_man = cli::safe_cast<Image^>(rm->GetObject("man"));
	//Image^ img_ground = cli::safe_cast<Image^>(rm->GetObject("ground"));
	//Image^ img_target = cli::safe_cast<Image^>(rm->GetObject("groundWithDot"));

	//Console::WriteLine(man_pos_y);
	//Console::WriteLine(man_pos_x);

	//


	//// mapArray 1:brick 2:box 3:box_target 4:man 5:ground 6:target
	//// manposx&j sync with maparray
	//if (e->KeyCode == Keys::W && man_pos_x-1 != -1) {
	//	// man behind a box
	//	if (mapArray[man_pos_x - 1, man_pos_y]->Equals(2)) {
	//		// exceed the border and won't meet a brick
	//		if (man_pos_x - 2 != -1 && !mapArray[man_pos_x - 2, man_pos_y]->Equals(1) && !mapArray[man_pos_x - 2, man_pos_y]->Equals(2))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			dataGridView1[man_pos_y, man_pos_x - 1]->Value = img_man;
	//			dataGridView1[man_pos_y, man_pos_x - 2]->Value = img_box;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			mapArray[man_pos_x - 1, man_pos_y] = 4;
	//			mapArray[man_pos_x - 2, man_pos_y] = 2;
	//			man_pos_x -= 1;
	//		}
	//	}
	//	// no box
	//	else {
	//		if (!mapArray[man_pos_x - 1, man_pos_y]->Equals(1))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			man_pos_x -= 1;
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
	//			mapArray[man_pos_x, man_pos_y] = 4;
	//			Console::WriteLine(man_pos_y);
	//			Console::WriteLine(man_pos_x);
	//		}
	//	}
	//}
	//if (e->KeyCode == Keys::S && man_pos_x + 1 != y) {
	//	// man behind a box
	//	if (mapArray[man_pos_x + 1, man_pos_y]->Equals(2)) {
	//		// exceed the border and won't meet a brick
	//		if (man_pos_x + 2 != y && !mapArray[man_pos_x + 2, man_pos_y]->Equals(1) && !mapArray[man_pos_x + 2, man_pos_y]->Equals(2))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			dataGridView1[man_pos_y, man_pos_x + 1]->Value = img_man;
	//			dataGridView1[man_pos_y, man_pos_x + 2]->Value = img_box;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			mapArray[man_pos_x + 1, man_pos_y] = 4;
	//			mapArray[man_pos_x + 2, man_pos_y] = 2;
	//			man_pos_x += 1;
	//		}
	//	}
	//	// no box
	//	else {
	//		if (!mapArray[man_pos_x + 1, man_pos_y]->Equals(1))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			man_pos_x += 1;
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
	//			mapArray[man_pos_x, man_pos_y] = 4;
	//		}
	//	}
	//}
	//if (e->KeyCode == Keys::A && man_pos_y - 1 != -1) {
	//	// man behind a box
	//	if (mapArray[man_pos_x, man_pos_y - 1]->Equals(2)) {
	//		// exceed the border and won't meet a brick
	//		if (man_pos_y - 2 != -1 && !mapArray[man_pos_x, man_pos_y - 2]->Equals(1) && !mapArray[man_pos_x, man_pos_y - 2]->Equals(2))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			dataGridView1[man_pos_y - 1, man_pos_x]->Value = img_man;
	//			dataGridView1[man_pos_y - 2, man_pos_x]->Value = img_box
// ;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			mapArray[man_pos_x, man_pos_y - 1] = 4;
	//			mapArray[man_pos_x, man_pos_y - 2] = 2;
	//			man_pos_y -= 1;
	//		}
	//	}
	//	// no box
	//	else {
	//		if (!mapArray[man_pos_x, man_pos_y - 1]->Equals(1))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			man_pos_y -= 1;
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
	//			mapArray[man_pos_x, man_pos_y] = 4;
	//		}
	//	}
	//}
	//if (e->KeyCode == Keys::D && man_pos_y + 1 != x) {
	//	// man behind a box
	//	if (mapArray[man_pos_x, man_pos_y + 1]->Equals(2)) {
	//		// exceed the border and won't meet a brick
	//		if (man_pos_y + 2 != x && !mapArray[man_pos_x, man_pos_y + 2]->Equals(1) && !mapArray[man_pos_x, man_pos_y + 2]->Equals(2))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			dataGridView1[man_pos_y + 1, man_pos_x]->Value = img_man;
	//			dataGridView1[man_pos_y + 2, man_pos_x]->Value = img_box;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			mapArray[man_pos_x, man_pos_y + 1] = 4;
	//			mapArray[man_pos_x, man_pos_y + 2] = 2;
	//			man_pos_y += 1;
	//		}
	//	}
	//	// no box
	//	else {
	//		if (!mapArray[man_pos_x, man_pos_y + 1]->Equals(1))
	//		{
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_ground;
	//			mapArray[man_pos_x, man_pos_y] = 5;
	//			man_pos_y += 1;
	//			dataGridView1[man_pos_y, man_pos_x]->Value = img_man;
	//			mapArray[man_pos_x, man_pos_y] = 4;
	//		}
	//	}
	//}

	//for (int i = 0; i < target_index; i++) {
	//	int tempx = cli::safe_cast<int>(targetArray[i, 0]);
	//	int tempy = cli::safe_cast<int>(targetArray[i, 1]);
	//	if (!(mapArray[tempx, tempy]->Equals(3) || mapArray[tempx, tempy]->Equals(2) || mapArray[tempx, tempy]->Equals(4)))
	//	{
	//		dataGridView1[tempy, tempx]->Value = img_target;
	//	}
	//	if (mapArray[tempx, tempy]->Equals(2)) {
	//		dataGridView1[tempy, tempx]->Value = img_box_target;
	//	}
	//}


	int x = Convert::ToInt32(textBox1->Text);
	int y = Convert::ToInt32(textBox2->Text);
	int dx[5] = { 0, -1, 0, 1, 0 };
	int dy[5] = { 0, 0, 1, 0, -1 };

	System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
	Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);
	Image^ img_brick = cli::safe_cast<Image^>(rm->GetObject("brick"));
	Image^ img_box = cli::safe_cast<Image^>(rm->GetObject("box"));
	Image^ img_box_target = cli::safe_cast<Image^>(rm->GetObject("box_target"));
	Image^ img_man = cli::safe_cast<Image^>(rm->GetObject("man"));
	Image^ img_ground = cli::safe_cast<Image^>(rm->GetObject("ground"));
	Image^ img_target = cli::safe_cast<Image^>(rm->GetObject("groundWithDot"));

	// dx dy [1]:up [2]:right [3]:down [4]:left
	int manX = 0;
	int manY = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (mapArray[i, j]->Equals(4) || mapArray[i, j]->Equals(7))
			{
				manX = i;
				manY = j;
				Console::Write("I AND J:{0},{1} \n", i, j);
				Console::Write("COOD BEFORE:{0},{1} \n", manX, manY);
			}
		}
	}	

	for (int j = 0; j < x; j++)
	{
		for (int k = 0; k < y; k++)
		{
			Console::Write("{0} ", mapArray[j, k]);
		}
		Console::WriteLine();
	}


	int direction_temp=0;
	bool move_or_not = true;

	if (e->KeyCode == Keys::A)direction_temp = 4;
	if (e->KeyCode == Keys::D)direction_temp = 2;
	if (e->KeyCode == Keys::S)direction_temp = 3;
	if (e->KeyCode == Keys::W)direction_temp = 1;


	if (e->KeyCode == Keys::W) {
		direction_temp = 1;

		//Console::WriteLine("-=-===");
		/*
		* exceed border
		*
		* man brick
		*
		* (if pos at x-2 will not exceed the border)
		* man box brick
		* man target_box brick
		* man box box
		* man box_target box
		* man box_target box_target
		* man box box_target
		*/
		if (manX - 1 == -1) {
			move_or_not = false;
			Console::WriteLine("1==");
		}
		else {
			if (mapArray[manX - 1, manY]->Equals(1)) {
				move_or_not = false;
				Console::WriteLine("2==");
			}
			else {
				if (manX - 2 != -1) {
					if ((mapArray[manX - 1, manY]->Equals(2) && mapArray[manX - 2, manY]->Equals(1)) ||
						(mapArray[manX - 1, manY]->Equals(3) && mapArray[manX - 2, manY]->Equals(1)) ||
						(mapArray[manX - 1, manY]->Equals(2) && mapArray[manX - 2, manY]->Equals(2)) ||
						(mapArray[manX - 1, manY]->Equals(3) && mapArray[manX - 2, manY]->Equals(2)) ||
						(mapArray[manX - 1, manY]->Equals(3) && mapArray[manX - 2, manY]->Equals(3)) ||
						(mapArray[manX - 1, manY]->Equals(2) && mapArray[manX - 2, manY]->Equals(3))) {
						move_or_not = false;
						Console::WriteLine("3==");
					}
				}
				else {
					if (mapArray[manX - 1, manY]->Equals(2) || mapArray[manX - 1, manY]->Equals(2)) {
						move_or_not = false;
						Console::WriteLine("3==");
					}
				}
			}
		}

	}
	if (e->KeyCode == Keys::S) {
		direction_temp = 3;
		if (manX + 1 == x)
			move_or_not = false;
		else {
			if (mapArray[manX + 1, manY]->Equals(1))
				move_or_not = false;
			else {
				if (manX + 2 != x) {
					if ((mapArray[manX + 1, manY]->Equals(2) && mapArray[manX + 2, manY]->Equals(1)) ||
						(mapArray[manX + 1, manY]->Equals(3) && mapArray[manX + 2, manY]->Equals(1)) ||
						(mapArray[manX + 1, manY]->Equals(2) && mapArray[manX + 2, manY]->Equals(2)) ||
						(mapArray[manX + 1, manY]->Equals(3) && mapArray[manX + 2, manY]->Equals(2)) ||
						(mapArray[manX + 1, manY]->Equals(3) && mapArray[manX + 2, manY]->Equals(3)) ||
						(mapArray[manX + 1, manY]->Equals(2) && mapArray[manX + 2, manY]->Equals(3)))
						move_or_not = false;
				}
				else {
					if (mapArray[manX + 1, manY]->Equals(2) || mapArray[manX + 1, manY]->Equals(2)) {
						move_or_not = false;
					}
				}
			}
		}
	}
	if (e->KeyCode == Keys::A) {
		direction_temp = 4;
		if (manY - 1 == -1)
			move_or_not = false;
		else {
			if (mapArray[manX, manY - 1]->Equals(1))
				move_or_not = false;
			else {
				if (manY - 2 != -1) {
					if ((mapArray[manX, manY - 1]->Equals(2) && mapArray[manX, manY - 2]->Equals(1)) ||
						(mapArray[manX, manY - 1]->Equals(3) && mapArray[manX, manY - 2]->Equals(1)) ||
						(mapArray[manX, manY - 1]->Equals(2) && mapArray[manX, manY - 2]->Equals(2)) ||
						(mapArray[manX, manY - 1]->Equals(3) && mapArray[manX, manY - 2]->Equals(2)) ||
						(mapArray[manX, manY - 1]->Equals(3) && mapArray[manX, manY - 2]->Equals(3)) ||
						(mapArray[manX, manY - 1]->Equals(2) && mapArray[manX, manY - 2]->Equals(3)))
						move_or_not = false;
				}
				else {
					if (mapArray[manX, manY - 1]->Equals(2) || mapArray[manX, manY-1]->Equals(2)) {
						move_or_not = false;
					}
				}
			}
		}
	}
	if (e->KeyCode == Keys::D) {
		direction_temp = 2;
		if (manY + 1 == y)
			move_or_not = false;
		else {
			if (mapArray[manX, manY + 1]->Equals(1))
				move_or_not = false;
			else {
				if (manY + 2 != y) {
					if ((mapArray[manX, manY + 1]->Equals(2) && mapArray[manX, manY + 2]->Equals(1)) ||
						(mapArray[manX, manY + 1]->Equals(3) && mapArray[manX, manY + 2]->Equals(1)) ||
						(mapArray[manX, manY + 1]->Equals(2) && mapArray[manX, manY + 2]->Equals(2)) ||
						(mapArray[manX, manY + 1]->Equals(3) && mapArray[manX, manY + 2]->Equals(2)) ||
						(mapArray[manX, manY + 1]->Equals(3) && mapArray[manX, manY + 2]->Equals(3)) ||
						(mapArray[manX, manY + 1]->Equals(2) && mapArray[manX, manY + 2]->Equals(3)))
						move_or_not = false;
				}
				else {
					if (mapArray[manX, manY + 1]->Equals(2) || mapArray[manX, manY + 1]->Equals(2)) {
						move_or_not = false;
					}
				}
			}
		}
	}


	/*for (int j = 0; j < x; j++)
	{
		for (int k = 0; k < y; k++)
		{
			Console::Write("{0} ", mapArray[j, k]);
		}
		Console::WriteLine();
	}*/

	if (move_or_not==true) {
		// 1
		if (mapArray[manX, manY]->Equals(4))
		{
			// 1.1
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(2))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 4;
				if (mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]]->Equals(5)) //��λ�ñ�����
				{
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 2;
				}
				else
				{ //������+target
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 3;
				}
				// dataGridView1
			}
			// 1.2
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(3))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 7;
				if (mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]]->Equals(5)) //��λ�ñ�����
				{
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 2;
				}
				else
				{ //������+target
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 3;
				}
			}
			// 1.3
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(5))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 4;
			}
			// 1.4
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(6))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 7;
			}
		}
		// 2
		else if (mapArray[manX, manY]->Equals(7))
		{
			// 2.1
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(2))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 4;
				if (mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]]->Equals(5)) //��λ�ñ�����
				{
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 2;
				}
				else
				{ //������+target
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 3;
				}
				// dataGridView1
			}
			// 2.2
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(3))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 7;
				if (mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]]->Equals(5)) //��λ�ñ�����
				{
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 2;
				}
				else
				{ //������+target
					mapArray[manX + 2 * dx[direction_temp], manY + 2 * dy[direction_temp]] = 3;
				}
			}
			// 2.3
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(5))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 4;
			}
			// 2.4
			if (mapArray[manX + dx[direction_temp], manY + dy[direction_temp]]->Equals(6))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[direction_temp], manY + dy[direction_temp]] = 7;
			}
		}


		/*for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				Console::Write("{0} ", mapArray[j, k]);
			}
			Console::WriteLine();
		}
		Console::Write("DIRECTION:{0} ", direction_temp);
		Console::Write("COOD:{0},{1} ", manX+dx[direction_temp],manY+dy[direction_temp]);
		Console::WriteLine("==========");*/


		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				if (mapArray[j, k]->Equals(1))
				{
					dataGridView1[k, j]->Value = img_brick;
				}
				else if (mapArray[j, k]->Equals(2))
				{
					dataGridView1[k, j]->Value = img_box;
				}
				else if (mapArray[j, k]->Equals(3))
				{
					dataGridView1[k, j]->Value = img_box_target;
				}
				else if (mapArray[j, k]->Equals(4))
				{
					dataGridView1[k, j]->Value = img_man;
				}
				else if (mapArray[j, k]->Equals(5))
				{
					dataGridView1[k, j]->Value = img_ground;
				}
				else if (mapArray[j, k]->Equals(6))
				{
					dataGridView1[k, j]->Value = img_target;
				}
				else if (mapArray[j, k]->Equals(7))
				{
					dataGridView1[k, j]->Value = img_man;
				}
				dataGridView1->Update();
			}
		}

		// MessageBox::Show("�����������ʾ");
	}
}



