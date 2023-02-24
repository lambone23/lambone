#pragma once
#include "CEngine.h"

namespace yha
{
	enum class EResolution
	{
		HD,
		FHD,
		END
	};

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
		HDC FnGetHdc();

	private:
		HWND mHwnd;
		HDC mHdc;

		// ¹é¹öÆÛ
		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;

	};
}