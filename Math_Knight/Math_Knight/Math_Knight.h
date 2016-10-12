/* ||                   Math_Knight.Lib 
   ||By: Jared Ramey (Oezaxs)	Started: 07/14/16
   ||
*/

//NOTE: THIS LIBRARY USES COLUMN ROW MAJOR. MAKE SURE YOUR MATRICIES ARE SET UP AS SUCH.

#include <string>
#include <iostream>
#include <cmath>
#include <vector>

//Defining pi so I don't have to type it out
//MSDN standard value
#define PI 3.14159265358979323846

namespace MK //Math_Knight shorthand
{
	//TODO: Fill out Basic Funcs
	class Basic
	{
	public:
		float LinearInterp(float v0, float v1, float t);
		float DegToRad(float Deg);
		float RadToDeg(float Rad);
		bool IsPowerOfTwo(unsigned int num);
	};

	//TODO: Create & fillout constructor from 4 Vec4's
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

	//TODO: Create & fillout constructor from 3 Vec3's
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
		void SetElement(int column, int row);
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

	//TODO: Create & fillout constructor from Vec3
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
		Mat3x1 operator * (const Mat3x3 &factor);
		Mat3x1 operator - (const Mat3x1 &term);
		Mat3x1 operator + (const Mat3x1 &term);
		Mat3x1 operator = (const Mat3x1 &equivalent);
		bool operator == (const Mat3x1 &check);
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		struct{ float zeroZero, oneZero, twoZero; } entries;
		#pragma endregion Operator_Overloads
	};

	//TODO: Fill Out Vec4 Funcs
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
		Vec4 operator + (const Vec4 &term);
		Vec4 operator += (const Vec4 &term);
		Vec4 operator - (const Vec4 &term);
		Vec4 operator -= (const Vec4 &term);
		Vec4 operator = (const Vec4 &equivalent);
		bool operator == (const Vec4 &check);
		#pragma endregion Operator_Overloads

		#pragma region Vec4_typedef
		struct{ float X, Y, Z, W; } entries;
		#pragma endregion Vec4_typedef
		 
	};

	//TODO: Fill Out Vec3 Funcs
	class Vec3
	{
	public:
		#pragma region Constructors
		Vec3();
		Vec3(float X, float Y, float Z);
		Vec3(std::vector<float> &vector);
		Vec3(float vector[3]);
		~Vec3();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		float Magnitude(const Vec3);
		float DotProduct(const Vec3 &otherVec3);
		float CrossProduct(const Vec3 &otherVec3);
		Vec3 Normalize(const Vec3);
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		Vec3 operator * (const Vec3 &factor);
		Vec3 operator *= (const Vec3 &factor);
		Vec3 operator + (const Vec3 &term);
		Vec3 operator += (const Vec3 &term);
		Vec3 operator - (const Vec3 &term);
		Vec3 operator -= (const Vec3 &term);
		Vec3 operator = (const Vec3 &equivalent);
		bool operator == (const Vec3 &equals);
		#pragma endregion Operator_Overloads

		#pragma region Vec3_typedef
		struct{ float X, Y, Z; } entries;
		#pragma endregion Vec3_typedef
	};

	//TODO: Fill Out Vec2 Funcs
	class Vec2
	{
	public:
		#pragma region Constructors
		Vec2();
		Vec2(float X, float Y);
		Vec2(std::vector<float> &vector);
		Vec2(float vector[2]);
		~Vec2();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		float Magnitude(const Vec2);
		float DotProduct(const Vec2 &otherVec2);
		float CrossProduct(const Vec2 &otherVec2);
		float Lerp(const Vec2 &otherVec, float percentage);
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		Vec2 operator * (const Vec2 &factor);
		Vec2 operator *= (const Vec2 &factor);
		Vec2 operator + (const Vec2 &term);
		Vec2 operator += (const Vec2 &term);
		Vec2 operator - (const Vec2 &term);
		Vec2 operator -= (const Vec2 &term);
		Vec2 operator = (const Vec2 &equivalent);
		bool operator == (const Vec2 &equals);
		#pragma endregion Operator_Overloads

		#pragma region Vec2_typedef
		struct{ float X, Y; } entries;
		#pragma endregion Vec2_typedef
	};
}