#pragma once

struct VectorXY
{
	float X;
	float Y;

	VectorXY()
		: X(0.0f)
		, Y(0.0f)
	{

	}

	VectorXY(float X, float Y)
		: X(X)
		, Y(Y)
	{

	}

	VectorXY(int X, int Y)
		: X(X)
		, Y(Y)
	{

	}

	VectorXY(const VectorXY&) = default;
	VectorXY& operator=(const VectorXY&) = default;

	VectorXY(VectorXY&&) = default;
	VectorXY& operator=(VectorXY&&) = default;

	//VectorXY(VectorXY& other)
	//	: X(other.X)
	//	, Y(other.Y)
	//{

	//}
};