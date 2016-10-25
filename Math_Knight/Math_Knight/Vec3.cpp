#include "Math_Knight.h"

namespace MK
{
	#pragma region Constructors
	Vec3::Vec3()
	{
		entries.X = 0;
		entries.Y = 0;
		entries.Z = 0;
	}
	Vec3::Vec3(float X, float Y, float Z)
	{
		entries.X = X;
		entries.Y = Y;
		entries.Z = Z;
	}
	Vec3::Vec3(std::vector<float> &vector)
	{
		entries.X = vector[0];
		entries.Y = vector[1];
		entries.Z = vector[2];
	}
	Vec3::Vec3(float vector[3])
	{
		entries.X = vector[0];
		entries.Y = vector[1];
		entries.Z = vector[2];
	}
	Vec3::~Vec3()
	{

	}
	#pragma endregion Constructors

	#pragma region Custom_Functions
	float Vec3::Magnitude(const Vec3 &vector)
	{
		float result = 0;

		result += sqrt((entries.X *entries.X) + (entries.Y * entries.Y) + (entries.Z + entries.Z));

		return result;
	}
	float Vec3::DotProduct(const Vec3 &otherVec3)
	{
		float result = 0;

		result = (entries.X * otherVec3.entries.X) + (entries.Y * otherVec3.entries.Y) + (entries.Z * otherVec3.entries.Z); \

		return result;
	}
	float Vec3::CrossProduct(const Vec3 &otherVec3)
	{
		float result = 0;

		result = ((entries.Y*otherVec3.entries.Z) + 
				  (entries.Z*otherVec3.entries.X) + 
				  (entries.X*otherVec3.entries.Y) - 
				  (entries.X*otherVec3.entries.Z) - 
				  (entries.Z*otherVec3.entries.Y) - 
				  (entries.Y*otherVec3.entries.X));

		return result;
	}
	Vec3 Vec3::Normalize(const Vec3)
	{
		entries.X = entries.X / Magnitude(*this);
		entries.Y = entries.Y / Magnitude(*this);
		entries.Z = entries.Z / Magnitude(*this);
	}
	#pragma endregion Custom_Functions

	#pragma region Operator_Overloads
	Vec3 Vec3::operator * (const Vec3 &factor)
	{
		entries.X = entries.X * factor.entries.X;
		entries.Y = entries.Y * factor.entries.Y;
		entries.Z = entries.Z * factor.entries.Z;
	}
	Vec3 Vec3::operator *= (const Vec3 &factor)
	{
		entries.X = entries.X *= factor.entries.X;
		entries.Y = entries.Y *= factor.entries.Y;
		entries.Z = entries.Z *= factor.entries.Z;
	}
	Vec3 Vec3::operator + (const Vec3 &term)
	{
		entries.X = entries.X + term.entries.X;
		entries.Y = entries.Y + term.entries.Y;
		entries.Z = entries.Z + term.entries.Z;
	}
	Vec3 Vec3::operator += (const Vec3 &term)
	{
		entries.X = entries.X += term.entries.X;
		entries.Y = entries.Y += term.entries.Y;
		entries.Z = entries.Z += term.entries.Z;
	}
	Vec3 Vec3::operator - (const Vec3 &term)
	{
		entries.X = entries.X - term.entries.X;
		entries.Y = entries.Y - term.entries.Y;
		entries.Z = entries.Z - term.entries.Z;
	}
	Vec3 Vec3::operator -= (const Vec3 &term)
	{
		entries.X = entries.X -= term.entries.X;
		entries.Y = entries.Y -= term.entries.Y;
		entries.Z = entries.Z -= term.entries.Z;
	}
	Vec3 Vec3::operator = (const Vec3 &equivalent)
	{
		entries.X = equivalent.entries.X;
		entries.Y = equivalent.entries.Y;
		entries.Z = equivalent.entries.Z;
	}
	bool Vec3::operator == (const Vec3 &equals)
	{
		if (entries.X == equals.entries.X &&
			entries.Y == equals.entries.Y &&
			entries.Z == equals.entries.Z)
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