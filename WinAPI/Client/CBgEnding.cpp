#include "CBgEnding.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"
#include "CTransform.h"

namespace yha
{
	CBgEnding::CBgEnding()
	{

	}
	CBgEnding::~CBgEnding()
	{
	}
	void CBgEnding::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"Ending", L"..\\Resources\\04_Ending.bmp");

		CGameObject::Initialize();
	}
	void CBgEnding::Update()
	{
		CGameObject::Update();
	}
	void CBgEnding::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		CTransform* Tr = FnGetComponent<CTransform>();
		VectorXY Pos = Tr->FnGetPos();

		BitBlt(hdc, Pos.X, Pos.Y,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgEnding::Release()
	{
		CGameObject::Release();
	}
}
