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

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	public:
		virtual void FnDestroy();
		virtual void FnOnEnter();
		virtual void FnOnExit();

		void FnAddGameObject(CGameObject* Obj, ELayerType Layer);
		std::vector<CGameObject*>& FnGetGameObjects(ELayerType Layer);

	private:
		std::vector<CLayer> mLayers;
	};
}
