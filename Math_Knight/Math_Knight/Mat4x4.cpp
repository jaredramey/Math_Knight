#include "Math_Knight.h"

namespace MK
{
#pragma region Constructors
	//Default constructor that inits a 4x4 Matrix with all values set to 0.
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
	//Init a 4x4 Matrix by using a Vector<Vector float>>.
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
	//Init a 4x4 Matrix by using a [3][3] Array.
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
	//Init a 4x4 Matrix by using a [15] Array.
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
	//Init a 4x4 Matrix by hard-coding all values.
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
	//Default deconstructor for a 4x4 Matrix.
	Mat4x4::~Mat4x4()
	{
	
	}
#pragma endregion Constructors

#pragma region Custom_Functions
	//Returns an Orthographic Projection
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
	//Scale a Matrix by X, Y, Z.
	Mat4x4 Mat4x4::ScaleMat4(float xChange, float yChange, float zChange, Mat4x4 &otherMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ xChange, 0, 0, 0 },
			{ 0, yChange, 0, 0 },
			{ 0, 0, zChange, 0 },
			{ 0, 0, 0, 1 }
		};

		Mat4x4 changeMat = Mat4x4(changeMatrix);

		return changeMat * otherMatrix;
	}
	//Rotate a Matrix on the X-axis by X degrees.
	Mat4x4 Mat4x4::RotMat4_X(float degreeChange, Mat4x4 &otherMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ 1, 0, 0, 0 },
			{ 0, (cos(degreeChange)), (asin(degreeChange)), 0 },
			{ 0, (sin(degreeChange)), (cos(degreeChange)), 0 },
			{ 0, 0, 0, 1 }
		};

		Mat4x4 changeMat = Mat4x4(changeMatrix);

		return changeMat * otherMatrix;
	}
	//Rotate a Matrix on the Y-axis by X degrees.
	Mat4x4 Mat4x4::RotMat4_Y(float degreeChange, Mat4x4 &otherMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ (cos(degreeChange)), 0, (asin(degreeChange)), 0 },
			{ 0, 1, 0, 0 },
			{ (sin(degreeChange)), 0, (cos(degreeChange)), 0 },
			{ 0, 0, 0, 1 }
		};

		Mat4x4 changeMat = Mat4x4(changeMatrix);

		return changeMat * otherMatrix;
	}
	//Rotate a Matrix on the Z-axis by X degrees.
	Mat4x4 Mat4x4::RotMat4_Z(float degreeChange, Mat4x4 &otherMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ (cos(degreeChange)), (sin(degreeChange)), 0, 0 },
			{ (asin(degreeChange)), (cos(degreeChange)), 0, 0 },
			{ 0, 0, 1, 0 },
			{ 0, 0, 0, 1 }
		};

		Mat4x4 changeMat = Mat4x4(changeMatrix);

		return changeMat * otherMatrix;
	}
	//Transform a Matrix by X, Y, and Z.
	Mat4x4 Mat4x4::TransformMat4(float xChange, float yChange, float zChange, Mat4x4 &otherMatrix)
	{
		std::vector<std::vector<float>> changeMatrix =
		{
			{ 1, 0, 0, 0 },
			{ 0, 1, 0, 0 },
			{ 0, 0, 1, 0 },
			{ xChange, yChange, zChange, 1 }
		};

		Mat4x4 changeMat = Mat4x4(changeMatrix);

		return changeMat * otherMatrix;
	}
	
	std::vector<std::vector<float>> Mat4x4::GetAsVector()
	{
		std::vector<std::vector<float>> matrixVector = 
		{
			{ this->entries.zeroZero, this->entries.zeroOne, this->entries.zeroTwo, this->entries.zeroThree },
			{ this->entries.oneZero, this->entries.oneOne, this->entries.oneTwo, this->entries.oneThree },
			{ this->entries.twoZero, this->entries.twoOne, this->entries.twoTwo, this->entries.twoThree },
			{ this->entries.threeZero, this->entries.threeOne, this->entries.threeTwo, this->entries.threeThree }
		};

		return matrixVector;
	}
