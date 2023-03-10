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

		// FnGetKey()		Ű�� ������ �ð���ŭ true�� ��ȯ
		// FnGetKeyDown()	Ű�� ������ ��, �� �ѹ� true�� ��ȯ
		// FnGetKeyUp()		Ű�� ������ ���� ��, �� �ѹ� true�� ��ȯ

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
