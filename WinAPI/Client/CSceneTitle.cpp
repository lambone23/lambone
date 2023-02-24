#include "CSceneTitle.h"

#include "CInput.h"
#include "CSceneManager.h"

namespace yha
{
	CSceneTitle::CSceneTitle()
	{
	}
	CSceneTitle::~CSceneTitle()
	{
	}
	void CSceneTitle::Initialize()
	{
		mBgTitle = new CBgTitle();
		mBgTitle->SetName(L"Title");
		FnAddGameObject(mBgTitle, ELayerType::BG);

		CScene::Initialize();
	}
	void CSceneTitle::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::Map);
		}
	}
	void CSceneTitle::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CSceneTitle::Release()
	{
		CScene::Release();
	}
	void CSceneTitle::FnOnEnter()
	{
	}
	void CSceneTitle::FnOnExit()
	{
	}
}