#pragma once
#include "CGameObject.h"

namespace yha
{
	class CRayman : public CGameObject
	{
	public:
		CRayman();
		~CRayman();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:
	};

}


