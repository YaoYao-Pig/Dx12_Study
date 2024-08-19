#include"BoxApp.h"


//1.构建Box
//2.设置更新CSV
//3.PSO设置
//4.Draw






bool BoxApp::Initialize()
{
    Dx12::Initialize();

    CreateCBVDescriptorHeap();
    CreateConstantBuffers();





    return true;;
}

void BoxApp::Update() {



}
void BoxApp::Draw() {

}

void BoxApp::CreateCBVDescriptorHeap()
{
    D3D12_DESCRIPTOR_HEAP_DESC cbvHeapDesc;
    cbvHeapDesc.NumDescriptors = 1;
    cbvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
    cbvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;
    cbvHeapDesc.NodeMask = 0;

    ThrowIfFailed(dx12->mDevice->CreateDescriptorHeap(&cbvHeapDesc,
        IID_PPV_ARGS(&mCbvHeap)));
}


void BoxApp::CreateConstantBuffers() {
    mObjectCB = std::make_unique<UploadBuffer<ObjectConstants>>(dx12->mDevice, 1, true);


    D3D12_GPU_VIRTUAL_ADDRESS cbAddress = mObjectCB->Resource()->GetGPUVirtualAddress();


    D3D12_CONSTANT_BUFFER_VIEW_DESC cbvDesc;
    cbvDesc.BufferLocation = cbAddress;
    cbvDesc.SizeInBytes = mObjectCB->GetElementByteSize();

    dx12->mDevice->CreateConstantBufferView(&cbvDesc, mCbvHeap->GetCPUDescriptorHandleForHeapStart());



}



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE prevInstance,
    _In_  LPSTR cmdLine,
    _In_  int showCmd)
{
    // Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
    BoxApp theApp(hInstance);
    theApp.Initialize();
    theApp.Run();

}

