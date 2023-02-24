#include "CScene.h"

namespace yha
{
	CScene::CScene()
	{
		mLayers.resize((UINT)ELayerType::End);
	}
	CScene::~CScene()
	{
	}
	void CScene::Initialize()
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Initialize();
		}
	}
	void CScene::Update()
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Update();
		}
	}
	void CScene::Render(HDC hdc)
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Render(hdc);
		}
	}
	void CScene::Release()
	{
		for (CLayer& Layer : mLayers)
		{
			Layer.Release();
		}
	}
	void CScene::FnOnEnter()
	{
	}
	void CScene::FnOnExit()
	{
	}
	void CScene::FnAddGameObject(CGameObject* Obj, ELayerType Layer)
	{
		mLayers[(UINT)Layer].FnAddGameObject(Obj);
	}
}
