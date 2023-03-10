#include "CCamera.h"
#include "CApplication.h"
#include "CGameObject.h"
#include "CTransform.h"
#include "CInput.h"
#include "CTime.h"

extern yha::CApplication MyApplication;
namespace yha
{
	VectorXY CCamera::mResolution = VectorXY::Zero;
	VectorXY CCamera::mLookPosition = VectorXY::Zero;
	VectorXY CCamera::mDistance = VectorXY::Zero;
	CGameObject* CCamera::mTarget = nullptr;

	void CCamera::Initiailize()
	{
		mResolution.X = MyApplication.FnGetWidth();
		mResolution.Y = MyApplication.FnGetHeight();
		mLookPosition = (mResolution / 2.0f);
	}

	void CCamera::Update()
	{

		if (CInput::FnGetKey(EKeyCode::LEFT))
			mLookPosition.X -= 100.0f * CTime::FnDeltaTime();

		if (CInput::FnGetKey(EKeyCode::RIGHT))
			mLookPosition.X += 100.0f * CTime::FnDeltaTime();

		if (CInput::FnGetKey(EKeyCode::UP))
			mLookPosition.Y -= 100.0f * CTime::FnDeltaTime();

		if (CInput::FnGetKey(EKeyCode::DOWN))
			mLookPosition.Y += 100.0f * CTime::FnDeltaTime();


		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->FnGetComponent<CTransform>()->FnGetPos();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}
	void CCamera::FnClear()
	{
		mResolution.X = MyApplication.FnGetWidth();
		mResolution.Y = MyApplication.FnGetHeight();
		mLookPosition = (mResolution / 2.0f);
		mDistance = VectorXY::Zero;
	}
}
