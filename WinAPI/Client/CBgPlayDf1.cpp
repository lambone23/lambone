#include "CBgPlayDf1.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"

namespace yha
{
	CBgPlayDf1::CBgPlayDf1()
	{

	}
	CBgPlayDf1::~CBgPlayDf1()
	{
	}
	void CBgPlayDf1::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"PlayDf1", L"..\\Resources\\10_DreamForest1.bmp");

		CGameObject::Initialize();
	}
	void CBgPlayDf1::Update()
	{
		CGameObject::Update();
	}
	void CBgPlayDf1::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		BitBlt(hdc, 0, 0,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgPlayDf1::Release()
	{
		CGameObject::Release();
	}
}
