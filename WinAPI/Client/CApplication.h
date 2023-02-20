#pragma once
#include "CEngine.h"

namespace yha
{
	class CApplication
	{
	public:
		CApplication();
		~CApplication();

		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();

		HWND FnGetHwnd();

	private:
		HWND mHwnd;
		HDC mHdc;

		// ¹é¹öÆÛ
		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;

		VectorXY mPos;

		//Scene mScene[256];
	};
}