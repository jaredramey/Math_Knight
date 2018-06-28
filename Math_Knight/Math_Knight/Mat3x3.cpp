#include "Math_Knight.h"

namespace MK
{
#pragma region Constructors
	//Default construction that sets all values to 0
	Mat3x3::Mat3x3()
	{
		entries.zeroZero = 0;
		entries.zeroOne = 0;
		entries.zeroTwo = 0;
		entries.oneZero = 0;
		entries.oneOne = 0;
		entries.oneTwo = 0;
		entries.twoZero = 0;
		entries.twoOne = 0;
		entries.twoTwo = 0;
	}
	//Build a Mat3x3 from a vector<vector<float>>
	Mat3x3::Mat3x3(std::vector<std::vector<float>> &matrix)
	{
		entries.zeroZero = matrix[0][0];
		entries.zeroOne = matrix[0][1];
		entries.zeroTwo = matrix[0][2];
		entries.oneZero = matrix[1][0];
		entries.oneOne = matrix[1][1];
		entries.oneTwo = matrix[1][2];
		entries.twoZero = matrix[2][0];
		entries.twoOne = matrix[2][1];
		entries.twoTwo = matrix[2][2];
	}
	//Build a Mat3x3 from a multidimensional array
	Mat3x3::Mat3x3(float matrix[2][2])
	{
		entries.zeroZero = matrix[0][0];
		entries.zeroOne = matrix[0][1];
		entries.zeroTwo = matrix[0][2];
		entries.oneZero = matrix[1][0];
		entries.oneOne = matrix[1][1];
		entries.oneTwo = matrix[1][2];
		entries.twoZero = matrix[2][0];
		entries.twoOne = matrix[2][1];
		entries.twoTwo = matrix[2][2];
	}
	//Build a Mat3x3 from an array
	Mat3x3::Mat3x3(float matrix[8])
	{
		entries.zeroZero = matrix[0];
		entries.zeroOne = matrix[1];
		entries.zeroTwo = matrix[2];
		entries.oneZero = matrix[3];
		entries.oneOne = matrix[4];
		entries.oneTwo = matrix[5];
		entries.twoZero = matrix[6];
		entries.twoOne = matrix[7];
		entries.twoTwo = matrix[8];
	}
	//Why you're using this constructor I have no idea. But know that I am so so sorry for you.
	Mat3x3::Mat3x3(float zeroZero, float zeroOne, float zeroTwo, float oneZero, float oneOne, float oneTwo, float twoZero, float twoOne, float twoTwo)
	{
		entries.zeroZero = zeroZero;
		entries.zeroOne = zeroOne;
		entries.zeroTwo = zeroTwo;
		entries.oneZero = oneZero;
		entries.oneOne = oneOne;
		entries.oneTwo = oneTwo;
		entries.twoZero = twoZero;
		entries.twoOne = twoOne;
		entries.twoTwo = twoTwo;
	}
	
	//Default deconstructor
	Mat3x3::~Mat3x3()
	{

	}
#pragma endregion Constructors

#pragma region Custom_Functions
	//Scale Mat3x3
	Mat3x3 Mat3x3::ScaleMat3(float xChange, float yChange, Mat3x3 &otherMatrix)
	{
		//Create change matrix
		std::vector<std::vector<float>> changeMatrix =
		{
			{ xChange, 0, 0 },
			{ 0, yChange, 0 },
			{ 0, 0, 1 }
		};

		//Turn change matrix into a mat3x3
		Mat3x3 ChangeMat = Mat3x3(changeMatrix);
		
		//Multiply and return the result
		return ChangeMat * otherMatrix;

	}

	//Rotate Mat3x3 on the X-axis by x degrees
	Mat3x3 Mat3x3::RotMat3_X(float degreeChange, Mat3x3 &otherMatrix)
	{
		//Create change matrix
		std::vector<std::vector<float>> changeMatrix =
		{
			{ 1, 0, 0 },
			{ 0, (cos(degreeChange)), (asin(degreeChange)) },
			{ 0, (sin(degreeChange)), (cos(degreeChange)) }

		};

		//Turn change matrix into a mat3x3
		Mat3x3 ChangeMat = Mat3x3(changeMatrix);

		//Multiply and return the result
		return ChangeMat * otherMatrix;
	}

	//Rotate Mat3x3 on the Y-axis by x degrees
	Mat3x3 Mat3x3::RotMat3_Y(float degreeChange, Mat3x3 &otherMatrix)
	{
		//Create change matrix
		std::vector<std::vector<float>> changeMatrix =
		{
			{ (cos(degreeChange)), 0, (sin(degreeChange)) },
			{ 0, 1, 0 },
			{ (asin(degreeChange)), 0, (cos(degreeChange)) }
		};

		//Turn change matrix into a mat3x3
		Mat3x3 ChangeMat = Mat3x3(changeMatrix);

		//Multiply and return the result
		return ChangeMat * otherMatrix;
	}

