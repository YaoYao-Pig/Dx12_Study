#pragma once
#ifndef _MAINWINDOW
#define _MAINWINDOW
#include "d3dUtil.h"
#include <WindowsX.h>
class MainWindow {

public:
	HINSTANCE mhAppInst = nullptr; //APP ¾ä±ú
	HWND mhMainWnd = nullptr;//Windows ¾ä±ú

	static MainWindow* mApp;

public:
	int mClientWidth = 800;
	int mClientHeight = 600;

	std::wstring mMainWndCaption = L"d3d App";

	static MainWindow* GetApp();
	
	LRESULT MsgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

	MainWindow(HINSTANCE _hin);
	bool InitMainWindow();
};
#endif // !_MAINWINDOW