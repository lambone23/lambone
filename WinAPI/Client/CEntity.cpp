#include "CEntity.h"

namespace yha
{
	CEntity::CEntity()
	{
	}
	CEntity::~CEntity()
	{
	}
	void CEntity::SetName(const std::wstring& name)
	{
		mName = name;
	}
	std::wstring& CEntity::GetName()
	{
		return mName;
	}
}

