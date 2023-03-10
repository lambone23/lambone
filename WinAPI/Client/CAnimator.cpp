#include "CAnimator.h"
#include "CResources.h"

namespace yha
{
	CAnimator::CAnimator()
		: CComponent(EComponentType::Animator)
		, mActiveAnimation(nullptr)
		, mSpriteSheet(nullptr)
		, mbLoop(false)
	{

	}
	CAnimator::~CAnimator()
	{
		for (auto Animation : mAnimations)
		{
			delete Animation.second;
			Animation.second = nullptr;
		}
		for (auto Events : mEvents)
		{
			delete Events.second;
			Events.second = nullptr;
		}
	}
	void CAnimator::Initialize()
	{
	}
	void CAnimator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mActiveAnimation->FnIsComplete())
			{
				CAnimator::Events* events
					= FnFindEvents(mActiveAnimation->FnGetName());

				if (events != nullptr)
					events->mCompleteEvent();
			}

			if (mbLoop && mActiveAnimation->FnIsComplete())
			{
				mActiveAnimation->FnReset();
			}
		}
	}
	void CAnimator::Render(HDC hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(hdc);
		}
	}
	void CAnimator::Release()
	{
	}
	void CAnimator::FnCreateAnimation(const std::wstring& Name
		, CImage* Sheet, VectorXY LeftTop
		, UINT Column, UINT Row, UINT SpriteLength
		, VectorXY Offset, float Duration)
	{
		CAnimation* Animation = FnFindAnimation(Name);

		if (Animation != nullptr)
		{
			return;
		}

		Animation = new CAnimation();
		Animation->FnCreate(Sheet, LeftTop, Column, Row, SpriteLength, Offset, Duration);
		Animation->FnSetName(Name);
		Animation->FnSetAnimator(this);

		mAnimations.insert(std::make_pair(Name, Animation));
		Events* event = new Events();
		mEvents.insert(std::make_pair(Name, event));
	}

	void CAnimator::FnCreateAnimations(const std::wstring& Path, VectorXY Offset, float Duration)
	{
		UINT Width = 0;
		UINT Height = 0;
		UINT FileCount = 0;

		std::filesystem::path Fs(Path);
		std::vector<CImage*> Images = {};
		for (const auto& P : std::filesystem::recursive_directory_iterator(Path))
		{
			std::wstring FileName = P.path().filename();
			std::wstring FulllName = Path + L"\\" + FileName;

			const std::wstring Ext = P.path().extension();
			if (Ext == L".png")
				continue;

			CImage* Image = CResources::FnLoad<CImage>(FileName, FulllName);
			Images.push_back(Image);

			if (Width < Image->FnGetWidth())
			{
				Width = Image->FnGetWidth();
			}
			if (Height < Image->FnGetHeight())
			{
				Height = Image->FnGetHeight();
			}
			FileCount++;
		}

		std::wstring Key = Fs.parent_path().filename();
		Key += Fs.filename();
		mSpriteSheet = CImage::FnCreate(Key, Width * FileCount, Height);

		int Index = 0;
		for (CImage* Image : Images)
		{
			int centerX = (Width - Image->FnGetWidth()) / 2;
			int centerY = (Height - Image->FnGetHeight());

			BitBlt(mSpriteSheet->FnGetHdc()
				, Width * Index + centerX
				, 0 + centerY
				, Image->FnGetWidth(), Image->FnGetHeight()
				, Image->FnGetHdc(), 0, 0, SRCCOPY);

			Index++;
		}

		FnCreateAnimation(Key, mSpriteSheet, VectorXY::Zero, Index, 1, Index, Offset, Duration);
	}

	CAnimation* CAnimator::FnFindAnimation(const std::wstring& Name)
	{
		std::map<std::wstring, CAnimation*>::iterator Iter
			= mAnimations.find(Name);

		if (Iter == mAnimations.end())
		{
			return nullptr;
		}
			
		return Iter->second;
	}
	void CAnimator::FnPlay(const std::wstring& Name, bool Loop)
	{
		if (mActiveAnimation != nullptr)
		{
			CAnimator::Events* PrevEvents
				= FnFindEvents(mActiveAnimation->FnGetName());

			if (PrevEvents != nullptr)
				PrevEvents->mEndEvent();
		}

		mActiveAnimation = FnFindAnimation(Name);
		mActiveAnimation->FnReset();
		mbLoop = Loop;

		CAnimator::Events* events
			= FnFindEvents(mActiveAnimation->FnGetName());

		if (events != nullptr)
			events->mStartEvent();
	}
	CAnimator::Events* CAnimator::FnFindEvents(const std::wstring& Name)
	{
		std::map<std::wstring, Events*>::iterator Iter
			= mEvents.find(Name);

		if (Iter == mEvents.end())
			return nullptr;

		return Iter->second;
	}
	std::function<void()>& CAnimator::FnGetStartEvent(const std::wstring& Name)
	{
		CAnimation* Animation = FnFindAnimation(Name);

		CAnimator::Events* events
			= FnFindEvents(Animation->FnGetAnimationName());

		return events->mStartEvent.mEvent;
	}
	std::function<void()>& CAnimator::FnGetCompleteEvent(const std::wstring& Name)
	{
		CAnimation* Animation = FnFindAnimation(Name);

		CAnimator::Events* events
			= FnFindEvents(Animation->FnGetAnimationName());

		return events->mCompleteEvent.mEvent;
	}
	std::function<void()>& CAnimator::FnGetEndEvent(const std::wstring& Name)
	{
		CAnimation* Animation = FnFindAnimation(Name);

		CAnimator::Events* events
			= FnFindEvents(Animation->FnGetAnimationName());

		return events->mEndEvent.mEvent;
	}
}