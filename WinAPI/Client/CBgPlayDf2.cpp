#include "CBgPlayDf2.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"

namespace yha
{
	CBgPlayDf2::CBgPlayDf2()
	{

	}
	CBgPlayDf2::~CBgPlayDf2()
	{
	}
	void CBgPlayDf2::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"PlayDf2", L"..\\Resources\\20_DreamForest2.bmp");

		CGameObject::Initialize();
	}
	void CBgPlayDf2::Update()
	{
		CGameObject::Update();
	}
	void CBgPlayDf2::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		BitBlt(hdc, 0, 0,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgPlayDf2::Release()
	{
		CGameObject::Release();
	}
}
