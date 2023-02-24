#include "CSceneTitleUbi.h"

#include "CInput.h"
#include "CSceneManager.h"


namespace yha
{
	CSceneTitleUbi::CSceneTitleUbi()
	{
	}
	CSceneTitleUbi::~CSceneTitleUbi()
	{
	}
	void CSceneTitleUbi::Initialize()
	{
		mBgTitleUbi = new CBgTitleUbi();
		mBgTitleUbi->SetName(L"TitleUbi");
		FnAddGameObject(mBgTitleUbi, ELayerType::BG);

		CScene::Initialize();
	}
	void CSceneTitleUbi::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::Title);
		}
	}
	void CSceneTitleUbi::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CSceneTitleUbi::Release()
	{
		CScene::Release();
	}
	void CSceneTitleUbi::FnOnEnter()
	{
	}
	void CSceneTitleUbi::FnOnExit()
	{
	}
}