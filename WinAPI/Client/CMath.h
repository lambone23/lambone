#pragma once
#include <math.h>
#define PI 3.141592

struct VectorXY
{
	static VectorXY Up;
	static VectorXY Right;

	static VectorXY One;
	static VectorXY Zero;

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

	VectorXY operator+(const VectorXY& Other)
	{
		VectorXY Temp;
		Temp.X = X + Other.X;
		Temp.Y = Y + Other.Y;

		return Temp;
	}

	VectorXY operator-(const VectorXY& Other)
	{
		VectorXY Temp;
		Temp.X = X - Other.X;
		Temp.Y = Y - Other.Y;

		return Temp;
	}

	VectorXY operator*(const VectorXY& Other)
	{
		VectorXY Temp;
		Temp.X = X * Other.X;
		Temp.Y = Y * Other.Y;

		return Temp;
	}

	VectorXY operator/(const float Ratio)
	{
		VectorXY Temp;
		Temp.X = X / Ratio;
		Temp.Y = Y / Ratio;

		return Temp;
	}

	void operator+=(const VectorXY& Other)
	{
		X += Other.X;
		Y += Other.Y;
	}

	void operator-=(const VectorXY& Other)
	{
		X -= Other.X;
		Y -= Other.Y;
	}

	float FnLength()
	{// 부동 소수점 숫자의 제곱근을 계산
		return sqrtf(X * X + Y * Y);
	}

	VectorXY& FnNormalize()
	{
		float Length = FnLength();
		X /= Length;
		Y /= Length;

		return *this;
	}
};

namespace yha::math
{
	//float x = dir.x * cosf(PI / 5.0f) - dir.y * sinf(PI / 5.0f);
	//float y = dir.x * sinf(PI / 5.0f) + dir.y * cosf(PI / 5.0f);

	inline static VectorXY FnRotate(VectorXY Vector, float Degree)
	{
		float radian = (Degree / 180.0f) * PI;
		Vector.FnNormalize();

		float X = Vector.X * cosf(radian) - Vector.Y * sinf(radian);
		float Y = Vector.X * sinf(radian) + Vector.Y * cosf(radian);
		//atan
		//atan();
		return VectorXY(X, Y);
	}


}