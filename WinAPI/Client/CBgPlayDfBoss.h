#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CBgPlayDfBoss : public CGameObject
	{
	public:
		CBgPlayDfBoss();
		~CBgPlayDfBoss();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:
		CImage* mImage;
	};
}
