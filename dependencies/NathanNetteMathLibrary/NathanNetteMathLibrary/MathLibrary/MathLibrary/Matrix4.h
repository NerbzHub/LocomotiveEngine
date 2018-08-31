//--------------------------------------------------------------------------------------
// Class for the Matrix4
//
//--------------------------------------------------------------------------------------
#pragma once
#include "Vector4.h"
#include "Matrix3.h"

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
// Matrix4 class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Matrix4
{
public:
	//--------------------------------------------------------------------------------------
	// Default Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4();

	//--------------------------------------------------------------------------------------
	// Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4(
		float m1, float m2, float m3, float m4,
		float m5, float m6, float m7, float m8,
		float m9, float m10, float m11, float m12,
		float m13, float m14, float m15, float m16);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Matrix4();

	// Creating the Matrix4
	float M[4][4];

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector4 by Vector4
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator *(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a matrix4 by matrix4
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a matrix4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 operator *(Matrix4 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a matrix4 by a float
	//
	// Param:
	//		scalar: A float representing the scalar to be multiplied by a matrix4
	// Return:
	//		Returns a matrix4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 operator *(float scalar);

	//--------------------------------------------------------------------------------------
	// Overloading the [] brackets to multiply a vector4 by a matrix4 
	//
	// Param:
	//		a: An int being parsed in to represent which section of the matrix will be multiplied
	// Return:
	//		Returns a matrix4 with the value that has been allocated into the [] brackets.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4& operator [](int a);

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
	// Sets the position in the matrix to the parsed in x, y and z 
	//
	// Param:
	//		x: The x value of the position
	//		y: The y value of the position
	//		z: The z value of the position
	// Return:
	//		Returns a matrix4 containing the identity matrix with the xyz in the position
	//		and a 1 for the w value
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 setPos(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Gets the position inside the matrix
	//
	// Param:
	//		x: The x value of the position
	//		y: The y value of the position
	//		z: The z value of the position 
	// Return:
	//		Returns a matrix4 with the x, y and z as the position then a 1 for the w.
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 getPos(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Sets the scale in the matrix to the parsed in x, y and z 
	//
	// Param:
	//		x: The x value of the scale
	//		y: The y value of the scale
	//		z: The z value of the scale
	// Return:
	//		Returns a matrix4 containing the x, y and z in the correct values for scale
	//		and a 1 for the w
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 setScale(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Gets the scale inside the matrix
	//
	// Param:
	//		x: The x value of the scale
	//		y: The y value of the scale
	//		z: The z value of the scale
	// Return:
	//		Returns a matrix4 with the x, y and z as the scale and a 1 for the w
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 getScale(float x, float y, float z);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a float inside a matrix4
	//
	// Return:
	//		Returns a matrix4
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Calculates the determinant of a matrix4
	//
	// Return:
	//		Returns a float with the result of the determinant
	//--------------------------------------------------------------------------------------
	MATH_DLL float Matrix4::determinant4();

	//--------------------------------------------------------------------------------------
	// Calculates and replaces the current matrix into an inverse matrix
	//--------------------------------------------------------------------------------------
	MATH_DLL void Matrix4::inverse4();
	
	//--------------------------------------------------------------------------------------
	// Checks whether the matrix4 is the same as an identity matrix
	//
	// Return:
	//		Returns true or false if it's an identity matrix or not
	//--------------------------------------------------------------------------------------
	MATH_DLL bool Matrix4::IsIdentity();

	//--------------------------------------------------------------------------------------
	// Calculates and creates a transposed matrix
	//
	// Return:
	//		Returns the transposed matrix
	//--------------------------------------------------------------------------------------
	MATH_DLL Matrix4 Matrix4::Transpose();

	//--------------------------------------------------------------------------------------
	// Gets the scale inside the matrix
	//
	// Param:
	//		from: The vector3 that the character is looking from
	//		target: The vector3 that the character is looking at
	//		up: The vector3 that t
	// Return:
	//		Returns a matrix3 with the x, y and z as the scale.
	//--------------------------------------------------------------------------------------
	MATH_DLL void LookAt(Vector3 from, Vector3 target, Vector3 up);
	
	
	
};

