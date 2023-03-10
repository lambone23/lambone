#pragma once
#include "CEntity.h"

namespace yha
{
	class CResource
	{
	public:
		CResource();
		virtual ~CResource();

	public:
		virtual HRESULT FnLoad(const std::wstring& Path) = 0;

		const std::wstring& FnGetKey() { return mKey; }
		const std::wstring& FnGetPath() { return mPath; }
		void FnSetKey(const std::wstring& Key) { mKey = Key; }
		void FnSetPath(const std::wstring& Path) { mPath = Path; }

	private:
		std::wstring mKey;
		std::wstring mPath;

	};
}
