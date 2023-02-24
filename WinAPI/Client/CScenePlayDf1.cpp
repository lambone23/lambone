#include "CScenePlayDf1.h"

#include "CInput.h"
#include "CSceneManager.h"

namespace yha
{
	CScenePlayDf1::CScenePlayDf1()
	{
	}
	CScenePlayDf1::~CScenePlayDf1()
	{
	}
	void CScenePlayDf1::Initialize()
	{
		mRayman = new CRayman();
		mRayman->SetName(L"Player_Rayman");
		FnAddGameObject(mRayman, ELayerType::Player);

		mBgPlayDf1 = new CBgPlayDf1();
		mBgPlayDf1->SetName(L"PlayDf1");
		FnAddGameObject(mBgPlayDf1, ELayerType::BG);

		CScene::Initialize();
	}
	void CScenePlayDf1::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::PlayDf2);
		}
	}
	void CScenePlayDf1::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CScenePlayDf1::Release()
	{
		CScene::Release();
	}
	void CScenePlayDf1::FnOnEnter()
	{
	}
	void CScenePlayDf1::FnOnExit()
	{
	}
}