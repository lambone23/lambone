#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgPlayDf2 : public CGameObject
	{
	public:
		CBgPlayDf2();
		~CBgPlayDf2();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
