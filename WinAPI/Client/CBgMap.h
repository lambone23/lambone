#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgMap : public CGameObject
	{
	public:
		CBgMap();
		~CBgMap();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
