#pragma once
#include "CEntity.h"
#include "CComponent.h"

namespace yha
{
	class CGameObject : public CEntity
	{
	public:
		CGameObject();
		virtual ~CGameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void SetPos(VectorXY pos) { mPos = pos; }

	protected:
		VectorXY mPos;

	private:
		std::vector<CComponent*> mComponents;
	};
}
