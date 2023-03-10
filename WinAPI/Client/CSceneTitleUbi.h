#pragma once
#include "CScene.h"
#include "CBgTitleUbi.h"

namespace yha
{
	class CBgTitleUbi;

	class CSceneTitleUbi : public CScene
	{
	public:
		CSceneTitleUbi();
		~CSceneTitleUbi();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CBgTitleUbi* mBgTitleUbi;

	};
}
