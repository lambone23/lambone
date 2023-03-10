#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CAnimator;
	class CBgObjPlayDf1 : public CGameObject
	{
	public:
		CBgObjPlayDf1();
		~CBgObjPlayDf1();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
		CAnimator* mAnimator;
	};
}