#pragma endregion Custom_Functions

#pragma region Operator_Overloads
	Mat4x4 Mat4x4::operator * (const Mat4x4 &factor)
	{
		entries.zeroZero = ((entries.zeroZero*factor.entries.zeroZero) + (entries.zeroOne*factor.entries.oneZero) + (entries.zeroTwo*factor.entries.twoZero) + (entries.zeroThree*factor.entries.threeZero));		//	{x, x, x, x}
		entries.zeroOne = ((entries.zeroZero*factor.entries.zeroOne) + (entries.zeroOne*factor.entries.oneOne) + (entries.zeroTwo*factor.entries.twoOne) + (entries.zeroThree*factor.entries.threeOne));			//	{O, O, O, O}
		entries.zeroTwo = ((entries.zeroZero*factor.entries.zeroTwo) + (entries.zeroOne*factor.entries.oneTwo) + (entries.zeroTwo*factor.entries.twoTwo) + (entries.zeroThree*factor.entries.threeTwo));			//	{O, O, O, O}
		entries.zeroThree = ((entries.zeroZero*factor.entries.zeroThree) + (entries.zeroOne*factor.entries.oneThree) + (entries.zeroTwo*factor.entries.twoThree) + (entries.zeroThree*factor.entries.threeThree));	//	{O, O, O, O}
		/*Second Row*/
		entries.oneZero = ((entries.oneZero*factor.entries.oneZero) + (entries.oneOne*factor.entries.zeroOne) + (entries.oneTwo*factor.entries.twoZero) + (entries.oneThree*factor.entries.threeZero));			//		{O, O, O, O}
		entries.oneOne = ((entries.oneZero*factor.entries.oneOne) + (entries.oneOne*factor.entries.oneOne) + (entries.oneTwo*factor.entries.oneTwo) + (entries.oneThree*factor.entries.threeOne));				//		{x, x, x, x}
		entries.oneTwo = ((entries.oneZero*factor.entries.oneTwo) + (entries.oneOne*factor.entries.twoOne) + (entries.oneTwo*factor.entries.twoTwo) + (entries.oneThree*factor.entries.threeTwo));				//		{O, O, O, O}
		entries.oneThree = (entries.oneZero*factor.entries.oneThree) + (entries.zeroOne*factor.entries.threeOne) + (entries.zeroTwo*factor.entries.threeTwo) + (entries.zeroThree*factor.entries.threeThree);	//      {O, O, O, O}
		/*Third Row*/
		entries.twoZero = ((entries.twoZero*factor.entries.twoZero) + (entries.twoOne*factor.entries.zeroOne) + (entries.twoTwo*factor.entries.zeroTwo) + (entries.twoThree*factor.entries.threeZero));			//		{O, O, O, O}
		entries.twoOne = ((entries.twoZero*factor.entries.twoOne) + (entries.twoOne*factor.entries.oneOne) + (entries.twoTwo*factor.entries.oneTwo) + (entries.twoThree*factor.entries.threeOne));				//		{O, O, O, O}
		entries.twoTwo = ((entries.twoZero*factor.entries.twoTwo) + (entries.twoOne*factor.entries.twoOne) + (entries.twoTwo*factor.entries.twoTwo) + (entries.twoThree*factor.entries.threeTwo));				//		{x, x, x, x}
		entries.twoThree = ((entries.twoZero*factor.entries.twoThree) + (entries.twoOne*factor.entries.threeOne) + (entries.threeTwo*factor.entries.twoTwo) + (entries.twoThree*factor.entries.threeThree));	//		{O, O, O, O}
		/*Fourth Row*/
		entries.threeZero = ((entries.threeZero*factor.entries.threeZero) + (entries.threeOne*factor.entries.zeroOne) + (entries.threeTwo*factor.entries.zeroTwo) + (entries.threeThree*factor.entries.zeroThree));
		entries.threeOne = ((entries.threeZero*factor.entries.threeOne) + (entries.threeOne*factor.entries.oneOne) + (entries.threeTwo*factor.entries.oneTwo) + (entries.threeThree*factor.entries.oneThree));
		entries.threeTwo = ((entries.threeZero*factor.entries.threeTwo) + (entries.threeOne*factor.entries.twoOne) + (entries.threeTwo*factor.entries.twoTwo) + (entries.threeThree*factor.entries.twoThree));
		entries.threeThree = ((entries.threeZero*factor.entries.threeThree) + (entries.threeOne*factor.entries.threeOne) + (entries.threeTwo*factor.entries.threeTwo) + (entries.threeThree*factor.entries.threeThree));

		return factor;
	}
	Mat4x4 Mat4x4::operator + (const Mat4x4 &term)
	{
		/*First Row*/
		entries.zeroZero = entries.zeroZero + term.entries.zeroZero;	//	{x, x, x, x}
		entries.zeroOne = entries.zeroOne + term.entries.zeroOne;		//	{O, O, O, O}
		entries.zeroTwo = entries.zeroTwo + term.entries.zeroTwo;		//	{O, O, O, O}
		entries.zeroThree = entries.zeroThree + term.entries.zeroThree; //  {O, O, O, O}
		/*Second Row*/
		entries.oneZero = entries.oneZero + term.entries.oneZero;		//		{O, O, O, O}
		entries.oneOne = entries.oneOne + term.entries.oneOne;			//		{x, x, x, x}
		entries.oneTwo = entries.oneTwo + term.entries.oneTwo;			//		{O, O, O, O}
		entries.oneThree = entries.oneThree + term.entries.oneThree;    //      {O, O, O, O}
		/*Third Row*/
		entries.twoZero = entries.twoZero + term.entries.twoZero;		//			{O, O, O, O}
		entries.twoOne = entries.twoOne + term.entries.twoZero;			//			{O, O, O, O}
		entries.twoTwo = entries.twoTwo + term.entries.zeroTwo;			//			{x, x, x, x}
		entries.twoThree = entries.twoThree + term.entries.twoThree;    //			{O, O, O, O}
		/*Fourth Row*/
		entries.twoZero = entries.threeZero + term.entries.threeZero;	//				{O, O, O, O}
		entries.twoOne = entries.threeOne + term.entries.threeZero;		//				{O, O, O, O}
		entries.twoTwo = entries.threeTwo + term.entries.threeTwo;		//				{O, O, O, O}
		entries.twoThree = entries.threeThree + term.entries.threeThree;//				{x, x, x, x}

		return term;
	}
	Mat4x4 Mat4x4::operator - (const Mat4x4 &term)
	{
		/*First Row*/
		entries.zeroZero = entries.zeroZero - term.entries.zeroZero;	//	{x, x, x, x}
		entries.zeroOne = entries.zeroOne - term.entries.zeroOne;		//	{O, O, O, O}
		entries.zeroTwo = entries.zeroTwo - term.entries.zeroTwo;		//	{O, O, O, O}
		entries.zeroThree = entries.zeroThree - term.entries.zeroThree; //  {O, O, O, O}
		/*Second Row*/
		entries.oneZero = entries.oneZero - term.entries.oneZero;		//		{O, O, O, O}
		entries.oneOne = entries.oneOne - term.entries.oneOne;			//		{x, x, x, x}
		entries.oneTwo = entries.oneTwo - term.entries.oneTwo;			//		{O, O, O, O}
		entries.oneThree = entries.oneThree - term.entries.oneThree;    //      {O, O, O, O}
		/*Third Row*/
		entries.twoZero = entries.twoZero - term.entries.twoZero;		//			{O, O, O, O}
		entries.twoOne = entries.twoOne - term.entries.twoZero;			//			{O, O, O, O}
		entries.twoTwo = entries.twoTwo - term.entries.zeroTwo;			//			{x, x, x, x}
		entries.twoThree = entries.twoThree - term.entries.twoThree;    //			{O, O, O, O}
		/*Fourth Row*/
		entries.twoZero = entries.threeZero - term.entries.threeZero;	//				{O, O, O, O}
		entries.twoOne = entries.threeOne - term.entries.threeZero;		//				{O, O, O, O}
		entries.twoTwo = entries.threeTwo - term.entries.threeTwo;		//				{O, O, O, O}
		entries.twoThree = entries.threeThree - term.entries.threeThree;//				{x, x, x, x}

		return term;
	}
	Mat4x4 Mat4x4::operator = (const Mat4x4 &equivalent)
	{
		/*First Row*/
		entries.zeroZero = equivalent.entries.zeroZero;		//	{x, x, x, x}
		entries.zeroOne = equivalent.entries.zeroOne;		//	{O, O, O, O}
		entries.zeroTwo = equivalent.entries.zeroTwo;		//	{O, O, O, O}
		entries.zeroThree = equivalent.entries.zeroThree;	//  {O, O, O, O}
		/*Second Row*/
		entries.oneZero = equivalent.entries.oneZero;		//		{O, O, O, O}
		entries.oneOne = equivalent.entries.oneOne;			//		{x, x, x, x}
		entries.oneTwo = equivalent.entries.oneTwo;			//		{O, O, O, O}
		entries.oneThree = equivalent.entries.oneThree;     //      {O, O, O, O}
		/*Third Row*/
		entries.twoZero = equivalent.entries.twoZero;		//			{O, O, O, O}
		entries.twoOne = equivalent.entries.twoZero;		//			{O, O, O, O}
		entries.twoTwo = equivalent.entries.zeroTwo;		//			{x, x, x, x}
		entries.twoThree = equivalent.entries.twoThree;		//			{O, O, O, O}
		/*Fourth Row*/
		entries.twoZero = equivalent.entries.threeZero;		//				{O, O, O, O}
		entries.twoOne = equivalent.entries.threeZero;		//				{O, O, O, O}
		entries.twoTwo = equivalent.entries.threeTwo;		//				{O, O, O, O}
		entries.twoThree = equivalent.entries.threeThree;	//				{x, x, x, x}

		return equivalent;
	}
	bool Mat4x4::operator == (const Mat4x4 &check)
	{
		std::vector<std::vector<float>> thisMat = this->GetAsVector();
		Mat4x4 temp = check;
		std::vector<std::vector<float>> compMat = temp.GetAsVector();

		for (int i = 0; i <= 3; i++)
		{
			for (int j = 0; j <= 3; j++)
			{
				if (thisMat[i][j] != compMat[i][j])
				{
					return false;
				}
			}
		}

		return true;
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
					//[0][3] == [0][3]
					if (entries.zeroThree == check.entries.zeroThree)
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
									//[1][3] == [1][3]
									if (entries.oneThree == check.entries.oneThree)
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
													//[2][3] == [2][3]
													if (entries.twoThree == check.entries.twoThree)
													{
														//[3][0] == [3][0]
														if (entries.threeZero == check.entries.threeZero)
														{
															//[3][1] == [3][1]
															if (entries.threeOne == check.entries.threeOne)
															{
																//[3][2] == [3][2]
																if (entries.threeTwo == check.entries.threeTwo)
																{
																	//[3][3] == [3][3]
																	if (entries.twoTwo == check.entries.twoTwo)
																	{
																		return true;
																	}
																	//[3][3] == [3][3]
																	else
																	{
																		return false;
																	}
																}
																//[3][2] == [3][2]
																else
																{
																	return false;
																}
															}
															//[3][1] == [3][1]
															else
															{
																return false;
															}
														}
														//[3][0] == [3][0]
														else
														{
															return false;
														}
													}
													//[2][3] == [2][3]
													else
													{
														return false;
													}
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
									//[1][3] == [1][3]
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
					//[0][3] == [0][3]
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