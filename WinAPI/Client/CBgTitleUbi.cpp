#include "CBgTitleUbi.h"

#include "CTime.h"
#include "CSceneMgr.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"

namespace yha
{
	CBgTitleUbi::CBgTitleUbi()
	{

	}
	CBgTitleUbi::~CBgTitleUbi()
	{
	}
	void CBgTitleUbi::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"TitleUbi", L"..\\Resources\\BG\\00_Logo.bmp");
		//mImage = CResources::FnLoad<CImage>(L"TitleUbi", L"..\\Resources\\00_Logo.bmp");

		CGameObject::Initialize();
	}
	void CBgTitleUbi::Update()
	{
		CGameObject::Update();
	}
	void CBgTitleUbi::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		CTransform* Tr = FnGetComponent<CTransform>();
		VectorXY Pos = Tr->FnGetPos();

		BitBlt(hdc, Pos.X, Pos.Y,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgTitleUbi::Release()
	{
		CGameObject::Release();
	}
}
