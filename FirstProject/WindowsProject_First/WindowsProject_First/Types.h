#pragma once
#include "cmath"
using int8 = __int8;
using int16 = __int16;
using int32 = __int32;
using int64 = __int64;
using uint8 = unsigned __int8;
using uint16 = unsigned __int16;
using uint32 = unsigned __int32;
using uint64 = unsigned __int64;

struct Stat
{
	int32 Hp = 0;
	int32 maxHp = 0;
	float Speed = 0.f;
};

struct Vector
{
	Vector(){}
	Vector(float x, float y) : x(x), y(y) {}

	Vector	operator+(const Vector& other)
	{
		Vector ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}


	Vector	operator-(const Vector& other)
	{
		Vector ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	Vector operator*(float value)
	{
		Vector ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}

	void operator+=(const Vector& other)
	{
		x = x + other.x;
		y = y + other.y;
	}

	void operator-=(const Vector& other)
	{
		x = x - other.x;
		y = y - other.y;
	}

	void operator*=(float value)
	{
		x *= x = value;
		y *= x = value;
	}

	float LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return ::sqrt(LengthSquared());
	}

	void Normalize()
	{
		float length = Length();
		if (length < 0.0000000000001f)
		{
			return;
		}
		x /= length;
		y /= length;

	}


	float x = 0;
	float y = 0;
};

using Pos = Vector;
