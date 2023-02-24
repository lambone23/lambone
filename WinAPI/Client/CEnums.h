#pragma once

enum class ESceneType
{
	TitleUbi,
	Title,
	Map,
	Loading,
	PlayDf1,
	PlayDf2,
	PlayDf3,
	PlayDfBoss,
	Ending,
	End,
};

enum class ELayerType
{
	BG,
	BG_Obj,
	Player,
	Monster,
	Item,
	Effect,
	UI,
	End,
};

enum class EComponentType
{
	Transform,
	Collider,
	SpriteRenderer,
	Animator,
	Audio,
	End,
};