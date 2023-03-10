#pragma once

enum class ESceneType
{
	TitleUbi,
	Title,
	//Map,
	//Loading,
	PlayDf1,
	PlayDf2,
	//PlayDf3,
	PlayDfBoss,
	Ending,
	End
};

enum class ELayerType
{
	BG,
	BG_Obj,
	Monster,
	Player,
	Punch,
	Item,
	Effect,
	UI,
	End = 16
};

enum class EComponentType
{
	Transform,
	SpriteRenderer,
	Animator,
	Collider,
	Audio,
	End
};