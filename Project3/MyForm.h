#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
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
		   //创建了一个二维数组，100行，105列
	public:array<int^, 2>^ mapArray = gcnew array<int^, 2>(100, 105);
	public: int target_index;
	public:array<int^, 2>^ targetArray = gcnew array<int^, 2>(10, 2);
	private: System::Windows::Forms::Button^ 自己玩;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::RadioButton^ radioButton6;
		   //记录下人的行与列
		   int manRow = 0;
		   int manCol = 0;
		   bool hasMan = false;//记录是否已经创建过人了
		   //记录有几个待求箱子
		   int boxes = 0;
		   //数组直接记录箱子坐标，最大十个点，其实实际不应该超过5个，多了算法解不出
		   array<int^, 2>^ boxesArray = gcnew array<int^, 2>(10, 2);

	private: System::Windows::Forms::Button^ button3;
		   //数组直接记录箱子坐标，最大十个点，其实实际不应该超过5个，多了算法解不出

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
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
			this->自己玩 = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->button3 = (gcnew System::Windows::Forms::Button());
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
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(160, 27);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(60, 21);
			this->textBox2->TabIndex = 1;
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
			this->button2->Location = System::Drawing::Point(340, 25);
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
			this->label3->Text = L"×";
			// 
			// 自己玩
			// 
			this->自己玩->Location = System::Drawing::Point(581, 25);
			this->自己玩->Name = L"自己玩";
			this->自己玩->Size = System::Drawing::Size(103, 23);
			this->自己玩->TabIndex = 18;
			this->自己玩->Text = L"开始自己玩！";
			this->自己玩->UseVisualStyleBackColor = true;
			this->自己玩->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(454, 25);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 19;
			this->button3->Text = L"Simulate";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1097, 603);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->自己玩);
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


		// read images from resx
		System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);


		Image^ img_brick = cli::safe_cast<Image^>(rm->GetObject("brick"));
		Image^ img_box = cli::safe_cast<Image^>(rm->GetObject("box"));
		Image^ img_box_target = cli::safe_cast<Image^>(rm->GetObject("box_target"));
		Image^ img_man = cli::safe_cast<Image^>(rm->GetObject("man"));
		Image^ img_ground = cli::safe_cast<Image^>(rm->GetObject("ground"));
		Image^ img_target = cli::safe_cast<Image^>(rm->GetObject("groundWithDot"));
		/*Image^ img_brick = Image::FromFile("C:\\Users\\Desktop\\brick.png");
		Image^ img_box = Image::FromFile("C:\\Users\\Desktop\\box.png");
		Image^ img_box_target = Image::FromFile("C:\\Users\\Desktop\\box_target.png");
		Image^ img_man = Image::FromFile("C:\\Users\\Desktop\\man.png");*/


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
			if (this->hasMan == false)//当前还没创建过人
			{
				this->hasMan = true;

			}
			else {//当前已经创建过人了
				mapArray[this->manRow, this->manCol] = 5;//把之前创建的人的地方改成地面方块
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

		for (int i = 0; i < 10; i++) {
			targetArray[i, 0] = -1;
			targetArray[i, 1] = -1;
			/*Console::WriteLine("---");
			Console::WriteLine(tempx);
			Console::WriteLine(tempy);
			Console::WriteLine("---");*/
		}

		// clear rhe gridview (reset)
		dataGridView1->Columns->Clear();

		// read from textbox
		int x, y;

		x = Convert::ToInt32(textBox1->Text);

		y = Convert::ToInt32(textBox2->Text);

		// build x*y gridview cells

		for (int i = 0; i < x; i++) {
			DataGridViewColumn^ newCol = (gcnew System::Windows::Forms::DataGridViewImageColumn);
			newCol->Width = 64;
			dataGridView1->Columns->Add(newCol);
		}


		for (int i = 0; i < y - 1; i++) {
			dataGridView1->Rows->Add();
		}


		// set default images for the cell
		System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();

		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				dataGridView1[i, j]->Value = cli::safe_cast<Image^>(rm->GetObject("ground"));
			}
		}

		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				mapArray[i, j] = 5;
			}
		}

	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{

		int x, y;
		x = Convert::ToInt32(textBox1->Text); // row
		y = Convert::ToInt32(textBox2->Text); // col
		int max_length = x;

		// box_robot -:0 ' ':5
		 //wall storage -:0 ' ':5

		array<int^, 2>^ box_robot = gcnew array<int^, 2>(x, y);
		array<int^, 2>^ wall_storage_space = gcnew array<int^, 2>(x, y);
		//注意xy为0的时候可能会溢出，所以地下有提示
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				box_robot[i, j] = 0;
				wall_storage_space[i, j] = 0;
			}
		}
		//长度不够的行补0没有

		// mapArray 1:brick 2:box 3:box_target 4:man 5:ground 6:target
		//1 O 2 B 3 * 4 R 5 人站在点上 6 S
		//注意先列后行
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				//MessageBox::Show("找1-6"+"本次找到的是"+Convert::ToString(mapArray[i, j]));
				if (mapArray[i, j]->Equals(2) || mapArray[i, j]->Equals(4)) {
					//box_robot记住R人和B箱子
					box_robot[i, j] = mapArray[i, j];
					//印度哥用的是空格，不知道
					wall_storage_space[i, j] = 5;
				}
				else if (mapArray[i, j]->Equals(6) || mapArray[i, j]->Equals(1)) {
					box_robot[i, j] = 5;
					//MessageBox::Show("找到一个1或6");
					//wall_storage_space存S即target存储位置和O即阻碍位置
					wall_storage_space[i, j] = mapArray[i, j];
				}

				else if (mapArray[i, j]->Equals(5)) {
					box_robot[i, j] = 5;
					wall_storage_space[i, j] = 5;
				}

			}
		}
		MessageBox::Show(Convert::ToString(x));
		MessageBox::Show(Convert::ToString(y));
		array<int^, 1>^ target_pos_row = gcnew array<int^, 1>(10);
		array<int^, 1>^ target_pos_col = gcnew array<int^, 1>(10);
		int targetNum = 0;
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				//Console::WriteLine(wall_storage_space[i, j]);
				if (wall_storage_space[i, j]->Equals(6)) {
					target_pos_row[targetNum] = i;
					target_pos_col[targetNum++] = j;
					MessageBox::Show("找到了一个target");
				}
			}
		}

		MessageBox::Show("目标点有" + Convert::ToString(targetNum) + "个");
		//MessageBox::Show(Convert::ToString(manhatten_dis()));


		int boxRobtDistance = 9999999;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (box_robot[i, j]->Equals(4))//如果是人，算它和target的曼哈顿距离
				{
					for (int k = 0; k < targetNum; k++)
					{
						//int tmp = Convert::ToInt32(target_pos_row[k]) - i;
						//if(boxRobtDistance>(abs()+))
						//Console::WriteLine(target_pos_row[k]);
						//Console::WriteLine(target_pos_col[k]);

						int tmpAbs = Math::Abs(Convert::ToInt32(target_pos_row[k]) - i) + Math::Abs(Convert::ToInt32(target_pos_col[k]) - j);
						if (boxRobtDistance > tmpAbs)
						{
							boxRobtDistance += tmpAbs;
						}
					}
				}
			}
		}
		MessageBox::Show(Convert::ToString(boxRobtDistance));//经验证是计算正确的，还不知道有什么用
		//以上是到defManhattan之前的所有内容，已经写上了注释，注意x和y的关系，除了datagridview是先列后行外，其他的都是先行后列，已经改好了


	}//buttonclick2函数右括号

	private: int manhatten_dis() {
		return 123;
	}
		   //自己玩选项，点击后
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		//System::Windows::Forms::KeyEventArgs e2;
		//while(KeyEventArgs::Control)

		// get target position->targetarray
		int x, y;
		target_index = 0;
		x = Convert::ToInt32(textBox1->Text); // row
		y = Convert::ToInt32(textBox2->Text); // col
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (mapArray[i, j]->Equals(6)) {

					targetArray[target_index, 0] = i;
					targetArray[target_index, 1] = j;

					target_index++;

					/*Console::WriteLine("======");
					Console::WriteLine(target_index);
					Console::WriteLine("---");
					Console::WriteLine(i);
					Console::WriteLine(j);
					Console::WriteLine("---");*/
				}
			}
		}

		if (Form::KeyPreview == false)
		{
			this->自己玩->Text = L"不想玩了";
			MessageBox^ nmsl2;
			nmsl2->Show("开始自己玩");
		}

		else
		{
			this->自己玩->Text = L"开始自己玩！";
			MessageBox^ nmsl2;
			nmsl2->Show("不想玩了");
		}
		//按一次取反一次，true接受键盘，否则不接受
		Form::KeyPreview = !Form::KeyPreview;




	}
		   //头文件里只声明，实现在cpp里
		   void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);



	private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {

		// get target position->targetarray
		int x, y;
		target_index = 0;
		x = Convert::ToInt32(textBox1->Text); // row
		y = Convert::ToInt32(textBox2->Text); // col
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (mapArray[i, j]->Equals(6)) {

					targetArray[target_index, 0] = i;
					targetArray[target_index, 1] = j;

					target_index++;
				}
			}

		}

		// get man position
		int man_pos_x, man_pos_y;
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				if (mapArray[i, j]->Equals(4)) {
					man_pos_x = i;
					man_pos_y = j;
				}
			}
		}

		// load image
		System::Reflection::Assembly^ assembly = System::Reflection::Assembly::GetExecutingAssembly();
		Resources::ResourceManager^ rm = gcnew Resources::ResourceManager("Project3" + ".Resource", assembly);
		Image^ img_brick = cli::safe_cast<Image^>(rm->GetObject("brick"));
		Image^ img_box = cli::safe_cast<Image^>(rm->GetObject("box"));
		Image^ img_box_target = cli::safe_cast<Image^>(rm->GetObject("box_target"));
		Image^ img_man = cli::safe_cast<Image^>(rm->GetObject("man"));
		Image^ img_ground = cli::safe_cast<Image^>(rm->GetObject("ground"));
		Image^ img_target = cli::safe_cast<Image^>(rm->GetObject("groundWithDot"));


		array<String^>^ simArray = gcnew array<String^>(10);
		simArray[0] = "l";//left
		simArray[1] = "l";
		simArray[2] = "l";
		simArray[3] = "u";//up
		simArray[4] = "u";
		simArray[5] = "u";
		simArray[6] = "r";
		simArray[7] = "r";
		simArray[8] = "r";
		simArray[9] = "d";//down
		// simulate

		for (int i = 0; i < 10; i++) {
			if (simArray[i] == "u" && man_pos_x - 1 != -1) {
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
			if (simArray[i] == "d" && man_pos_x + 1 != y) {
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
			if (simArray[i] == "l" && man_pos_y - 1 != -1) {
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
			if (simArray[i] == "r" && man_pos_y + 1 != x) {
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
			
		}

		for (int i = 0; i < target_index; i++) {
			int tempx = cli::safe_cast<int>(targetArray[i, 0]);
			int tempy = cli::safe_cast<int>(targetArray[i, 1]);
			if (!(mapArray[tempx, tempy]->Equals(3) || mapArray[tempx, tempy]->Equals(2) || mapArray[tempx, tempy]->Equals(4)))
			{
				dataGridView1[tempy, tempx]->Value = img_target;
			}
		}


	}
	};
	}