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


		private:
			/// <summary>
			/// 必需的设计器变量。
			/// </summary>
			System::ComponentModel::Container ^components;

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
			this->radioButton5 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton4 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->dataGridView1->Size = System::Drawing::Size(442, 247);
			this->dataGridView1->TabIndex = 4;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->radioButton5);
			this->groupBox1->Controls->Add(this->radioButton4);
			this->groupBox1->Controls->Add(this->radioButton3);
			this->groupBox1->Controls->Add(this->radioButton2);
			this->groupBox1->Controls->Add(this->radioButton1);
			this->groupBox1->Location = System::Drawing::Point(487, 67);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(155, 148);
			this->groupBox1->TabIndex = 15;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Brick List";
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(669, 358);
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

			/*Image^ img_brick = Image::FromFile("C:\\Users\\Desktop\\brick.png");
			Image^ img_box = Image::FromFile("C:\\Users\\Desktop\\box.png");
			Image^ img_box_target = Image::FromFile("C:\\Users\\Desktop\\box_target.png");
			Image^ img_man = Image::FromFile("C:\\Users\\Desktop\\man.png");*/


			// set a image for the cell[index_x,index_y]
			int index_x = dataGridView1->CurrentCell->ColumnIndex;
			int index_y = dataGridView1->CurrentCell->RowIndex;

			if (radioButton1->Checked)
				dataGridView1[index_x, index_y]->Value = img_brick;
			if (radioButton2->Checked)
				dataGridView1[index_x, index_y]->Value = img_box;
			if (radioButton3->Checked)
				dataGridView1[index_x, index_y]->Value = img_box_target;
			if (radioButton4->Checked)
				dataGridView1[index_x, index_y]->Value = img_man;
			if (radioButton5->Checked)
				dataGridView1[index_x, index_y]->Value = img_ground;
			


		}
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
			
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


			for (int i = 0; i < y-1; i++) {
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

		}

		
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{

		}
		
	};
}
