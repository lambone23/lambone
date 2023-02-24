#include "CSceneEnding.h"

#include "CInput.h"
#include "CSceneManager.h"

namespace yha
{
	CSceneEnding::CSceneEnding()
	{
	}
	CSceneEnding::~CSceneEnding()
	{
	}
	void CSceneEnding::Initialize()
	{
		mBgEnding = new CBgEnding();
		mBgEnding->SetName(L"Ending");
		FnAddGameObject(mBgEnding, ELayerType::BG);

		CScene::Initialize();
	}
	void CSceneEnding::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::Title);
		}
	}
	void CSceneEnding::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CSceneEnding::Release()
	{
		CScene::Release();
	}
	void CSceneEnding::FnOnEnter()
	{
	}
	void CSceneEnding::FnOnExit()
	{
	}
}