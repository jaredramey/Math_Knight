#include "Math_Knight.h"

namespace MK
{
	#pragma region Constructors
	Vec4::Vec4()
	{
		entries.X = 0;
		entries.Y = 0;
		entries.Z = 0;
		entries.W = 0;
	}

	Vec4::Vec4(float x, float y, float z, float w)
	{
		entries.X = x;
		entries.Y = y;
		entries.Z = z;
		entries.W = w;
	}

	Vec4::Vec4(std::vector<float> &vector)
	{
		entries.X = vector[0];
		entries.Y = vector[1];
		entries.Z = vector[2];
		entries.W = vector[3];
	}

	Vec4::Vec4(float vector[4])
	{
		entries.X = vector[0];
		entries.Y = vector[1];
		entries.Z = vector[2];
		entries.W = vector[3];
	}

	Vec4::Vec4(const unsigned int hex)
	{
		unsigned int mask = 0x000000FF;
		unsigned int color = hex;

		entries.W = color & mask;
		color = color >> 8;
		entries.Z = color & mask;
		color = color >> 8;
		entries.Y = color & mask;
		color = color >> 8;
		entries.X = color & mask;
	}

	Vec4::~Vec4()
	{

	}
	#pragma endregion Constructors

	#pragma region Custom_Functions
	Vec4 Vec4::Normalize(const Vec4 &vector)
	{
		entries.X = entries.X / (sqrt((entries.X * entries.X) + (entries.Y * entries.Y) + (entries.Z * entries.Z) + (entries.W * entries.W)));
		entries.Y = entries.Y / (sqrt((entries.X * entries.X) + (entries.Y * entries.Y) + (entries.Z * entries.Z) + (entries.W * entries.W)));
		entries.Z = entries.Z / (sqrt((entries.X * entries.X) + (entries.Y * entries.Y) + (entries.Z * entries.Z) + (entries.W * entries.W)));
		entries.W = entries.W / (sqrt((entries.X * entries.X) + (entries.Y * entries.Y) + (entries.Z * entries.Z) + (entries.W * entries.W)));

		//If i'm not mistaken this should return the current Vec4 that's being worked on
		//(for debugging and testing purposes) but i'm not entirely sure on that.
		return *this;
	}
	#pragma endregion Custom_Functions

	#pragma region Operator_Overloads
	Vec4 Vec4::operator * (const Vec4 &factor)
	{
		entries.X = entries.X * factor.entries.X;
		entries.Y = entries.Y * factor.entries.Y;
		entries.Z = entries.Z * factor.entries.Z;
		entries.W = entries.W * factor.entries.W;
	}
	Vec4 Vec4::operator *= (const Vec4 &factor)
	{
		entries.X = entries.X *= factor.entries.X;
		entries.Y = entries.Y *= factor.entries.Y;
		entries.Z = entries.Z *= factor.entries.Z;
		entries.W = entries.W *= factor.entries.W;
	}
	Vec4 Vec4::operator + (const Vec4 &term)
	{
		entries.X = entries.X + term.entries.X;
		entries.Y = entries.Y + term.entries.Y;
		entries.Z = entries.Z + term.entries.Z;
		entries.W = entries.W + term.entries.W;
	}
	Vec4 Vec4::operator += (const Vec4 &term)
	{
		entries.X = entries.X += term.entries.X;
		entries.Y = entries.Y += term.entries.Y;
		entries.Z = entries.Z += term.entries.Z;
		entries.W = entries.W += term.entries.W;
	}
	Vec4 Vec4::operator - (const Vec4 &term)
	{
		entries.X = entries.X - term.entries.X;
		entries.Y = entries.Y - term.entries.Y;
		entries.Z = entries.Z - term.entries.Z;
		entries.W = entries.W - term.entries.W;
	}
	Vec4 Vec4::operator -= (const Vec4 &term)
	{
		entries.X = entries.X -= term.entries.X;
		entries.Y = entries.Y -= term.entries.Y;
		entries.Z = entries.Z -= term.entries.Z;
		entries.W = entries.W -= term.entries.W;
	}
	Vec4 Vec4::operator = (const Vec4 &equivalent)
	{
		entries.X = equivalent.entries.X;
		entries.Y = equivalent.entries.Y;
		entries.Z = equivalent.entries.Z;
		entries.W = equivalent.entries.W;
	}
	bool Vec4::operator == (const Vec4 &check)
	{
		if (entries.X == check.entries.X &&
			entries.Y == check.entries.Y &&
			entries.Z == check.entries.Z &&
			entries.W == check.entries.W)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	#pragma endregion Operator_Overloads
}