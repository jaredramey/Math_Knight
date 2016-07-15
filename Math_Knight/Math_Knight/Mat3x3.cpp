#include "Math_Knight.h"

namespace MK
{
#pragma region Constructors
	//TODO: Fill out Mat3x3 Constructors

	//Default should set all values to 0
	Mat3x3::Mat3x3()
	{
		
	}
	//Build a Mat3x3 from a vector<vector<float>>
	Mat3x3::Mat3x3(std::vector<std::vector<float>> &matrix)
	{
		
	}
	//Build a Mat3x3 from a multidimensional array
	Mat3x3::Mat3x3(float matrix[3][3])
	{

	}
	//Build a Mat3x3 from an array
	Mat3x3::Mat3x3(float matrix[9])
	{

	}
	
	//Default deconstructor
	Mat3x3::~Mat3x3()
	{

	}
#pragma endregion Constructors

#pragma region Custom_Functions
	//TODO: Fillout Mat3x3 custom functions
	Mat3x3 Mat3x3::ScaleMat3(float xChange, float yChange, Mat3x3 &otherMatrix)
	{

	}

	Mat3x3 Mat3x3::RotMat3_X(float degreeChange, Mat3x3 &otherMatrix)
	{

	}

	Mat3x3 Mat3x3::RotMat3_Y(float degreeChange, Mat3x3 &otherMatrix)
	{

	}

	Mat3x3 Mat3x3::RotMat3_Z(float degreeChange, Mat3x3 &otherMatrix)
	{

	}

	Mat3x3 Mat3x3::TransformMat3(float xChange, float yChange, Mat3x3 &otherMatrix)
	{

	}
	/*float GetElement(int column, int row);
	void SetElement(int column, int row);*/
	//Mat3 MultMat3();
	//Going to try an operator overload instead of a func. I feel like there was a reason
	//why we didn't during the project. Can't remember if there was but i'll figure it out
	//once I get to filling it out.
#pragma endregion Custom_Functions

#pragma region Operator_Overloads
	//TODO: Fill out Mat3x3 operator overloads
	Mat3x3 Mat3x3::operator * (const Mat3x3 &factor)
	{

	}

	Mat3x3 Mat3x3::operator * (const Mat3x1 &factor)
	{

	}

	Mat3x3 Mat3x3::operator + (const Mat3x3 &term)
	{

	}

	Mat3x3 Mat3x3::operator - (const Mat3x3 &term)
	{

	}

	Mat3x3 Mat3x3::operator = (const Mat3x3 &equivalent)
	{

	}

	bool Mat3x3::operator == (const Mat3x3 &check)
	{

	}
#pragma endregion Operator_Overloads
}