#include "CApplication.h"
#include "CSceneManager.h"
#include "CTime.h"
#include "CInput.h"

namespace yha
{
	CApplication::CApplication()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	CApplication::~CApplication()
	{
		CSceneManager::Release();
		//Time::Release();
	}
	
	void CApplication::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		const EResolution SetResolution = EResolution::HD;

		if ((int)SetResolution == (int)EResolution::HD)
		{
			mWidth	= 1280;
			mHeight	= 720;
		}
		else if ((int)SetResolution == (int)EResolution::FHD)
		{
			mWidth	= 1920;
			mHeight	= 1080;
		}

		// 비트맵 해상도를 설정하기 위한 실제 윈도우 크기를 계산
		RECT Rect = { 0, 0, mWidth , mHeight };
		AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, false);

		// 윈도우 크기 변경 및 출력 설정
		SetWindowPos(mHwnd
			, nullptr, 100, 50
			, Rect.right - Rect.left
			, Rect.bottom - Rect.top
			, 0);

		ShowWindow(hWnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHDC = CreateCompatibleDC(mHdc);

		HBITMAP defaultBitmap
			= (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
		DeleteObject(defaultBitmap);

		CTime::Initiailize();
		CInput::Initialize();
		CSceneManager::Initialize();
	}

	void CApplication::Run()
	{
		Update();
		Render();
	}

	void CApplication::Update()
	{
		CTime::Update();
		CInput::Update();
		CSceneManager::Update();
	}

	void CApplication::Render()
	{
		// clear
		Rectangle(mBackHDC, -1, -1, 1602, 902);

		CTime::Render(mBackHDC);
		CInput::Render(mBackHDC);
		CSceneManager::Render(mBackHDC);

		// 백버퍼에 있는 그림을 원본버퍼에 그리기
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);

	}

	HWND CApplication::FnGetHwnd()
	{
		return mHwnd;
	}
	HDC CApplication::FnGetHdc()
	{
		return mHdc;
	}
}