	//Rotate Mat3x3 on the Z-axis by x degrees
	Mat3x3 Mat3x3::RotMat3_Z(float degreeChange, Mat3x3 &otherMatrix)
	{
		//Create change matrix
		std::vector<std::vector<float>> changeMatrix =
		{
			{ (cos(degreeChange)), (sin(degreeChange)), 0 },
			{ (asin(degreeChange)), (cos(degreeChange)), 0 },
			{ 0, 0, 1 }
		};

		//Turn change matrix into a mat3x3
		Mat3x3 ChangeMat = Mat3x3(changeMatrix);

		//Multiply and return the result
		return ChangeMat * otherMatrix;
	}

	//Transform matrix by X and Y
	Mat3x3 Mat3x3::TransformMat3(float xChange, float yChange, Mat3x3 &otherMatrix)
	{
		//Create change matrix
		std::vector<std::vector<float>> changeMatrix =
		{
			{ 1, 0, 0 },
			{ 0, 1, 0 },
			{ xChange, yChange, 1 }
		};

		//Turn change matrix into a mat3x3
		Mat3x3 ChangeMat = Mat3x3(changeMatrix);

		//Multiply and return the result
		return ChangeMat * otherMatrix;
	}

	std::vector<std::vector<float>> Mat3x3::GetAsVector()
	{
		std::vector<std::vector<float>> matrixVector =
		{
			{ this->entries.zeroZero, this->entries.zeroOne, this->entries.zeroTwo},
			{ this->entries.oneZero, this->entries.oneOne, this->entries.oneTwo},
			{ this->entries.twoZero, this->entries.twoOne, this->entries.twoTwo}
		};

		return matrixVector;
	}
#pragma endregion Custom_Functions

#pragma region Operator_Overloads
	Mat3x3 Mat3x3::operator * (const Mat3x3 &factor)
	{
		/*First Row*/																																		/*First Row*/
		entries.zeroZero = ((entries.zeroZero*factor.entries.zeroZero) + (entries.zeroOne*factor.entries.oneZero) + (entries.zeroTwo*factor.entries.twoZero));	//	{x, x, x}
		entries.zeroOne = ((entries.zeroZero*factor.entries.oneZero) + (entries.zeroOne*factor.entries.oneOne) + (entries.zeroTwo*factor.entries.twoOne));		//	{O, O, O}
		entries.zeroTwo = ((entries.zeroZero*factor.entries.twoZero) + (entries.zeroOne*factor.entries.oneTwo) + (entries.zeroTwo*factor.entries.twoTwo));		//	{O, O, O}
		/*Second Row*/
		entries.oneZero = ((entries.oneZero*factor.entries.zeroZero) + (entries.oneOne*factor.entries.zeroOne) + (entries.oneTwo*factor.entries.zeroTwo));		//		{O, O, O}
		entries.oneOne = ((entries.oneZero*factor.entries.oneZero) + (entries.oneOne*factor.entries.oneOne) + (entries.oneTwo*factor.entries.oneTwo));			//		{x, x, x}
		entries.oneTwo = ((entries.oneZero*factor.entries.twoZero) + (entries.oneOne*factor.entries.twoOne) + (entries.oneTwo*factor.entries.twoTwo));			//		{O, O, O}
		/*Third Row*/
		entries.twoZero = ((entries.twoZero*factor.entries.zeroZero) + (entries.twoOne*factor.entries.zeroOne) + (entries.twoTwo*factor.entries.zeroTwo));		//			{O, O, O}
		entries.twoOne = ((entries.twoZero*factor.entries.oneZero) + (entries.twoOne*factor.entries.oneOne) + (entries.twoTwo*factor.entries.oneTwo));			//			{O, O, O}
		entries.twoTwo = ((entries.twoZero*factor.entries.twoZero) + (entries.twoOne*factor.entries.twoOne) + (entries.twoTwo*factor.entries.twoTwo));			//			{x, x, x}
	}

	Mat3x3 Mat3x3::operator + (const Mat3x3 &term)
	{
		/*First Row*/
		entries.zeroZero = entries.zeroZero + term.entries.zeroZero;	//	{x, x, x}
		entries.zeroOne = entries.zeroOne + term.entries.zeroOne;		//	{O, O, O}
		entries.zeroTwo = entries.zeroTwo + term.entries.zeroTwo;		//	{O, O, O}
		/*Second Row*/
		entries.oneZero = entries.oneZero + term.entries.oneZero;		//		{O, O, O}
		entries.oneOne = entries.oneOne + term.entries.oneOne;			//		{x, x, x}
		entries.oneTwo = entries.oneTwo + term.entries.oneTwo;			//		{O, O, O}
		/*Third Row*/
		entries.twoZero = entries.twoZero + term.entries.twoZero;		//			{O, O, O}
		entries.twoOne = entries.twoOne + term.entries.twoZero;			//			{O, O, O}
		entries.twoTwo = entries.twoTwo + term.entries.zeroTwo;			//			{x, x, x}
	}

