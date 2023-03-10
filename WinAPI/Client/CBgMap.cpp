//#include "CBgMap.h"
//
//#include "CTime.h"
//#include "CSceneMgr.h"
//#include "CInput.h"
//#include "CResources.h"
//
//namespace yha
//{
//	CBgMap::CBgMap()
//	{
//
//	}
//	CBgMap::~CBgMap()
//	{
//	}
//	void CBgMap::Initialize()
//	{
//		mImage = CResources::FnLoad<CImage>(L"Map", L"..\\Resources\\tmp\\02_Map.bmp");
//
//		CGameObject::Initialize();
//	}
//	void CBgMap::Update()
//	{
//		CGameObject::Update();
//	}
//	void CBgMap::Render(HDC hdc)
//	{
//		CGameObject::Render(hdc);
//
//		BitBlt(hdc, 0, 0,
//			mImage->FnGetWidth(), mImage->FnGetHeight(),
//			mImage->FnGetHdc(), 0, 0, SRCCOPY);
//
//	}
//	void CBgMap::Release()
//	{
//		CGameObject::Release();
//	}
//}
