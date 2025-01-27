#include "framework.h"
#include "ShaderResourceView.h"

ShaderResourceView::ShaderResourceView(wstring file)
{
   
    LoadFromWICFile(file.c_str(), WIC_FLAGS_NONE, nullptr, image);

    CreateShaderResourceView(DEVICE.Get(), image.GetImages(), image.GetImageCount(), image.GetMetadata(),
        IN _srv.ReleaseAndGetAddressOf());

    
}

ShaderResourceView::~ShaderResourceView()
{
    image.Release();
}

void ShaderResourceView::PSSet(int slot)
{
    DC->PSSetShaderResources(slot, 1, _srv.GetAddressOf());
}
