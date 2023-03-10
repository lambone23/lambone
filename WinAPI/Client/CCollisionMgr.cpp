#include "CCollisionMgr.h"

#include "CScene.h"
#include "CSceneMgr.h"

namespace yha
{
	WORD CCollisionMgr::mMatrix[(UINT)ELayerType::End] = {};
	std::map<UINT64, bool> CCollisionMgr::mCollisionMap;
	void CCollisionMgr::Update()
	{
		CScene* Scene = CSceneMgr::FnGetActiveScene();

		for (UINT Row = 0; Row < (UINT)ELayerType::End; Row++)
		{
			for (UINT Col = 0; Col < (UINT)ELayerType::End; Col++)
			{
				if (mMatrix[Row] & (1 << Col))
				{
					FnLayerCollision(Scene, (ELayerType)Row, (ELayerType)Col);
				}
			}
		}
	}

	void CCollisionMgr::FnLayerCollision(CScene* Scene, ELayerType Left, ELayerType Right)
	{
		std::vector<CGameObject*>& Lefts = Scene->FnGetGameObjects(Left);
		std::vector<CGameObject*>& Rights = Scene->FnGetGameObjects(Right);

		for (auto LeftObject : Lefts)
		{
			CCollider* LeftCollider = LeftObject->FnGetComponent<CCollider>();
			if (LeftCollider == nullptr)
				continue;

			for (auto RightObject : Rights)
			{
				CCollider* RightCollider = RightObject->FnGetComponent<CCollider>();
				if (RightCollider == nullptr)
					continue;

				if (LeftObject == RightObject)
					continue;

				FnColliderCollision(LeftCollider, RightCollider, Left, Right);
			}
		}
	}

	void CCollisionMgr::FnColliderCollision(CCollider* LeftCol, CCollider* RightCol, ELayerType Left, ELayerType Right)
	{
		ColliderID colliderID = {};
		colliderID.Left = (UINT)LeftCol->FnGetID();
		colliderID.Right = (UINT)RightCol->FnGetID();

		//static std::map<UINT64, bool> mCollisionMap;
		std::map<UINT64, bool>::iterator Iter
			= mCollisionMap.find(colliderID.Id);

		if (Iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(colliderID.Id, false));
			Iter = mCollisionMap.find(colliderID.Id);
		}

		if (FnIntersect(LeftCol, RightCol))
		{
			if (Iter->second == false)
			{// 최초 충돌 시작했을때 enter

				LeftCol->FnOnCollisionEnter(RightCol);
				RightCol->FnOnCollisionEnter(LeftCol);

				Iter->second = true;
			}
			else
			{// 충돌 중인상태 stay

				LeftCol->FnOnCollisionStay(RightCol);
				RightCol->FnOnCollisionStay(LeftCol);
			}
		}
		else
		{
			// Exit
			// 이전프레임 충돌 O
			// 현재는 충돌 X 
			if (Iter->second == true)
			{
				LeftCol->FnOnCollisionExit(RightCol);
				RightCol->FnOnCollisionExit(LeftCol);

				Iter->second = false;
			}
		}
	}

	bool CCollisionMgr::FnIntersect(CCollider* Left, CCollider* Right)
	{
		VectorXY LeftPos = Left->FnGetPos();
		VectorXY RightPos = Right->FnGetPos();

		// 두 충돌체 간의 거리와,
		// 각 면적의 절반끼리의 합을 비교.
		// 거리가 더 길다면 충돌 X,
		// 거리가 더 짧다면 충돌 O
		VectorXY LeftSize = Left->FnGetSize();
		VectorXY RightSize = Right->FnGetSize();

		//부동 소수점의 절대값을 연산
		if (fabs(LeftPos.X - RightPos.X) < (LeftSize.X / 2.0f) + (RightSize.X / 2.0f)
			&& fabs(LeftPos.Y - RightPos.Y) < (LeftSize.Y / 2.0f) + (RightSize.Y / 2.0f))
		{
			return true;
		}

		return false;
	}

	void CCollisionMgr::FnSetLayer(ELayerType Left, ELayerType Right, bool Value)
	{
		UINT Row = 0;
		UINT Col = 0;

		UINT iLeft = (UINT)Left;
		UINT iRight = (UINT)Right;

		if (Left <= Right)
		{
			Row = iLeft;
			Col = iRight;
		}
		else
		{
			Row = iRight;
			Col = iLeft;
		}

		if (Value == true)
			mMatrix[Row] |= (1 << Col);
		else
			mMatrix[Row] &= ~(1 << Col);
	}

	void CCollisionMgr::FnClear()
	{
		memset(mMatrix, 0, sizeof(WORD) * (UINT)ELayerType::End);
		mCollisionMap.clear();
	}
}
