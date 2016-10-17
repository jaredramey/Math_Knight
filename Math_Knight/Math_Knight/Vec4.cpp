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
		color = color & mask;
		entries.X = color & mask;
	}

	Vec4::~Vec4()
	{

	}
	#pragma endregion Constructors

	#pragma region Custom_Functions
	Vec4 Vec4::Normalize(const Vec4 &vector)
	{
		entries.X = 0;
		entries.Y = 0;
		entries.Z = 0;
		entries.W = 0;
	}
	#pragma endregion Custom_Functions

	#pragma region Operator_Overloads
	#pragma endregion Operator_Overloads
}