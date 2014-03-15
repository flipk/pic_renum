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

using namespace PFKPicRenum;
using namespace System;

System::Void
Form1 :: performRenumActions(bool preview)
{
	System::String ^ destdir;
	int nextFileNumber = this->destPicNextCount;
	int count;

	this->actionListBox->Items->Clear();
	if (preview)
		this->actionListBox->Items->Add("renumber actions (preview):");
	else
		this->actionListBox->Items->Add("renumber actions performed:");

	if (this->destPicNextCount <= 0)
	{
		this->actionListBox->Items->Add(
			String::Format("destination folder not selected!"));
		return;
	}

	if (this->sourceFilesCount <= 0)
	{
		this->actionListBox->Items->Add(
			String::Format("source folder not selected!"));
		return;
	}

	destdir = this->destinationFolderTextBox->Text;
	PFKPicRegistrySetDestFolder(destdir);

	for (count=0; count < sourceFilesCount; count++)
	{
		String ^ sourcefile = sourceFiles[count];

		String ^ destfile = String::Format(
			"{0}/pic{1}.jpg",
			this->destinationFolderTextBox->Text,
			nextFileNumber.ToString("D5"));

		if (!preview)
		{
			try {
				IO::Directory::Move(sourcefile, destfile);
				this->actionListBox->Items->Add(
					String::Format("{0} --> {1}",
								   sourcefile, destfile));
			}
			catch (...) {
				this->actionListBox->Items->Add(
					String::Format("{0} --> {1} *** FAILED!",
								   sourcefile, destfile));
			}
		}
		else
		{
			this->actionListBox->Items->Add(
				String::Format("{0} --> {1}",
							   sourcefile, destfile));
		}

		nextFileNumber++;
	}
}
