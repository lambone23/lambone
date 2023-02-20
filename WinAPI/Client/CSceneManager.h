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

	private:
		static std::vector<CScene*> mScenes;
	};
}
