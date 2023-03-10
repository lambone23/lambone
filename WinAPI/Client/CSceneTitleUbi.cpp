#include "CSceneTitleUbi.h"

#include "CInput.h"
#include "CSceneMgr.h"
#include "CCollisionMgr.h"
#include "CTransform.h"
#include "CCamera.h"
#include "CObject.h"

namespace yha
{
	CSceneTitleUbi::CSceneTitleUbi()
	{
	}
	CSceneTitleUbi::~CSceneTitleUbi()
	{
	}
	void CSceneTitleUbi::Initialize()
	{
		CScene::Initialize();

		//object::Instantiate<CRayman>(VectorXY(400.0f, 400.0f), ELayerType::Player);
		object::Instantiate<CBgTitleUbi>(ELayerType::BG);
		//object::Instantiate<Monster>(VectorXY(500.0f, 500.0f), ELayerType::Monster);
	}
	void CSceneTitleUbi::Update()
	{
		CScene::Update();

		if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
		{
			CSceneMgr::FnLoadScene(ESceneType::Title);
		}

		CScene::Update();
	}
	void CSceneTitleUbi::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}
	void CSceneTitleUbi::Release()
	{
		CScene::Release();
	}
	void CSceneTitleUbi::FnOnEnter()
	{
		CCollisionMgr::FnSetLayer(ELayerType::Player, ELayerType::Monster, true);
	}
	void CSceneTitleUbi::FnOnExit()
	{
	}












	//CSceneTitleUbi::CSceneTitleUbi()
	//{
	//}
	//CSceneTitleUbi::~CSceneTitleUbi()
	//{
	//}
	//void CSceneTitleUbi::Initialize()
	//{
	//	mBgTitleUbi = new CBgTitleUbi();
	//	mBgTitleUbi->FnSetName(L"TitleUbi");
	//	FnAddGameObject(mBgTitleUbi, ELayerType::BG);

	//	CScene::Initialize();
	//}
	//void CSceneTitleUbi::Update()
	//{
	//	CScene::Update();

	//	if (CInput::FnGetKeyState(EKeyCode::N) == EKeyState::Down)
	//	{
	//		CSceneMgr::FnLoadScene(ESceneType::Title);
	//	}
	//}
	//void CSceneTitleUbi::Render(HDC hdc)
	//{
	//	CScene::Render(hdc);
	//}
	//void CSceneTitleUbi::Release()
	//{
	//	CScene::Release();
	//}
	//void CSceneTitleUbi::FnOnEnter()
	//{
	//}
	//void CSceneTitleUbi::FnOnExit()
	//{
	//}
}