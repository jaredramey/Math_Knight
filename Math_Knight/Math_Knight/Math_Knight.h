/* ||                   Math_Knight.Lib 
   ||By: Jared Ramey (Oezaxs)	Started: 07/14/16
   ||
*/

//NOTE: THIS LIBRARY USES COLUMN ROW MAJOR. MAKE SURE YOUR MATRICIES ARE SET UP AS SUCH.
//TODO: Figure out how I want to lay all my classes out. I'll finish up mat3x3 and use it as the basis for how the other classes should look.

#include <string>
#include <iostream>
#include <math.h>
#include <vector>

namespace MK //Math_Knight shorthand
{
	//TODO: Fill out Basic Funcs
	class Basic
	{
	public:
		float LinearInterp();
		float DegToRad();
		float RadToDeg();
		bool IsPowerOfTwo();
	};

	//TODO: Fill Out Mat4 Funcs & decide how to represent a Mat4
	class Mat4x4
	{
	public:

		#pragma region Constructors
		Mat4x4();
		Mat4x4(std::vector<std::vector<float>> &matrix);
		Mat4x4(float matrix[3][3]);
		Mat4x4(float matrix[15]);
		//Why someone would do this to themselves, I have no idea...
		Mat4x4(float zeroZero, float zeroOne, float zeroTwo, float zeroThree,
			   float oneZero, float oneOne, float oneTwo, float oneThree,
			   float twoZero, float twoOne, float twoTwo, float twoThree,
			   float threeZero, float threeOne, float threeTwo, float threeThree);
		~Mat4x4();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		Mat4x4 OrthographicProjection(float left, float right, float top, float bottom, float near, float far, Mat4x4 &otherMatrix);
		Mat4x4 ScaleMat4(float xChange, float yChange, float zChange, Mat4x4 &otherMatrix);
		Mat4x4 RotMat4_X(float degreeChange, Mat4x4 &otherMatrix);
		Mat4x4 RotMat4_Y(float degreeChange, Mat4x4 &otherMatrix);
		Mat4x4 RotMat4_Z(float degreeChange, Mat4x4 &otherMatrix);
		Mat4x4 TransformMat4(float xChange, float yChange, float zChange, Mat4x4 &otherMatrix);
		float GetElement(int column, int row);
		void SetElement(int column, int row, float value);
		std::vector<std::vector<float>> GetAsVector();
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		Mat4x4 operator * (const Mat4x4 &factor);
		Mat4x4 operator + (const Mat4x4 &term);
		Mat4x4 operator - (const Mat4x4 &term);
		Mat4x4 operator = (const Mat4x4 &equivalent);
		bool operator == (const Mat4x4 &check);
		#pragma endregion Operator_Overloads

		#pragma region typedef_Mat4x4
		struct{	float zeroZero, oneZero, twoZero, threeZero,
					  zeroOne, oneOne, twoOne, threeOne,
					  zeroTwo, oneTwo, twoTwo, threeTwo,
					  zeroThree, oneThree, twoThree, threeThree;		} entries;
		#pragma endregion typedef_Mat4x4
	};

	class Mat3x3
	{
	public:

		#pragma region Constructors
		Mat3x3();
		Mat3x3(std::vector<std::vector<float>> &matrix);
		Mat3x3(float matrix[2][2]);
		Mat3x3(float matrix[8]);
		//Why someone would do this to themselves, I have no idea...
		Mat3x3(float zeroZero, float zeroOne, float zeroTwo, float oneZero, float oneOne, float oneTwo, float twoZero, float twoOne, float twoTwo);
		~Mat3x3();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		Mat3x3 ScaleMat3(float xChange, float yChange, Mat3x3 &otherMatrix);
		Mat3x3 RotMat3_X(float degreeChange, Mat3x3 &otherMatrix);
		Mat3x3 RotMat3_Y(float degreeChange, Mat3x3 &otherMatrix);
		Mat3x3 RotMat3_Z(float degreeChange, Mat3x3 &otherMatrix);
		Mat3x3 TransformMat3(float xChange, float yChange, Mat3x3 &otherMatrix);
		float GetElement(int column, int row);
		void SetElement(int column, int row, float value);
		std::vector<std::vector<float>> GetAsVector();
		#pragma endregion Custom_Functions
		 
