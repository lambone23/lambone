#include "CSceneManager.h"

#include "CSceneTitleUbi.h"
#include "CSceneTitle.h"
#include "CSceneMap.h"
#include "CSceneLoading.h"
#include "CSceneEnding.h"

#include "CScenePlayDf1.h"
#include "CScenePlayDf2.h"
#include "CScenePlayDf3.h"
#include "CScenePlayDfBoss.h"

namespace yha
{
	std::vector<CScene*> CSceneManager::mScenes = {};
	CScene* CSceneManager::mActiveScene = nullptr;

	void CSceneManager::Initialize()
	{
		mScenes.resize((UINT)ESceneType::End);

		mScenes[(UINT)ESceneType::TitleUbi]		= new CSceneTitleUbi();
		mScenes[(UINT)ESceneType::Title]		= new CSceneTitle();
		mScenes[(UINT)ESceneType::Map]			= new CSceneMap();
		mScenes[(UINT)ESceneType::Loading]		= new CSceneLoading();
		mScenes[(UINT)ESceneType::Ending]		= new CSceneEnding();

		mScenes[(UINT)ESceneType::PlayDf1]		= new CScenePlayDf1();
		mScenes[(UINT)ESceneType::PlayDf2]		= new CScenePlayDf2();
		mScenes[(UINT)ESceneType::PlayDf3]		= new CScenePlayDf3();
		mScenes[(UINT)ESceneType::PlayDfBoss]	 = new CScenePlayDfBoss();

		mActiveScene = mScenes[(UINT)ESceneType::TitleUbi];

		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			Scene->Initialize();
		}
	}

	void CSceneManager::Update()
	{
		mActiveScene->Update();
	}

	void CSceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void CSceneManager::Release()
	{
		for (CScene* Scene : mScenes)
		{
			//if (Scene == nullptr)
			if (Scene == NULL)
				continue;

			Scene->Release();
			delete Scene;
			Scene = nullptr;
		}
	}
	void CSceneManager::FnLoadScene(ESceneType Type)
	{
		// ÇöÀç¾À
		mActiveScene->FnOnExit();

		//´ÙÀ½¾À
		mActiveScene = mScenes[(UINT)Type];
		mActiveScene->FnOnEnter();
	}
}
