#pragma once
#include "CEngine.h"

namespace yha
{
	enum class EKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,

		UP, DOWN, LEFT, RIGHT,
		END,
	};

	enum class EKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};

	class CInput
	{
	public:
		struct Key
		{
			EKeyCode key;
			EKeyState state;
			bool bPressed;
		};

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

	public:
		inline static EKeyState FnGetKeyState(EKeyCode KeyCode)
		{
			return mKeys[(UINT)KeyCode].state;
		};

		// FnGetKey()		키를 누르는 시간만큼 true를 반환
		// FnGetKeyDown()	키를 눌렀을 때, 딱 한번 true를 반환
		// FnGetKeyUp()		키를 누르다 땠을 때, 딱 한번 true를 반환

		static __forceinline bool FnGetKey(EKeyCode KeyCode)
		{
			return mKeys[static_cast<UINT>(KeyCode)].state == EKeyState::Pressed;
		}

		static __forceinline bool FnGetKeyDown(EKeyCode KeyCode)
		{
			return mKeys[static_cast<UINT>(KeyCode)].state == EKeyState::Down;
		}

		static __forceinline bool FnGetKeyUp(EKeyCode KeyCode)
		{
			return mKeys[static_cast<UINT>(KeyCode)].state == EKeyState::Up;
		}

	private:
		static std::vector<Key> mKeys;
	};
}