		#pragma region Operator_Overloads
		//TODO: Make more operator overloads then just multiplication for matricies. Don't think I'll need them but might as well just in case.
		Mat3x3 operator * (const Mat3x3 &factor);
		//Moved this function to Mat3x1 since it effects that Mat more
		//Mat3x3 operator * (const Mat3x1 &factor);
		Mat3x3 operator + (const Mat3x3 &term);
		Mat3x3 operator - (const Mat3x3 &term);
		Mat3x3 operator = (const Mat3x3 &equivalent);
		bool operator == (const Mat3x3 &check);
		#pragma endregion Operator_Overloads

		#pragma region Mat3x3_def
		//Struct is set up to represent a matrix in column row major
		struct{ float zeroZero, oneZero, twoZero,
					  zeroOne , oneOne , twoOne,
					  zeroTwo , oneTwo , twoTwo ;   } entries;
		#pragma endregion Mat3x3_def

	};

	class Mat3x1
	{
	public:
		#pragma region Constructors
		Mat3x1();
		Mat3x1(std::vector<float> &matrix);
		Mat3x1(float matrix[3]);
		~Mat3x1();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		Mat3x1 operator * (const Mat3x1 &factor);
		//Putting this here for later since this effects a mat3x1 more then the mat3x3
		/*{
			someVector[0] = ((someVector[0] * someMatrix.zeroZero) + (someVector[0] * someMatrix.zeroOne) + (someVector[0] * someMatrix.zeroTwo));
			someVector[1] = ((someVector[1] * someMatrix.oneZero) + (someVector[1] * someMatrix.oneOne) + (someVector[1] * someMatrix.oneTwo));
			someVector[2] = ((someVector[2] * someMatrix.twoZero) + (someVector[2] * someMatrix.twoOne) + (someVector[2] * someMatrix.twoTwo));
		}*/
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		struct{ float zeroZero, oneZero, twoZero; } entries;
		#pragma endregion Operator_Overloads
	};

	//TODO: Fill Out Vec4 Funcs & decide how to represent a Vec4
	class Vec4
	{
	public:
		#pragma region Constructors
		Vec4();
		Vec4(float x, float y, float z, float w);
		Vec4(std::vector<float> &vector);
		Vec4(float vector[4]);
		Vec4(const unsigned int hex);
		~Vec4();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		Vec4 Normalize(const Vec4 &vector);
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		Vec4 operator * (const Vec4 &factor);
		Vec4 operator *= (const Vec4 &factor);
		Vec4 operator / (const Vec4 &dividen);
		Vec4 operator /= (const Vec4 &dividen);
		Vec4 operator + (const Vec4 &term);
		Vec4 operator += (const Vec4 &term);
		Vec4 operator - (const Vec4 &term);
		Vec4 operator -= (const Vec4 &term);
		Vec4 operator = (const Vec4 &equivalent);
		bool operator == (const Vec4 &check);
		#pragma endregion Operator_Overloads

		#pragma region Vec4_typedef
		#pragma endregion Vec4_typedef
		 
	};

	//TODO: Fill Out Vec3 Funcs & decide how to represent a Vec3
	class Vec3
	{
	public:
		#pragma region Constructors
		#pragma endregion Constructors

		#pragma region Custom_Functions
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		#pragma endregion Operator_Overloads

		#pragma region Vec3_typedef
		#pragma endregion Vec3_typedef
	};

	//TODO: Fill Out Vec2 Funcs & decide how to represent a Vec2
	class Vec2
	{
	public:
		#pragma region Constructors
		#pragma endregion Constructors

		#pragma region Custom_Functions
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		#pragma endregion Operator_Overloads

		#pragma region Vec2_typedef
		#pragma endregion Vec2_typedef
	};
}