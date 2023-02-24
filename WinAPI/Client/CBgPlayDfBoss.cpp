#include "CBgPlayDfBoss.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"

namespace yha
{
	CBgPlayDfBoss::CBgPlayDfBoss()
	{

	}
	CBgPlayDfBoss::~CBgPlayDfBoss()
	{
	}
	void CBgPlayDfBoss::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"PlayDfBoss", L"..\\Resources\\40_DreamForestBoss.bmp");

		CGameObject::Initialize();
	}
	void CBgPlayDfBoss::Update()
	{
		CGameObject::Update();
	}
	void CBgPlayDfBoss::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		BitBlt(hdc, 0, 0,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgPlayDfBoss::Release()
	{
		CGameObject::Release();
	}
}
