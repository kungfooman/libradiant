/*
   Copyright (C) 1999-2007 id Software, Inc. and contributors.
   For a list of contributors, see the accompanying CONTRIBUTORS file.

   This file is part of GtkRadiant.

   GtkRadiant is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   GtkRadiant is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with GtkRadiant; if not, write to the Free Software
   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#ifndef _PLUGIN_H_
#define _PLUGIN_H_

/*!
   \todo need general notice about lib purpose etc.
   and the external dependencies (such as GLib, STL, mathlib etc.)
 */

/*!
   \todo not sure about what should be used for common data structures, GLib or STL
   I think STL would be better since I intend on using STL in synapse
 */

#include <stdio.h>
#include "synapse.h"
#include "qerplugin.h"
#include "ientity.h"
#include "ieclass.h"
#include "ibrush.h"
#include "iundo.h"
#include "imodel.h"
#include "igl.h"

IModelCache* GetModelCache();
extern "C" void Sys_FPrintf( int level, const char *text, ... );

#include "isurfaceplugin.h"
#include "../radiant/brush.h"

#include "../ccall/ccall.h"
CCALL int imgui_log(char *format, ...);
#define Error imgui_log

const char* WINAPI QERApp_GetGameFile();

#endif // _PLUGIN_H_
