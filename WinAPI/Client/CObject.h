#pragma once
#include "CGameObject.h"
#include "CScene.h"
#include "CSceneMgr.h"
#include "CTransform.h"

namespace yha::object
{
	template <typename T>
	static inline T* Instantiate(ELayerType Type)
	{
		T* GameObj = new T();
		CScene* Scene = CSceneMgr::FnGetActiveScene();

		Scene->FnAddGameObject(GameObj, Type);
		GameObj->Initialize();
		return GameObj;
	}

	template <typename T>
	static inline T* Instantiate(VectorXY Pos, ELayerType Type)
	{
		T* GameObj = new T();
		CScene* Scene = CSceneMgr::FnGetActiveScene();

		Scene->FnAddGameObject(GameObj, Type);
		GameObj->Initialize();
		GameObj->CGameObject::FnGetComponent<CTransform>()->FnSetPos(Pos);
		return GameObj;
	}


	static void FnDestory(CGameObject* Obj)
	{
		Obj->FnSetState(CGameObject::EState::Death);
	}
}