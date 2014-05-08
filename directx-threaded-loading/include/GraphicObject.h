#pragma once
#include <d3d11.h>
#include "DDSTextureLoader.h"
#include "Model.h"
#include "Effects.h"

namespace GameEngine{
	class GraphicObject{
	public:
		GraphicObject(ID3D11Device* p_d3dd);
		GraphicObject(ID3D11Device* p_d3dd, wchar_t* p_TextureName);
		GraphicObject(ID3D11Device* p_d3dd, wchar_t* p_TextureName, wchar_t* p_ModelName);
		~GraphicObject();
	private:
		ID3D11Device* m_d3dd;
		ID3D11ShaderResourceView* m_pTexture;
		
	};
}