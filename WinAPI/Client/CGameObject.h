#pragma once
#include "CEntity.h"
#include "CComponent.h"

namespace yha
{
	class CGameObject : public CEntity
	{
	public:
		enum class EState
		{
			Active,
			Pause,
			Death,
		};

	public:
		CGameObject();
		virtual ~CGameObject();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	public:
		virtual void FnOnCollisionEnter(class CCollider* Other);
		virtual void FnOnCollisionStay(class CCollider* Other);
		virtual void FnOnCollisionExit(class CCollider* Other);

		template <typename T>
		T* FnAddComponent()
		{
			T* Comp = new T();
			UINT CompType = (UINT)Comp->FnGetType();
			mComponents[CompType] = Comp;
			Comp->FnSetOwner(this);

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

		EState FnGetState() { return mState; }
		void FnSetState(EState State) { mState = State; }

	private:
		std::vector<CComponent*> mComponents;
		EState mState;
	};
}
