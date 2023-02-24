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

		// ��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�⸦ ���
		RECT Rect = { 0, 0, mWidth , mHeight };
		AdjustWindowRect(&Rect, WS_OVERLAPPEDWINDOW, false);

		// ������ ũ�� ���� �� ��� ����
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

		// ����ۿ� �ִ� �׸��� �������ۿ� �׸���
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
