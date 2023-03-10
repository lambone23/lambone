#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgTitle : public CGameObject
	{
	public:
		CBgTitle();
		~CBgTitle();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
