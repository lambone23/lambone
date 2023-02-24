#pragma once
#include "CScene.h"

#include "CRayman.h"
#include "CBgPlayDfBoss.h"

namespace yha
{
	class CRayman;
	class CBgPlayDfBoss;

	class CScenePlayDfBoss : public CScene
	{
	public:
		CScenePlayDfBoss();
		~CScenePlayDfBoss();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CRayman* mRayman;
		CBgPlayDfBoss* mBgPlayDfBoss;

	};
}



