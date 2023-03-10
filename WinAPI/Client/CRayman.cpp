#include "CRayman.h"

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
	CRayman::CRayman()
	{
	}
	CRayman::~CRayman()
	{
	}

	void CRayman::Initialize()
	{
		CImage* mImage_Walk = CResources::FnLoad<CImage>(L"Rayman_Walk", L"..\\Resources\\Rayman\\Rayman_Walk.bmp");
		//CImage* mImage_Walk = CResources::FnLoad<CImage>(L"Rayman_Walk", L"..\\Resources\\Rayman_Walk.bmp");
		CImage* mImage_Idle = CResources::FnLoad<CImage>(L"Rayman_Idle", L"..\\Resources\\Rayman\\Rayman_Idle.bmp");
		//CImage* mImage_Idle = CResources::FnLoad<CImage>(L"Rayman_Idle", L"..\\Resources\\Rayman_Idle.bmp");
		
		mAnimator = FnAddComponent<CAnimator>();

		//void CAnimator::FnCreateAnimation(const std::wstring & Name
		//	, CImage * Sheet, VectorXY LeftTop
		//	, UINT Column, UINT Row, UINT SpriteLength
		//	, VectorXY Offset, float Duration)

		//mAnimator->FnCreateAnimation(L"FowardRun", mImage, Vector2::Zero, 16, 8, 16, Vector2::Zero, 0.1);
		//mAnimator->FnCreateAnimation(L"FowardRight", mImage, VectorXY(0.0f, 113.0f), 16, 8, 15, VectorXY::Zero, 0.1);
		//mAnimator->FnCreateAnimation(L"Foward_R", mImage_Walk, VectorXY(0.0f, 0.0f), 11, 1, 11, VectorXY::Zero, 0.05);
		mAnimator->FnCreateAnimation(L"Foward_R", mImage_Walk, VectorXY(0.0f, 0.0f), 5, 2, 5, VectorXY::Zero, 0.2);
		mAnimator->FnCreateAnimation(L"Foward_L", mImage_Walk, VectorXY(0.0f, 400.0f), 5, 2, 5, VectorXY::Zero, 0.2);
		mAnimator->FnCreateAnimation(L"Idle_R", mImage_Idle, VectorXY(0.0f, 0.0f), 9, 2, 9, VectorXY::Zero, 0.2);
		mAnimator->FnCreateAnimation(L"Idle_L", mImage_Idle, VectorXY(0.0f, 400.0f), 9, 2, 9, VectorXY::Zero, 0.2);

		//mAnimator->FnCreateAnimations(L"..\\Resources\\Chalise\\Idle", Vector2::Zero, 0.1f);

		//mAnimator->FnGetStartEvent(L"Idle_R") = std::bind(&CRayman::FnIdleCompleteEvent, this);
		mAnimator->FnPlay(L"Idle_R", true);
		//mAnimator->FnPlay(L"FowardRight", true);

		CCollider* collider = FnAddComponent<CCollider>();
		collider->FnSetCenter(VectorXY(-60.0f, -80.0f));

		mState = ERaymanState::Idle;

		CGameObject::Initialize();
	}

	void CRayman::Update()
	{
		CGameObject::Update();

		switch (mState)
		{
		case yha::CRayman::ERaymanState::Move:
			FnMove();
			break;
		case yha::CRayman::ERaymanState::Shoot:
			FnShoot();
			break;
		case yha::CRayman::ERaymanState::Death:
			FnDeath();
			break;
		case yha::CRayman::ERaymanState::Idle:
			FnIdle();
			break;
		default:
			break;
		}

		/*Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		Animator* animator = GetComponent<Animator>();
		if (Input::GetKeyState(eKeyCode::A) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::D) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Down)
		{
			animator->Play(L"FowardRun", true);
		}
		if (Input::GetKeyState(eKeyCode::W) == eKeyState::Up)
		{
			animator->Play(L"Idle", true);
		}

		if (Input::GetKeyState(eKeyCode::S) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		tr->SetPos(pos);*/
	}

	void CRayman::Render(HDC hdc)
	{
		CGameObject::Render(hdc);
	}
	void CRayman::Release()
	{
		CGameObject::Release();

	}

	void CRayman::FnOnCollisionEnter(CCollider* Other)
	{

	}

	void CRayman::FnOnCollisionStay(CCollider* Other)
	{

	}

	void CRayman::FnOnCollisionExit(CCollider* Other)
	{

	}

	void CRayman::FnMove()
	{
		if (/*CInput::FnGetKeyUp(EKeyCode::A)
			|| CInput::FnGetKeyUp(EKeyCode::D)
			|| CInput::FnGetKeyUp(EKeyCode::S)
			|| CInput::FnGetKeyUp(EKeyCode::W))*/
			CInput::FnGetKeyUp(EKeyCode::D)
			)
		{
			mState = ERaymanState::Idle;
			mAnimator->FnPlay(L"Idle_R", true);
		}
		if (/*CInput::FnGetKeyUp(EKeyCode::A)
			|| CInput::FnGetKeyUp(EKeyCode::D)
			|| CInput::FnGetKeyUp(EKeyCode::S)
			|| CInput::FnGetKeyUp(EKeyCode::W))*/
			CInput::FnGetKeyUp(EKeyCode::A)
			)
		{
			mState = ERaymanState::Idle;
			mAnimator->FnPlay(L"Idle_L", true);
		}

		CTransform* Tr = FnGetComponent<CTransform>();
		VectorXY Pos = Tr->FnGetPos();

		if (CInput::FnGetKey(EKeyCode::A))
			Pos.X -= 100.0f * CTime::FnDeltaTime();

		if (CInput::FnGetKey(EKeyCode::D))
			Pos.X += 100.0f * CTime::FnDeltaTime();

		if (CInput::FnGetKey(EKeyCode::W))
			Pos.Y -= 100.0f * CTime::FnDeltaTime();

		if (CInput::FnGetKey(EKeyCode::S))
			Pos.Y += 100.0f * CTime::FnDeltaTime();

		Tr->FnSetPos(Pos);
	}
	void CRayman::FnShoot()
	{
	}
	void CRayman::FnDeath()
	{
	}
	void CRayman::FnIdle()
	{
		if (//CInput::FnGetKeyDown(EKeyCode::A)
			//|| CInput::FnGetKeyDown(EKeyCode::D)
			//|| CInput::FnGetKeyDown(EKeyCode::S)
			//|| CInput::FnGetKeyDown(EKeyCode::W))
			CInput::FnGetKeyDown(EKeyCode::D)
			)
		{
			mState = ERaymanState::Move;
			mAnimator->FnPlay(L"Foward_R", true);
		}

		if (//CInput::FnGetKeyDown(EKeyCode::A)
			//|| CInput::FnGetKeyDown(EKeyCode::D)
			//|| CInput::FnGetKeyDown(EKeyCode::S)
			//|| CInput::FnGetKeyDown(EKeyCode::W))
			CInput::FnGetKeyDown(EKeyCode::A)
			)
		{
			mState = ERaymanState::Move;
			mAnimator->FnPlay(L"Foward_L", true);
		}
	}

	void CRayman::FnIdleCompleteEvent(/*const Cuphead* this*/)
	{
		int a = 0;
		//mState =
		//Transform* tr = GetComponent<Transform>();
		//Scene* curScene = SceneManager::GetActiveScene();
		//BaseBullet* bullet = new BaseBullet();
		//bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
		//curScene->AddGameObeject(bullet, eLayerType::Bullet);
	}













	//CRayman::CRayman()
	//{
	//}
	//CRayman::~CRayman()
	//{
	//}
	//void CRayman::Initialize()
	//{
	//	mImage = CResources::FnLoad<CImage>(L"Player_MapRayman", L"..\\Resources\\BmpRaymanR.bmp");

	//	CGameObject::Initialize();
	//}
	//void CRayman::Update()
	//{
	//	CGameObject::Update();

	//	CTransform* Tr = FnGetComponent<CTransform>();
	//	VectorXY Pos = Tr->FnGetPos();

	//	if (CInput::FnGetKeyState(EKeyCode::A) == EKeyState::Pressed)
	//	{
	//		Pos.X -= 100.0f * CTime::FnDeltaTime();
	//	}

	//	if (CInput::FnGetKeyState(EKeyCode::D) == EKeyState::Pressed)
	//	{
	//		Pos.X += 100.0f * CTime::FnDeltaTime();
	//	}

	//	if (CInput::FnGetKeyState(EKeyCode::W) == EKeyState::Pressed)
	//	{
	//		Pos.Y -= 100.0f * CTime::FnDeltaTime();
	//	}

	//	if (CInput::FnGetKeyState(EKeyCode::S) == EKeyState::Pressed)
	//	{
	//		Pos.Y += 100.0f * CTime::FnDeltaTime();
	//	}
	//	Tr->FnSetPos(Pos);
	//}
	//void CRayman::Render(HDC hdc)
	//{
	//	CGameObject::Render(hdc);
	//	CTransform* Tr = FnGetComponent<CTransform>();
	//	VectorXY Pos = Tr->FnGetPos();
	//	BitBlt(hdc, Pos.X, Pos.Y,
	//		mImage->FnGetWidth(), mImage->FnGetHeight(),
	//		mImage->FnGetHdc(), 0, 0, SRCCOPY);
	//}
	//void CRayman::Release()
	//{
	//	CGameObject::Release();
	//}
}