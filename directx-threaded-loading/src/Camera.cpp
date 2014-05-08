#include "Camera.h"
using namespace DirectX;

Camera::Camera(){
	g_World = XMMatrixIdentity();
	Eye = XMVectorSet(0.0f, 0.0f, -6.0f, 0.0f);
    At = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
    Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
    g_View = XMMatrixLookAtLH(Eye, At, Up);
	g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800/600, 0.01f, 100.0f);
}

Camera::~Camera(){

}

void Camera::Update(float delta){
	g_World = XMMatrixRotationY(delta);
}

void Camera::SetViewport(UINT p_width, UINT p_height){
	g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, p_width / (FLOAT)p_height, 0.01f, 100.0f);
}

void Camera::SetLookAt(float x, float y, float z){
	At = XMVectorSet(x, y, z, 0.0f);
	g_View = XMMatrixLookAtLH(Eye, At, Up);
}

void Camera::SetPosition(float x, float y, float z){
	Eye = XMVectorSet(x, y, z, 0.0f);
	g_View = XMMatrixLookAtLH(Eye, At, Up);
}