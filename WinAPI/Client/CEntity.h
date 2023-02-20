#pragma once
#include "CEngine.h"

namespace yha
{
	class CEntity
	{
	public:
		CEntity();
		virtual ~CEntity();

		void SetName(const std::wstring& name);
		std::wstring& GetName();

	private:
		std::wstring mName;
	};
}


