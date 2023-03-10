#include "CApplication.h"
#include "CSceneMgr.h"
#include "CTime.h"
#include "CInput.h"
#include "CCollisionMgr.h"
#include "CCamera.h"

namespace yha
{
	CApplication::CApplication()
		: mHwnd(NULL)
		, mHdc(NULL)
	{
	}

	CApplication::~CApplication()
	{
		//CSceneMgr::Release();
		//Time::Release();
	}
	
	void CApplication::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);

		const EResolution SetResolution = EResolution::Custom;

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
		else if ((int)SetResolution == (int)EResolution::Custom)
		{
			mWidth = 1600;
			mHeight = 1000;
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
		CSceneMgr::Initialize();
		CCamera::Initiailize();
	}

	void CApplication::Run()
	{
		Update();
		Render();
		CSceneMgr::FnDestroy();
	}

	void CApplication::Update()
	{
		CTime::Update();
		CInput::Update();
		CCamera::Update();

		CSceneMgr::Update();
		CCollisionMgr::Update();
	}

	void CApplication::Render()
	{
		// clear
		//Rectangle(mBackHDC, -1, -1, 1602, 902);
		FnClear();

		CTime::Render(mBackHDC);
		CInput::Render(mBackHDC);
		CSceneMgr::Render(mBackHDC);

		// ����ۿ� �ִ� �׸��� �������ۿ� �׸���
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);

	}


	void CApplication::FnClear()
	{
		HBRUSH GreyBrush = CreateSolidBrush(RGB(121, 121, 121));
		HBRUSH OldBrush = (HBRUSH)SelectObject(mBackHDC, GreyBrush);
		//Rectangle(mBackHDC, -1, -1, 1602, 902);
		Rectangle(mBackHDC, -1, -1, mWidth + 2, mHeight + 2);
		SelectObject(mBackHDC, OldBrush);
		DeleteObject(GreyBrush);
	}
}
