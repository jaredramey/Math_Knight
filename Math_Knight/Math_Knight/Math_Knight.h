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
		~Mat4x4();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		#pragma endregion Operator_Overloads

	};

	//TODO: Fill Out Mat3 Funcs & decide how to represent a Mat3
	class Mat3x3
	{
	public:

		#pragma region Constructors
		Mat3x3();
		Mat3x3(std::vector<std::vector<float>> &matrix);
		Mat3x3(float matrix[3][3]);
		Mat3x3(float matrix[9]);
		~Mat3x3();
		#pragma endregion Constructors

		#pragma region Custom_Functions
		Mat3x3 ScaleMat3();
		Mat3x3 RotMat3_X();
		Mat3x3 RotMat3_Y();
		Mat3x3 RotMat3_Z();
		Mat3x3 TransformMat3();
		float GetElement(int column, int row);
		//Mat3 MultMat3();
		//Going to try an operator overload instead of a func. I feel like there was a reason
		//why we didn't during the project. Can't remember if there was but i'll figure it out
		//once I get to filling it out.
		#pragma endregion Custom_Functions
		 
		#pragma region Operator_Overloads
		//TODO: Make more operator overloads then just multiplication for matricies. Don't think I'll need them but might as well just in case.
		Mat3x3 operator * (const Mat3x3 &factor);
		Mat3x3 operator * (const Mat3x1 &factor);
		Mat3x3 operator / (const Mat3x3 &dividen);
		Mat3x3 operator + (const Mat3x3 &term);
		Mat3x3 operator - (const Mat3x3 &term);
		Mat3x3 operator = (const Mat3x3 &equivalent);
		bool operator == (const Mat3x3 &check);
		#pragma endregion Operator_Overloads

		#pragma region Mat3x3_typedef
						//Struct is set up to represent a matrix in column row major
		typedef struct{ float zeroZero, OneZero, twoZero;
						float zeroOne , oneOne , twoOne ;
						float zeroTwo , OneTwo , twoTwo ;   } mat3x3;
		 
		//typedef std::vector<std::vector<float>> mat3x3;
		#pragma endregion

	};

	class Mat3x1
	{
	public:
		#pragma region Constructors
		#pragma endregion Constructors

		#pragma region Custom_Functions
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		#pragma endregion Operator_Overloads
	};

	//TODO: Fill Out Vec4 Funcs & decide how to represent a Vec4
	class Vec4
	{
	public:
		#pragma region Constructors
		#pragma endregion Constructors

		#pragma region Custom_Functions
		#pragma endregion Custom_Functions

		#pragma region Operator_Overloads
		#pragma endregion Operator_Overloads
		 
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
	};
}