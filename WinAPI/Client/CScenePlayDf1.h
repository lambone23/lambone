#pragma once
#include "CScene.h"

#include "CRayman.h"
#include "CBgPlayDf1.h"

namespace yha
{
	class CRayman;
	class CBgPlayDf1;

	class CScenePlayDf1 : public CScene
	{
	public:
		CScenePlayDf1();
		~CScenePlayDf1();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CRayman* mRayman;
		CBgPlayDf1* mBgPlayDf1;

	};
}



