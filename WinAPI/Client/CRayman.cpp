#include "CRayman.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"

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
		mImage = CResources::FnLoad<CImage>(L"Player_MapRayman", L"..\\Resources\\BmpRaymanR.bmp");

		CGameObject::Initialize();
	}
	void CRayman::Update()
	{
		CGameObject::Update();

		CTransform* Tr = FnGetComponent<CTransform>();
		VectorXY Pos = Tr->FnGetPos();

		if (CInput::FnGetKeyState(EKeyCode::A) == EKeyState::Pressed)
		{
			Pos.X -= 100.0f * CTime::FnDeltaTime();
		}

		if (CInput::FnGetKeyState(EKeyCode::D) == EKeyState::Pressed)
		{
			Pos.X += 100.0f * CTime::FnDeltaTime();
		}

		if (CInput::FnGetKeyState(EKeyCode::W) == EKeyState::Pressed)
		{
			Pos.Y -= 100.0f * CTime::FnDeltaTime();
		}

		if (CInput::FnGetKeyState(EKeyCode::S) == EKeyState::Pressed)
		{
			Pos.Y += 100.0f * CTime::FnDeltaTime();
		}
		Tr->FnSetPos(Pos);
	}
	void CRayman::Render(HDC hdc)
	{
		CGameObject::Render(hdc);
		CTransform* Tr = FnGetComponent<CTransform>();
		VectorXY Pos = Tr->FnGetPos();
		BitBlt(hdc, Pos.X, Pos.Y,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);
	}
	void CRayman::Release()
	{
		CGameObject::Release();
	}
}