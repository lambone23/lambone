#include "CLayer.h"

namespace yha
{
	CLayer::CLayer()
	{
	}
	CLayer::~CLayer()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			if (GameObj == nullptr)
			{
				continue;
			}
				
			delete GameObj;
			GameObj = nullptr;
		}
	}
	void CLayer::Initialize()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			if (GameObj == nullptr)
			{
				continue;
			}

			if (GameObj->FnGetState()
				!= CGameObject::EState::Active)
			{
				continue;
			}

			GameObj->Initialize();
		}
	}
	void CLayer::Update()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			if (GameObj == nullptr)
			{
				continue;
			}

			if (GameObj->FnGetState()
				!= CGameObject::EState::Active)
			{
				continue;
			}
			

			GameObj->Update();
		}
	}
	void CLayer::Render(HDC hdc)
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			if (GameObj == nullptr)
			{
				continue;
			}
			if (GameObj->FnGetState()
				!= CGameObject::EState::Active)
			{
				continue;
			}
			
			GameObj->Render(hdc);
		}
	}
	void CLayer::Release()
	{
		for (CGameObject* GameObj : mGameObjects)
		{
			if (GameObj == nullptr)
			{
				continue;
			}

			GameObj->Release();
		}
	}
	void CLayer::FnAddGameObject(CGameObject* GameObj)
	{
		if (GameObj == nullptr)
		{
			return;
		}

		mGameObjects.push_back(GameObj);
	}
}
