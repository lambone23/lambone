#include "CInput.h"

namespace yha
{
	int ASCII[(UINT)EKeyCode::END] =
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	};

	std::vector<CInput::Key> CInput::mKeys;

	void CInput::Initialize()
	{
		for (UINT i = 0; i < (UINT)EKeyCode::END; i++)
		{
			Key keyInfo;
			keyInfo.key = (EKeyCode)i;
			keyInfo.state = EKeyState::None;
			keyInfo.bPressed = false;

			mKeys.push_back(keyInfo);
		}
	}

	void CInput::Update()
	{
		for (UINT i = 0; i < (UINT)EKeyCode::END; i++)
		{
			if (GetAsyncKeyState(ASCII[i]) & 0x8000)
			{
				// 이전 프레임에도 눌려 있었다
				if (mKeys[i].bPressed)
					mKeys[i].state = EKeyState::Pressed;
				else
					mKeys[i].state = EKeyState::Down;

				mKeys[i].bPressed = true;
			}
			else // 현재 프레임에 키가 눌려있지 않다.
			{
				// 이전 프레임에 내키가 눌려있엇다.
				if (mKeys[i].bPressed)
					mKeys[i].state = EKeyState::Up;
				else
					mKeys[i].state = EKeyState::None;

				mKeys[i].bPressed = false;
			}
		}
	}

	void CInput::Render(HDC hdc)
	{

	}
}
