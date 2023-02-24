#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgLoading : public CGameObject
	{
	public:
		CBgLoading();
		~CBgLoading();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
