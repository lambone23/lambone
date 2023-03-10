#pragma once
#include "CEntity.h"

namespace yha
{
	class CImage;
	class CAnimator;
	class CAnimation : public CEntity
	{
	public:
		struct Sprite
		{
			VectorXY LeftTop;
			VectorXY Size;
			VectorXY Offset;
			float Duration;

			Sprite()
				: LeftTop(VectorXY::Zero)
				, Size(VectorXY::Zero)
				, Offset(VectorXY::Zero)
				, Duration(0.0f)
			{

			}
		};

	public:
		CAnimation();
		~CAnimation();

	public:
		void Initialize();
		void Update();
		void Render(HDC hdc);

	public:

		void FnCreate(CImage* Sheet, VectorXY LeftTop, UINT Column, UINT Row, UINT SpriteLength, VectorXY Offset, float Duration);
		void FnReset();

		bool FnIsComplete() { return mbComplete; }
		void FnSetAnimator(CAnimator* Animator) { mAnimator = Animator; }
		void FnSetAnimationName(const std::wstring& Name) { mAnimationName = Name; }
		std::wstring& FnGetAnimationName() { return mAnimationName; }

	private:
		CAnimator* mAnimator;
		CImage* mSheetImage;
		std::vector<Sprite> mSpriteSheet;
		std::wstring mAnimationName;
		float mTime;
		bool mbComplete;
		int mSpriteIndex;
	};
}
