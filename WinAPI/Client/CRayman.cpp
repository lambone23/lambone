#include "CRayman.h"
#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"

namespace yha
{
	CRayman::CRayman()
	{
	}
	CRayman::~CRayman()
	{
	}
	void CRayman::Initialize()
	{
		CGameObject::Initialize();
	}
	void CRayman::Update()
	{
		CGameObject::Update();

		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mPos.X -= 100.0f * CTime::FnDeltaTime();
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mPos.X += 100.0f * CTime::FnDeltaTime();
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mPos.Y -= 100.0f * CTime::FnDeltaTime();
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mPos.Y += 100.0f * CTime::FnDeltaTime();
		}


		if (CInput::FnGetKeyState(EKeyCode::A) == EKeyState::Pressed)
		{
			mPos.X -= 100.0f * CTime::FnDeltaTime();
		}

		if (CInput::FnGetKeyState(EKeyCode::D) == EKeyState::Pressed)
		{
			mPos.X += 100.0f * CTime::FnDeltaTime();
		}

		if (CInput::FnGetKeyState(EKeyCode::W) == EKeyState::Pressed)
		{
			mPos.Y -= 100.0f * CTime::FnDeltaTime();
		}

		if (CInput::FnGetKeyState(EKeyCode::S) == EKeyState::Pressed)
		{
			mPos.Y += 100.0f * CTime::FnDeltaTime();
		}
	}//END - void CRayman::Update()
	void CRayman::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		// stock 오브젝트
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		//Rectangle(mHdc, -1, -1, 1601, 901);

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		Rectangle(hdc, mPos.X, mPos.Y, mPos.X + 100, mPos.Y + 100);

		SelectObject(hdc, oldPen);
		DeleteObject(pen);
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}
	void CRayman::Release()
	{
		CGameObject::Release();
	}
}