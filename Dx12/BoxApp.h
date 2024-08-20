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
    DirectX::XMFLOAT3 Pos;
    DirectX::XMFLOAT4 Color;
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


    DirectX::XMFLOAT4X4 mWorld = MathHelper::Identity4x4();
    DirectX::XMFLOAT4X4 mView = MathHelper::Identity4x4();
    DirectX::XMFLOAT4X4 mProj = MathHelper::Identity4x4();

    float mTheta = 1.5f * DirectX::XM_PI;
    float mPhi = DirectX::XM_PIDIV4;
    float mRadius = 5.0f;
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











