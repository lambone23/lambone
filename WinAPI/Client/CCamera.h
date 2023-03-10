#pragma once
#include "CEngine.h"

namespace yha
{
	class CGameObject;

	class CCamera
	{
	public:
		static void Initiailize();
		static void Update();

	public:
		static void FnClear();

		static void FnSetTarget(CGameObject* Target) { mTarget = Target; }
		static VectorXY FnCaluatePos(VectorXY Pos) { return Pos - mDistance; }


	private:
		static VectorXY mResolution;
		static VectorXY mLookPosition;
		static VectorXY mDistance;
		static CGameObject* mTarget;
	};
}

