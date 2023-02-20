#pragma once
#include "CScene.h"

namespace yha
{
	class CScenePlay : public CScene
	{
	public:
		CScenePlay();
		~CScenePlay();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:

	};
}
