#include "CScenePlay.h"
#include "CRayman.h"

namespace yha
{
	CScenePlay::CScenePlay()
	{
	}

	CScenePlay::~CScenePlay()
	{
	}

	void CScenePlay::Initialize()
	{
		CRayman* Rayman = new CRayman();
		Rayman->SetName(L"Player");
		FnAddGameObject(Rayman, ELayerType::Player);

		CScene::Initialize();
	}

	void CScenePlay::Update()
	{
		CScene::Update();
	}

	void CScenePlay::Render(HDC hdc)
	{
		CScene::Render(hdc);
	}

	void CScenePlay::Release()
	{
		CScene::Release();
	}
}
