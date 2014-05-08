#include "GraphicObject.h"
using namespace DirectX;
using namespace GameEngine;

GraphicObject::GraphicObject(ID3D11Device* p_d3dd){
	m_d3dd = p_d3dd;
	m_pTexture = nullptr;
}

GraphicObject::GraphicObject(ID3D11Device* p_d3dd, wchar_t* p_TextureName){
	HRESULT hr = S_OK;
	m_d3dd = p_d3dd;
	//m_Model = nullptr;
	m_pTexture = nullptr;
	hr = CreateDDSTextureFromFile(m_d3dd, p_TextureName, nullptr, &m_pTexture);
	if(FAILED(hr))
		m_pTexture = nullptr;
}

GraphicObject::GraphicObject(ID3D11Device* p_d3dd, wchar_t* p_TextureName,  wchar_t* p_ModelName){
	HRESULT hr = S_OK;
	m_d3dd = p_d3dd;
	//m_Model = nullptr;
	m_pTexture = nullptr;

	hr = CreateDDSTextureFromFile(m_d3dd, p_TextureName, nullptr, &m_pTexture);
	if(FAILED(hr))
		m_pTexture = nullptr;

	/*EffectFactory tmpFactory(m_d3dd);
	m_Model = Model::CreateFromSDKMESH(p_d3dd, p_ModelName, tmpFactory, true);*/
}