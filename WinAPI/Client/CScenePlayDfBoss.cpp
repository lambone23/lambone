#include "CScenePlayDfBoss.h"

#include "CInput.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTransform.h"
#include "CCamera.h"
#include "CObject.h"

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

		CScene::Initialize();
		object::Instantiate<CRayman>(VectorXY(200.0f, 700.0f), ELayerType::Player);
		object::Instantiate<CBgPlayDfBoss>(ELayerType::BG);
	}
	void CScenePlayDfBoss::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneMgr::FnLoadScene(ESceneType::Ending);
		}

		CScene::Update();
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
		CCollisionMgr::FnSetLayer(ELayerType::Player, ELayerType::Monster, true);
	}
	void CScenePlayDfBoss::FnOnExit()
	{
	}











	//CScenePlayDfBoss::CScenePlayDfBoss()
	//{
	//}
	//CScenePlayDfBoss::~CScenePlayDfBoss()
	//{
	//}
	//void CScenePlayDfBoss::Initialize()
	//{
	//	mRayman = new CRayman();
	//	mRayman->FnSetName(L"Player_Rayman");
	//	FnAddGameObject(mRayman, ELayerType::Player);

	//	mBgPlayDfBoss = new CBgPlayDfBoss();
	//	mBgPlayDfBoss->FnSetName(L"PlayDfBoss");
	//	FnAddGameObject(mBgPlayDfBoss, ELayerType::BG);

	//	CScene::Initialize();
	//}
	//void CScenePlayDfBoss::Update()
	//{
	//	CScene::Update();

	//	if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
	//	{
	//		CSceneMgr::FnLoadScene(ESceneType::Ending);
	//	}
	//}
	//void CScenePlayDfBoss::Render(HDC hdc)
	//{
	//	CScene::Render(hdc);
	//}
	//void CScenePlayDfBoss::Release()
	//{
	//	CScene::Release();
	//}
	//void CScenePlayDfBoss::FnOnEnter()
	//{
	//}
	//void CScenePlayDfBoss::FnOnExit()
	//{
	//}
}