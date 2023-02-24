#include "CLayer.h"

namespace yha
{
	CLayer::CLayer()
	{
	}
	CLayer::~CLayer()
	{
	}
	void CLayer::Initialize()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			//if (GameObj == nullptr)
			if (GameObj == NULL)
				continue;

			GameObj->Initialize();
		}
	}
	void CLayer::Update()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			//if (GameObj == nullptr)
			if (GameObj == NULL)
				continue;

			GameObj->Update();
		}
	}
	void CLayer::Render(HDC hdc)
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			//if (GameObj == nullptr)
			if (GameObj == NULL)
				continue;

			GameObj->Render(hdc);
		}
	}
	void CLayer::Release()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			//if (GameObj == nullptr)
			if (GameObj == NULL)
				continue;

			GameObj->Release();
		}
	}
	void CLayer::FnAddGameObject(CGameObject* GameObj)
	{
		//if (GameObj == nullptr)
		if (GameObj == NULL)
			return;

		mGameObjects.push_back(GameObj);
	}
}
