#pragma once
#include "CEntity.h"

namespace yha
{
	class CComponent : public CEntity
	{
	public:
		CComponent(EComponentType Type);
		~CComponent();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		EComponentType FnGetType() { return mType; }

	private:
		const EComponentType mType;
	};
}
