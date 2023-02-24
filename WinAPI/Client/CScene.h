#pragma once
#include "CEntity.h"
#include "CLayer.h"

namespace yha
{
	class CScene : public CEntity
	{
	public:
		CScene();
		virtual ~CScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void FnOnEnter();
		virtual void FnOnExit();

		void FnAddGameObject(CGameObject* Obj, ELayerType Layer);

	private:
		std::vector<CLayer> mLayers;
	};
}
