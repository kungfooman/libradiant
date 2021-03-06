#include "dock_z.h"
#include "../imgui_docks/dock_console.h"

#include "../radiant/qe3.h"
#include "../radiant/mainframe.h"
//#include "../mainframe.h"

DockZ::DockZ() {}

const char *DockZ::label() {
	return "Z";
}

extern MainFrame *mainframe_intance;

#include "dock_z.h"
extern DockZ *dock_z;

void rendercallback_z(const ImDrawList* parent_list, const ImDrawCmd* cmd) {
	if (dock_z->cdock->active && mainframe_intance && mainframe_intance->m_pZWnd)
		mainframe_intance->m_pZWnd->Render();
}

void DockZ::imgui() {
	auto size = ImGui::GetWindowSize();
	size -= ImVec2(16,16); // substract a bit so there is no overflow to right/bottom
	//ImGui::Text("pos %f %f size %f %f", pos.x, pos.y, size.x, size.y);
	auto &io = ImGui::GetIO();
	auto fullsize = io.DisplaySize;
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->m_nWidth = size.x;
		mainframe_intance->m_pZWnd->m_nHeight = size.y;
		mainframe_intance->m_pZWnd->viewport_left = screenpos.x;
		mainframe_intance->m_pZWnd->viewport_bottom = fullsize.y - (screenpos.y + size.y);
	}

	ImDrawList *drawlist = ImGui::GetWindowDrawList();
	drawlist->AddCallback(rendercallback_z, NULL);
}

guint32 getMouseFlags();

extern MainFrame *mainframe_intance;

// left mouse

void DockZ::OnLeftMouseDown(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnLeftMouseDown %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnLButtonDown(getMouseFlags(), left, top);
	}
}

void DockZ::OnLeftMouseUp(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnLeftMouseUp %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnLButtonUp(getMouseFlags(), left, top);
	}
}

// right mouse

void DockZ::OnRightMouseDown(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnLeftMouseDown %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnRButtonDown(getMouseFlags(), left, top);
	}
}

void DockZ::OnRightMouseUp(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnLeftMouseUp %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnRButtonUp(getMouseFlags(), left, top);
	}
}

// middle mouse

void DockZ::OnMiddleMouseDown(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnLeftMouseDown %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnMButtonDown(getMouseFlags(), left, top);
	}
}

void DockZ::OnMiddleMouseUp(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnLeftMouseUp %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnMButtonUp(getMouseFlags(), left, top);
	}
}

void DockZ::OnMouseMove(ImVec2 posLeftTop) {
	int left = posLeftTop.x;
	int top = posLeftTop.y;
	//imgui_log("DockXY::OnMouseMove %d %d\n", left, top);
	if (mainframe_intance && mainframe_intance->m_pZWnd) {
		mainframe_intance->m_pZWnd->OnMouseMove(getMouseFlags(), left, top);
	}
}

void DockZ::OnKeyDown(int key) {
	switch (key) {
		case VK_ESCAPE:
			mainframe_intance->OnSelectionDeselect();
		default:
			mainframe_keypress(key);
			//imgui_log("DockXY::OnKeyDown(int key=%d)\n", key);
	}
}

void DockZ::OnMouseWheelUp(ImVec2 posLeftTop) {
	if (mainframe_intance && mainframe_intance->m_pXYWnd) {
		mainframe_intance->m_pZWnd->OnMouseWheel(true, posLeftTop.x, posLeftTop.y);
	}
}

void DockZ::OnMouseWheelDown(ImVec2 posLeftTop) {
	if (mainframe_intance && mainframe_intance->m_pXYWnd) {
		mainframe_intance->m_pZWnd->OnMouseWheel(false, posLeftTop.x, posLeftTop.y);
	}
}