	Mat3x3 Mat3x3::operator - (const Mat3x3 &term)
	{
		/*First Row*/
		entries.zeroZero = entries.zeroZero - term.entries.zeroZero;	//	{x, x, x}
		entries.zeroOne = entries.zeroOne - term.entries.zeroOne;		//	{O, O, O}
		entries.zeroTwo = entries.zeroTwo - term.entries.zeroTwo;		//	{O, O, O}
		/*Second Row*/
		entries.oneZero = entries.oneZero - term.entries.oneZero;		//		{O, O, O}
		entries.oneOne = entries.oneOne - term.entries.oneOne;			//		{x, x, x}
		entries.oneTwo = entries.oneTwo - term.entries.oneTwo;			//		{O, O, O}
		/*Third Row*/
		entries.twoZero = entries.twoZero - term.entries.twoZero;		//			{O, O, O}
		entries.twoOne = entries.twoOne - term.entries.twoZero;			//			{O, O, O}
		entries.twoTwo = entries.twoTwo - term.entries.zeroTwo;			//			{x, x, x}
	}

	Mat3x3 Mat3x3::operator = (const Mat3x3 &equivalent)
	{
		/*First Row*/
		entries.zeroZero = entries.zeroZero = equivalent.entries.zeroZero;	//	{x, x, x}
		entries.zeroOne = entries.zeroOne = equivalent.entries.zeroOne;		//	{O, O, O}
		entries.zeroTwo = entries.zeroTwo = equivalent.entries.zeroTwo;		//	{O, O, O}
		/*Second Row*/
		entries.oneZero = entries.oneZero = equivalent.entries.oneZero;			//		{O, O, O}
		entries.oneOne = entries.oneOne = equivalent.entries.oneOne;			//		{x, x, x}
		entries.oneTwo = entries.oneTwo = equivalent.entries.oneTwo;			//		{O, O, O}
		/*Third Row*/
		entries.twoZero = entries.twoZero = equivalent.entries.twoZero;				//			{O, O, O}
		entries.twoOne = entries.twoOne = equivalent.entries.twoZero;				//			{O, O, O}
		entries.twoTwo = entries.twoTwo = equivalent.entries.zeroTwo;				//			{x, x, x}
	}

	bool Mat3x3::operator == (const Mat3x3 &check)
	{
		std::vector<std::vector<float>> thisMat = this->GetAsVector();
		Mat3x3 temp = check;
		std::vector<std::vector<float>> compMat = temp.GetAsVector();

		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (thisMat[i][j] != compMat[i][j])
				{
					return false;
				}
			}
		}

		/*
		//[0][0] == [0][0] 
		if (entries.zeroZero == check.entries.zeroZero)
		{
			//[0][1] == [0][1]
			if (entries.zeroOne == check.entries.zeroOne)
			{
				//[0][2] == [0][2]
				if (entries.zeroTwo == check.entries.zeroTwo)
				{
					//[1][0] == [1][0]
					if (entries.oneZero == check.entries.oneZero)
					{
						//[1][1] == [1][1]
						if (entries.oneOne == check.entries.oneOne)
						{
							//[1][2] == [1][2]
							if (entries.oneTwo == check.entries.oneTwo)
							{
								//[2][0] == [2][0]
								if (entries.twoZero == check.entries.twoZero)
								{
									//[2][1] == [2][1]
									if (entries.twoOne == check.entries.twoOne)
									{
										//[2][2] == [2][2]
										if (entries.twoTwo == check.entries.twoTwo)
										{
											return true;
										}
										//[2][2] == [2][2]
										else
										{
											return false;
										}
									}
									//[2][1] == [2][1]
									else
									{
										return false;
									}
								}
								//[2][0] == [2][0]
								else
								{
									return false;
								}
							}
							//[1][2] == [1][2]
							else
							{
								return false;
							}
						}
						//[1][1] == [1][1]
						else
						{
							return false;
						}
					}
					//[1][0] == [1][0]
					else
					{
						return false;
					}
				}
				//[0][2] == [0][2]
				else
				{
					return false;
				}
			}
			//[0][1] == [0][1]
			else
			{
				return false;
			}
		}
		//[0][0] == [0][0] 
		else
		{
			return false;
		}*/
	}
#pragma endregion Operator_Overloads
}