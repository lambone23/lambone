#pragma once
#include "CEngine.h"

namespace yha
{
	enum class EKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
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

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		inline static EKeyState FnGetKeyState(EKeyCode KeyCode)
		{
			return mKeys[(UINT)KeyCode].state;
		};

	private:
		static std::vector<Key> mKeys;
	};
}
