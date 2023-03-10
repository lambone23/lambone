#include "CAnimation.h"
#include "CTime.h"
#include "CImage.h"
#include "CAnimator.h"
#include "CTransform.h"
#include "CGameObject.h"
#include "CCamera.h"

namespace yha
{
    CAnimation::CAnimation()
        : mAnimator(nullptr)
        , mSheetImage(nullptr)
        , mTime(0.0f)
        , mbComplete(false)
        , mSpriteIndex(0)
        , mAnimationName(L"")
    {

    }

    CAnimation::~CAnimation()
    {
    }

    void CAnimation::Initialize()
    {
    }

    void CAnimation::Update()
    {
        if (mbComplete == true)
            return;

        mTime += CTime::FnDeltaTime();
        if (mSpriteSheet[mSpriteIndex].Duration < mTime)
        {
            mTime = 0.0f;

            if (mSpriteSheet.size() <= mSpriteIndex + 1)
            {
                mbComplete = true;
            }
            else
            {
                mSpriteIndex++;
            }
        }
    }

    void CAnimation::Render(HDC hdc)
    {
        CTransform* Tr
            = mAnimator->FnGetOwner()->FnGetComponent<CTransform>();
        VectorXY Scale = Tr->GetScale();

        //TransparentBlt(hdc
        //    , Tr->FnGetPos().X + mSpriteSheet[mSpriteIndex].Offset.X
        //    , Tr->FnGetPos().Y + mSpriteSheet[mSpriteIndex].Offset.Y
        //    , mSpriteSheet[mSpriteIndex].Size.X * Scale.X
        //    , mSpriteSheet[mSpriteIndex].Size.Y * Scale.Y
        //    , mSheetImage->FnGetHdc()
        //    , mSpriteSheet[mSpriteIndex].LeftTop.X
        //    , mSpriteSheet[mSpriteIndex].LeftTop.Y
        //    , mSpriteSheet[mSpriteIndex].Size.X
        //    , mSpriteSheet[mSpriteIndex].Size.Y
        //    , RGB(255, 0, 255));

        // 이미지가 그려질 좌표는 오브젝트 좌표의 위쪽 중간에 그려진다.
        // 캐릭터의 발을 기준으로 포지션을 계산
        VectorXY Pos = Tr->FnGetPos();
        Pos = CCamera::FnCaluatePos(Pos);
        Pos += mSpriteSheet[mSpriteIndex].Offset;
        Pos.X -= mSpriteSheet[mSpriteIndex].Size.X / 2.0f;
        Pos.Y -= mSpriteSheet[mSpriteIndex].Size.Y;

        TransparentBlt( hdc
            , Pos.X
            , Pos.Y
            , mSpriteSheet[mSpriteIndex].Size.X * Scale.X
            , mSpriteSheet[mSpriteIndex].Size.Y * Scale.Y
            , mSheetImage->FnGetHdc()
            , mSpriteSheet[mSpriteIndex].LeftTop.X
            , mSpriteSheet[mSpriteIndex].LeftTop.Y
            , mSpriteSheet[mSpriteIndex].Size.X
            , mSpriteSheet[mSpriteIndex].Size.Y
            , RGB(255, 0, 255)
        );
    }

    void CAnimation::FnCreate(CImage* Sheet, VectorXY LeftTop
        , UINT Column, UINT Row, UINT SpriteLength
        , VectorXY Offset, float Duration)
    {
        mSheetImage = Sheet;

        //UINT coulmn = mSheetImage->GetWidth() / size.x;
        VectorXY Size = VectorXY::One;
        Size.X = mSheetImage->FnGetWidth() / (float)Column;
        Size.Y = mSheetImage->FnGetHeight() / (float)Row;

        for (size_t i = 0; i < SpriteLength; i++)
        {
            Sprite SpriteInfo;

            SpriteInfo.LeftTop.X = LeftTop.X + (Size.X * i);
            SpriteInfo.LeftTop.Y = LeftTop.Y;
            SpriteInfo.Size = Size;
            SpriteInfo.Offset = Offset;
            SpriteInfo.Duration = Duration;

            mSpriteSheet.push_back(SpriteInfo);
        }
    }

    void CAnimation::FnReset()
    {
        mSpriteIndex = 0;
        mTime = 0.0f;
        mbComplete = false;
    }

}
