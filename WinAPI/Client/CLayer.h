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

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void FnAddGameObject(CGameObject* GameObj);

	private:
		std::vector<CGameObject*> mGameObjects;
	};
}
