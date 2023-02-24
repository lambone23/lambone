#include "CImage.h"
#include "CApplication.h"

extern yha::CApplication MyApplication;

namespace yha
{
	CImage::CImage()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{
	}

	CImage::~CImage()
	{

	}

	HRESULT CImage::FnLoad(const std::wstring& Path)
	{
		mBitmap = (HBITMAP)LoadImageW(nullptr
			, Path.c_str(), IMAGE_BITMAP
			, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr)
			return E_FAIL;

		BITMAP BitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &BitInfo);

		mWidth = BitInfo.bmWidth;
		mHeight = BitInfo.bmHeight;

		HDC MainDC = MyApplication.FnGetHdc();
		mHdc = CreateCompatibleDC(MainDC);

		HBITMAP OldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(OldBitmap);

		return S_OK;
	}
}
