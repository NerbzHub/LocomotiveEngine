//--------------------------------------------------------------------------------------
// Class for the Matrix2
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector2.h"

//--------------------------------------------------------------------------------------
// This is used to be able to toggle between lib and dll builds
//--------------------------------------------------------------------------------------
#ifdef STATIC_LIB//using static library
#define MATH_DLL

#else //using dynamic array

#ifdef DLL_EXPORT//if we are exporting
#define MATH_DLL __declspec(dllexport)
#else//we are importing
#define MATH_DLL __declspec(dllimport)
#endif
#endif

//--------------------------------------------------------------------------------------
// Matrix2 class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Matrix2
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2();

	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2(
		float m1, float m2,
		float m3, float m4);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix2();

	// Creating the Matrix2
	float M[2][2];

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector2 by Vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator *(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a matrix2 by matrix2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a matrix2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2 operator *(Matrix2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a matrix2 by a float
	//
	// Param:
	//		scalar: A float representing the scalar to be multiplied by a matrix2
	// Return:
	//		Returns a matrix2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2 operator *(float scalar);

	//--------------------------------------------------------------------------------------
	// Overloading the [] brackets to multiply a vector3 by a matrix2
	//
	// Param:
	//		a: An int being parsed in to represent which section of the matrix will be multiplied
	// Return:
	//		Returns a matrix2 with the value that has been allocated into the [] brackets.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2& operator [](int a);

	//--------------------------------------------------------------------------------------
	// Checks whether the matrix2 is the same as an identity matrix
	//
	// Return:
	//		Returns true or false if it's an identity matrix or not
	//--------------------------------------------------------------------------------------
	MATH_DLL bool Matrix2::IsIdentity();

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a matrix 2
	//
	// Return:
	//		Returns a float that is the result of calculating the determinant of a matrix 2
	//--------------------------------------------------------------------------------------
	MATH_DLL float Matrix2::determinant2();

	//--------------------------------------------------------------------------------------
	// Calculates the inverse of a matrix 2x2
	//
	// Return:
	//		Returns a Matrix2 
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix2 Matrix2::inverse2();

	//--------------------------------------------------------------------------------------
	// Creates a float pointer for the matrix2
	//
	// Return:
	//		Returns a Matrix2 
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Sets the rotate of a Matrix2
	//
	// Param:
	//		eType: The type of the weapon the player currently has equipped.
	//		a: 
	//		level: The player's current level.
	//		bonus: Any bonus damage from buffs.
	// Return:
	//		Returns an int containing the total damage the player will do with next attack.
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotate(float a);


};

