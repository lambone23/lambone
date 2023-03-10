#pragma once
#include "CScene.h"

namespace yha
{
	class CSceneMgr
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

	public:
		static void FnDestroy();
		static void FnLoadScene(ESceneType Type);
		static CScene* FnGetActiveScene() { return mActiveScene; }
		static void FnSetActiveScene(CScene* Scene) { mActiveScene = Scene; }

	private:
		static std::vector<CScene*> mScenes;
		static CScene* mActiveScene;
	};
}
