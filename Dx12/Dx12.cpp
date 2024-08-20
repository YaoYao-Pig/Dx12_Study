#include "Dx12.h"

using namespace std;
void Dx12::Initialize()
{

	mWnd = make_unique<MainWindow>(mHin);

	

	mWnd->InitMainWindow();

	mHwnd = mWnd->mhMainWnd;

	dx12 = make_unique<DX12Object>(mHwnd);

	dx12->InitDirect3D();



	dx12->FlushCommandQueue();
	ThrowIfFailed(dx12->mCommandList->Reset(dx12->mCommandAllocator.Get(), nullptr));
}

void Dx12::Draw()
{
	//dx12->Draw();
}
