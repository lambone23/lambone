#pragma once
#include "CGameObject.h"
#include "CImage.h"

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
		CImage* mImage;
	};
}


