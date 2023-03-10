#include "CBlueChomper.h"

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
	CBlueChomper::CBlueChomper()
	{
	}
	CBlueChomper::~CBlueChomper()
	{
	}

	void CBlueChomper::Initialize()
	{
		CImage* mImage_Idle = CResources::FnLoad<CImage>(L"BlueChomper_Idle", L"..\\Resources\\Monster\\BlueChomper\\BlueChomper_Idle.bmp");
		CImage* mImage_Attack = CResources::FnLoad<CImage>(L"BlueChomper_Walk", L"..\\Resources\\Monster\\BlueChomper\\BlueChomper_Attack.bmp");


		mAnimator = FnAddComponent<CAnimator>();

		//void CAnimator::FnCreateAnimation(const std::wstring & Name
		//	, CImage * Sheet, VectorXY LeftTop
		//	, UINT Column, UINT Row, UINT SpriteLength
		//	, VectorXY Offset, float Duration)

		mAnimator->FnCreateAnimation(L"Idle_R", mImage_Idle, VectorXY(0.0f, 0.0f), 4, 2, 4, VectorXY::Zero, 0.2);
		mAnimator->FnCreateAnimation(L"Idle_L", mImage_Idle, VectorXY(0.0f, 180.0f), 4, 2, 4, VectorXY::Zero, 0.2);

		mAnimator->FnCreateAnimation(L"Attck_R", mImage_Attack, VectorXY(0.0f, 0.0f), 7, 2, 7, VectorXY::Zero, 0.2);
		mAnimator->FnCreateAnimation(L"Attck_L", mImage_Attack, VectorXY(0.0f, 400.0f), 7, 2, 7, VectorXY::Zero, 0.2);


		//mAnimator->FnGetStartEvent(L"Idle_R") = std::bind(&CRayman::FnIdleCompleteEvent, this);
		mAnimator->FnPlay(L"Idle_L", true);
		//mAnimator->FnPlay(L"FowardRight", true);

		CCollider* collider = FnAddComponent<CCollider>();
		collider->FnSetCenter(VectorXY(-60.0f, -80.0f));

		mState = EBlueChomperState::Idle;

		CGameObject::Initialize();
	}

	void CBlueChomper::Update()
	{
		CGameObject::Update();

		//switch (mState)
		//{
		//case yha::CBlueChomper::ERaymanState::Move:
		//	FnMove();
		//	break;
		//case yha::CBlueChomper::ERaymanState::Shoot:
		//	FnShoot();
		//	break;
		//case yha::CBlueChomper::ERaymanState::Death:
		//	FnDeath();
		//	break;
		//case yha::CBlueChomper::ERaymanState::Idle:
		//	FnIdle();
		//	break;
		//default:
		//	break;
		//}

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

	void CBlueChomper::Render(HDC hdc)
	{
		CGameObject::Render(hdc);
	}
	void CBlueChomper::Release()
	{
		CGameObject::Release();

	}

	void CBlueChomper::FnOnCollisionEnter(CCollider* Other)
	{
		mState = EBlueChomperState::Attack;
		mAnimator->FnPlay(L"Attck_L", true);
	}

	void CBlueChomper::FnOnCollisionStay(CCollider* Other)
	{

	}

	void CBlueChomper::FnOnCollisionExit(CCollider* Other)
	{
		mState = EBlueChomperState::Idle;
		mAnimator->FnPlay(L"Idle_L", true);
	}

	void CBlueChomper::FnMove()
	{
		//if (/*CInput::FnGetKeyUp(EKeyCode::A)
		//	|| CInput::FnGetKeyUp(EKeyCode::D)
		//	|| CInput::FnGetKeyUp(EKeyCode::S)
		//	|| CInput::FnGetKeyUp(EKeyCode::W))*/
		//	CInput::FnGetKeyUp(EKeyCode::D)
		//	)
		//{
		//	mState = ERaymanState::Idle;
		//	mAnimator->FnPlay(L"Idle_R", true);
		//}
		//if (/*CInput::FnGetKeyUp(EKeyCode::A)
		//	|| CInput::FnGetKeyUp(EKeyCode::D)
		//	|| CInput::FnGetKeyUp(EKeyCode::S)
		//	|| CInput::FnGetKeyUp(EKeyCode::W))*/
		//	CInput::FnGetKeyUp(EKeyCode::A)
		//	)
		//{
		//	mState = ERaymanState::Idle;
		//	mAnimator->FnPlay(L"Idle_L", true);
		//}

		//CTransform* Tr = FnGetComponent<CTransform>();
		//VectorXY Pos = Tr->FnGetPos();

		//if (CInput::FnGetKey(EKeyCode::A))
		//	Pos.X -= 100.0f * CTime::FnDeltaTime();

		//if (CInput::FnGetKey(EKeyCode::D))
		//	Pos.X += 100.0f * CTime::FnDeltaTime();

		//if (CInput::FnGetKey(EKeyCode::W))
		//	Pos.Y -= 100.0f * CTime::FnDeltaTime();

		//if (CInput::FnGetKey(EKeyCode::S))
		//	Pos.Y += 100.0f * CTime::FnDeltaTime();

		//Tr->FnSetPos(Pos);
	}
	void CBlueChomper::FnShoot()
	{
	}
	void CBlueChomper::FnDeath()
	{
	}
	void CBlueChomper::FnIdle()
	{
		//if (//CInput::FnGetKeyDown(EKeyCode::A)
		//	//|| CInput::FnGetKeyDown(EKeyCode::D)
		//	//|| CInput::FnGetKeyDown(EKeyCode::S)
		//	//|| CInput::FnGetKeyDown(EKeyCode::W))
		//	CInput::FnGetKeyDown(EKeyCode::D)
		//	)
		//{
		//	mState = ERaymanState::Move;
		//	mAnimator->FnPlay(L"Foward_R", true);
		//}

		//if (//CInput::FnGetKeyDown(EKeyCode::A)
		//	//|| CInput::FnGetKeyDown(EKeyCode::D)
		//	//|| CInput::FnGetKeyDown(EKeyCode::S)
		//	//|| CInput::FnGetKeyDown(EKeyCode::W))
		//	CInput::FnGetKeyDown(EKeyCode::A)
		//	)
		//{
		//	mState = ERaymanState::Move;
		//	mAnimator->FnPlay(L"Foward_L", true);
		//}
	}

	void CBlueChomper::FnIdleCompleteEvent(/*const Cuphead* this*/)
	{
		int a = 0;
		//mState =
		//Transform* tr = GetComponent<Transform>();
		//Scene* curScene = SceneManager::GetActiveScene();
		//BaseBullet* bullet = new BaseBullet();
		//bullet->GetComponent<Transform>()->SetPos(tr->GetPos());
		//curScene->AddGameObeject(bullet, eLayerType::Bullet);
	}

}