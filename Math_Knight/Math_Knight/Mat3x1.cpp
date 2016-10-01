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
	//This operator overload is used to multiply a 3x1 matricie by a 3x3 matricie
	Mat3x1 Mat3x1::operator * (const Mat3x3 &term)
	{
		entries.zeroZero = ((entries.zeroZero * term.entries.zeroZero) + (entries.zeroZero * term.entries.zeroOne) + (entries.zeroZero * term.entries.zeroTwo));
		entries.oneZero = ((entries.oneZero * term.entries.oneZero) + (entries.oneZero * term.entries.oneOne) + (entries.oneZero * term.entries.oneTwo));
		entries.twoZero = ((entries.twoZero * term.entries.twoZero) + (entries.twoZero * term.entries.twoOne) + (entries.twoZero * term.entries.twoTwo));
	}

	Mat3x1 Mat3x1::operator - (const Mat3x1 &term)
	{
		entries.zeroZero = (entries.zeroZero - term.entries.zeroZero);
		entries.oneZero = (entries.oneZero - term.entries.oneZero);
		entries.twoZero = (entries.twoZero - term.entries.twoZero);
	}

	Mat3x1 Mat3x1::operator + (const Mat3x1 &term)
	{
		entries.zeroZero = (entries.zeroZero + term.entries.zeroZero);
		entries.oneZero = (entries.oneZero + term.entries.oneZero);
		entries.twoZero = (entries.twoZero + term.entries.twoZero);
	}

	Mat3x1 Mat3x1::operator = (const Mat3x1 &equivalent)
	{
		entries.zeroZero = equivalent.entries.zeroZero;
		entries.oneZero = equivalent.entries.oneZero;
		entries.twoZero = equivalent.entries.twoZero;
	}

	bool Mat3x1::operator == (const Mat3x1 &check)
	{
		if (entries.zeroZero == check.entries.zeroZero &&
			entries.oneZero == check.entries.oneZero &&
			entries.twoZero == check.entries.twoZero)
		{
			return true;
		}

		else
		{
			return false;
		}
	}
	#pragma endregion
}