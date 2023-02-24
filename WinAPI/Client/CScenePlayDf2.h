#pragma once
#include "CScene.h"

#include "CRayman.h"
#include "CBgPlayDf2.h"

namespace yha
{
	class CRayman;
	class CBgPlayDf2;

	class CScenePlayDf2 : public CScene
	{
	public:
		CScenePlayDf2();
		~CScenePlayDf2();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CRayman* mRayman;
		CBgPlayDf2* mBgPlayDf2;

	};
}



