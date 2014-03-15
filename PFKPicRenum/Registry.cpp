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
#include "Registry.h"

using namespace PFKPicRenum;
using namespace System;
using namespace Windows::Forms;
using namespace Microsoft::Win32;

String ^
PFKPicRenum :: PFKPicRegistryFetchDestFolder(void)
{
	String ^ retval = nullptr;
	RegistryKey ^ swkey1, ^ swkey2;
	Object ^ value_obj;

	swkey1 = Registry::CurrentUser->OpenSubKey(SW_MANUFACTURER_KEY_NAME,true);
	if (!swkey1)
		swkey1 = Registry::CurrentUser->CreateSubKey(SW_MANUFACTURER_KEY_NAME);
	if (!swkey1)
	{
		MessageBox::Show("Unable to access or create Registry Key!",
						 "Initialization Error");
		return nullptr;
	}
	swkey2 = swkey1->OpenSubKey(SW_PROG_KEY_NAME,true);
	if (!swkey2)
		swkey2 = swkey1->CreateSubKey(SW_PROG_KEY_NAME);
	if (!swkey2)
	{
		MessageBox::Show("Unable to access or create Registry Key!",
						 "Initialization Error");
		return nullptr;
	}
  
	value_obj = swkey2->GetValue(SW_DEST_DIR_KEY_NAME);
	if (value_obj)
		retval = value_obj->ToString();

	return retval;
}

Void
PFKPicRenum :: PFKPicRegistrySetDestFolder(String ^ dir)
{
	RegistryKey ^ swkey1, ^ swkey2;

	swkey1 = Registry::CurrentUser->OpenSubKey(SW_MANUFACTURER_KEY_NAME,true);
	if (swkey1)
		swkey2 = swkey1->OpenSubKey(SW_PROG_KEY_NAME,true);

	if (!swkey1 || !swkey2)
	{
		MessageBox::Show("Cannot open registry keys during write!",
						 "Shutdown error");
		return;
	}

	swkey2->SetValue(SW_DEST_DIR_KEY_NAME, dir);
}
