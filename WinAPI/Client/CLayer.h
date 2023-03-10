#pragma once
#include "CEntity.h"
#include "CGameObject.h"

namespace yha
{
	class CLayer : public CEntity
	{
	public:
		CLayer();
		virtual ~CLayer();

	public:
		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	public:
		void FnAddGameObject(CGameObject* GameObj);
		std::vector<CGameObject*>& FnGetGameObjects() { return mGameObjects; }

	private:
		std::vector<CGameObject*> mGameObjects;
	};
}
