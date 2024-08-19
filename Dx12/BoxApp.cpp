#include"BoxApp.h"


//1.����Box
//2.���ø���CSV
//3.PSO����
//4.Draw




using Microsoft::WRL::ComPtr;

bool BoxApp::Initialize()
{
    Dx12::Initialize();

    CreateCBVDescriptorHeap();
    CreateConstantBuffers();

    CreateRootSignature();



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

void BoxApp::CreateRootSignature()
{
    //��ǩ����
    CD3DX12_ROOT_PARAMETER slotRootParameter[1];

    CD3DX12_ROOT_SIGNATURE_DESC rootSigDesc(1, slotRootParameter, 0, nullptr,
        D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

    ComPtr<ID3DBlob> serializedRootSig = nullptr;
    ComPtr<ID3DBlob> errorBlob = nullptr;

    HRESULT hr = D3D12SerializeRootSignature(&rootSigDesc, D3D_ROOT_SIGNATURE_VERSION_1, serializedRootSig.GetAddressOf(), errorBlob.GetAddressOf());


    dx12->mDevice->CreateRootSignature(0, serializedRootSig->GetBufferPointer(), serializedRootSig->GetBufferSize(), IID_PPV_ARGS(&mRootSignature));

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

