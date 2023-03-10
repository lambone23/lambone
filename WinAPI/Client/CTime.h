#pragma once
#include "CommonInclude.h"

namespace yha
{
	class CTime
	{
	public:
		static void Initiailize();
		static void Update();
		static void Render(HDC hdc);

	public:
		__forceinline static double FnDeltaTime() { return mDeltaTime; }

	private:
		static double mDeltaTime;
		static double mSecond;
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurFrequency;
	};
}
