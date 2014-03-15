/*
    This file is part of the "PFKPicRenum" tool written by Phil Knaack
    (pknaack1@netscape.net).
    Copyright (C) 2010  Phillip F Knaack

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#pragma once

#include "Registry.h"

namespace PFKPicRenum {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private:
		array<System::String ^> ^ sourceFiles;
		int sourceFilesCount;
		int destPicNextCount;

	public:
		Form1(void)
		{
			InitializeComponent();
			sourceFiles = nullptr;
			this->sourceFolderCountLabel->Text = L"";
			this->destinationFolderCountLabel->Text = L"";
			this->destinationFolderTextBox->Text =
				PFKPicRegistryFetchDestFolder();
		}

	protected:
		~Form1()
		{
			if (sourceFiles)
				delete sourceFiles;
			if (components)
				delete components;
		}

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  destinationFolderTextBox;
	private: System::Windows::Forms::Button^  destinationSelectButton;
	private: System::Windows::Forms::Button^  sourceSelectButton;
	private: System::Windows::Forms::TextBox^  sourceFolderTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  destinationFolderCountLabel;
	private: System::Windows::Forms::Button^  previewButton;
	private: System::Windows::Forms::Button^  executeButton;
	private: System::Windows::Forms::Button^  exitButton;
	private: System::Windows::Forms::Label^  sourceFolderCountLabel;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::ListBox^  actionListBox;
	private: System::Windows::Forms::FolderBrowserDialog^  sourceFolderBrowserDialog;
	private: System::Windows::Forms::FolderBrowserDialog^  destinationFolderBrowserDialog;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->destinationFolderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->destinationSelectButton = (gcnew System::Windows::Forms::Button());
			this->sourceSelectButton = (gcnew System::Windows::Forms::Button());
			this->sourceFolderTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->destinationFolderCountLabel = (gcnew System::Windows::Forms::Label());
			this->previewButton = (gcnew System::Windows::Forms::Button());
			this->executeButton = (gcnew System::Windows::Forms::Button());
			this->exitButton = (gcnew System::Windows::Forms::Button());
			this->sourceFolderCountLabel = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->actionListBox = (gcnew System::Windows::Forms::ListBox());
			this->sourceFolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->destinationFolderBrowserDialog = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Destination Folder";
			// 
			// destinationFolderTextBox
			// 
			this->destinationFolderTextBox->Location = System::Drawing::Point(110, 64);
			this->destinationFolderTextBox->Name = L"destinationFolderTextBox";
			this->destinationFolderTextBox->Size = System::Drawing::Size(504, 20);
			this->destinationFolderTextBox->TabIndex = 2;
			this->destinationFolderTextBox->WordWrap = false;
			this->destinationFolderTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::destinationFolderTextBox_TextChanged);
			// 
			// destinationSelectButton
			// 
			this->destinationSelectButton->Location = System::Drawing::Point(621, 62);
			this->destinationSelectButton->Name = L"destinationSelectButton";
			this->destinationSelectButton->Size = System::Drawing::Size(75, 23);
			this->destinationSelectButton->TabIndex = 3;
			this->destinationSelectButton->Text = L"Select...";
			this->destinationSelectButton->UseVisualStyleBackColor = true;
			this->destinationSelectButton->Click += gcnew System::EventHandler(this, &Form1::destinationSelectButton_Click);
			// 
			// sourceSelectButton
			// 
			this->sourceSelectButton->Location = System::Drawing::Point(620, 10);
			this->sourceSelectButton->Name = L"sourceSelectButton";
			this->sourceSelectButton->Size = System::Drawing::Size(75, 23);
			this->sourceSelectButton->TabIndex = 1;
			this->sourceSelectButton->Text = L"Select...";
			this->sourceSelectButton->UseVisualStyleBackColor = true;
			this->sourceSelectButton->Click += gcnew System::EventHandler(this, &Form1::sourceSelectButton_Click);
			// 
			// sourceFolderTextBox
			// 
			this->sourceFolderTextBox->Location = System::Drawing::Point(109, 12);
			this->sourceFolderTextBox->Name = L"sourceFolderTextBox";
			this->sourceFolderTextBox->Size = System::Drawing::Size(505, 20);
			this->sourceFolderTextBox->TabIndex = 0;
			this->sourceFolderTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::sourceFolderTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 15);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Source Folder";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 87);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Next Picture # in Destination Folder:";
			// 
			// destinationFolderCountLabel
			// 
			this->destinationFolderCountLabel->AutoSize = true;
			this->destinationFolderCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->destinationFolderCountLabel->Location = System::Drawing::Point(196, 85);
			this->destinationFolderCountLabel->Name = L"destinationFolderCountLabel";
			this->destinationFolderCountLabel->Size = System::Drawing::Size(40, 16);
			this->destinationFolderCountLabel->TabIndex = 7;
			this->destinationFolderCountLabel->Text = L"Junk";
			// 
			// previewButton
			// 
			this->previewButton->Location = System::Drawing::Point(110, 138);
			this->previewButton->Name = L"previewButton";
			this->previewButton->Size = System::Drawing::Size(75, 23);
			this->previewButton->TabIndex = 4;
			this->previewButton->Text = L"Preview";
			this->previewButton->UseVisualStyleBackColor = true;
			this->previewButton->Click += gcnew System::EventHandler(this, &Form1::previewButton_Click);
			// 
			// executeButton
			// 
			this->executeButton->Location = System::Drawing::Point(191, 138);
			this->executeButton->Name = L"executeButton";
			this->executeButton->Size = System::Drawing::Size(75, 23);
			this->executeButton->TabIndex = 5;
			this->executeButton->Text = L"Execute";
			this->executeButton->UseVisualStyleBackColor = true;
			this->executeButton->Click += gcnew System::EventHandler(this, &Form1::executeButton_Click);
			// 
			// exitButton
			// 
			this->exitButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->exitButton->Location = System::Drawing::Point(334, 138);
			this->exitButton->Name = L"exitButton";
			this->exitButton->Size = System::Drawing::Size(75, 23);
			this->exitButton->TabIndex = 6;
			this->exitButton->Text = L"Exit";
			this->exitButton->UseVisualStyleBackColor = true;
			this->exitButton->Click += gcnew System::EventHandler(this, &Form1::exitButton_Click);
			// 
			// sourceFolderCountLabel
			// 
			this->sourceFolderCountLabel->AutoSize = true;
			this->sourceFolderCountLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->sourceFolderCountLabel->Location = System::Drawing::Point(196, 33);
			this->sourceFolderCountLabel->Name = L"sourceFolderCountLabel";
			this->sourceFolderCountLabel->Size = System::Drawing::Size(40, 16);
			this->sourceFolderCountLabel->TabIndex = 12;
			this->sourceFolderCountLabel->Text = L"Junk";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(13, 35);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(153, 13);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Pictures found in source folder:";
			// 
			// actionListBox
			// 
			this->actionListBox->FormattingEnabled = true;
			this->actionListBox->Location = System::Drawing::Point(16, 180);
			this->actionListBox->Name = L"actionListBox";
			this->actionListBox->Size = System::Drawing::Size(679, 316);
			this->actionListBox->TabIndex = 7;
			// 
			// sourceFolderBrowserDialog
			// 
			this->sourceFolderBrowserDialog->ShowNewFolderButton = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(707, 514);
			this->Controls->Add(this->actionListBox);
			this->Controls->Add(this->sourceFolderCountLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->exitButton);
			this->Controls->Add(this->executeButton);
			this->Controls->Add(this->previewButton);
			this->Controls->Add(this->destinationFolderCountLabel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->sourceSelectButton);
			this->Controls->Add(this->sourceFolderTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->destinationSelectButton);
			this->Controls->Add(this->destinationFolderTextBox);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"PFK Picture Renumbering";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private:
	System::Void rescanSourceFolder(void);
	System::Void rescanDestFolder(void);
	System::Void performRenumActions(bool preview);
	System::Void
		exitButton_Click(System::Object^  sender,
						 System::EventArgs^  e)
	{
		this->Close();
	}
	System::Void
		sourceSelectButton_Click(System::Object^  sender,
								 System::EventArgs^  e)
	{
		this->sourceFolderBrowserDialog->SelectedPath =
			this->sourceFolderTextBox->Text;
		this->sourceFolderBrowserDialog->ShowDialog();
		this->sourceFolderTextBox->Text =
			this->sourceFolderBrowserDialog->SelectedPath;
	}
	System::Void
		destinationSelectButton_Click(System::Object^  sender,
									  System::EventArgs^  e)
	{
		this->destinationFolderBrowserDialog->SelectedPath =
			this->destinationFolderTextBox->Text;
		this->destinationFolderBrowserDialog->ShowDialog();
		this->destinationFolderTextBox->Text =
			this->destinationFolderBrowserDialog->SelectedPath;
	}
	System::Void
		sourceFolderTextBox_TextChanged(System::Object^  sender,
										System::EventArgs^  e)
	{
		this->rescanSourceFolder();
	}
	System::Void
		destinationFolderTextBox_TextChanged(System::Object^ sender,
											 System::EventArgs^  e)
	{
		this->rescanDestFolder();
	}
	System::Void
		previewButton_Click(System::Object^  sender,
							System::EventArgs^  e)
	{
		this->executeButton->Enabled = false;
		this->exitButton->Enabled    = false;
		this->previewButton->Enabled = false;
		performRenumActions(true);
		this->executeButton->Enabled = true;
		this->exitButton->Enabled    = true;
		this->previewButton->Enabled = true;
	}
	System::Void
		executeButton_Click(System::Object^  sender,
							System::EventArgs^  e)
	{
		this->executeButton->Enabled = false;
		this->exitButton->Enabled    = false;
		this->previewButton->Enabled = false;
		performRenumActions(false);
		this->executeButton->Enabled = true;
		this->exitButton->Enabled    = true;
		this->previewButton->Enabled = true;
	}
	};
}

