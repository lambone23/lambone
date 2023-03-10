#include "CSceneTitle.h"

#include "CInput.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTransform.h"
#include "CCamera.h"
#include "CObject.h"

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
		CScene::Initialize();

		//object::Instantiate<CRayman>(VectorXY(400.0f, 400.0f), ELayerType::Player);
		object::Instantiate<CBgTitle>(ELayerType::BG);
		//object::Instantiate<Monster>(VectorXY(500.0f, 500.0f), ELayerType::Monster);
	}
	void CSceneTitle::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneMgr::FnLoadScene(ESceneType::PlayDf1);
		}

		CScene::Update();
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
		CCollisionMgr::FnSetLayer(ELayerType::Player, ELayerType::Monster, true);
	}
	void CSceneTitle::FnOnExit()
	{
	}

	//CSceneTitle::CSceneTitle()
	//{
	//}
	//CSceneTitle::~CSceneTitle()
	//{
	//}
	//void CSceneTitle::Initialize()
	//{
	//	mBgTitle = new CBgTitle();
	//	mBgTitle->FnSetName(L"Title");
	//	FnAddGameObject(mBgTitle, ELayerType::BG);

	//	CScene::Initialize();
	//}
	//void CSceneTitle::Update()
	//{
	//	CScene::Update();

	//	if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
	//	{
	//		//CSceneMgr::FnLoadScene(ESceneType::Map);
	//		CSceneMgr::FnLoadScene(ESceneType::PlayDf1);
	//	}
	//}
	//void CSceneTitle::Render(HDC hdc)
	//{
	//	CScene::Render(hdc);
	//}
	//void CSceneTitle::Release()
	//{
	//	CScene::Release();
	//}
	//void CSceneTitle::FnOnEnter()
	//{
	//}
	//void CSceneTitle::FnOnExit()
	//{
	//}
}