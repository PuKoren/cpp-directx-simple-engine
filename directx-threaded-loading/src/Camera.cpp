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

void Camera::SetViewport(RECT p_viewPort){
	m_viewPort = p_viewPort;
	g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, m_viewPort.right - m_viewPort.left / m_viewPort.bottom - m_viewPort.top, 0.01f, 100.0f);
}

Camera::~Camera(){

}

void Camera::Update(float delta){
	g_World = XMMatrixRotationY(delta);
}