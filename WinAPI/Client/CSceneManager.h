#pragma once
#include "CScene.h"

namespace yha
{
	class CSceneManager
	{
	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

		static void FnLoadScene(ESceneType Type);

	private:
		static std::vector<CScene*> mScenes;
		static CScene* mActiveScene;
	};
}
