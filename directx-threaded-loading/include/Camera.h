#pragma once
#include <directxmath.h>
#include "GeometricPrimitive.h"

class Camera{
public:
	Camera();
	~Camera();

	bool Input();
	void Update(float delta);
	void SetFieldOfView(float radians);
	void SetLookAt(float x, float y, float z);
	void SetPosition(float x, float y, float z);
	void SetViewport(UINT p_width, UINT p_height);

	DirectX::XMMATRIX g_World;
	DirectX::XMMATRIX g_View;
	DirectX::XMMATRIX g_Projection;
private:
	DirectX::XMVECTOR Eye;
	DirectX::XMVECTOR At;
	DirectX::XMVECTOR Up;
};