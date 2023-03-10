#include "CSceneMgr.h"

#include "CSceneTitleUbi.h"
#include "CSceneTitle.h"
//#include "CSceneMap.h"
//#include "CSceneLoading.h"
#include "CSceneEnding.h"

#include "CScenePlayDf1.h"
#include "CScenePlayDf2.h"
//#include "CScenePlayDf3.h"
#include "CScenePlayDfBoss.h"

#include "CCollisionMgr.h"
#include "CCamera.h"


namespace yha
{
	std::vector<CScene*> CSceneMgr::mScenes = {};
	CScene* CSceneMgr::mActiveScene = nullptr;

	void CSceneMgr::Initialize()
	{
		mScenes.resize((UINT)ESceneType::End);

		mScenes[(UINT)ESceneType::TitleUbi]		= new CSceneTitleUbi();
		mScenes[(UINT)ESceneType::Title]		= new CSceneTitle();
		//mScenes[(UINT)ESceneType::Map]			= new CSceneMap();
		//mScenes[(UINT)ESceneType::Loading]		= new CSceneLoading();
		mScenes[(UINT)ESceneType::Ending]		= new CSceneEnding();

		mScenes[(UINT)ESceneType::PlayDf1]		= new CScenePlayDf1();
		mScenes[(UINT)ESceneType::PlayDf2]		= new CScenePlayDf2();
		//mScenes[(UINT)ESceneType::PlayDf3]		= new CScenePlayDf3();
		mScenes[(UINT)ESceneType::PlayDfBoss]	= new CScenePlayDfBoss();

		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			Scene->Initialize();
		}

		mActiveScene = mScenes[(UINT)ESceneType::TitleUbi];
	}

	void CSceneMgr::Update()
	{
		mActiveScene->Update();
	}

	void CSceneMgr::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void CSceneMgr::Release()
	{
		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			//Scene->Release();
			delete Scene;
			Scene = nullptr;
		}
	}

	void CSceneMgr::FnDestroy()
	{
		mActiveScene->FnDestroy();
	}


	void CSceneMgr::FnLoadScene(ESceneType Type)
	{
		CCamera::FnClear();

		// ÇöÀç¾À
		mActiveScene->FnOnExit();

		CCollisionMgr::FnClear();

		//´ÙÀ½¾À
		mActiveScene = mScenes[(UINT)Type];
		mActiveScene->FnOnEnter();
	}
}
