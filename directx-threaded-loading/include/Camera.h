#pragma once
#include <directxmath.h>
#include "GeometricPrimitive.h"

class Camera{
public:
	Camera();
	~Camera();
	void SetViewport(RECT p_viewPort);
	void Update(float delta);

	DirectX::XMMATRIX g_World;
	DirectX::XMMATRIX g_View;
	DirectX::XMMATRIX g_Projection;
private:
	DirectX::XMVECTOR Eye;
	DirectX::XMVECTOR At;
	DirectX::XMVECTOR Up;

	RECT m_viewPort;
};