#pragma once
#include "CComponent.h"

namespace yha
{
	class CTransform : public CComponent
	{
	public:
		CTransform();
		~CTransform();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		void FnSetPos(VectorXY Pos) { mPos = Pos; }
		void FnSetSize(VectorXY Size) { mSize = Size; }
		VectorXY FnGetPos() { return mPos; }
		VectorXY FnGetSize() { return mSize; }

	private:
		VectorXY mPos;
		VectorXY mSize;

	};
}
