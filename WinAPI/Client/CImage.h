#pragma once
#include "CResource.h"

namespace yha
{
	class CImage : public CResource
	{
	public:
		CImage();
		~CImage();

		virtual HRESULT FnLoad(const std::wstring& Path) override;

		HDC FnGetHdc() { return mHdc; }
		HBITMAP FnGetBitmap() { return mBitmap; }
		UINT FnGetWidth() { return mWidth; }
		UINT FnGetHeight() { return mHeight; }

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}
