#pragma once
#include "CEntity.h"

namespace yha
{
	class CGameObject;
	class CComponent : public CEntity
	{
	public:
		CComponent(EComponentType Type);
		~CComponent();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	public:
		EComponentType FnGetType() { return mType; }
		void FnSetOwner(CGameObject* Owner) { mOwner = Owner; }
		CGameObject* FnGetOwner() { return mOwner; }

	private:
		const EComponentType mType;
		CGameObject* mOwner;
	};
}
