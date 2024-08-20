#pragma once
#include"Dx12.h"
#include"UploadBuffer.h"

//1.构建Box
//2.设置更新CSV
//3.PSO设置
//4.Draw


//常量对象
struct ObjectConstants
{
    DirectX::XMFLOAT4X4 WorldViewProj = MathHelper::Identity4x4();
};

struct Vertex
{
    XMFLOAT3 Pos;
    XMFLOAT4 Color;
};



class BoxApp :public Dx12 {

public:

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mCbvHeap;
    std::unique_ptr<MeshGeometry> mBoxGeo = nullptr;




    std::unique_ptr<UploadBuffer<ObjectConstants>> mObjectCB = nullptr;

    Microsoft::WRL::ComPtr<ID3D12RootSignature> mRootSignature = nullptr;
    Microsoft::WRL::ComPtr<ID3DBlob> mvsByteCode;
    Microsoft::WRL::ComPtr<ID3DBlob> mpsByteCode;

    std::vector< D3D12_INPUT_ELEMENT_DESC> mInputLayout;
    Microsoft::WRL::ComPtr<ID3D12PipelineState> mPso;
public:
    BoxApp(HINSTANCE hInstance) :Dx12(hInstance) {
        ;
    }

    bool Initialize();


    void Update()override;
    void Draw()override;
    


private:
    void CreateCBVDescriptorHeap();
    void CreateConstantBuffers();
    void CreateRootSignature();
    void BuildShadersAndInputLayout();
    void BuildBoxGeometry();
    void BuildPSO();
};








