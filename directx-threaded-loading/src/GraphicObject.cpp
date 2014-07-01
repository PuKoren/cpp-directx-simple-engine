#include "GraphicObject.h"
using namespace DirectX;
using namespace GameEngine;

GraphicObject::GraphicObject(){

}

GraphicObject::~GraphicObject(){

}

GraphicObject::GraphicObject(const GraphicObject& p_go){

}

/*
GraphicObject::GraphicObject(ID3D11Device* p_d3dd, ID3D11DeviceContext* p_d3ddcontext){
	m_d3dd = p_d3dd;
	m_pTexture = nullptr;
	m_d3ddcontext = p_d3ddcontext;
	m_FXFactory.reset(new EffectFactory(p_d3dd));
	m_States.reset(new CommonStates(p_d3dd));

	SetScale(0.01f, 0.01f, 0.01f);
}

GraphicObject::GraphicObject(ID3D11Device* p_d3dd, ID3D11DeviceContext* p_d3ddcontextn, wchar_t* p_TextureName){
	HRESULT hr = S_OK;
	m_d3dd = p_d3dd;
	m_d3ddcontext = p_d3ddcontextn;
	//m_Model = nullptr;
	m_pTexture = nullptr;
	hr = CreateDDSTextureFromFile(m_d3dd, p_TextureName, nullptr, &m_pTexture);
	if(FAILED(hr))
		m_pTexture = nullptr;
	m_FXFactory.reset(new EffectFactory(p_d3dd));
	m_States.reset(new CommonStates(p_d3dd));

	SetScale(0.01f, 0.01f, 0.01f);
}
*/
GraphicObject::GraphicObject(ID3D11Device* p_d3dd, ID3D11DeviceContext* p_d3ddcontext, wchar_t* p_TextureName,  wchar_t* p_ModelName, std::vector<GraphicObject*>* objList){
	m_d3dd = p_d3dd;
	m_d3ddcontext = p_d3ddcontext;
	//m_Model = nullptr;
	m_pTexture = nullptr;
    m_TextureName = p_TextureName;
    m_ModelName = p_ModelName;
    m_objList = objList;
}

void GraphicObject::run(){
    HRESULT hr = S_OK;
	hr = CreateDDSTextureFromFile(m_d3dd, m_TextureName, nullptr, &m_pTexture);
	if(FAILED(hr))
		m_pTexture = nullptr;

	m_FXFactory.reset(new EffectFactory(m_d3dd));
	m_Model = Model::CreateFromSDKMESH(m_d3dd, m_ModelName, *m_FXFactory, true);
	m_States.reset(new CommonStates(m_d3dd));
    
	SetScale((rand()%10)/100.f, (rand()%10)/100.f, (rand()%10)/100.f);
    m_objList->push_back(dynamic_cast<GraphicObject*>(this));
}

GraphicObject& GraphicObject::operator=(const GraphicObject& rhs){

	return *this;
}

void GraphicObject::SetScale(float x, float y, float z){
	m_scale.f[0] = x;
	m_scale.f[1] = y;
	m_scale.f[2] = z;
}

void GraphicObject::Update(float dt){

}

void GraphicObject::Draw(GameEngine::Camera* cam){
	XMMATRIX local = XMMatrixMultiply(cam->g_World, XMMatrixTranslation(-2.f, -2.f, 4.f));
	XMVECTOR qid = XMQuaternionIdentity();
    const XMVECTORF32 translate = { 3.f, -2.f, 4.f };
    XMVECTOR rotate = XMQuaternionRotationRollPitchYaw(45.f, XM_PI/2.f, XM_PI/2.f);
	local = XMMatrixMultiply(cam->g_World, XMMatrixTransformation(g_XMZero, qid, m_scale, g_XMZero, rotate, translate));
    this->m_Model->Draw(m_d3ddcontext, *m_States, local, cam->g_View, cam->g_Projection);
}