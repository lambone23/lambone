#include "CScenePlayDf2.h"

#include "CInput.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTransform.h"
#include "CCamera.h"
#include "CObject.h"

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
		CScene::Initialize();

		object::Instantiate<CRayman>(VectorXY(200.0f, 700.0f), ELayerType::Player);
		object::Instantiate<CBgPlayDf2>(ELayerType::BG);
	}
	void CScenePlayDf2::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneMgr::FnLoadScene(ESceneType::PlayDfBoss);
		}

		CScene::Update();
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
		CCollisionMgr::FnSetLayer(ELayerType::Player, ELayerType::Monster, true);
	}
	void CScenePlayDf2::FnOnExit()
	{
	}













	//CScenePlayDf2::CScenePlayDf2()
	//{
	//}
	//CScenePlayDf2::~CScenePlayDf2()
	//{
	//}
	//void CScenePlayDf2::Initialize()
	//{
	//	mRayman = new CRayman();
	//	mRayman->FnSetName(L"Player_Rayman");
	//	FnAddGameObject(mRayman, ELayerType::Player);

	//	mBgPlayDf2 = new CBgPlayDf2();
	//	mBgPlayDf2->FnSetName(L"PlayDf2");
	//	FnAddGameObject(mBgPlayDf2, ELayerType::BG);

	//	CScene::Initialize();
	//}
	//void CScenePlayDf2::Update()
	//{
	//	CScene::Update();

	//	if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
	//	{
	//		//CSceneMgr::FnLoadScene(ESceneType::PlayDf3);
	//		CSceneMgr::FnLoadScene(ESceneType::PlayDfBoss);
	//	}
	//}
	//void CScenePlayDf2::Render(HDC hdc)
	//{
	//	CScene::Render(hdc);
	//}
	//void CScenePlayDf2::Release()
	//{
	//	CScene::Release();
	//}
	//void CScenePlayDf2::FnOnEnter()
	//{
	//}
	//void CScenePlayDf2::FnOnExit()
	//{
	//}
}