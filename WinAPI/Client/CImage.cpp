#include "CImage.h"
#include "CApplication.h"
#include "CResources.h"

extern yha::CApplication MyApplication;

namespace yha
{
	CImage* CImage::FnCreate(const std::wstring& Name, UINT Width, UINT Height)
	{
		if (Width == 0 || Height == 0)
		{
			return nullptr;
		}
			
		CImage* Image = CResources::FnFind<CImage>(Name);
		if (Image != nullptr)
		{
			return Image;
		}

		Image = new CImage();
		HDC MainHdc = MyApplication.FnGetHdc();

		Image->mBitmap = CreateCompatibleBitmap(MainHdc, Width, Height);
		Image->mHdc = CreateCompatibleDC(MainHdc);

		HBITMAP OldBitmap = (HBITMAP)SelectObject(Image->mHdc, Image->mBitmap);
		DeleteObject(OldBitmap);

		Image->mWidth = Width;
		Image->mHeight = Height;

		Image->FnSetKey(Name);
		CResources::FnInsert<CImage>(Name, Image);

		Rectangle(Image->FnGetHdc(), -1, -1, Image->mWidth + 1, Image->mHeight + 1);

		return Image;
	}
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
