#pragma once

#include<crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include"d3dUtil.h"


class DX12Object {
	template <class T>
	using WComptr = Microsoft::WRL::ComPtr<T>;
public:
	int currentFence = 0;


public:
	WComptr<ID3D12Device> mDevice;
	WComptr<IDXGIFactory4> mFactory;
	
	WComptr<ID3D12Fence> mFence;

	WComptr<IDXGISwapChain> mSwapChain;




	WComptr<ID3D12GraphicsCommandList> mCommandList;
	WComptr<ID3D12CommandQueue> mCommandQueue;
	WComptr<ID3D12CommandAllocator> mCommandAllocator;

	

	WComptr<ID3D12DescriptorHeap> mRtvHeap;
	WComptr<ID3D12DescriptorHeap> mDsvHeap;

	float AspectRatio()const
	{
		return static_cast<float>(mClientWidth) / mClientHeight;
	}
public:

	//**需要额外处理
	HWND mhMainWnd = nullptr;


	//设置窗口大小，同时也是buffer的大小
	int mClientWidth = 800;
	int mClientHeight = 600;

	//SwapChain
	static const int mSwapChainBufferCount = 2;
	int mCurrBackBuffer = 0;

	//Buffer
	WComptr<ID3D12Resource> mSwapChainBuffer[mSwapChainBufferCount];
	WComptr<ID3D12Resource> mDepthStencilBuffer;

	//BackBuffer格式
	DXGI_FORMAT mBackBufferFormat = DXGI_FORMAT_R8G8B8A8_UNORM;
	DXGI_FORMAT mDepthStencilFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
	//MSAA
	bool      m4xMsaaState = false;    // 4X MSAA enabled
	UINT      m4xMsaaQuality = 1;      // quality level of 4X MSAA

	D3D12_VIEWPORT mScreenViewport;

	UINT mCurrentFence=0;


	//RTV/DSV Size

	UINT mRtvDescriptorSize = 0;
	UINT mDsvDescriptorSize = 0;



public:

	DX12Object(HWND _mhMainWnd) { mhMainWnd = _mhMainWnd; }

	bool InitDirect3D();

	void Draw();


	void InitBuffer();

	ID3D12Resource* CurrentBackBuffer()const;
	D3D12_CPU_DESCRIPTOR_HANDLE CurrentBackBufferView()const;
	D3D12_CPU_DESCRIPTOR_HANDLE DepthStencilView()const;
	void FlushCommandQueue();
private:

	bool IniteMSAA();
	bool CreatCommandObjects();
	bool CreateSwapChain();

	bool CreatDescriptorHeaps();
	bool CreatRTVHeap();
	bool CreatDSVHeap();

	bool SetViewPort();



};