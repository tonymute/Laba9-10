#pragma once
#include<cmath>
#include <stdlib.h>
#include <ctime>
#include <string>
int m, n, i, j, a = 0, b = 0;
int A[100][100];
int B[8]{ 0, 0, 0, 1, 0, 0 ,0 ,0 };
using namespace std;

namespace Project2 {

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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Location = System::Drawing::Point(12, 12);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(636, 313);
			this->dataGridView1->TabIndex = 0;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(654, 12);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(178, 316);
			this->listBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(12, 395);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(145, 65);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Создать массива";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(184, 395);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(148, 65);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Рассчитать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(370, 423);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 24);
			this->label1->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(844, 477);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		srand(time(0));
		n = 10;
		m = 8;
		dataGridView1->Columns->Clear();
		dataGridView1->ColumnCount = m;
		dataGridView1->RowCount = n;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				A[i][j] = rand() % 2;
				dataGridView1->Rows[i]->Cells[j]->Value = A[i][j];
			}
	}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	this->label1->Text = Convert::ToString("");
	listBox1->Items->Clear();
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			a += A[i][j] * pow(2, 7 - j);
		}
		listBox1->Items->Add(a);
		a = 0;
	}
	for (i = 0; i < n; i++)
	{
		b = 0;
		for (j = 0; j < m; j++)
		{
			if (A[i][j] == B[j])
				b += 1;
		}
		if (b == 8)
			break;
	}

	if (b != 8)
		this->label1->Text = Convert::ToString("Нету числа равного 10h");
	else
	{
		a = 0;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				a += A[i][j] * pow(2, 7 - j);
			}
		}
		this->label1->Text = Convert::ToString("Сумма равна " + a );
	}
}
};
}
