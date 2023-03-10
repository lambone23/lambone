#pragma once
#include "CEngine.h"

namespace yha
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

	public:
		void FnSetName(const std::wstring& Name) { mName = Name; }
		std::wstring& FnGetName() { return mName; }
		void FnSetID(UINT64 Id) { mID = Id; }
		UINT64 FnGetID() { return mID; }

	private:
		std::wstring mName;
		UINT64 mID;
	};
}


