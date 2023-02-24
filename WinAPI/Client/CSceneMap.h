#pragma once
#include "CScene.h"

#include "CMapRayman.h"
#include "CBgMap.h"

namespace yha
{
	class CMapRayman;
	class CBgMap;

	class CSceneMap : public CScene
	{
	public:
		CSceneMap();
		~CSceneMap();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void FnOnEnter() override;
		virtual void FnOnExit() override;

	private:
		CMapRayman* mMapRayman;
		CBgMap* mBgMap;

	};
}



