#pragma once
#include "CScene.h"
#include "CBgTitle.h"

namespace yha
{
	class CBgTitle;

	class CSceneTitle : public CScene
	{
	public:
		CSceneTitle();
		~CSceneTitle();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CBgTitle* mBgTitle;

	};
}

