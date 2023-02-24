#pragma once
#include "CEntity.h"
#include "CComponent.h"

namespace yha
{
	class CGameObject : public CEntity
	{
	public:
		CGameObject();
		virtual ~CGameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		template <typename T>
		T* FnAddComponent()
		{
			T* Comp = new T();
			UINT CompType = (UINT)Comp->FnGetType();
			mComponents[CompType] = Comp;

			return Comp;
		}

		template <typename T>
		T* FnGetComponent()
		{
			for (CComponent* Comp : mComponents)
			{
				if (dynamic_cast<T*>(Comp))
					return dynamic_cast<T*>(Comp);
			}

			return nullptr;
		}

	private:
		std::vector<CComponent*> mComponents;
	};
}
