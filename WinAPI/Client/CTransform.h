#pragma once
#include "CComponent.h"

namespace yha
{
	class CTransform : public CComponent
	{
	public:
		CTransform();
		~CTransform();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		void FnSetPos(VectorXY Pos) { mPos = Pos; }
		void FnSetSize(VectorXY Size) { mScale = Size; }
		VectorXY FnGetPos() { return mPos; }
		VectorXY GetScale() { return mScale; }

	private:
		VectorXY mPos;
		VectorXY mScale;

	};
}
