#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgPlayDf1 : public CGameObject
	{
	public:
		CBgPlayDf1();
		~CBgPlayDf1();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
