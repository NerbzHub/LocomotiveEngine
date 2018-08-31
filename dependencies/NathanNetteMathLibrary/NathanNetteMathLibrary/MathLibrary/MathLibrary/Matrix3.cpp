#include "Matrix3.h"
#include "Math.h"


//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Matrix3::Matrix3()
{
	//Assigning the identity matrix as the default
	M[0][0] = 1;
	M[0][1] = 0;
	M[0][2] = 0;

	M[1][0] = 0;
	M[1][1] = 1;
	M[1][2] = 0;

	M[2][0] = 0;
	M[2][1] = 0;
	M[2][2] = 1;

}

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Matrix3::Matrix3(
		float m1, float m2, float m3,
		float m4, float m5, float m6,
		float m7, float m8, float m9)
{
	//Assigning each value to the floats
	M[0][0] = m1;
	M[0][1] = m2;
	M[0][2] = m3;

	M[1][0] = m4;
	M[1][1] = m5;
	M[1][2] = m6;

	M[2][0] = m7;
	M[2][1] = m8;
	M[2][2] = m9;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Matrix3::~Matrix3()
{
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector3 by Vector3
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
Vector3 Matrix3::operator *(Vector3 rhs)
{
	// Create a Vector3 called result that will contain the result
	Vector3 result;

	// Multiplying the matrix by the rhs x, y and z
	result.x = M[0][0] * rhs.x + M[1][0] * rhs.y + M[2][0] * rhs.z;
	result.y = M[0][1] * rhs.x + M[1][1] * rhs.y + M[2][1] * rhs.z;
	result.z = M[0][2] * rhs.x + M[1][2] * rhs.y + M[2][2] * rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a matrix3 by matrix3
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a matrix3 containing the result.
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::operator *(Matrix3 rhs)
{
	// Create a matrix3 called result that will contain the result
	Matrix3 result;

	// Multiplying the rhs matrix3 by a matrix3
	result.M[0][0] = M[0][0] * rhs.M[0][0] + M[1][0] * rhs.M[0][1] + M[2][0] * rhs.M[0][2];
	result.M[1][0] = M[0][0] * rhs.M[1][0] + M[1][0] * rhs.M[1][1] + M[2][0] * rhs.M[1][2];
	result.M[2][0] = M[0][0] * rhs.M[2][0] + M[1][0] * rhs.M[2][1] + M[2][0] * rhs.M[2][2];

	result.M[0][1] = M[0][1] * rhs.M[0][0] + M[1][1] * rhs.M[0][1] + M[2][1] * rhs.M[0][2];
	result.M[1][1] = M[0][1] * rhs.M[1][0] + M[1][1] * rhs.M[1][1] + M[2][1] * rhs.M[1][2];
	result.M[2][1] = M[0][1] * rhs.M[2][0] + M[1][1] * rhs.M[2][1] + M[2][1] * rhs.M[2][2];

	result.M[0][2] = M[0][2] * rhs.M[0][0] + M[1][2] * rhs.M[0][1] + M[2][2] * rhs.M[0][2];
	result.M[1][2] = M[0][2] * rhs.M[1][0] + M[1][2] * rhs.M[1][1] + M[2][2] * rhs.M[1][2];
	result.M[2][2] = M[0][2] * rhs.M[2][0] + M[1][2] * rhs.M[2][1] + M[2][2] * rhs.M[2][2];

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a matrix3 by a float
//
// Param:
//		scalar: A float representing the scalar to be multiplied by a matrix3
// Return:
//		Returns a matrix3 containing the result.
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::operator *(float scalar)
{
	// Creates a matrix3 called temp that is a temporary matrix to be multiplied by the scalar.
	Matrix3 temp;

	// This multiplies the temp matrix by the parsed in scalar value.
	temp.M[0][0] = (M[0][0] * scalar);
	temp.M[0][1] = (M[0][1] * scalar);
	temp.M[0][2] = (M[0][2] * scalar);
	

	temp.M[1][0] = (M[1][0] * scalar);
	temp.M[1][1] = (M[1][1] * scalar);
	temp.M[1][2] = (M[1][2] * scalar);
	

	temp.M[2][0] = (M[2][0] * scalar);
	temp.M[2][1] = (M[2][1] * scalar);
	temp.M[2][2] = (M[2][2] * scalar);

	return temp;
}

//--------------------------------------------------------------------------------------
// Overloading the [] brackets to multiply a vector3 by a matrix3 
//
// Param:
//		a: An int being parsed in to represent which section of the matrix will be multiplied
// Return:
//		Returns a matrix3 with the value that has been allocated into the [] brackets.
//--------------------------------------------------------------------------------------
Vector3& Matrix3::operator [](int a)
{
	return *(Vector3*)M[a];
}

//--------------------------------------------------------------------------------------
// Checks whether the matrix3 is the same as an identity matrix
//
// Return:
//		Returns true or false if it's an identity matrix or not
//--------------------------------------------------------------------------------------
bool Matrix3::IsIdentity()
{
	//If the matrix being compared to this is the same as an identity matrix return true.
	if (
		M[0][0] == 1 &&
		M[0][1] == 0 &&
		M[0][2] == 0 &&

		M[1][0] == 0 &&
		M[1][1] == 1 &&
		M[1][2] == 0 &&

		M[2][0] == 0 &&
		M[2][1] == 0 &&
		M[2][2] == 1 
		)
		return true;
	//If the matrix being compared is anything other than an identity matrix then return false.
	else
		false;
}

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
Matrix3 Matrix3::setPos(float x, float y, float z)
{
	// Creates a matrix3 to contain the position.
	Matrix3 m3;

	// Allocating the position inside the matrix and identity for the rest of the matrix.
	m3[0][0] = 1;
	m3[0][1] = 0;
	m3[0][2] = 0;
	 
	m3[1][0] = 0;
	m3[1][1] = 1;
	m3[1][2] = 0;
	 
	m3[2][2] = z;
	m3[2][0] = x;
	m3[2][1] = y;
	
	return m3;
}

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
Matrix3 Matrix3::getPos(float x, float y, float z)
{
	// Creates a matrix3 to contain the result
	Matrix3 result;

	// Allocating the x, y and z in the position of the matrix
	result[0][0] = x;
	result[0][1] = y;
	result[0][2] = z;

	return result;
}

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
Matrix3 Matrix3::setScale(float x, float y, float z)
{
	// Creates a matrix3 to contain the scale
	Matrix3 m3;

	// Allocating the scale in the matrix3.
	m3[0][0] = x;
	m3[0][1] = 0;
	m3[0][2] = 0;
	
	m3[1][0] = 0;
	m3[1][1] = y;
	m3[1][2] = 0;
	
	m3[2][0] = 0;
	m3[2][1] = 0;
	m3[2][2] = z;

	return m3;
}

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
Matrix3 Matrix3::getScale(float x, float y, float z)
{
	// Creates a Matrix3 to contain the scale
	Matrix3 result;

	// Allocating the x, y and z in the position of the matrix
	result[0][0] = x;
	result[1][1] = y;
	result[2][2] = z;

	return result;
}

//--------------------------------------------------------------------------------------
// Sets the rotation of x in the matrix 
//
// Param:
//		a: The rotation value in radians
//--------------------------------------------------------------------------------------
void Matrix3::setRotateX(float a)
{
	// Rotate X
	M[1][1] = cosf(a);
	M[2][1] = -sinf(a);
	M[1][2] = sinf(a);
	M[2][2] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Sets the rotation of y in the matrix 
//
// Param:
//		a: The rotation value in radians
//--------------------------------------------------------------------------------------
void Matrix3::setRotateY(float a)
{
	// Rotate Y
	M[0][0] = cosf(a);
	M[2][0] = sinf(a);
	M[0][2] = -sinf(a);
	M[2][2] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Sets the rotation of z in the matrix 
//
// Param:
//		a: The rotation value in radians
//--------------------------------------------------------------------------------------
void Matrix3::setRotateZ(float a)
{
	// Rotate Z
	M[0][0] = cosf(a);
	M[0][1] = sinf(a);
	M[1][0] = -sinf(a);
	M[1][1] = cosf(a);
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float inside a matrix3
//
// Return:
//		Returns a matrix3
//--------------------------------------------------------------------------------------
Matrix3::operator float*() 
{
	return &M[0][0];
}

//--------------------------------------------------------------------------------------
// Calculates the determinant of a matrix3
//
// Return:
//		Returns a float with the result of the determinant
//--------------------------------------------------------------------------------------
float Matrix3::determinant3()
{
	// Allocating letters to each value in the matrix for ease of use in the equation.
	float a = M[0][0];
	float b = M[0][1];
	float c = M[0][2];
	float d = M[1][0];
	float e = M[1][1];
	float f = M[1][2];
	float g = M[2][0];
	float h = M[2][1];
	float i = M[2][2];

	// Creating a result for each of a, b and c to break up the equation
	float result1;
	float result2;
	float result3;

	// The equation for the determinant
	result1 = a * (e * d - f * h);
	result2 = b * (d * i - f * g);
	result3 = c * (d * h - e * c);

	return result1 - result2 + result3;
}

//--------------------------------------------------------------------------------------
// Calculates and creates the inverse matrix
//
// Return:
//		Returns the inverse matrix
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::inverse3()
{
	// Allocating letters to each value in the matrix for ease of use in the equation.
	float a = M[0][0];
	float b = M[1][0];
	float c = M[2][0];
	float d = M[0][1];
	float e = M[1][1];
	float f = M[2][1];
	float g = M[0][2];
	float h = M[1][2];
	float i = M[2][2];

	// Calculates the determinant
	float detResult = 
	a * (e * i - h * f) -
	b * (d * i - f * g) +
	c * (d * h - e * g);

	// Calculates the inverse determinant
	float invDet = 1 / detResult;

	// Creates a matrix for the inverse matrix
	Matrix3 invRes;

	// Calculates the matrix of minors and Matrix of Cofactors
	invRes[0][0] = M[1][1] * M[2][2] - M[1][2] * M[2][1];
	invRes[0][1] = M[0][2] * M[2][1] - M[0][1] * M[2][2] * -1;//
	invRes[0][2] = M[0][1] * M[1][2] - M[0][2] * M[1][1];
	invRes[1][0] = M[1][2] * M[2][0] - M[1][0] * M[2][2] * -1;//
	invRes[1][1] = M[0][0] * M[2][2] - M[0][2] * M[2][0];
	invRes[1][2] = M[1][0] * M[0][2] - M[0][0] * M[1][2] * -1;//
	invRes[2][0] = M[1][0] * M[2][1] - M[2][0] * M[1][1];
	invRes[2][1] = M[2][0] * M[0][1] - M[0][0] * M[2][1] * -1;//
	invRes[2][2] = M[0][0] * M[1][1] - M[1][0] * M[0][1];

	Matrix3 adjRes;

	adjRes = invRes.Transpose();
	adjRes = adjRes * invDet;

	return adjRes;
}

//--------------------------------------------------------------------------------------
// Calculates and creates a transposed matrix
//
// Return:
//		Returns the transposed matrix
//--------------------------------------------------------------------------------------
Matrix3 Matrix3::Transpose()
{
	// Creates a matrix for transposed matrix
	Matrix3 result;

	// Calculates the transposed matrix
	result[0][0] = M[0][0];
	result[0][1] = M[1][0];
	result[0][2] = M[2][0];

	result[1][0] = M[0][1];
	result[1][1] = M[1][1];
	result[1][2] = M[2][1];

	result[2][0] = M[0][2];
	result[2][1] = M[1][2];
	result[2][2] = M[2][2];

	return result;
}