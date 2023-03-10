#pragma once
#include "CComponent.h"

namespace yha
{
	class CCollider : public CComponent
	{
	public:
		CCollider();
		~CCollider();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		virtual void FnOnCollisionEnter(CCollider* Other);
		virtual void FnOnCollisionStay(CCollider* Other);
		virtual void FnOnCollisionExit(CCollider* Other);

		void FnSetCenter(VectorXY Center) { mCenter = Center; };
		void FnSetSize(VectorXY Size) { mSize = Size; };
		VectorXY FnGetPos() { return mPos; }
		VectorXY FnGetSize() { return mSize; }
		UINT FnGetID() { return mID; }

	private:
		static UINT ColliderNumber;
		UINT mID;
		VectorXY mCenter;
		VectorXY mSize;
		VectorXY mPos;
	};
}

