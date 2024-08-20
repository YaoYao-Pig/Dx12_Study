#pragma once
#include"Dx12Object.h"
#include"MainWindow.h"
#include<memory>
#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib,"d3dcompiler.lib")

class Dx12 {
public:
    HINSTANCE mHin;
    HWND mHwnd;

public:
    Dx12(HINSTANCE _hin){
        mHin = _hin;
    }

	std::unique_ptr<DX12Object> dx12;
    std::unique_ptr<MainWindow> mWnd;

	void Initialize();

	int Run() {
		MSG msg = { 0 };
		while (msg.message != WM_QUIT)
		{
			// If there are Window messages then process them.
			if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			// Otherwise, do animation/game stuff.
			else
			{
				Update();
				Draw();
			}
		}

		return (int)msg.wParam;
    }
	virtual void Update(){}
    virtual void Draw();
};









