#pragma once
#include "CEntity.h"

namespace yha
{
	class CComponent : public CEntity
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
	};
}
