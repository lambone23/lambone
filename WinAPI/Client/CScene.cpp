#include "CScene.h"
#include "CSceneMgr.h"

namespace yha
{
	CScene::CScene()
	{
		mLayers.resize((UINT)ELayerType::End);
	}
	CScene::~CScene()
	{

	}
	void CScene::Initialize()
	{
		CSceneMgr::FnSetActiveScene(this);

		//for (CLayer& Layer : mLayers)
		//{
		//	Layer.Initialize();
		//}
	}
	void CScene::Update()
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Update();
		}
	}
	void CScene::Render(HDC hdc)
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Render(hdc);
		}
	}
	void CScene::Release()
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Release();
		}
	}

	void CScene::FnDestroy()
	{
		std::vector<CGameObject*> DeleteGameObjects = {};
		for (CLayer& Layer : mLayers)
		{
			std::vector<CGameObject*>& GameObjects
				= Layer.FnGetGameObjects();

			for (std::vector<CGameObject*>::iterator Iter = GameObjects.begin()
				; Iter != GameObjects.end(); )
			{
				if ((*Iter)->FnGetState() == CGameObject::EState::Death)
				{
					DeleteGameObjects.push_back((*Iter));
					Iter = GameObjects.erase(Iter);
				}
				else
				{
					Iter++;
				}
			}
		}

		for (CGameObject* DeathObj : DeleteGameObjects)
		{
			delete DeathObj;
			DeathObj = nullptr;
		}
	}

	void CScene::FnOnEnter()
	{
	}
	void CScene::FnOnExit()
	{
	}
	void CScene::FnAddGameObject(CGameObject* Obj, ELayerType Layer)
	{
		mLayers[(UINT)Layer].FnAddGameObject(Obj);
	}

	std::vector<CGameObject*>& CScene::FnGetGameObjects(ELayerType Layer)
	{
		return mLayers[(UINT)Layer].FnGetGameObjects();
	}
}
