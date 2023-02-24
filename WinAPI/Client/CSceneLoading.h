#pragma once
#include "CScene.h"
#include "CBgLoading.h"

namespace yha
{
	class CBgLoading;

	class CSceneLoading : public CScene
	{
	public:
		CSceneLoading();
		~CSceneLoading();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CBgLoading* mBgLoading;

	};
}
