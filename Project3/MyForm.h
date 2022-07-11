#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm ժҪ
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO:  �ڴ˴���ӹ��캯������
				//
			}

		protected:
			/// <summary>
			/// ������������ʹ�õ���Դ��
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::TextBox^ textBox2;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::DataGridView^ dataGridView1;
		private: System::Windows::Forms::GroupBox^ groupBox1;
		private: System::Windows::Forms::RadioButton^ radioButton2;
		private: System::Windows::Forms::RadioButton^ radioButton1;
		private: System::Windows::Forms::RadioButton^ radioButton4;
		private: System::Windows::Forms::RadioButton^ radioButton3;
		private: System::Windows::Forms::RadioButton^ radioButton5;
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label3;
		//������һ����ά���飬100�У�105��
		public:array<int^, 2>^ mapArray = gcnew array<int^, 2>(100, 105);
	private: System::Windows::Forms::Button^ �Լ���;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::RadioButton^ radioButton6;
		   //��¼�±������еĽ��
		   ArrayList^ AnsArray;

		   System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
		   Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);





		   Image^ img_brick = cli::safe_cast<Image^>(rm->GetObject("brick"));
		   Image^ img_box = cli::safe_cast<Image^>(rm->GetObject("box"));
		   Image^ img_box_target = cli::safe_cast<Image^>(rm->GetObject("box_target"));
		   Image^ img_man = cli::safe_cast<Image^>(rm->GetObject("man"));
		   Image^ img_ground = cli::safe_cast<Image^>(rm->GetObject("ground"));
		   Image^ img_target = cli::safe_cast<Image^>(rm->GetObject("groundWithDot"));

		   //��¼���˵�������
		   int manRow = 0;
		   int manCol = 0;
		   bool hasMan = false;//��¼�Ƿ��Ѿ�����������
		   //��¼�м�����������
		   int boxes = 0;
		   //����ֱ�Ӽ�¼�������꣬���ʮ���㣬��ʵʵ�ʲ�Ӧ�ó���5���������㷨�ⲻ��
		   array<int^, 2>^ boxesArray = gcnew array<int^, 2>(10, 2);
		   //��¼�м��������
		   int targetPos = 0;
	private: System::Windows::Forms::Button^ ���԰�ť;
	private: System::Windows::Forms::Button^ ģ��;
		   //����ֱ�Ӽ�¼�������꣬���ʮ���㣬��ʵʵ�ʲ�Ӧ�ó���5���������㷨�ⲻ��

	private:
			/// <summary>
			/// ����������������
			/// </summary>
			System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
			/// <summary>
			/// �����֧������ķ��� - ��Ҫ�޸�
			/// ʹ�ô���༭���޸Ĵ˷��������ݡ�
			/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton6 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->�Լ��� = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->���԰�ť = (gcnew System::Windows::Forms::Button());
			this->ģ�� = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(67, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(64, 21);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"6";
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 21);
			this->textBox2->TabIndex = 1;
			this->textBox2->Text = L"6";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(236, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Generate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(463, 25);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Calculate";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(28, 67);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 64;
			this->dataGridView1->Size = System::Drawing::Size(859, 472);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton6);
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(903, 166);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(155, 173);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Brick List";
			// 
			// radioButton6
			// 
			this->radioButton6->AutoSize = true;
			this->radioButton6->Location = System::Drawing::Point(7, 135);
			this->radioButton6->Name = L"radioButton6";
			this->radioButton6->Size = System::Drawing::Size(59, 16);
			this->radioButton6->TabIndex = 5;
			this->radioButton6->TabStop = true;
			this->radioButton6->Text = L"Target";
			this->radioButton6->UseVisualStyleBackColor = true;
			// 
			// radioButton5
			// 
			this->radioButton5->AutoSize = true;
			this->radioButton5->Location = System::Drawing::Point(7, 113);
			this->radioButton5->Name = L"radioButton5";
			this->radioButton5->Size = System::Drawing::Size(59, 16);
			this->radioButton5->TabIndex = 4;
			this->radioButton5->TabStop = true;
			this->radioButton5->Text = L"Ground";
			this->radioButton5->UseVisualStyleBackColor = true;
			// 
			// radioButton4
			// 
			this->radioButton4->AutoSize = true;
			this->radioButton4->Location = System::Drawing::Point(7, 90);
			this->radioButton4->Name = L"radioButton4";
			this->radioButton4->Size = System::Drawing::Size(41, 16);
			this->radioButton4->TabIndex = 3;
			this->radioButton4->TabStop = true;
			this->radioButton4->Text = L"Man";
			this->radioButton4->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(7, 67);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(83, 16);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->TabStop = true;
			this->radioButton3->Text = L"Box Target";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(7, 44);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(41, 16);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Box";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(6, 20);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(53, 16);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Brick";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 12);
			this->label1->TabIndex = 16;
			this->label1->Text = L"Size:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(137, 30);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(17, 12);
			this->label3->TabIndex = 17;
			this->label3->Text = L"��";
			// 
			// �Լ���
			// 
			this->�Լ���->Location = System::Drawing::Point(740, 25);
			this->�Լ���->Name = L"�Լ���";
			this->�Լ���->Size = System::Drawing::Size(103, 23);
			this->�Լ���->TabIndex = 18;
			this->�Լ���->Text = L"��ʼ�Լ��棡";
			this->�Լ���->UseVisualStyleBackColor = true;
			this->�Լ���->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// ���԰�ť
			// 
			this->���԰�ť->Location = System::Drawing::Point(351, 25);
			this->���԰�ť->Name = L"���԰�ť";
			this->���԰�ť->Size = System::Drawing::Size(75, 23);
			this->���԰�ť->TabIndex = 19;
			this->���԰�ť->Text = L"���԰�ť";
			this->���԰�ť->UseVisualStyleBackColor = true;
			this->���԰�ť->Click += gcnew System::EventHandler(this, &MyForm::���԰�ť_Click);
			// 
			// ģ��
			// 
			this->ģ��->Location = System::Drawing::Point(586, 25);
			this->ģ��->Name = L"ģ��";
			this->ģ��->Size = System::Drawing::Size(75, 23);
			this->ģ��->TabIndex = 20;
			this->ģ��->Text = L"ģ��";
			this->ģ��->UseVisualStyleBackColor = true;
			this->ģ��->Click += gcnew System::EventHandler(this, &MyForm::ģ��_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1097, 603);
			this->Controls->Add(this->ģ��);
			this->Controls->Add(this->���԰�ť);
			this->Controls->Add(this->�Լ���);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::OnKeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion
		private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			}
		private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
			}
		private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {


			// set a image for the cell[index_x,index_y]
			int index_y = dataGridView1->CurrentCell->ColumnIndex;
			int index_x = dataGridView1->CurrentCell->RowIndex;


			// mapArray 1:brick 2:box 3:box_target 4:man 5:ground 6:target
			if (radioButton1->Checked)
			{
				dataGridView1[index_y, index_x]->Value = img_brick;
				mapArray[index_x, index_y] = 1;
			}
				
			if (radioButton2->Checked)
			{
				dataGridView1[index_y, index_x]->Value = img_box;
				mapArray[index_x, index_y] = 2;
			}
				
			if (radioButton3->Checked)
			{
				dataGridView1[index_y, index_x]->Value = img_box_target;
				mapArray[index_x, index_y] = 3;
			}
				
			if (radioButton4->Checked)
			{
				if (this->hasMan == false)//��ǰ��û��������
				{
					this->hasMan = true;

				}
				else {//��ǰ�Ѿ�����������
					mapArray[this->manRow, this->manCol] = 5;//��֮ǰ�������˵ĵط��ĳɵ��淽��
					dataGridView1[this->manCol, this->manRow]->Value = img_ground;
				}
				dataGridView1[index_y, index_x]->Value = img_man;
				mapArray[index_x, index_y] = 4;
				this->manRow = index_x;
				this->manCol = index_y;

			}
				
			if (radioButton5->Checked)
			{
				dataGridView1[index_y, index_x]->Value = img_ground;
				mapArray[index_x, index_y] = 5;
			}
				
			if (radioButton6->Checked)
			{
				dataGridView1[index_y, index_x]->Value = img_target;
				mapArray[index_x, index_y] = 6;
			}
			


		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			
			// clear rhe gridview (reset)
			dataGridView1->Columns->Clear();
			
			// read from textbox
			int x, y;
	
			x = Convert::ToInt32(textBox1->Text);

			y = Convert::ToInt32(textBox2->Text);

			// build x*y gridview cells

			for (int i = 0; i < y; i++) {
				DataGridViewColumn^ newCol = (gcnew System::Windows::Forms::DataGridViewImageColumn);
				newCol->Width = 64;
				dataGridView1->Columns->Add(newCol);
			}


			for (int i = 0; i < x-1; i++) {
				dataGridView1->Rows->Add();
			}


			// set default images for the cell
			System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly(); 

			Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);

			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					dataGridView1[j, i]->Value = cli::safe_cast<Image^>(rm->GetObject("ground"));
					mapArray[i, j] = 5;
				}
			}

		}

			   
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Form^ tmpForm = gcnew Form;
			tmpForm->StartPosition = FormStartPosition::CenterScreen;
			tmpForm->Show();
			tmpForm->Text = "���������";
			
			//tmpForm->Controls->Add(tmpButton);
			tmpForm->ControlBox = false;
			Label^ tmpLabel = gcnew Label;
			tmpLabel->Size= System::Drawing::Size(300, 200);
			tmpLabel->Font = gcnew System::Drawing::Font("����", 20);
			tmpLabel->Location = System::Drawing::Point(60, 125);
			tmpLabel->Text = "��������У�";

			tmpForm->Controls->Add(tmpLabel);
			//tmpLabel->ma
			int x, y;
			x = Convert::ToInt32(textBox1->Text); // row
			y = Convert::ToInt32(textBox2->Text); // col
			int max_length = x;

			// box_robot -:0 ' ':5
			 //wall storage -:0 ' ':5
			
			array<int^, 2>^ box_robot = gcnew array<int^, 2>(x, y);
			array<int^, 2>^ wall_storage_space = gcnew array<int^, 2>(x, y);
			//ע��xyΪ0��ʱ����ܻ���������Ե�������ʾ
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					box_robot[i,j] = 0;
					wall_storage_space[i,j] = 0;
				}
			}
			//���Ȳ������в�0û��

			// mapArray 1:brick 2:box 3:box_target 4:man 5:ground 6:target
			//1 O 2 B 3 * 4 R 5 ��վ�ڵ��� 6 S
			//ע�����к���
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					//MessageBox::Show("��1-6"+"�����ҵ�����"+Convert::ToString(mapArray[i, j]));
					if (mapArray[i, j]->Equals(2) || mapArray[i, j]->Equals(4)) {
						//box_robot��סR�˺�B����
						box_robot[i, j] = mapArray[i, j];
						//ӡ�ȸ��õ��ǿո񣬲�֪��
						wall_storage_space[i, j] =5;
					}
					else if (mapArray[i, j]->Equals(6)  || mapArray[i, j]->Equals(1)) {
						box_robot[i, j] = 5;
						//MessageBox::Show("�ҵ�һ��1��6");
						//wall_storage_space��S��target�洢λ�ú�O���谭λ��
						wall_storage_space[i, j] = mapArray[i,j];
					}
					
					else if (mapArray[i, j] ->Equals(5)) {
						box_robot[i, j] = 5;
						wall_storage_space[i, j] = 5;
					}

				}
			}

			System::Collections::ArrayList^ storage_row1 = gcnew ArrayList;
			System::Collections::ArrayList^ storage_col1 = gcnew ArrayList;
			System::Collections::ArrayList^ target_pos_row1 = gcnew ArrayList;
			System::Collections::ArrayList^ target_pos_col1 = gcnew ArrayList;
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					//Console::WriteLine(wall_storage_space[i, j]);
					if (wall_storage_space[i, j] ->Equals(6)) {//target
						storage_row1->Add(i);
						storage_col1->Add(j);
						target_pos_row1->Add(i);
						target_pos_col1->Add(j);

						MessageBox::Show("�ҵ���һ��target");
					}
				}
			}
			//for (int i = 0; i < (int)storage_row1->Count; i++)
			//{
			//	Console::Write("{0},{1}", storage_row1[i], storage_col1[i]);
			//}
			MessageBox::Show("Ŀ�����"+Convert::ToString(target_pos_row1->Count)+"��");
			MessageBox::Show("{0}"+Convert::ToString(target_pos_row1->Count));
			//MessageBox::Show(Convert::ToString(manhatten_dis()));


			int boxRobtDistance = 9999999;
			System::Collections::ArrayList^ boxesX1 = gcnew ArrayList;
			System::Collections::ArrayList^ boxesY1 = gcnew ArrayList;
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					if (box_robot[i, j]->Equals(2))
					{
						boxesX1->Add(i);
						boxesY1->Add(j);
					}
				}
			}

			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					if (box_robot[i, j]->Equals(4))//������ˣ�������target�������پ���
					{
						for (int k = 0; k < (int)boxesX1->Count; k++)
						{
							//int tmp = Convert::ToInt32(target_pos_row[k]) - i;
							//if(boxRobtDistance>(abs()+))
							//Console::WriteLine(target_pos_row[k]);
							//Console::WriteLine(target_pos_col[k]);
							
							int tmpAbs = Math::Abs((int)boxesX1[k] - i) + Math::Abs((int)boxesY1[k] - j);
							Console::WriteLine("{0}", tmpAbs);
							if (boxRobtDistance > tmpAbs)
							{
								boxRobtDistance += tmpAbs;
							}
						}
					}
				}
			}
			MessageBox::Show(Convert::ToString(boxRobtDistance));//����֤�Ǽ�����ȷ�ģ�����֪����ʲô��
			//�����ǵ�defManhattan֮ǰ���������ݣ��Ѿ�д����ע�ͣ�ע��x��y�Ĺ�ϵ������datagridview�����к����⣬�����Ķ������к��У��Ѿ��ĺ���
			//mahattan����дһ������

			Console::WriteLine("���ڽ�");
			
			//�������������У��ǳ���Ҫ 
			//movesList
			System::Collections::ArrayList^ movesList = gcnew ArrayList;
			//movesList->Add(0);
			//visitedMoves

			//1 boxRobot��list
			System::Collections::ArrayList^ boxRobotList = gcnew ArrayList;
			//2 movesList��list
			System::Collections::ArrayList^ movesListList = gcnew ArrayList;
			//3 boxRobtDistance��list
			System::Collections::ArrayList^ boxRobtDistanceList = gcnew ArrayList;			
			//4
			System::Collections::ArrayList^ visitedMovesList = gcnew ArrayList;
			if(!isInVisitedMoves(visitedMovesList,box_robot))
			//if (!visitedMovesList->Contains(box_robot))
			{
				visitedMovesList->Add(box_robot);
			}/*
			Console::WriteLine("������һ��contains�ж�");
			Console::WriteLine(visitedMovesList->Contains(box_robot));*/
			boxRobtDistanceList->Add(boxRobtDistance);
			boxRobotList->Add(box_robot);

			movesListList->Add(movesList);

			int robot_x = -1, robot_y = -1, completed = 0;
			int cnt = 0;
			while ((int)boxRobotList->Count!=0&&completed==0)
			{
				cnt++;
				int tmpboxRobtDistance = (int)boxRobtDistanceList[0];
				boxRobtDistanceList->RemoveAt(0);
				//curPosition
				array<int^, 2>^ tmpBoxRobotList = (array<int^, 2>^)boxRobotList[0];
				boxRobotList->RemoveAt(0);
				//moivesTillNow
				//Console::WriteLine("{0}   movesListList[0]", movesListList[0]);
				System::Collections::ArrayList^ tmpMovesList = (ArrayList^)movesListList[0];
				movesListList->RemoveAt(0);
				

				int stepsTillNow = (int)tmpMovesList->Count;
				for (int i = 0; i < x; i++)
				{
					int tmpj = 0;
					for (tmpj = 0; tmpj < y; tmpj++)
					{
						if (tmpBoxRobotList[i, tmpj]->Equals(4))
						{
							robot_x = i;
							robot_y = tmpj;
							break;
						}
					}
					if (tmpj == y)
					{
						continue;
					}
				}
				//int dx[5] = { 0,-1,0,-1,1 };//���������ĸ�����
				//int dy[5] = { 0,-1,1,0,0 };
				int dx[5] = { 0,-1,0,1,0 };//���������ĸ�����
				int dy[5] = { 0,0,1,0,-1 };
				for (int i = 1; i <= 4; i++)
				{
					int robotNew_x = robot_x + dx[i];
					int robotNew_y = robot_y + dy[i];
					if (robotNew_x < 0 || robotNew_y < 0|| robotNew_x>=x|| robotNew_y>=y)//��ֹԽ��
						continue;
					array<int^, 2>^ copy_tmp_box_robot = gcnew array<int^, 2>(x, y);
					Array::Copy(tmpBoxRobotList, copy_tmp_box_robot, tmpBoxRobotList->Length);//���������������
					System::Collections::ArrayList^ copyTmpMovesList=gcnew ArrayList;
					for (int j = 0; j < (int)tmpMovesList->Count; j++)//ǿ�����
					{
						copyTmpMovesList->Add(tmpMovesList[j]);
					}

					if (copy_tmp_box_robot[robotNew_x, robotNew_y]->Equals(2))
					{
						int boxNew_x = robotNew_x + dx[i];
						int boxNew_y = robotNew_y + dy[i];
						if (copy_tmp_box_robot[boxNew_x, boxNew_y]->Equals(2) || wall_storage_space[boxNew_x, boxNew_y]->Equals(1))//�����λ�������ӻ������ϰ���˵�������ƣ�continue
						{
							continue;
						}
						else {
							copy_tmp_box_robot[boxNew_x, boxNew_y] = 2;//box
							copy_tmp_box_robot[robotNew_x, robotNew_y] = 4;//��
							copy_tmp_box_robot[robot_x, robot_y] = 5;//��ɵ���
							if (!isInVisitedMoves(visitedMovesList, copy_tmp_box_robot))
							//if (!visitedMovesList->Contains(copy_tmp_box_robot))
							{
								int matches = 0;
								for (int k = 0; k < x; k++)
								{
									for (int l = 0; l < y; l++)
									{
										if (wall_storage_space[k, l]->Equals(6))
										{
											if (!copy_tmp_box_robot[k, l]->Equals(2))
											{
												matches = 1;
											}
										}
									}
								}
								copyTmpMovesList->Add(i);//�����������
								if (matches == 0)
								{
									completed = 1;
									Console::WriteLine("�ɹ��ˣ�����ڵ�ǰ��copyTmpMovesList��");
									AnsArray = gcnew ArrayList;
									for (int tmpi = 0; tmpi < (int)copyTmpMovesList->Count; tmpi++)
									{
										Console::WriteLine("{0}", copyTmpMovesList[tmpi]);
										AnsArray->Add(copyTmpMovesList[tmpi]);
									}
								}
								else {
									int boxRobtDistance2 = 999999;
									System::Collections::ArrayList^ boxesX2 = gcnew ArrayList;
									System::Collections::ArrayList^ boxesY2 = gcnew ArrayList;
									int storagesLeft2 = (int)storage_row1->Count;//190�У���Щ����
									for (int k = 0; k < x; k++)
									{
										for (int l = 0; l < y; l++)
										{
											if (copy_tmp_box_robot[k, l]->Equals(2))//box
											{
												if (wall_storage_space[k, l]->Equals(6))//target
												{
													storagesLeft2--;
												}
												boxesX2->Add(k);
												boxesY2->Add(l);
											}
										}
									}

									for (int k = 0; k < x; k++)
									{
										for (int l = 0; l < y; l++)
										{
											if (copy_tmp_box_robot[k, l]->Equals(4))//man
											{
												for (int m = 0; m < (int)boxesX2->Count; m++)
												{
													if (boxRobtDistance2 > (Math::Abs((int)boxesX2[m] - k) + Math::Abs((int)boxesY2[m] - l)))
													{
														boxRobtDistance2 = Math::Abs((int)boxesX2[m] - k) + Math::Abs((int)boxesY2[m] - l);
													}
												}
											}
										}
									}

									storagesLeft2 = 0;
									int manhattanNum = manhattan(copy_tmp_box_robot, storage_row1, storage_col1)+ boxRobtDistance2+ stepsTillNow;

									//int manhattanNum = manhattan2(copy_tmp_box_robot, storage_row1);
									//������Ҫ�õ�manhattan����
									//����list�����
									boxRobtDistanceList->Add(manhattanNum);
									boxRobotList->Add(copy_tmp_box_robot);
									movesListList->Add(copyTmpMovesList);


									visitedMovesList->Add(copy_tmp_box_robot);
								}
							}
						}
					}
					else {//210
						if (wall_storage_space[robotNew_x, robotNew_y]->Equals(1)|| !copy_tmp_box_robot[robotNew_x, robotNew_y]->Equals(5))//obstacle��û����
						{
							continue;
						}
						else {
							copy_tmp_box_robot[robotNew_x, robotNew_y] = 4;//ren
							copy_tmp_box_robot[robot_x, robot_y] = 5;//��
							if (!isInVisitedMoves(visitedMovesList, copy_tmp_box_robot))
							//if (!visitedMovesList->Contains(copy_tmp_box_robot))
							{
								copyTmpMovesList->Add(i);
								int boxRobtDistance4 = 9999999;
								System::Collections::ArrayList^ boxesX4 = gcnew ArrayList;
								System::Collections::ArrayList^ boxesY4 = gcnew ArrayList;
								int storagesLeft4= (int)storage_row1->Count;
								for (int k = 0; k < x; k++)
								{
									for (int l = 0; l < y; l++)
									{
										if (copy_tmp_box_robot[k, l]->Equals(2))//box
										{
											if (wall_storage_space[k, l]->Equals(6))//target
											{
												storagesLeft4--;
											}
											boxesX4->Add(k);
											boxesY4->Add(l);
										}
									}
								}
								for (int k = 0; k < x; k++)
								{
									for (int l = 0; l < y; l++)
									{
										if (copy_tmp_box_robot[k, l]->Equals(4))//man
										{
											for (int m = 0; m < (int)boxesX4->Count; m++)
											{
												if (boxRobtDistance4 > (Math::Abs((int)boxesX4[m] - k) + Math::Abs((int)boxesY4[m] - l)))
												{
													boxRobtDistance4 = Math::Abs((int)boxesX4[m] - k) + Math::Abs((int)boxesY4[m] - l);
												}
											}
										}
									}
								}
								storagesLeft4 = 0;
								//int manhattan = 77777;//������Ҫ�õ�manhattan����236
								//����list�����
								int manhattanNum = manhattan(copy_tmp_box_robot, storage_row1, storage_col1) + boxRobtDistance4 + stepsTillNow;
								boxRobtDistanceList->Add(manhattanNum);
								boxRobotList->Add(copy_tmp_box_robot);
								movesListList->Add(copyTmpMovesList);


								visitedMovesList->Add(copy_tmp_box_robot);

							}
						}
					}
					/*tmpMovesList->CopyTo(copyTmpMovesList,)*/
				}
			}
			if (completed == 0)
			{
				Console::WriteLine("�Ҳ������");
			}
			Console::WriteLine("while����");
			System::Collections::ArrayList^ aaa=gcnew ArrayList;
			aaa->Add((127, "wodnm"));//�����У�ֻ�Ž�ȥ�˺����һ��
			Console::WriteLine(aaa[0]->GetType());

			
			Console::WriteLine("��ť����");
			//Button^ tmpButton = gcnew Button;
			//tmpButton->Text = "��";
			//tmpLabel->Text = "������ɣ�";
			//tmpForm->AcceptButton = tmpButton;
			//tmpForm->Controls->Add(tmpButton);
			tmpForm->Close();
			

		}//buttonclick2����������

		int manhattan(array<int^, 2>^ state,ArrayList^ storagesX, ArrayList^ storagesY)
		{
			int distance = 0;
			int x = Convert::ToInt32(textBox1->Text);
			int y = Convert::ToInt32(textBox2->Text);
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					if (state[i, j]->Equals(2))//box
					{
						int temp = 9999999;
						for (int k = 0; k < (int)storagesX->Count; k++)
						{
							//abs(storage[0] - i) + abs(storage[1] - j)
							int distanceToNearest = Math::Abs((int)storagesX[k] - i) + Math::Abs((int)storagesY[k] - j);
							if (temp > distanceToNearest)
							{
								temp = distanceToNearest;
							}
						}
						distance += temp;
					}
				}
			}
			return distance;
		}
		bool erWeiSame(array<int^, 2>^ a, array<int^, 2>^ b)
		{
			int x = Convert::ToInt32(textBox1->Text);
			int y = Convert::ToInt32(textBox2->Text);
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < y; j++)
				{
					if (!a[i, j]->Equals(b[i, j]))
					{
						return false;
					}
				}
			}
			return true;
		}
		bool isInVisitedMoves(ArrayList^ VisitedMoves, array<int^, 2>^ copy_tmp_box_robot)
		{
			for (int i = 0; i < (int)VisitedMoves->Count; i++)
			{
				if (erWeiSame((array<int^, 2>^)VisitedMoves[i], copy_tmp_box_robot))
				{
					return true;
				}
			}
			return false;
		}

	//�Լ���ѡ������
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		
		//System::Windows::Forms::KeyEventArgs e2;
		//while(KeyEventArgs::Control)
		if (Form::KeyPreview == false)
		{
			this->�Լ���->Text = L"��������";
			MessageBox^ nmsl2;
			nmsl2->Show("��ʼ�Լ���");
		}
			
		else
		{
			this->�Լ���->Text = L"��ʼ�Լ��棡";
			MessageBox^ nmsl2;
			nmsl2->Show("��������");
		}
		//��һ��ȡ��һ�Σ�true���ܼ��̣����򲻽���
		Form::KeyPreview = !Form::KeyPreview;


	}
	//ͷ�ļ���ֻ������ʵ����cpp��
	void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);



