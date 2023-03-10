//#include "CScenePlayDf3.h"
//
//#include "CInput.h"
//#include "CSceneMgr.h"
//
//namespace yha
//{
//	CScenePlayDf3::CScenePlayDf3()
//	{
//	}
//	CScenePlayDf3::~CScenePlayDf3()
//	{
//	}
//	void CScenePlayDf3::Initialize()
//	{
//		mRayman = new CRayman();
//		mRayman->FnSetName(L"Player_Rayman");
//		FnAddGameObject(mRayman, ELayerType::Player);
//
//		mBgPlayDf3 = new CBgPlayDf3();
//		mBgPlayDf3->FnSetName(L"PlayDf3");
//		FnAddGameObject(mBgPlayDf3, ELayerType::BG);
//
//		CScene::Initialize();
//	}
//	void CScenePlayDf3::Update()
//	{
//		CScene::Update();
//
//		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
//		{
//			CSceneMgr::FnLoadScene(ESceneType::PlayDfBoss);
//		}
//	}
//	void CScenePlayDf3::Render(HDC hdc)
//	{
//		CScene::Render(hdc);
//	}
//	void CScenePlayDf3::Release()
//	{
//		CScene::Release();
//	}
//	void CScenePlayDf3::FnOnEnter()
//	{
//	}
//	void CScenePlayDf3::FnOnExit()
//	{
//	}
//}