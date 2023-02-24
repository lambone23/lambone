#include "CScenePlayDfBoss.h"

#include "CInput.h"
#include "CSceneManager.h"

namespace yha
{
	CScenePlayDfBoss::CScenePlayDfBoss()
	{
	}
	CScenePlayDfBoss::~CScenePlayDfBoss()
	{
	}
	void CScenePlayDfBoss::Initialize()
	{
		mRayman = new CRayman();
		mRayman->SetName(L"Player_Rayman");
		FnAddGameObject(mRayman, ELayerType::Player);

		mBgPlayDfBoss = new CBgPlayDfBoss();
		mBgPlayDfBoss->SetName(L"PlayDfBoss");
		FnAddGameObject(mBgPlayDfBoss, ELayerType::BG);

		CScene::Initialize();
	}
	void CScenePlayDfBoss::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::Ending);
		}
	}
	void CScenePlayDfBoss::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CScenePlayDfBoss::Release()
	{
		CScene::Release();
	}
	void CScenePlayDfBoss::FnOnEnter()
	{
	}
	void CScenePlayDfBoss::FnOnExit()
	{
	}
}