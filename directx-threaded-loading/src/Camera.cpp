#include "Camera.h"
using namespace DirectX;
using namespace GameEngine;

Camera::Camera(){
	g_World = XMMatrixIdentity();
	Eye = XMVectorSet(0.0f, 0.0f, -6.0f, 0.0f);
    At = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
    Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
    g_View = XMMatrixLookAtLH(Eye, At, Up);
	g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800/600, 0.01f, 100.0f);

	m_speed = 1.f;

	state = CameraState::NONE;
}

Camera::~Camera(){

}

bool Camera::Input(UINT message, WPARAM wParam){
	switch(message){
		case WM_KEYDOWN:
			switch(wParam){
				case VK_LEFT:
					state = state | CameraState::MOVE_LEFT;
					break;
				case VK_RIGHT:
					state = state | CameraState::MOVE_RIGHT;
					break;
				case VK_UP:
					state = state | CameraState::MOVE_FORWARD;
					break;
				case VK_DOWN:
					state = state | CameraState::MOVE_BACKWARD;
					break;
				case VK_SHIFT:
					state = state | CameraState::MOVE_UP;
					break;
				case VK_CONTROL:
					state = state | CameraState::MOVE_DOWN;
					break;
			};
			break;
		case WM_KEYUP:
			switch(wParam){
				case VK_LEFT:
					state = state &~ CameraState::MOVE_LEFT;
					break;
				case VK_RIGHT:
					state = state &~ CameraState::MOVE_RIGHT;
					break;
				case VK_UP:
					state = state &~ CameraState::MOVE_FORWARD;
					break;
				case VK_DOWN:
					state = state &~ CameraState::MOVE_BACKWARD;
					break;
				case VK_SHIFT:
					state = state &~ CameraState::MOVE_UP;
					break;
				case VK_CONTROL:
					state = state &~ CameraState::MOVE_DOWN;
					break;
			};
			break;
	};
	return false;
}

void Camera::SetSpeed(float p_speed){
	m_speed = m_speed;
}

void Camera::Update(float delta){
	DirectX::XMVECTOR command;
	command.m128_f32[0] = 0.f;command.m128_f32[1] = 0.f;command.m128_f32[2] = 0.f;command.m128_f32[3] = 0.f;

	if((state & CameraState::MOVE_LEFT) == CameraState::MOVE_LEFT){
		command.m128_f32[0] -= m_speed * delta;
	}
	if((state & CameraState::MOVE_RIGHT) == CameraState::MOVE_RIGHT){
		command.m128_f32[0] += m_speed * delta;
	}
	if((state & CameraState::MOVE_UP) == CameraState::MOVE_UP){
		command.m128_f32[1] += m_speed * delta;
	}
	if((state & CameraState::MOVE_DOWN) == CameraState::MOVE_DOWN){
		command.m128_f32[1] -= m_speed * delta;
	}
	if((state & CameraState::MOVE_FORWARD) == CameraState::MOVE_FORWARD){
		command.m128_f32[2] += m_speed * delta;
	}
	if((state & CameraState::MOVE_BACKWARD) == CameraState::MOVE_BACKWARD){
		command.m128_f32[2] -= m_speed * delta;
	}

	if(command.m128_f32[0] != 0.f || command.m128_f32[1] != 0.f || command.m128_f32[2] != 0.f){
		Eye.m128_f32[0] += command.m128_f32[0];
		Eye.m128_f32[1] += command.m128_f32[1];
		Eye.m128_f32[2] += command.m128_f32[2];

		g_View = XMMatrixLookAtLH(Eye, At, Up);
	}
}

void Camera::SetViewport(UINT p_width, UINT p_height, float pnear, float pfar){
    g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, ((FLOAT)p_width / (FLOAT)p_height), pnear, pfar);
}

void Camera::SetLookAt(float x, float y, float z){
	At = XMVectorSet(x, y, z, 0.0f);
	g_View = XMMatrixLookAtLH(Eye, At, Up);
}

void Camera::SetPosition(float x, float y, float z){
	Eye = XMVectorSet(x, y, z, 0.0f);
	g_View = XMMatrixLookAtLH(Eye, At, Up);
}