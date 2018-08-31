#include "Matrix2.h"
#include <math.h>


//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Matrix2::Matrix2()
{
	//Identity matrix
	M[0][0] = 1;
	M[1][0] = 0;

	M[0][1] = 0;
	M[1][1] = 1;
}


//--------------------------------------------------------------------------------------
// Constructor
//--------------------------------------------------------------------------------------
Matrix2::Matrix2(
		float m1, float m2, 
		float m3, float m4) 
{
	//Assigning each value to the floats
	M[0][0] = m1;
	M[1][0] = m2;

	M[0][1] = m3;
	M[1][1] = m4;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Matrix2::~Matrix2()
{
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector2 by Vector2
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
Vector2 Matrix2::operator *(Vector2 rhs)
{
	// Create a Vector2 called result that will contain the result
	Vector2 result;

	// Multiplying the matrix by the rhs x and y
	result.x = M[0][0] * rhs.x + M[0][1] * rhs.y;
	result.y = M[1][0] * rhs.x + M[1][1] * rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a matrix2 by matrix2
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a matrix2 containing the result.
//--------------------------------------------------------------------------------------
Matrix2 Matrix2::operator *(Matrix2 rhs)
{
	// Create a matrix2 called result that will contain the result
	Matrix2 result;

	// Multiplying the rhs matrix2 by a matrix2
	result.M[0][0] = M[0][0] * rhs.M[0][0] + M[1][0] * rhs.M[0][1];
	result.M[1][0] = M[0][0] * rhs.M[1][0] + M[1][0] * rhs.M[1][1];

	result.M[0][1] = M[0][1] * rhs.M[0][0] + M[1][1] * rhs.M[0][1];
	result.M[1][1] = M[0][1] * rhs.M[1][0] + M[1][1] * rhs.M[1][1];

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a matrix2 by a float
//
// Param:
//		scalar: A float representing the scalar to be multiplied by a matrix2
// Return:
//		Returns a matrix2 containing the result.
//--------------------------------------------------------------------------------------
Matrix2 Matrix2::operator *(float scalar)
{
	// Creates a matrix2 called temp that is a temporary matrix to be multiplied by the scalar.
	Matrix2 temp;

	// This multiplies the temp matrix by the parsed in scalar value.
	temp.M[0][0] = (M[0][0] * scalar);
	temp.M[0][1] = (M[0][1] * scalar);

	temp.M[1][0] = (M[1][0] * scalar);
	temp.M[1][1] = (M[1][1] * scalar);

	temp.M[2][0] = (M[2][0] * scalar);
	temp.M[2][1] = (M[2][1] * scalar);

	return temp;
}

//--------------------------------------------------------------------------------------
// Overloading the [] brackets to multiply a vector3 by a matrix2
//
// Param:
//		a: An int being parsed in to represent which section of the matrix will be multiplied
// Return:
//		Returns a matrix2 with the value that has been allocated into the [] brackets.
//--------------------------------------------------------------------------------------
Vector2& Matrix2::operator [](int a)
{
	return *(Vector2*)M[a];
}

//--------------------------------------------------------------------------------------
// Checks whether the matrix2 is the same as an identity matrix
//
// Return:
//		Returns true or false if it's an identity matrix or not
//--------------------------------------------------------------------------------------
bool Matrix2::IsIdentity()
{
	//If the matrix being compared to this is the same as an identity matrix return true.
	if (
		M[0][0] == 1 &&
		M[0][1] == 0 &&

		M[1][0] == 0 &&
		M[1][1] == 1 
		)
		return true;
	//If the matrix being compared is anything other than an identity matrix then return false.
	else
		false;
}

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
void Matrix2::setRotate(float a)
{
	M[0][0] = cosf(a);
	M[0][1] = -sinf(a);
	M[1][0] = sinf(a);
	M[1][1] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Creates a float pointer for the matrix2
//
// Return:
//		Returns a Matrix2 
//--------------------------------------------------------------------------------------
Matrix2::operator float*() 
{
	return &M[0][0];
}

//--------------------------------------------------------------------------------------
// Calculates the determinant of a matrix 2
//
// Return:
//		Returns a float that is the result of calculating the determinant of a matrix 2
//--------------------------------------------------------------------------------------
float Matrix2::determinant2()
{
	//Allocating floats a, b, c and d to the matrix for ease of use in the equation
	float a = M[0][0];
	float b = M[0][1];
	float c = M[1][0];
	float d = M[1][1];

	//Creates a float called result that will hold the result of the determinant to be returned
	float result;

	//This is the equation for the determinant of a matrix 2x2
	result = a * d - c * d;

	//Return the result
	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the inverse of a matrix 2x2
//
// Return:
//		Returns a Matrix2 
//--------------------------------------------------------------------------------------
Matrix2 Matrix2::inverse2()
{
	// Allocating floats a, b, c and d to the matrix for ease of use in the equation
	float a = M[0][0];
	float b = M[0][1];
	float c = M[1][0];
	float d = M[1][1];

	// Creates a new float for each inversed value
	float invRes00, invRes01, invRes10, invRes11;
	// Creates a float for the determinent result
	float detResult = a * d - b * c;
	
	// Calculates the inverse
	invRes00 = d / detResult;
	invRes01 = -b / detResult;
	invRes10 = -c / detResult;
	invRes11 = a / detResult;

	// Creates a Matrix2 called invMatrix and allocates the inverse values in to it.
	Matrix2 invMatrix(invRes00, invRes01, invRes10, invRes11);

	return invMatrix;
}