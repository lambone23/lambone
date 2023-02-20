#include "CGameObject.h"

namespace yha
{
	CGameObject::CGameObject()
	{

	}

	CGameObject::~CGameObject()
	{
	}

	void CGameObject::Initialize()
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
				continue;

			Component->Initialize();
		}
	}

	void CGameObject::Update()
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
				continue;

			Component->Update();
		}
	}

	void CGameObject::Render(HDC hdc)
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
				continue;

			Component->Render(hdc);
		}
	}

	void CGameObject::Release()
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
				continue;

			Component->Release();
		}
	}
}
