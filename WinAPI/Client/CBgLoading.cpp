//#include "CBgLoading.h"
//
//#include "CTime.h"
//#include "CSceneMgr.h"
//#include "CInput.h"
//#include "CResources.h"
//#include "CTransform.h"
//
//namespace yha
//{
//	CBgLoading::CBgLoading()
//	{
//
//	}
//	CBgLoading::~CBgLoading()
//	{
//	}
//	void CBgLoading::Initialize()
//	{
//		mImage = CResources::FnLoad<CImage>(L"Loading", L"..\\Resources\\tmp\\03_Loading.bmp");
//
//		CGameObject::Initialize();
//	}
//	void CBgLoading::Update()
//	{
//		CGameObject::Update();
//	}
//	void CBgLoading::Render(HDC hdc)
//	{
//		CGameObject::Render(hdc);
//
//		CTransform* Tr = FnGetComponent<CTransform>();
//		VectorXY Pos = Tr->FnGetPos();
//
//		BitBlt(hdc, Pos.X, Pos.Y,
//			mImage->FnGetWidth(), mImage->FnGetHeight(),
//			mImage->FnGetHdc(), 0, 0, SRCCOPY);
//
//	}
//	void CBgLoading::Release()
//	{
//		CGameObject::Release();
//	}
//}
