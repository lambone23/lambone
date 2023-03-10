#include "CScenePlayDf1.h"

#include "CInput.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTransform.h"
#include "CCamera.h"
#include "CObject.h"

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
		CScene::Initialize();

		object::Instantiate<CRayman>(VectorXY(200.0f, 700.0f), ELayerType::Player);
		object::Instantiate<CBlueChomper>(VectorXY(400.0f, 700.0f), ELayerType::Monster);

		object::Instantiate<CBgPlayDf1>(ELayerType::BG);
		object::Instantiate<CBgObjPlayDf1>(ELayerType::BG_Obj);
		
	}
	void CScenePlayDf1::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneMgr::FnLoadScene(ESceneType::PlayDf2);
		}

		CScene::Update();
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
		CCollisionMgr::FnSetLayer(ELayerType::Player, ELayerType::Monster, true);
	}
	void CScenePlayDf1::FnOnExit()
	{
	}



















	//CScenePlayDf1::CScenePlayDf1()
	//{
	//}
	//CScenePlayDf1::~CScenePlayDf1()
	//{
	//}
	//void CScenePlayDf1::Initialize()
	//{
	//	mRayman = new CRayman();
	//	mRayman->FnSetName(L"Player_Rayman");
	//	FnAddGameObject(mRayman, ELayerType::Player);

	//	mBgPlayDf1 = new CBgPlayDf1();
	//	mBgPlayDf1->FnSetName(L"PlayDf1");
	//	FnAddGameObject(mBgPlayDf1, ELayerType::BG);

	//	//mBgObjPlayDf1 = new CBgObjPlayDf1();
	//	//mBgObjPlayDf1->FnSetName(L"PlayDf1_Obj");
	//	//FnAddGameObject(mBgObjPlayDf1, ELayerType::BG_Obj);

	//	CScene::Initialize();
	//}
	//void CScenePlayDf1::Update()
	//{
	//	CScene::Update();

	//	if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
	//	{
	//		CSceneMgr::FnLoadScene(ESceneType::PlayDf2);
	//	}
	//}
	//void CScenePlayDf1::Render(HDC hdc)
	//{
	//	CScene::Render(hdc);
	//}
	//void CScenePlayDf1::Release()
	//{
	//	CScene::Release();
	//}
	//void CScenePlayDf1::FnOnEnter()
	//{
	//}
	//void CScenePlayDf1::FnOnExit()
	//{
	//}
}