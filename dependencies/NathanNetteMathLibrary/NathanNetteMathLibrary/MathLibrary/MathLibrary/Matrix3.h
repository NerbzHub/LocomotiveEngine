//--------------------------------------------------------------------------------------
// Class for the Matrix3
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector3.h"

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
// Matrix3 class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Matrix3
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3();

	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3(
		float m1, float m2, float m3,
		float m4, float m5, float m6,
		float m7, float m8, float m9);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix3();

	// Creating the Matrix2
	float M[3][3];

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector3 by Vector3
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator *(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a matrix3 by matrix3
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a matrix3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 operator *(Matrix3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a matrix3 by a float
	//
	// Param:
	//		scalar: A float representing the scalar to be multiplied by a matrix3
	// Return:
	//		Returns a matrix3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 operator *(float scalar);

	//--------------------------------------------------------------------------------------
	// Overloading the [] brackets to multiply a vector3 by a matrix3 
	//
	// Param:
	//		a: An int being parsed in to represent which section of the matrix will be multiplied
	// Return:
	//		Returns a matrix3 with the value that has been allocated into the [] brackets.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3& operator [](int a);

	//--------------------------------------------------------------------------------------
	// Checks whether the matrix3 is the same as an identity matrix
	//
	// Return:
	//		Returns true or false if it's an identity matrix or not
	//--------------------------------------------------------------------------------------
	MATH_DLL bool Matrix3::IsIdentity();

	//--------------------------------------------------------------------------------------
	// Sets the position in the matrix to the parsed in x, y and z 
	//
	// Param:
	//		x: The x value of the position
	//		y: The y value of the position
	//		z: The z value of the position
	// Return:
	//		Returns a matrix3 containing the identity matrix with the xyz in the position
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 setPos(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Gets the position inside the matrix
	//
	// Param:
	//		x: The x value of the position
	//		y: The y value of the position
	//		z: The z value of the position 
	// Return:
	//		Returns a matrix3 with the x, y and z as the position.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 getPos(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Sets the scale in the matrix to the parsed in x, y and z 
	//
	// Param:
	//		x: The x value of the scale
	//		y: The y value of the scale
	//		z: The z value of the scale
	// Return:
	//		Returns a matrix3 containing the x, y and z in the correct values for scale
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 setScale(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Gets the scale inside the matrix
	//
	// Param:
	//		x: The x value of the scale
	//		y: The y value of the scale
	//		z: The z value of the scale
	// Return:
	//		Returns a matrix3 with the x, y and z as the scale.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 getScale(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Sets the rotation of x in the matrix 
	//
	// Param:
	//		a: The rotation value in radians
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateX(float a);

	//--------------------------------------------------------------------------------------
	// Sets the rotation of y in the matrix 
	//
	// Param:
	//		a: The rotation value in radians
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateY(float a);

	//--------------------------------------------------------------------------------------
	// Sets the rotation of z in the matrix 
	//
	// Param:
	//		a: The rotation value in radians
	//--------------------------------------------------------------------------------------
	MATH_DLL void setRotateZ(float a);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a float inside a matrix3
	//
	// Return:
	//		Returns a matrix3
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a matrix3
	//
	// Return:
	//		Returns a float with the result of the determinant
	//--------------------------------------------------------------------------------------
	MATH_DLL float Matrix3::determinant3();

	//--------------------------------------------------------------------------------------
	// Calculates and creates the inverse matrix
	//
	// Return:
	//		Returns the inverse matrix
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 Matrix3::inverse3();

	//--------------------------------------------------------------------------------------
	// Calculates and creates a transposed matrix
	//
	// Return:
	//		Returns the transposed matrix
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix3 Matrix3::Transpose();
};

