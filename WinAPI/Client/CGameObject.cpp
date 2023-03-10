#include "CGameObject.h"

#include "CTransform.h"

namespace yha
{
	CGameObject::CGameObject()
		: mState(EState::Active)
	{
		mComponents.resize((UINT)EComponentType::End);
		FnAddComponent<CTransform>();
	}

	CGameObject::~CGameObject()
	{
		for (CComponent* Component : mComponents)
		{
			delete Component;
			Component = nullptr;
		}
	}

	void CGameObject::Initialize()
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
			{
				continue;
			}

			Component->Initialize();
		}
	}

	void CGameObject::Update()
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
			{
				continue;
			}

			Component->Update();
		}
	}

	void CGameObject::Render(HDC hdc)
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
			{
				continue;
			}

			Component->Render(hdc);
		}
	}

	void CGameObject::Release()
	{
		for (CComponent* Component : mComponents)
		{
			if (Component == nullptr)
			{
				continue;
			}

			Component->Release();
		}
	}

	void CGameObject::FnOnCollisionEnter(CCollider* Other)
	{
	}
	void CGameObject::FnOnCollisionStay(CCollider* Other)
	{
	}
	void CGameObject::FnOnCollisionExit(CCollider* Other)
	{
	}
}
