#pragma once
#include "CEngine.h"

namespace yha
{
	enum class EResolution
	{
		HD,
		FHD,
		Custom,
		END
	};

	class CApplication
	{
	public:
		CApplication();
		~CApplication();

	public:
		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();

	public:
		HWND FnGetHwnd() { return mHwnd; }
		HDC FnGetHdc() { return mHdc; }
		UINT FnGetWidth() { return mWidth; }
		UINT FnGetHeight() { return mHeight; }

	private:
		void FnClear();

	private:
		HWND mHwnd;
		HDC mHdc;

		// ¹é¹öÆÛ
		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;

		VectorXY mPos;
	};
}