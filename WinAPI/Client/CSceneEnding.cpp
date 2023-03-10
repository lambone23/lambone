#include "CSceneEnding.h"

#include "CInput.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTransform.h"
#include "CCamera.h"
#include "CObject.h"

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
		CScene::Initialize();

		//object::Instantiate<CRayman>(VectorXY(400.0f, 400.0f), ELayerType::Player);
		object::Instantiate<CBgEnding>(ELayerType::BG);
		//object::Instantiate<Monster>(VectorXY(500.0f, 500.0f), ELayerType::Monster);
	}
	void CSceneEnding::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneMgr::FnLoadScene(ESceneType::Title);
		}

		CScene::Update();
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
		CCollisionMgr::FnSetLayer(ELayerType::Player, ELayerType::Monster, true);
	}
	void CSceneEnding::FnOnExit()
	{
	}















	//CSceneEnding::CSceneEnding()
	//{
	//}
	//CSceneEnding::~CSceneEnding()
	//{
	//}
	//void CSceneEnding::Initialize()
	//{
	//	mBgEnding = new CBgEnding();
	//	mBgEnding->FnSetName(L"Ending");
	//	FnAddGameObject(mBgEnding, ELayerType::BG);

	//	CScene::Initialize();
	//}
	//void CSceneEnding::Update()
	//{
	//	CScene::Update();

	//	if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
	//	{
	//		CSceneMgr::FnLoadScene(ESceneType::Title);
	//	}
	//}
	//void CSceneEnding::Render(HDC hdc)
	//{
	//	CScene::Render(hdc);
	//}
	//void CSceneEnding::Release()
	//{
	//	CScene::Release();
	//}
	//void CSceneEnding::FnOnEnter()
	//{
	//}
	//void CSceneEnding::FnOnExit()
	//{
	//}
}