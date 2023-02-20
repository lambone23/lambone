#include "CSceneManager.h"
#include "CScenePlay.h"

namespace yha
{
	std::vector<CScene*> CSceneManager::mScenes = {};

	void CSceneManager::Initialize()
	{
		mScenes.resize((UINT)ESceneType::Max);

		mScenes[(UINT)ESceneType::Play] = new CScenePlay();
		mScenes[(UINT)ESceneType::Play]->SetName(L"PLAYER");

		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			Scene->Initialize();
		}
	}

	void CSceneManager::Update()
	{
		//for (size_t i = 0; i < (UINT)ESceneType::Max; i++)
		//{
		//	if (mScenes[i] == nullptr)
		//		continue;

		//	mScenes[i]->Update();
		//}
		//read only
		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			Scene->Update();
		}
	}

	void CSceneManager::Render(HDC hdc)
	{
		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			Scene->Render(hdc);
		}
	}

	void CSceneManager::Release()
	{
		for (CScene* Scene : mScenes)
		{
			if (Scene == nullptr)
				continue;

			Scene->Release();
		}
	}

}
