#pragma once
#include"Dx12.h"
#include"UploadBuffer.h"

//1.����Box
//2.���ø���CSV
//3.PSO����
//4.Draw


//��������
struct ObjectConstants
{
    DirectX::XMFLOAT4X4 WorldViewProj = MathHelper::Identity4x4();
};


class BoxApp :public Dx12 {

public:

    Microsoft::WRL::ComPtr<ID3D12DescriptorHeap> mCbvHeap;
    std::unique_ptr<MeshGeometry> mBoxGeo = nullptr;




    std::unique_ptr<UploadBuffer<ObjectConstants>> mObjectCB = nullptr;

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

};








