#pragma once
#include "CScene.h"
#include "CBgEnding.h"

namespace yha
{
	class CBgEnding;

	class CSceneEnding : public CScene
	{
	public:
		CSceneEnding();
		~CSceneEnding();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CBgEnding* mBgEnding;

	};
}
