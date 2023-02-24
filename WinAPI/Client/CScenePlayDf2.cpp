#include "CScenePlayDf2.h"

#include "CInput.h"
#include "CSceneManager.h"

namespace yha
{
	CScenePlayDf2::CScenePlayDf2()
	{
	}
	CScenePlayDf2::~CScenePlayDf2()
	{
	}
	void CScenePlayDf2::Initialize()
	{
		mRayman = new CRayman();
		mRayman->SetName(L"Player_Rayman");
		FnAddGameObject(mRayman, ELayerType::Player);

		mBgPlayDf2 = new CBgPlayDf2();
		mBgPlayDf2->SetName(L"PlayDf2");
		FnAddGameObject(mBgPlayDf2, ELayerType::BG);

		CScene::Initialize();
	}
	void CScenePlayDf2::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::PlayDf3);
		}
	}
	void CScenePlayDf2::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CScenePlayDf2::Release()
	{
		CScene::Release();
	}
	void CScenePlayDf2::FnOnEnter()
	{
	}
	void CScenePlayDf2::FnOnExit()
	{
	}
}