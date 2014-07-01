#pragma once
#include <d3d11.h>
#include "DDSTextureLoader.h"
#include "CommonStates.h"
#include "Model.h"
#include "Effects.h"
#include "Camera.h"
#include "Job.h"

namespace GameEngine{
	class GraphicObject: public Job{
	public:
		GraphicObject();
		GraphicObject(const GraphicObject&);
		/*GraphicObject(ID3D11Device* p_d3dd, ID3D11DeviceContext* p_d3ddcontext);
		GraphicObject(ID3D11Device* p_d3dd, ID3D11DeviceContext* p_d3ddcontext, wchar_t* p_TextureName);*/
		GraphicObject(ID3D11Device* p_d3dd, ID3D11DeviceContext* p_d3ddcontext, wchar_t* p_TextureName, wchar_t* p_ModelName, std::vector<GraphicObject*>* objList);
		~GraphicObject();

		void Draw(GameEngine::Camera* cam);
		void Update(float dt);
		void SetScale(float x, float y, float z);
        void run();

		GraphicObject& operator=(const GraphicObject& rhs);

	private:
		ID3D11Device* m_d3dd;
		ID3D11DeviceContext* m_d3ddcontext;
		ID3D11ShaderResourceView* m_pTexture;
        wchar_t* m_TextureName;
        wchar_t* m_ModelName;

		DirectX::XMVECTORF32 m_scale;

		std::unique_ptr<DirectX::EffectFactory> m_FXFactory;
		std::unique_ptr<DirectX::CommonStates> m_States;
		std::unique_ptr<DirectX::Model> m_Model;
        std::vector<GraphicObject*>* m_objList;
	};
}