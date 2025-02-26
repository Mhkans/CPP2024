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

Vector ShaderResourceView::GetSize()
{
    if (image.GetImageCount() == 0) {
        return Vector(0, 0);
    }
    float x = image.GetMetadata().width;
    float y = image.GetMetadata().height;

    return Vector(x,y);
}