private: System::Void ���԰�ť_Click(System::Object^ sender, System::EventArgs^ e) {
	dataGridView1->Columns->Clear();

	int inputx[4] = { 6,7,6,6 };
	int inputy[4] = { 6,5,6,8 };
	
	

	char inputss[4][8][8] = { 
	{
		{'O','O','O','O','O','O'},
		{'O','S','-','-','O','O'},
		{'O','-','B','B','-','O'},
		{'O','-','B','R','-','O'},
		{'O','S','-','-','S','O'},
		{'O','O','O','O','O','O'} 
	},
	{
		{'O','O','O','O','O'},
		{'O','S','R','O','O'},
		{'O','B','B','S','O'},
		{'O','-','B','-','O'},
		{'O','-','S','-','O'},
		{'O','O','-','-','O'},
		{'-','O','O','O','O'}
	},
	{
		{'-','-','O','O','O','O'},
		{'O','O','O','-','S','O'},
		{'O','S','-','B','-','O'},
		{'O','O','-','B','-','O'},
		{'O','S','B','-','O','O'},
		{'O','O','O','O','O','O'}
	},
	{
		{'O','O','O','O','O','O','O','O'},
		{'O','-','-','-','-','R','-','O'},
		{'O','-','-','-','-','B','-','O'},
		{'O','O','O','O','O','B','S','O'},
		{'-','-','-','-','O','-','S','O'},
		{'-','-','-','-','O','O','O','O'}
	}
	
	
	
	
	
	};
	// set a image for the cell[index_x,index_y]

	int k = 3;


	for (int i = 0; i < inputy[k]; i++) {
		DataGridViewColumn^ newCol = (gcnew System::Windows::Forms::DataGridViewImageColumn);
		newCol->Width = 64;
		dataGridView1->Columns->Add(newCol);
	}


	for (int i = 0; i < inputx[k]-1; i++) {
		dataGridView1->Rows->Add();
	}


	for (int i = 0; i < inputx[k]; i++)
	{
		for (int j = 0; j < inputy[k]; j++)
		{
			if(inputss[k][i][j]=='O')
			{
				dataGridView1[j, i]->Value = img_brick;
				mapArray[i, j] = 1;
			}

			if (inputss[k][i][j] == 'B')
			{
				dataGridView1[j, i]->Value = img_box;
				mapArray[i, j] = 2;
			}


			if (inputss[k][i][j] == 'R')
			{
				if (this->hasMan == false)//��ǰ��û��������
				{
					this->hasMan = true;

				}
				else {//��ǰ�Ѿ�����������
					mapArray[this->manRow, this->manCol] = 5;//��֮ǰ�������˵ĵط��ĳɵ��淽��
					dataGridView1[this->manCol, this->manRow]->Value = img_ground;
				}
				dataGridView1[j, i]->Value = img_man;
				mapArray[i, j] = 4;
				this->manRow = i;
				this->manCol = j;
			}

			if (inputss[k][i][j] == '-')
			{
				dataGridView1[j, i]->Value = img_ground;
				mapArray[i, j] = 5;
			}

			if (inputss[k][i][j] == 'S')
			{
				dataGridView1[j, i]->Value = img_target;
				mapArray[i, j] = 6;
			}
		}
	}

	// mapArray 1:brick 2:box 3:box_target 4:man 5:ground 6:target
	
}
private: System::Void ģ��_Click(System::Object^ sender, System::EventArgs^ e) {
	int x = Convert::ToInt32(textBox1->Text);
	int y = Convert::ToInt32(textBox2->Text);
	int dx[5] = { 0,-1,0,1,0 };
	int dy[5] = { 0,0,1,0,-1 };
	int manX = 0;
	int manY = 0;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (mapArray[i, j]->Equals(4))
			{
				manX = i;
				manY = j;
			}
		}
	}
	for (int i = 0; i < (int)AnsArray->Count; i++)
	{
		Console::WriteLine("{0}", i);
		for (int j = 0; j < x; j++)
		{
			for (int k = 0; k < y; k++)
			{
				Console::Write("{0} ", mapArray[j, k]);
			}
			Console::WriteLine();
		}
		int tmpOldMan = (int)mapArray[manX, manY];
		int tmpNewMan = (int)mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]];
		int tmpNewBox = (int)mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]];
		//1
		if (mapArray[manX, manY]->Equals(4))
		{
			//1.1
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(2))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 4;
				if (mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]]->Equals(5))//��λ�ñ�����
				{
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 2;
				}
				else {//������+target
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 3;
				}
				//dataGridView1
			}
			//1.2
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(3))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 7;
				if (mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]]->Equals(5))//��λ�ñ�����
				{
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 2;
				}
				else {//������+target
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 3;
				}
			}
			//1.3
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(5))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 4;
			}
			//1.4
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(6))
			{
				mapArray[manX, manY] = 5;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 7;
			}
		}

		//2
		else if (mapArray[manX, manY]->Equals(7)) {//��ǰ��target��
			//2.1
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(2))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 4;
				if (mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]]->Equals(5))//��λ�ñ����ӣ�ԭ������ͨ����
				{
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 2;
				}
				else {//������+target
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 3;
				}
				//dataGridView1
			}
			//2.2
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(3))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 7;
				if (mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]]->Equals(5))//��λ�ñ�����
				{
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 2;
				}
				else {//������+target
					mapArray[manX + 2 * dx[(int)AnsArray[i]], manY + 2 * dy[(int)AnsArray[i]]] = 3;
				}
			}
			//2.3
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(5))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 4;
			}
			//2.4
			if (mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]]->Equals(6))
			{
				mapArray[manX, manY] = 6;
				mapArray[manX + dx[(int)AnsArray[i]], manY + dy[(int)AnsArray[i]]] = 7;
			}
		}
		manX = manX + dx[(int)AnsArray[i]];
		manY = manY + dy[(int)AnsArray[i]];
		//System::Threading::Thread::Sleep(500);
		//System::Threading::Tasks::Task::Delay(10000);

		DateTime curr=DateTime::Now;
		while (curr.AddMilliseconds(1000) > DateTime::Now)
		{
			Application::DoEvents();
		}
		 //await Task.Delay(1000);
		//MessageBox::Show("��һ��");
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


		//MessageBox::Show("�����������ʾ");
	}





}
};
}

