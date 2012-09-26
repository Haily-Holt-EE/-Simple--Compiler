#pragma once
#include "Compiler.h"

namespace HailyHoltPA7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Runtime::InteropServices;
	using namespace System::IO;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			compiler = new Compiler();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}

			delete compiler;
		}

	private: Compiler *compiler;
	private: System::Windows::Forms::RichTextBox^  CodeTextBox;
	private: System::Windows::Forms::ListBox^  MachineListBox;

	protected: 

	protected: 

	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  LoadButton;
	private: System::Windows::Forms::ToolStripButton^  SaveButton;


	private: System::Windows::Forms::Button^  CompileButton;
	private: System::Windows::Forms::ListBox^  ExecutionListBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  StepIntoButton;
	private: System::Windows::Forms::RichTextBox^  InputTextBox;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::TabControl^  CompilerTab;

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  DataTab;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::ListBox^  StoredDataBox;

	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  AccumulatorBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  CurrentOperationBox;
	private: System::Windows::Forms::TextBox^  InstructionCounterBox;
	private: System::Windows::Forms::TextBox^  CurrentMemoryLocationBox;
	private: System::Windows::Forms::Button^  button2;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->CodeTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->MachineListBox = (gcnew System::Windows::Forms::ListBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->LoadButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->SaveButton = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->CompileButton = (gcnew System::Windows::Forms::Button());
			this->ExecutionListBox = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->StepIntoButton = (gcnew System::Windows::Forms::Button());
			this->InputTextBox = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->CompilerTab = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->DataTab = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->CurrentMemoryLocationBox = (gcnew System::Windows::Forms::TextBox());
			this->CurrentOperationBox = (gcnew System::Windows::Forms::TextBox());
			this->InstructionCounterBox = (gcnew System::Windows::Forms::TextBox());
			this->AccumulatorBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->StoredDataBox = (gcnew System::Windows::Forms::ListBox());
			this->toolStrip1->SuspendLayout();
			this->CompilerTab->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->DataTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// CodeTextBox
			// 
			this->CodeTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CodeTextBox->Location = System::Drawing::Point(6, 27);
			this->CodeTextBox->Name = L"CodeTextBox";
			this->CodeTextBox->Size = System::Drawing::Size(331, 355);
			this->CodeTextBox->TabIndex = 0;
			this->CodeTextBox->Text = L"";
			this->CodeTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::CodeTextBox_TextChanged);
			// 
			// MachineListBox
			// 
			this->MachineListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->MachineListBox->FormattingEnabled = true;
			this->MachineListBox->ItemHeight = 16;
			this->MachineListBox->Location = System::Drawing::Point(371, 27);
			this->MachineListBox->Name = L"MachineListBox";
			this->MachineListBox->Size = System::Drawing::Size(126, 340);
			this->MachineListBox->TabIndex = 1;
			this->MachineListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listBox1_SelectedIndexChanged);
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->LoadButton, this->SaveButton, 
				this->toolStripButton1});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(905, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// LoadButton
			// 
			this->LoadButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->LoadButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->LoadButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"LoadButton.Image")));
			this->LoadButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(37, 22);
			this->LoadButton->Text = L"Load";
			this->LoadButton->Click += gcnew System::EventHandler(this, &Form1::LoadButton_Click);
			// 
			// SaveButton
			// 
			this->SaveButton->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->SaveButton->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->SaveButton->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"SaveButton.Image")));
			this->SaveButton->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->SaveButton->Name = L"SaveButton";
			this->SaveButton->Size = System::Drawing::Size(35, 22);
			this->SaveButton->Text = L"Save";
			this->SaveButton->Click += gcnew System::EventHandler(this, &Form1::SaveButton_Click);
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(29, 22);
			this->toolStripButton1->Text = L"Exit";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// CompileButton
			// 
			this->CompileButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->CompileButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->CompileButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->CompileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->CompileButton->Location = System::Drawing::Point(115, 400);
			this->CompileButton->Name = L"CompileButton";
			this->CompileButton->Size = System::Drawing::Size(94, 28);
			this->CompileButton->TabIndex = 3;
			this->CompileButton->Text = L"Compile";
			this->CompileButton->UseVisualStyleBackColor = false;
			this->CompileButton->Click += gcnew System::EventHandler(this, &Form1::CompileButton_Click);
			// 
			// ExecutionListBox
			// 
			this->ExecutionListBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->ExecutionListBox->FormattingEnabled = true;
			this->ExecutionListBox->ItemHeight = 15;
			this->ExecutionListBox->Location = System::Drawing::Point(534, 27);
			this->ExecutionListBox->Name = L"ExecutionListBox";
			this->ExecutionListBox->Size = System::Drawing::Size(331, 349);
			this->ExecutionListBox->TabIndex = 4;
			this->ExecutionListBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::ExecutionListBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(122, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(87, 17);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Simple Code";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(368, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(129, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Machine Language";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(668, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(69, 17);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Execution";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// StepIntoButton
			// 
			this->StepIntoButton->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->StepIntoButton->Cursor = System::Windows::Forms::Cursors::Hand;
			this->StepIntoButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->StepIntoButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->StepIntoButton->Location = System::Drawing::Point(380, 400);
			this->StepIntoButton->Name = L"StepIntoButton";
			this->StepIntoButton->Size = System::Drawing::Size(94, 28);
			this->StepIntoButton->TabIndex = 8;
			this->StepIntoButton->Text = L"Step";
			this->StepIntoButton->UseVisualStyleBackColor = false;
			this->StepIntoButton->Click += gcnew System::EventHandler(this, &Form1::StepIntoButton_Click);
			// 
			// InputTextBox
			// 
			this->InputTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->InputTextBox->Location = System::Drawing::Point(597, 400);
			this->InputTextBox->Name = L"InputTextBox";
			this->InputTextBox->Size = System::Drawing::Size(125, 27);
			this->InputTextBox->TabIndex = 9;
			this->InputTextBox->Text = L"";
			this->InputTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::InputTextBox_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(552, 406);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(43, 17);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Input:";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(737, 400);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(96, 27);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// CompilerTab
			// 
			this->CompilerTab->Controls->Add(this->tabPage1);
			this->CompilerTab->Controls->Add(this->DataTab);
			this->CompilerTab->Location = System::Drawing::Point(12, 28);
			this->CompilerTab->Name = L"CompilerTab";
			this->CompilerTab->SelectedIndex = 0;
			this->CompilerTab->Size = System::Drawing::Size(881, 471);
			this->CompilerTab->TabIndex = 12;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::Gainsboro;
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->CodeTextBox);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->MachineListBox);
			this->tabPage1->Controls->Add(this->InputTextBox);
			this->tabPage1->Controls->Add(this->CompileButton);
			this->tabPage1->Controls->Add(this->StepIntoButton);
			this->tabPage1->Controls->Add(this->ExecutionListBox);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(873, 445);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Compiler";
			// 
			// DataTab
			// 
			this->DataTab->BackColor = System::Drawing::Color::Gainsboro;
			this->DataTab->Controls->Add(this->button2);
			this->DataTab->Controls->Add(this->CurrentMemoryLocationBox);
			this->DataTab->Controls->Add(this->CurrentOperationBox);
			this->DataTab->Controls->Add(this->InstructionCounterBox);
			this->DataTab->Controls->Add(this->AccumulatorBox);
			this->DataTab->Controls->Add(this->label9);
			this->DataTab->Controls->Add(this->label8);
			this->DataTab->Controls->Add(this->label7);
			this->DataTab->Controls->Add(this->label6);
			this->DataTab->Controls->Add(this->label5);
			this->DataTab->Controls->Add(this->StoredDataBox);
			this->DataTab->Location = System::Drawing::Point(4, 22);
			this->DataTab->Name = L"DataTab";
			this->DataTab->Padding = System::Windows::Forms::Padding(3);
			this->DataTab->Size = System::Drawing::Size(873, 445);
			this->DataTab->TabIndex = 1;
			this->DataTab->Text = L"Data";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(275, 390);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(87, 29);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Refresh";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// CurrentMemoryLocationBox
			// 
			this->CurrentMemoryLocationBox->Location = System::Drawing::Point(437, 238);
			this->CurrentMemoryLocationBox->Name = L"CurrentMemoryLocationBox";
			this->CurrentMemoryLocationBox->Size = System::Drawing::Size(97, 20);
			this->CurrentMemoryLocationBox->TabIndex = 9;
			// 
			// CurrentOperationBox
			// 
			this->CurrentOperationBox->Location = System::Drawing::Point(437, 212);
			this->CurrentOperationBox->Name = L"CurrentOperationBox";
			this->CurrentOperationBox->Size = System::Drawing::Size(97, 20);
			this->CurrentOperationBox->TabIndex = 8;
			// 
			// InstructionCounterBox
			// 
			this->InstructionCounterBox->Location = System::Drawing::Point(437, 186);
			this->InstructionCounterBox->Name = L"InstructionCounterBox";
			this->InstructionCounterBox->Size = System::Drawing::Size(97, 20);
			this->InstructionCounterBox->TabIndex = 7;
			// 
			// AccumulatorBox
			// 
			this->AccumulatorBox->Location = System::Drawing::Point(437, 160);
			this->AccumulatorBox->Name = L"AccumulatorBox";
			this->AccumulatorBox->Size = System::Drawing::Size(97, 20);
			this->AccumulatorBox->TabIndex = 6;
			this->AccumulatorBox->TextChanged += gcnew System::EventHandler(this, &Form1::AccumulatorBox_TextChanged);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(540, 186);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(127, 17);
			this->label9->TabIndex = 5;
			this->label9->Text = L"Instruction Counter";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(540, 238);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(167, 17);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Current Memory Location";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(540, 212);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(122, 17);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Current Operation";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(540, 160);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(86, 17);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Accumulator";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(278, 35);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 17);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Stored Data";
			// 
			// StoredDataBox
			// 
			this->StoredDataBox->FormattingEnabled = true;
			this->StoredDataBox->Location = System::Drawing::Point(251, 55);
			this->StoredDataBox->Name = L"StoredDataBox";
			this->StoredDataBox->Size = System::Drawing::Size(135, 316);
			this->StoredDataBox->TabIndex = 0;
			this->StoredDataBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::StoredDataBox_SelectedIndexChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(905, 505);
			this->Controls->Add(this->CompilerTab);
			this->Controls->Add(this->toolStrip1);
			this->Name = L"Form1";
			this->Text = L"Simpletron Compiler";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->CompilerTab->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->DataTab->ResumeLayout(false);
			this->DataTab->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CompileButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 bool successOrNot = false, flagsFixed = false;
				 DataMemory *current = this->compiler->getInformation()->getTopDatPtr();
				 string memory;
				 int number = 0;

				 char *chars = (char*)Marshal::StringToHGlobalAnsi(CodeTextBox->Text).ToPointer();
				 //this->compiler->setProgram(p->ToCharArray());
				 this->compiler->setProgram(chars);
				 successOrNot = this->compiler->populateTable();

				 if (successOrNot == true)
				 {
					flagsFixed = this->compiler->fixFlags();

					if (flagsFixed == true)
					{
					 this->compiler->populateSimpletron();
					 MachineListBox->Items->Clear();
					 for (int i = 0; i < compiler->getInstructions().size(); i++)
					 {
						 string plusSign = "+";
						 plusSign += convertInt(compiler->getInstructions()[i]);
						 String^ s = gcnew String(plusSign.c_str());

						 MachineListBox->Items->Add(s);
					 }
					}
					else
					{
						MachineListBox->Items->Clear();
						MachineListBox->Items->Add("ERROR:");
						MachineListBox->Items->Add("Branching incorrect!");
						MachineListBox->Items->Add("Branching line ");
						MachineListBox->Items->Add("nonexistent!");
					}
				 }
				 else
				 {
					 MachineListBox->Items->Clear();
					 MachineListBox->Items->Add("ERROR:");
					 MachineListBox->Items->Add("Code not correct!");

					 int i = compiler->getTable().size();
					 string errorLine = "Possibly line ";
					 errorLine += convertInt(compiler->getTable()[i-1].getSymbol());
					 errorLine += "?";
					 String^ e = gcnew String(errorLine.c_str());

					 MachineListBox->Items->Add(e);
				 }

			 }
	private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void CodeTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void StepIntoButton_Click(System::Object^  sender, System::EventArgs^  e) {


				 DataMemory *current = this->compiler->getInformation()->getTopDatPtr();
				 string memory;
				 int number = 0;

				 if (this->compiler->getIsFirstInstruction() == true) // Set everything to a definite starting position
				 {
					 ExecutionListBox->Items->Clear();
					 this->compiler->setInstructionCounter(0);
					 MachineListBox->SelectedIndex = this->compiler->getInstructionCounter();
				 }

				 if (this->compiler->getIsEnd() != true)
				 {
					 StoredDataBox->Items->Clear();

					 for(int index = 0; index < 1000; index++)
					 {
						 if ((current != NULL) && (index == current->getLocationInMemory()))
						 {
							 memory = convertInt(current->getVal());
							 current = current->getNextPtr();
						 }
						 else
						 {
							 memory = convertInt(number);
						 }

						 String^ m = gcnew String(memory.c_str());

						 StoredDataBox->Items->Add(m);
					 }

					 int s = this->compiler->getInstructionCounter();
					 int op = this->compiler->getDividedInstructions()[s].getOpCode();

					 AccumulatorBox->Text = gcnew String (convertInt(this->compiler->getAccumulator()).c_str());
					 InstructionCounterBox->Text = gcnew String (convertInt(this->compiler->getInstructionCounter()).c_str());

					 switch (op)
					 {
					 case READ:
						 CurrentOperationBox->Text = "READ";
						 break;
					 case WRITE:
						 CurrentOperationBox->Text = "WRITE";
						 break;
					 case LOAD:
						 CurrentOperationBox->Text = "LOAD";
						 break;
					 case STORE:
						 CurrentOperationBox->Text = "STORE";
						 break;
					 case ADD:
						 CurrentOperationBox->Text = "ADD";
						 break;
					 case SUBTRACT:
						 CurrentOperationBox->Text = "SUBTRACT";
						 break;
					 case MULTIPLY:
						 CurrentOperationBox->Text = "MULTIPLY";
						 break;
					 case DIVIDE:
						 CurrentOperationBox->Text = "DIVIDE";
						 break;
					 case MOD:
						 CurrentOperationBox->Text = "MOD";
						 break;
					 case EXPO:
						 CurrentOperationBox->Text = "EXPONENTIATION";
						 break;
					 case BRANCH:
						 CurrentOperationBox->Text = "BRANCH";
						 break;
					 case BRANCHNEG:
						 CurrentOperationBox->Text = "BRANCHNEG";
						 break;
					 case BRANCHZERO:
						 CurrentOperationBox->Text = "BRANCHZERO";
						 break;
					 case HALT:
						 CurrentOperationBox->Text = "HALT";
						 break;
					 }

					 if ((op != BRANCH) && (op != BRANCHZERO) && (op != BRANCHNEG))
					 {
						 CurrentMemoryLocationBox->Text = gcnew String (convertInt(this->compiler->getDividedInstructions()[s].getOperand()).c_str());
					 }
					 else
					 {
						 CurrentMemoryLocationBox->Text = "(Instructions)";
					 }
				 }


				 if (this->compiler->getIsEnd() == false)
				 {
					 int s = this->compiler->getInstructionCounter();
					 MachineListBox->SelectedIndex = this->compiler->getInstructionCounter();
					 StoredDataBox->SelectedIndex = this->compiler->getDividedInstructions()[s].getOperand();
				 }

				 if ((this->compiler->getIsEnd() == false) && (this->compiler->CurrentIsRead() == true))
				 {
					 ExecutionListBox->Items->Add(gcnew String("Please enter number into input box."));
					 return;
				 }

				 this->compiler->executionCode();

				 ExecutionListBox->Items->Add(gcnew String(this->compiler->getStatedAction().c_str()));

			 }
	private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 OpenFileDialog o; //= gcnew OpenFileDialog();

				 if (o.ShowDialog() == Windows::Forms::DialogResult::OK)
				 {
					 CodeTextBox->Text = File::ReadAllText(o.FileName);
				 }
			 }
	private: System::Void SaveButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 SaveFileDialog saveFile1;

				 saveFile1.DefaultExt = "*.txt";
				 saveFile1.Filter = "TXT Files|*.txt";

				 if(saveFile1.ShowDialog() == System::Windows::Forms::DialogResult::OK &&
					 saveFile1.FileName->Length > 0) 
				 {

					 File::WriteAllText(saveFile1.FileName,CodeTextBox->Text);
				 }
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 if (InputTextBox->Text != "")
				 {
					 this->compiler->setInputFromUser(Convert::ToInt32(InputTextBox->Text));
					 InputTextBox->Text = "";
					 this->compiler->executionCode();
					 ExecutionListBox->Items->Add(gcnew String(this->compiler->getStatedAction().c_str()));
				 }
			 }
	private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {

				 if(MessageBox::Show("Would you like to save before exiting?", "Closing", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
				 {
					 SaveFileDialog saveFile1;

					 saveFile1.DefaultExt = "*.txt";
					 saveFile1.Filter = "TXT Files|*.txt";

					 if(saveFile1.ShowDialog() == System::Windows::Forms::DialogResult::OK &&
						 saveFile1.FileName->Length > 0) 
					 {

						 File::WriteAllText(saveFile1.FileName,CodeTextBox->Text);
						 this->Close();
					 }
				 }
				 else
				 {
					 this->Close();
				 }

			 }
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void ExecutionListBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void InputTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void StoredDataBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {

			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
                 //Refresh Button
				 DataMemory *current = this->compiler->getInformation()->getTopDatPtr();
				 string memory;
				 int number = 0;

				 if (this->compiler->getIsEnd() != true)
				 {

					 StoredDataBox->Items->Clear();

					 for(int index = 0; index < 1000; index++)
					 {
						 if ((current != NULL) && (index == current->getLocationInMemory()))
						 {
							 memory = convertInt(current->getVal());
							 current = current->getNextPtr();
						 }
						 else
						 {
							 memory = convertInt(number);
						 }

						 String^ m = gcnew String(memory.c_str());

						 StoredDataBox->Items->Add(m);
					 }

					 int s = this->compiler->getInstructionCounter();

					 int op = this->compiler->getDividedInstructions()[s].getOpCode();

					 AccumulatorBox->Text = gcnew String (convertInt(this->compiler->getAccumulator()).c_str());
					 InstructionCounterBox->Text = gcnew String (convertInt(this->compiler->getInstructionCounter()).c_str());

					 switch (op)
					 {
					 case READ:
						 CurrentOperationBox->Text = "READ";
						 break;
					 case WRITE:
						 CurrentOperationBox->Text = "WRITE";
						 break;
					 case LOAD:
						 CurrentOperationBox->Text = "LOAD";
						 break;
					 case STORE:
						 CurrentOperationBox->Text = "STORE";
						 break;
					 case ADD:
						 CurrentOperationBox->Text = "ADD";
						 break;
					 case SUBTRACT:
						 CurrentOperationBox->Text = "SUBTRACT";
						 break;
					 case MULTIPLY:
						 CurrentOperationBox->Text = "MULTIPLY";
						 break;
					 case DIVIDE:
						 CurrentOperationBox->Text = "DIVIDE";
						 break;
					 case MOD:
						 CurrentOperationBox->Text = "MOD";
						 break;
					 case EXPO:
						 CurrentOperationBox->Text = "EXPONENTIATION";
						 break;
					 case BRANCH:
						 CurrentOperationBox->Text = "BRANCH";
						 break;
					 case BRANCHNEG:
						 CurrentOperationBox->Text = "BRANCHNEG";
						 break;
					 case BRANCHZERO:
						 CurrentOperationBox->Text = "BRANCHZERO";
						 break;
					 case HALT:
						 CurrentOperationBox->Text = "HALT";
						 break;
					 }

					 if ((op != BRANCH) && (op != BRANCHZERO) && (op != BRANCHNEG))
					 {
						 CurrentMemoryLocationBox->Text = gcnew String (convertInt(this->compiler->getDividedInstructions()[s].getOperand()).c_str());
					 }
					 else
					 {
						 CurrentMemoryLocationBox->Text = "(Instructions)";
					 }

					 StoredDataBox->SelectedIndex = this->compiler->getDividedInstructions()[s].getOperand();

				 }

			 }
	private: System::Void AccumulatorBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
};
}

