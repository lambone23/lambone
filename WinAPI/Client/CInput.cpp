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
				// ���� �����ӿ��� ���� �־���
				if (mKeys[i].bPressed)
					mKeys[i].state = EKeyState::Pressed;
				else
					mKeys[i].state = EKeyState::Down;

				mKeys[i].bPressed = true;
			}
			else // ���� �����ӿ� Ű�� �������� �ʴ�.
			{
				// ���� �����ӿ� ��Ű�� �����־���.
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
