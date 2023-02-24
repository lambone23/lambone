#include "CComponent.h"

namespace yha
{
	CComponent::CComponent(EComponentType Type)
		: mType(Type)
	{
	}
	CComponent::~CComponent()
	{
	}
	void CComponent::Initialize()
	{
	}
	void CComponent::Update()
	{
	}
	void CComponent::Render(HDC hdc)
	{
	}
	void CComponent::Release()
	{
	}
}
