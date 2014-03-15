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


#include "stdafx.h"
#include "Form1.h"
#include "Registry.h"

using namespace PFKPicRenum;
using namespace System;
using namespace System::IO;

Void
Form1 :: rescanDestFolder(void)
{
	String ^ dir;
	array<String ^> ^ ents;
	bool listCompletions = false;
	int pos;

	destPicNextCount = 0;
	this->destinationFolderCountLabel->Text = L"";

	dir = this->destinationFolderTextBox->Text;
	if (dir->EndsWith(":") || dir->EndsWith("\\"))
		listCompletions = true;

	try {
		this->actionListBox->Items->Clear();
		this->actionListBox->Items->Add("Destination folder:");

		ents = Directory::GetFiles(dir);
		for each(String ^ path in ents)
		{
			if (path->EndsWith(".jpg", StringComparison::OrdinalIgnoreCase))
			{
				pos = path->LastIndexOf('\\');
				String ^ filename = path->Substring(pos+1);
				if (filename->StartsWith("pic") && filename->Length == 12)
				{
					int value;
					try {
						value = Int32::Parse(filename->Substring(3,5));
						this->actionListBox->Items->Add(path);
						if ((value+1) > destPicNextCount)
							destPicNextCount = value+1;
					}
					catch (...) {
						// ignore
					}
				}
			}
		}
		this->destinationFolderCountLabel->Text = destPicNextCount.ToString();
	}
	catch (...) {
		listCompletions = true;
	}

	if (listCompletions)
	{
		if (dir->EndsWith(":"))
			pos = dir->Length;
		else
			pos = dir->LastIndexOf('\\');
		if (pos >= 0)
		{
			String ^ basedir, ^ last;
			if (dir->EndsWith(":"))
			{
				basedir = String::Format("{0}\\", dir);
				last = L"";
			}
			else
			{
				basedir = dir->Substring(0,pos+1);
				last = dir->Substring(pos+1);
			}
			this->destinationFolderCountLabel->Text =
				"completions listed below";
			try {
				ents = Directory::GetDirectories(basedir);
				for each(String ^ path in ents)
				{
					String ^ pathlast;
					pos = path->LastIndexOf('\\');
					if (pos < 0)
						pathlast = path;
					else
						pathlast = path->Substring(pos+1);
					if (String::Compare(pathlast, 0, last, 0,
										last->Length, true) == 0)
						this->actionListBox->Items->Add(path);
				}
			}
			catch (...) {
				// ignore
			}
		}
	}
}
