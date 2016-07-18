#include "Math_Knight.h"

namespace MK
{
#pragma region Constructors
	Mat4x4::Mat4x4()
	{
		entries.zeroZero = 0.0f;
		entries.zeroOne = 0.0f;
		entries.zeroTwo = 0.0f;
		entries.zeroThree = 0.0f;
		entries.oneZero = 0.0f;
		entries.oneOne = 0.0f;
		entries.oneTwo = 0.0f;
		entries.oneThree = 0.0f;
		entries.twoZero = 0.0f;
		entries.twoOne = 0.0f;
		entries.twoTwo = 0.0f;
		entries.twoThree = 0.0f;
		entries.threeZero = 0.0f;
		entries.threeOne = 0.0f;
		entries.threeTwo = 0.0f;
		entries.threeThree = 0.0f;
	}
	Mat4x4::Mat4x4(std::vector<std::vector<float>> &matrix)
	{
		entries.zeroZero = matrix[0][0];
		entries.zeroOne = matrix[0][1];
		entries.zeroTwo = matrix[0][2];
		entries.zeroThree = matrix[0][3];
		entries.oneZero = matrix[1][0];
		entries.oneOne = matrix[1][1];
		entries.oneTwo = matrix[1][2];
		entries.oneThree = matrix[1][3];
		entries.twoZero = matrix[2][0];
		entries.twoOne = matrix[2][1];
		entries.twoTwo = matrix[2][2];
		entries.twoThree = matrix[2][3];
		entries.threeZero = matrix[3][0];
		entries.threeOne = matrix[3][1];
		entries.threeTwo = matrix[3][2];
		entries.threeThree = matrix[3][3];
	}
	Mat4x4::Mat4x4(float matrix[3][3])
	{
		entries.zeroZero = matrix[0][0];
		entries.zeroOne = matrix[0][1];
		entries.zeroTwo = matrix[0][2];
		entries.zeroThree = matrix[0][3];
		entries.oneZero = matrix[1][0];
		entries.oneOne = matrix[1][1];
		entries.oneTwo = matrix[1][2];
		entries.oneThree = matrix[1][3];
		entries.twoZero = matrix[2][0];
		entries.twoOne = matrix[2][1];
		entries.twoTwo = matrix[2][2];
		entries.twoThree = matrix[2][3];
		entries.threeZero = matrix[3][0];
		entries.threeOne = matrix[3][1];
		entries.threeTwo = matrix[3][2];
		entries.threeThree = matrix[3][3];
	}
	Mat4x4::Mat4x4(float matrix[15])
	{
		entries.zeroZero = matrix[0];
		entries.zeroOne = matrix[1];
		entries.zeroTwo = matrix[2];
		entries.zeroThree = matrix[3];
		entries.oneZero = matrix[4];
		entries.oneOne = matrix[5];
		entries.oneTwo = matrix[6];
		entries.oneThree = matrix[7];
		entries.twoZero = matrix[8];
		entries.twoOne = matrix[9];
		entries.twoTwo = matrix[10];
		entries.twoThree = matrix[11];
		entries.threeZero = matrix[12];
		entries.threeOne = matrix[13];
		entries.threeTwo = matrix[14];
		entries.threeThree = matrix[15];
	}
	//Why someone would do this to themselves, I have no idea...
	Mat4x4::Mat4x4(float zeroZero, float zeroOne, float zeroTwo, float zeroThree,
		float oneZero, float oneOne, float oneTwo, float oneThree,
		float twoZero, float twoOne, float twoTwo, float twoThree,
		float threeZero, float threeOne, float threeTwo, float threeThree)
	{
		entries.zeroZero = zeroZero;
		entries.zeroOne = zeroOne;
		entries.zeroTwo = zeroTwo;
		entries.zeroThree = zeroThree;
		entries.oneZero = oneZero;
		entries.oneOne = oneOne;
		entries.oneTwo = oneTwo;
		entries.oneThree = oneThree;
		entries.twoZero = twoZero;
		entries.twoOne = twoOne;
		entries.twoTwo = twoTwo;
		entries.twoThree = twoThree;
		entries.threeZero = threeZero;
		entries.threeOne = threeOne;
		entries.threeTwo = threeTwo;
		entries.threeThree = threeThree;
	}
	Mat4x4::~Mat4x4()
	{
	
	}
#pragma endregion Constructors

#pragma region Custom_Functions
	Mat4x4 Mat4x4::OrthographicProjection(float left, float right, float top, float bottom, float near, float far, Mat4x4 &otherMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =																		  //||-------The Matrix in column row major -------||
		{																													  //||=============================================||
			{ (2 / (right - left)), 0, 0, 0 },																				  //  |(2 / (a_right - a_left)), 0, 0, 0|
			{ 0, (2 / (top - bottom)), 0, 0 },																				  //  |0, (2 / (a_top - a_bottom)), 0, 0|
			{ 0, 0, (-1 / (far - near)), 0 },																				  //  |0, 0, (-1 / (a_far - a_near)), 0 |
			{ (((right + left) / (right - left))*-1), (((top + bottom) / (top - bottom))*-1), (near / (far - near)), 1 }      //  |(((a_right + a_left) / (a_right - a_left))*-1), (((a_top + a_bottom) / (a_top - a_bottom))*-1), (a_near / (a_far - a_near)), 1|
		};

		Mat4x4 changeMat = Mat4x4(changeMatrix);

		return changeMat * otherMatrix;
	}
	Mat4x4 Mat4x4::ScaleMat4(float xChange, float yChange, float zChange, Mat4x4 &otherMatrix)
	{
	
	}
	Mat4x4 Mat4x4::RotMat4_X(float degreeChange, Mat4x4 &otherMatrix)
	{
	
	}
	Mat4x4 Mat4x4::RotMat4_Y(float degreeChange, Mat4x4 &otherMatrix)
	{
	
	}
	Mat4x4 Mat4x4::RotMat4_Z(float degreeChange, Mat4x4 &otherMatrix)
	{
	
	}
	Mat4x4 Mat4x4::TransformMat4(float degreeChange, Mat4x4 &otherMatrix)
	{
	
	}
#pragma endregion Custom_Functions

#pragma region Operator_Overloads
	Mat4x4 Mat4x4::operator * (const Mat4x4 &factor)
	{
	
	}
	Mat4x4 Mat4x4::operator + (const Mat4x4 &term)
	{
	
	}
	Mat4x4 Mat4x4::operator - (const Mat4x4 &term)
	{
	
	}
	Mat4x4 Mat4x4::operator = (const Mat4x4 &equivalent)
	{
	
	}
	bool Mat4x4::operator == (const Mat4x4 &check)
	{
	
	}
#pragma endregion Operator_Overloads
}