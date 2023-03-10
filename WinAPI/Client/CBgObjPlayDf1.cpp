#include "CBgObjPlayDf1.h"

#include "CTime.h"
#include "CSceneMgr.h"
#include "CInput.h"
#include "CResources.h"

#include "CTransform.h"
#include "CAnimator.h"
#include "CCollider.h"
//#include "yaBaseBullet.h"
#include "CScene.h"
#include "CObject.h"

namespace yha
{
	CBgObjPlayDf1::CBgObjPlayDf1()
	{

	}
	CBgObjPlayDf1::~CBgObjPlayDf1()
	{
	}
	void CBgObjPlayDf1::Initialize()
	{
		mImage = CResources::FnLoad<CImage>(L"PlayDf1_Obj", L"..\\Resources\\BG_Obj\\10_DreamForest1_BgObj.bmp");

		//mAnimator = FnAddComponent<CAnimator>();

		//mAnimator->FnCreateAnimation(L"PlayDf1_Obj", mImage, VectorXY(0.0f, 0.0f), 1, 1, 1, VectorXY::Zero, 0.1);

		//mAnimator->FnPlay(L"PlayDf1_Obj", true);

		CGameObject::Initialize();
	}
	void CBgObjPlayDf1::Update()
	{
		CGameObject::Update();
	}
	void CBgObjPlayDf1::Render(HDC hdc)
	{
		CGameObject::Render(hdc);

		//BitBlt(hdc, 0, 0,
		//	mImage->FnGetWidth(), mImage->FnGetHeight(),
		//	mImage->FnGetHdc(), 0, 0, SRCCOPY);


		//CTransform* Tr
		//	= mAnimator->FnGetOwner()->FnGetComponent<CTransform>();
		//VectorXY Scale = Tr->GetScale();

		//VectorXY Pos = Tr->FnGetPos();
		//Pos = CCamera::FnCaluatePos(Pos);
		//Pos += mSpriteSheet[mSpriteIndex].Offset;
		//Pos.X -= mSpriteSheet[mSpriteIndex].Size.X / 2.0f;
		//Pos.Y -= mSpriteSheet[mSpriteIndex].Size.Y;

		TransparentBlt(hdc
			, 0 //, Pos.X
			, 0 //, Pos.Y
			, mImage->FnGetWidth() * 1.5
			, mImage->FnGetHeight() * 1.5
			, mImage->FnGetHdc()
			, 0
			, 0
			, mImage->FnGetWidth()
			, mImage->FnGetHeight()
			, RGB(255, 0, 255)
		);

	}
	void CBgObjPlayDf1::Release()
	{
		CGameObject::Release();
	}
}
