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

#ifndef _TEXWINDOW_H_
#define _TEXWINDOW_H_

#include "glwindow.h"

class TexWnd : public GLWindow
{
public:
	GtkWidget *m_pFilter;
	TexWnd();
	void UpdateFilter( const char* pFilter );
	void UpdatePrefs();
	void FocusEdit();
	bool CheckFilter( const char* );
	virtual ~TexWnd();
	bool m_bNeedRange;
	void OnCreate();
	void OnExpose();
	void OnLButtonDown( guint32 flags, int x, int y );
	void OnRButtonDown( guint32 flags, int x, int y );
	void OnMButtonDown( guint32 flags, int x, int y );
	void OnLButtonUp( guint32 flags, int pointx, int pointy );
	void OnRButtonUp( guint32 flags, int pointx, int pointy );
	void OnMButtonUp( guint32 flags, int pointx, int pointy );
	void OnMouseMove( guint32 flags, int pointx, int pointy );
	void OnSize( int cx, int cy );
	void OnMouseWheel( bool bUp, int pointx, int pointy );
	void OnVScroll();
	void DragDropTexture( guint32 flags, int pointx, int pointy );
	LONG WinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
};

#endif // _TEXWINDOW_H_
