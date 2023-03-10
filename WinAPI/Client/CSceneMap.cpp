//#include "CSceneMap.h"
//
//#include "CInput.h"
//#include "CSceneMgr.h"
//
//namespace yha
//{
//	CSceneMap::CSceneMap()
//	{
//	}
//	CSceneMap::~CSceneMap()
//	{
//	}
//	void CSceneMap::Initialize()
//	{
//		mMapRayman = new CMapRayman();
//		mMapRayman->FnSetName(L"Player_MapRayman");
//		FnAddGameObject(mMapRayman, ELayerType::Player);
//
//		mBgMap = new CBgMap();
//		mBgMap->FnSetName(L"Map");
//		FnAddGameObject(mBgMap, ELayerType::BG);
//
//		CScene::Initialize();
//	}
//	void CSceneMap::Update()
//	{
//		CScene::Update();
//
//		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
//		{
//			//CSceneMgr::FnLoadScene(ESceneType::Loading);
//		}
//	}
//	void CSceneMap::Render(HDC hdc)
//	{
//		CScene::Render(hdc);
//	}
//	void CSceneMap::Release()
//	{
//		CScene::Release();
//	}
//	void CSceneMap::FnOnEnter()
//	{
//	}
//	void CSceneMap::FnOnExit()
//	{
//	}
//}