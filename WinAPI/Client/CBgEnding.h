#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgEnding : public CGameObject
	{
	public:
		CBgEnding();
		~CBgEnding();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
