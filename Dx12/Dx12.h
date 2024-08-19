#pragma once
#include"Dx12Object.h"
#include"MainWindow.h"
#include<memory>
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

    void Run() { 
        while (1) {
            Update();
            Draw();
        }
    }
	virtual void Update(){}
    virtual void Draw();
};









