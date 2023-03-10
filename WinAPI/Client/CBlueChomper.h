#pragma once
#include "CGameObject.h"
#include "CImage.h"

namespace yha
{
	class CAnimator;
	class CBlueChomper : public CGameObject
	{
	public:
		CBlueChomper();
		~CBlueChomper();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		enum class EBlueChomperState
		{
			Attack,
			Idle,
			End
		};

	private:
		virtual void FnOnCollisionEnter(class CCollider* Other) override;
		virtual void FnOnCollisionStay(class CCollider* Other) override;
		virtual void FnOnCollisionExit(class CCollider* Other) override;

		void FnMove();
		void FnShoot();
		void FnDeath();
		void FnIdle();

		void FnIdleCompleteEvent();

	private:
		//CImage* mImage;
		EBlueChomperState mState;
		CAnimator* mAnimator;
	};
}


