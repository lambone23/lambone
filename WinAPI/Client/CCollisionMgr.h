#pragma once
#include "CommonInclude.h"
#include "CEnums.h"
#include "CCollider.h"

namespace yha
{
	union ColliderID
	{
		struct
		{
			UINT32 Left;
			UINT32 Right;
		};
		UINT64 Id;
	};

	class CScene;

	class CCollisionMgr
	{
	public:
		static void Update();

	public:
		static void FnLayerCollision(CScene* Scene, ELayerType Left, ELayerType Right);
		static void FnColliderCollision(CCollider* LeftCol, CCollider* RightCol, ELayerType Left, ELayerType Right);
		static bool FnIntersect(CCollider* Left, CCollider* Right);

		static void FnSetLayer(ELayerType Left, ELayerType Right, bool Value);
		static void FnClear();

	private:
		static WORD mMatrix[(UINT)ELayerType::End];
		static std::map<UINT64, bool> mCollisionMap;
	};

}

