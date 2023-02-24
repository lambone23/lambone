#pragma once
#include "CScene.h"

#include "CRayman.h"
#include "CBgPlayDf3.h"

namespace yha
{
	class CRayman;
	class CBgPlayDf3;

	class CScenePlayDf3 : public CScene
	{
	public:
		CScenePlayDf3();
		~CScenePlayDf3();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CRayman* mRayman;
		CBgPlayDf3* mBgPlayDf3;

	};
}



