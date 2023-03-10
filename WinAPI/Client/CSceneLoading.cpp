//#include "CSceneLoading.h"
//
//#include "CInput.h"
//#include "CSceneMgr.h"
//
//namespace yha
//{
//	CSceneLoading::CSceneLoading()
//	{
//	}
//	CSceneLoading::~CSceneLoading()
//	{
//	}
//	void CSceneLoading::Initialize()
//	{
//		mBgLoading = new CBgLoading();
//		mBgLoading->FnSetName(L"Loading");
//		FnAddGameObject(mBgLoading, ELayerType::BG);
//
//		CScene::Initialize();
//	}
//	void CSceneLoading::Update()
//	{
//		CScene::Update();
//
//		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
//		{
//			//CSceneMgr::FnLoadScene(ESceneType::PlayDf1);
//		}
//	}
//	void CSceneLoading::Render(HDC hdc)
//	{
//		CScene::Render(hdc);
//	}
//	void CSceneLoading::Release()
//	{
//		CScene::Release();
//	}
//	void CSceneLoading::FnOnEnter()
//	{
//	}
//	void CSceneLoading::FnOnExit()
//	{
//	}
//}