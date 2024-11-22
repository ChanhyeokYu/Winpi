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
	int32 Defence = 0;
	int32 Attack = 0;
	float Speed = 0.f;
};

struct Vector
{
	Vector(){}
	Vector(float x, float y) : x(x), y(y) {}
	// 벡터의 마우스 포인터 값 기본 생성자
	Vector(POINT pt) : x(static_cast<float>(pt.x)),y(static_cast<float>(pt.y)) {}

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
		y *= y = value;
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

	float Dot(Vector other)
	{
		// 내적 예각 내 대각 길이 계산
		return x * other.x + y * other.y;
	}

	float Cross(Vector other)
	{
		return x * other.y - y * other.x;
	}

	float x = 0;
	float y = 0;
};


struct VectorInt
{
	VectorInt() {}
	VectorInt(int32 x, int32 y) : x(x), y(y) {}
	// 벡터의 마우스 포인터 값 기본 생성자
	VectorInt(POINT pt) : x(static_cast<int32>(pt.x)), y(static_cast<int32>(pt.y)) {}

	VectorInt	operator+(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x + other.x;
		ret.y = y + other.y;
		return ret;
	}


	VectorInt	operator-(const VectorInt& other)
	{
		VectorInt ret;
		ret.x = x - other.x;
		ret.y = y - other.y;
		return ret;
	}

	VectorInt operator*(float value)
	{
		VectorInt ret;
		ret.x = x * value;
		ret.y = y * value;
		return ret;
	}

	void operator+=(const VectorInt& other)
	{
		x = x + other.x;
		y = y + other.y;
	}

	void operator-=(const VectorInt& other)
	{
		x = x - other.x;
		y = y - other.y;
	}

	bool operator<(const VectorInt& other) const
	{
		if ( x != other.x)
		{
			return x < other.x;
		}
		return y < other.y;

	}

	bool operator>(const VectorInt& other) const
	{
		if (x != other.x)
		{
			return x > other.x;
		}
		return y > other.y;

	}

	bool operator==(const VectorInt& other)
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const VectorInt& other)
	{
		return !(*this == other);
	}

	int32 LengthSquared()
	{
		return x * x + y * y;
	}

	float Length()
	{
		return (float)::sqrt(LengthSquared());
	}

	float Dot(VectorInt other)
	{
		// 내적 예각 내 대각 길이 계산
		return x * other.x + y * other.y;
	}

	float Cross(VectorInt other)
	{
		return x * other.y - y * other.x;
	}

	int32 x = 0;
	int32 y = 0;
};

using Pos = Vector;
