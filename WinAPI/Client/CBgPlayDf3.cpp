#include "CBgPlayDf3.h"

#include "CTime.h"
#include "CSceneManager.h"
#include "CInput.h"
#include "CResources.h"

namespace yha
{
	CBgPlayDf3::CBgPlayDf3()
	{

	}
	CBgPlayDf3::~CBgPlayDf3()
	{
	}
	void CBgPlayDf3::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"PlayDf3", L"..\\Resources\\30_DreamForest3.bmp");

		CGameObject::Initialize();
	}
	void CBgPlayDf3::Update()
	{
		CGameObject::Update();
	}
	void CBgPlayDf3::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		BitBlt(hdc, 0, 0,
			mImage->FnGetWidth(), mImage->FnGetHeight(),
			mImage->FnGetHdc(), 0, 0, SRCCOPY);

	}
	void CBgPlayDf3::Release()
	{
		CGameObject::Release();
	}
}
