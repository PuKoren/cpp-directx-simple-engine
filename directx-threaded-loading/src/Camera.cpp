#include "Camera.h"
using namespace DirectX;
using namespace GameEngine;

Camera::Camera(){
	g_World = XMMatrixIdentity();
	Eye = XMVectorSet(0.0f, 0.0f, -6.0f, 0.0f);
    At = XMVectorSet(0.0f, 0.0f, 0.0f, 0.0f);
    Up = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
    g_View = XMMatrixLookAtLH(Eye, At, Up);
	g_Projection = XMMatrixPerspectiveFovLH(XM_PIDIV4, 800/600, 0.01f, 100.0f);

	state = CameraState::NONE;
	pos.x = 0.f;
	pos.y = 0.f;
	pos.z = -6.f;

	g_View = XMMatrixLookAtLH(Eye, At, Up);
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

void Camera::Update(float delta){
	
	CameraState::pos prevPos = pos;

	if((state & CameraState::MOVE_LEFT) == CameraState::MOVE_LEFT){
		pos.x -= 0.001f * delta;
	}else if((state & CameraState::MOVE_RIGHT) == CameraState::MOVE_RIGHT){
		pos.x += 0.001f * delta;
	}else if((state & CameraState::MOVE_UP) == CameraState::MOVE_UP){
		pos.y += 0.001f * delta;
	}else if((state & CameraState::MOVE_DOWN) == CameraState::MOVE_DOWN){
		pos.y -= 0.001f * delta;
	}else if((state & CameraState::MOVE_FORWARD) == CameraState::MOVE_FORWARD){
		pos.z += 0.001f * delta;
	}else if((state & CameraState::MOVE_BACKWARD) == CameraState::MOVE_BACKWARD){
		pos.z -= 0.001f * delta;
	}

	if(prevPos.x != pos.x || prevPos.y != pos.y || prevPos.z != pos.z){
		Eye = XMVectorSet(pos.x, pos.y, pos.z, 0.0f);
		g_View = XMMatrixLookAtLH(Eye, At, Up);
	}
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