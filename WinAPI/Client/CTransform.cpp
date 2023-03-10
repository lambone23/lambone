#include "CTransform.h"

namespace yha
{
	CTransform::CTransform()
		:CComponent(EComponentType::Transform)
		, mPos(VectorXY::Zero)
		, mScale(VectorXY::One)
	{
	}
	CTransform::~CTransform()
	{
	}
	void CTransform::Initialize()
	{
	}
	void CTransform::Update()
	{
	}
	void CTransform::Render(HDC hdc)
	{
	}
	void CTransform::Release()
	{
	}
}