#pragma once
#include "CComponent.h"
#include "CAnimation.h"
#include "CImage.h"

namespace yha
{
	class CAnimator : public CComponent
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent();
			}

			//void(*name)(int, int);
			std::function<void()> mEvent;
		};

		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

	public:
		CAnimator();
		~CAnimator();

	public:
		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	public:
		//완성된 스프라이트 시트를 지정해서 애니메이션 제작하는 함수
		void FnCreateAnimation(const std::wstring& Name
			, CImage* Sheet
			, VectorXY LeftTop
			, UINT Column, UINT Row, UINT SpriteLength
			, VectorXY Offset, float Duration);

		// 폴더에 들어있는 스프라이트들을 이용해서 애니메이션 제작해주는 함수
		void FnCreateAnimations(const std::wstring& Path, VectorXY Offset, float Duration);

		CAnimation* FnFindAnimation(const std::wstring& Name);
		void FnPlay(const std::wstring& Name, bool Loop);

		Events* FnFindEvents(const std::wstring& Name);
		std::function<void()>& FnGetStartEvent(const std::wstring& Name);
		std::function<void()>& FnGetCompleteEvent(const std::wstring& Name);
		std::function<void()>& FnGetEndEvent(const std::wstring& Name);
		bool FnIsComplte() { return mActiveAnimation->FnIsComplete(); }

	private:
		std::map<std::wstring, CAnimation*> mAnimations;
		std::map<std::wstring, Events*> mEvents;

		CAnimation* mActiveAnimation;
		CImage* mSpriteSheet;
		bool mbLoop;
	};
}
