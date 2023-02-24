#include "CBgTitle.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"

namespace yha
{
	CBgTitle::CBgTitle()
	{

	}
	CBgTitle::~CBgTitle()
	{
	}
	void CBgTitle::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"Title", L"..\\Resources\\01_Title.bmp");

		CGameObject::Initialize();
	}
	void CBgTitle::Update()
	{
		CGameObject::Update();
	}
	void CBgTitle::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		CTransform* Tr = FnGetComponent<CTransform>();
		VectorXY Pos = Tr->FnGetPos();

		BitBlt(hdc, Pos.X, Pos.Y,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgTitle::Release()
	{
		CGameObject::Release();
	}
}
