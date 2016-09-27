#include "Math_Knight.h"

namespace MK
{
	#pragma region Constructors
	//Default constructor that fills all values to 0
	Mat3x1::Mat3x1()
	{
		entries.zeroZero = 0;
		entries.oneZero = 0;
		entries.twoZero = 0;
	}

	//Construct from Vector
	Mat3x1::Mat3x1(std::vector<float> &matrix)
	{
		entries.zeroZero = matrix[0];
		entries.oneZero = matrix[1];
		entries.twoZero = matrix[2];
	}

	//Construct from an array
	Mat3x1::Mat3x1(float matrix[3])
	{
		entries.zeroZero = matrix[0];
		entries.oneZero = matrix[1];
		entries.twoZero = matrix[2];
	}
	#pragma endregion

	#pragma region Custom_Functions
	#pragma endregion

	#pragma region Operator_Overloads
	Mat3x1 Mat3x1::operator * (const Mat3x1 &term)
	{

	}
	#pragma endregion
}