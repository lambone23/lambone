#include "CSceneMap.h"

#include "CInput.h"
#include "CSceneManager.h"

namespace yha
{
	CSceneMap::CSceneMap()
	{
	}
	CSceneMap::~CSceneMap()
	{
	}
	void CSceneMap::Initialize()
	{
		mMapRayman = new CMapRayman();
		mMapRayman->SetName(L"Player_MapRayman");
		FnAddGameObject(mMapRayman, ELayerType::Player);

		mBgMap = new CBgMap();
		mBgMap->SetName(L"Map");
		FnAddGameObject(mBgMap, ELayerType::BG);

		CScene::Initialize();
	}
	void CSceneMap::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneManager::FnLoadScene(ESceneType::Loading);
		}
	}
	void CSceneMap::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CSceneMap::Release()
	{
		CScene::Release();
	}
	void CSceneMap::FnOnEnter()
	{
	}
	void CSceneMap::FnOnExit()
	{
	}
}