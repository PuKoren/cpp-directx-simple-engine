#pragma once
#include <directxmath.h>
#include "GeometricPrimitive.h"

namespace GameEngine{

	namespace CameraState{
		enum State{
			NONE = 0x01,
			MOVE_LEFT = 0x02,
			MOVE_RIGHT = 0x04,
			MOVE_UP = 0x08,
			MOVE_DOWN = 0x10,
			MOVE_FORWARD = 0x20,
			MOVE_BACKWARD = 0x40
		};

		struct pos{
			float x;
			float y;
			float z;
		};
	}

	class Camera{
	public:
		Camera();
		~Camera();

		bool Input(UINT message, WPARAM wParam);
	
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

		DWORD state;
		CameraState::pos pos;
	};
}