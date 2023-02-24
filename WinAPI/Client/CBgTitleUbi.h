#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgTitleUbi : public CGameObject
	{
	public:
		CBgTitleUbi();
		~CBgTitleUbi();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
