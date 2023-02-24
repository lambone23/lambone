#include "CGameObject.h"

#include "CTransform.h"

namespace yha
{
	CGameObject::CGameObject()
	{
		mComponents.resize((UINT)EComponentType::End);
		FnAddComponent<CTransform>();
	}

	CGameObject::~CGameObject()
	{
		//for (CComponent* Comp : mComponents)
		//{
		//	delete Comp;
		//	Comp = nullptr;
		//}
	}

	void CGameObject::Initialize()
	{
		for (CComponent* Component : mComponents)
		{
			//if (Component == nullptr)
			if (Component == NULL)
				continue;

			Component->Initialize();
		}
	}

	void CGameObject::Update()
	{
		for (CComponent* Component : mComponents)
		{
			//if (Component == nullptr)
			if (Component == NULL)
				continue;

			Component->Update();
		}
	}

	void CGameObject::Render(HDC hdc)
	{
		for (CComponent* Component : mComponents)
		{
			//if (Component == nullptr)
			if (Component == NULL)
				continue;

			Component->Render(hdc);
		}
	}

	void CGameObject::Release()
	{
		for (CComponent* Component : mComponents)
		{
			//if (Component == nullptr)
			if (Component == NULL)
				continue;

			Component->Release();
		}
	}
}
