#include "Matrix4.h"
#include "Math.h"

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Matrix4::Matrix4()
{
	//Identity matrix
	M[0][0] = 1;
	M[0][1] = 0;
	M[0][2] = 0;
	M[0][3] = 0;

	M[1][0] = 0;
	M[1][1] = 1;
	M[1][2] = 0;
	M[1][3] = 0;

	M[2][0] = 0;
	M[2][1] = 0;
	M[2][2] = 1;
	M[2][3] = 0;

	M[3][0] = 0;
	M[3][1] = 0;
	M[3][2] = 0;
	M[3][3] = 1;
}

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Matrix4::Matrix4(
	float m1, float m2, float m3, float m4,
	float m5, float m6, float m7, float m8,
	float m9, float m10, float m11, float m12,
	float m13, float m14, float m15, float m16)
{
	//Assigning each value to the floats
	M[0][0] = m1;
	M[0][1] = m2;
	M[0][2] = m3;
	M[0][3] = m4;

	M[1][0] = m5;
	M[1][1] = m6;
	M[1][2] = m7;
	M[1][3] = m8;

	M[2][0] = m9;
	M[2][1] = m10;
	M[2][2] = m11;
	M[2][3] = m12;

	M[3][0] = m13;
	M[3][1] = m14;
	M[3][2] = m15;
	M[3][3] = m16;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Matrix4::~Matrix4()
{
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector4 by Vector4
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
Vector4 Matrix4::operator *(Vector4 rhs)
{
	// Create a Vector4 called result that will contain the result
	Vector4 result;

	// Multiplying the matrix by the rhs x, y, z and w
	result.x = M[0][0] * rhs.x + M[1][0] * rhs.y + M[2][0] * rhs.z + M[3][0] * rhs.w;
	result.y = M[0][1] * rhs.x + M[1][1] * rhs.y + M[2][1] * rhs.z + M[3][1] * rhs.w;
	result.z = M[0][2] * rhs.x + M[1][2] * rhs.y + M[2][2] * rhs.z + M[3][2] * rhs.w;
	result.w = M[0][3] * rhs.x + M[1][3] * rhs.y + M[2][3] * rhs.z + M[3][3] * rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a matrix4 by matrix4
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a matrix4 containing the result.
//--------------------------------------------------------------------------------------
Matrix4 Matrix4::operator *(Matrix4 rhs)
{
	// Create a matrix4 called result that will contain the result
	Matrix4 result;

	// Multiplying the rhs matrix3 by a matrix4
	result.M[0][0] = M[0][0] * rhs.M[0][0] + M[1][0] * rhs.M[0][1] + M[2][0] * rhs.M[0][2] + M[3][0] * rhs.M[0][3];
	result.M[1][0] = M[0][0] * rhs.M[1][0] + M[1][0] * rhs.M[1][1] + M[2][0] * rhs.M[1][2] + M[3][0] * rhs.M[1][3];
	result.M[2][0] = M[0][0] * rhs.M[2][0] + M[1][0] * rhs.M[2][1] + M[2][0] * rhs.M[2][2] + M[3][0] * rhs.M[2][3];
	result.M[3][0] = M[0][0] * rhs.M[3][0] + M[1][0] * rhs.M[3][1] + M[2][0] * rhs.M[3][2] + M[3][0] * rhs.M[3][3];

	result.M[0][1] = M[0][1] * rhs.M[0][0] + M[1][1] * rhs.M[0][1] + M[2][1] * rhs.M[0][2] + M[3][1] * rhs.M[0][3];
	result.M[1][1] = M[0][1] * rhs.M[1][0] + M[1][1] * rhs.M[1][1] + M[2][1] * rhs.M[1][2] + M[3][1] * rhs.M[1][3];
	result.M[2][1] = M[0][1] * rhs.M[2][0] + M[1][1] * rhs.M[2][1] + M[2][1] * rhs.M[2][2] + M[3][1] * rhs.M[2][3];
	result.M[3][1] = M[0][1] * rhs.M[3][0] + M[1][1] * rhs.M[3][1] + M[2][1] * rhs.M[3][2] + M[3][1] * rhs.M[3][3];

	result.M[0][2] = M[0][2] * rhs.M[0][0] + M[1][2] * rhs.M[0][1] + M[2][2] * rhs.M[0][2] + M[3][2] * rhs.M[0][3];
	result.M[1][2] = M[0][2] * rhs.M[1][0] + M[1][2] * rhs.M[1][1] + M[2][2] * rhs.M[1][2] + M[3][2] * rhs.M[1][3];
	result.M[2][2] = M[0][2] * rhs.M[2][0] + M[1][2] * rhs.M[2][1] + M[2][2] * rhs.M[2][2] + M[3][2] * rhs.M[2][3];
	result.M[3][2] = M[0][2] * rhs.M[3][0] + M[1][2] * rhs.M[3][1] + M[2][2] * rhs.M[3][2] + M[3][2] * rhs.M[3][3];

	result.M[0][3] = M[0][3] * rhs.M[0][0] + M[1][3] * rhs.M[0][1] + M[2][3] * rhs.M[0][2] + M[3][3] * rhs.M[0][3];
	result.M[1][3] = M[0][3] * rhs.M[1][0] + M[1][3] * rhs.M[1][1] + M[2][3] * rhs.M[1][2] + M[3][3] * rhs.M[1][3];
	result.M[2][3] = M[0][3] * rhs.M[2][0] + M[1][3] * rhs.M[2][1] + M[2][3] * rhs.M[2][2] + M[3][3] * rhs.M[2][3];
	result.M[3][3] = M[0][3] * rhs.M[3][0] + M[1][3] * rhs.M[3][1] + M[2][3] * rhs.M[3][2] + M[3][3] * rhs.M[3][3];

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a matrix4 by a float
//
// Param:
//		scalar: A float representing the scalar to be multiplied by a matrix4
// Return:
//		Returns a matrix4 containing the result.
//--------------------------------------------------------------------------------------
Matrix4 Matrix4::operator *(float scalar)
{
	// Creates a matrix4 called temp that is a temporary matrix to be multiplied by the scalar.
	Matrix4 temp;

	// This multiplies the temp matrix by the parsed in scalar value.
	temp.M[0][0] = (M[0][0] * scalar);
	temp.M[0][1] = (M[0][1] * scalar);
	temp.M[0][2] = (M[0][2] * scalar);
	temp.M[0][3] = (M[0][3] * scalar);

	temp.M[1][0] = (M[1][0] * scalar);
	temp.M[1][1] = (M[1][1] * scalar);
	temp.M[1][2] = (M[1][2] * scalar);
	temp.M[1][3] = (M[1][3] * scalar);

	temp.M[2][0] = (M[2][0] * scalar);
	temp.M[2][1] = (M[2][1] * scalar);
	temp.M[2][2] = (M[2][2] * scalar);
	temp.M[2][3] = (M[2][3] * scalar);

	temp.M[3][0] = (M[3][0] * scalar);
	temp.M[3][1] = (M[3][1] * scalar);
	temp.M[3][2] = (M[3][2] * scalar);
	temp.M[3][3] = (M[3][3] * scalar);

	return temp;
}

//--------------------------------------------------------------------------------------
// Overloading the [] brackets to multiply a vector4 by a matrix4 
//
// Param:
//		a: An int being parsed in to represent which section of the matrix will be multiplied
// Return:
//		Returns a matrix4 with the value that has been allocated into the [] brackets.
//--------------------------------------------------------------------------------------
Vector4& Matrix4::operator [](int a)
{
	return *(Vector4*)M[a];
}

//--------------------------------------------------------------------------------------
// Sets the rotation of x in the matrix 
//
// Param:
//		a: The rotation value in radians
//--------------------------------------------------------------------------------------
void Matrix4::setRotateX(float a)
{
	//Rotate X
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
void Matrix4::setRotateY(float a)
{
	//Rotate Y
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
void Matrix4::setRotateZ(float a)
{
	//Rotate Z
	M[0][0] = cosf(a);
	M[0][1] = sinf(a);
	M[1][0] = -sinf(a);
	M[1][1] = cosf(a);
}
//Doesn't need one for W because it is just 0 or 1

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
Matrix4 Matrix4::setPos(float x, float y, float z)
{
	// Creates a matrix4 to contain the position.
	Matrix4 m4;

	// Allocating the position inside the matrix and identity for the rest of the matrix.
	m4[0][0] = 1;
	m4[0][1] = 0;
	m4[0][2] = 0;
	m4[0][3] = 0;
	m4[1][0] = 0;
	m4[1][1] = 1;
	m4[1][2] = 0;
	m4[1][3] = 0;
	m4[2][0] = 0;
	m4[2][1] = 0;
	m4[2][2] = 1;
	m4[2][3] = 0;
	m4[3][0] = x;
	m4[3][1] = y;
	m4[3][2] = z;
	m4[3][3] = 1;

	return m4;
}

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
Matrix4 Matrix4::getPos(float x, float y, float z)
{
	// Creates a matrix4 to contain the result
	Matrix4 result;

	// Allocating the x, y and z in the position of the matrix and a 1 for the w
	result[0][0] = x;
	result[0][1] = y;
	result[0][2] = z;
	result[0][3] = 1; //w
	
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
//		Returns a matrix4 containing the x, y and z in the correct values for scale
//		and a 1 for the w
//--------------------------------------------------------------------------------------
Matrix4 Matrix4::setScale(float x, float y, float z)
{
	// Creates a matrix4 to contain the scale
	Matrix4 m4;

	// Allocating the scale in the matrix4.
	m4[0][0] = x;
	m4[0][1] = 0;
	m4[0][2] = 0;
	m4[0][3] = 0;

	m4[1][0] = 0;
	m4[1][1] = y;
	m4[1][2] = 0;
	m4[1][3] = 0;

	m4[2][0] = 0;
	m4[2][1] = 0;
	m4[2][2] = z;
	m4[2][3] = 0;

	m4[3][0] = 0;
	m4[3][1] = 0;
	m4[3][2] = 0;
	m4[3][3] = 1;

	return m4;
}

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
Matrix4 Matrix4::getScale(float x, float y, float z)
{
	// Creates a Matrix4 to contain the scale
	Matrix4 result;

	// Allocating the x, y and z in the position of the matrix and a 1 for the w
	result[0][0] = x;
	result[1][1] = y;
	result[2][2] = z;
	result[3][3] = 1; //w

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float inside a matrix4
//
// Return:
//		Returns a matrix4
//--------------------------------------------------------------------------------------
Matrix4::operator float*() 
{
	return &M[0][0];
}

//--------------------------------------------------------------------------------------
// Calculates the determinant of a matrix4
//
// Return:
//		Returns a float with the result of the determinant
//--------------------------------------------------------------------------------------
float Matrix4::determinant4()
{
	// Allocating letters to each value in the matrix for ease of use in the equation.
	float a = M[0][0];
	float b = M[0][1];
	float c = M[0][2];
	float d = M[0][3];

	float e = M[1][0];
	float f = M[1][1];
	float g = M[1][2];
	float h = M[1][3];

	float i = M[2][0];
	float j = M[2][1];
	float k = M[2][2];
	float l = M[2][3];

	float m = M[3][0];
	float n = M[3][1];
	float o = M[3][2];
	float p = M[3][3];

	// Creating a result for each of a, b, c and d to break up the equation
	float result1 = a * (f * k * p - f * l * o - g * j * p + g * l * n + h * j * o - h * k * n);
	float result2 = b * (e * k * p - e * l * o - g * i * p + g * l * m + h * j * o - h * k * m);
	float result3 = c * (e * j * p - e * l * n - f * i * p + f * l * m + h * i * n - h * j * m);
	float result4 = d * (e * j * o - e * k * n - f * i * o + f * k * m + g * i * n - g * j * m);

	return result1 - result2 + result3 - result4;
}

//--------------------------------------------------------------------------------------
// Calculates and replaces the current matrix into an inverse matrix
//
// Calculates the matrix minor 
// Calculates the determinant of the matrix minor
// Transposes the matrix minor after being multiplied by the determinant
// 
//--------------------------------------------------------------------------------------
void Matrix4::inverse4()
{
	// Allocating letters to each value in the matrix for ease of use in the equation.
	float a1 = M[0][0];
	float a2 = M[0][1];
	float a3 = M[0][2];
	float a4 = M[0][3];
		  
	float a5 = M[1][0];
	float a6 = M[1][1];
	float a7 = M[1][2];
	float a8 = M[1][3];
		  
	float a9 = M[2][0];
	float a10 = M[2][1];
	float a11 = M[2][2];
	float a12 = M[2][3];
		  
	float a13 = M[3][0];
	float a14 = M[3][1];
	float a15 = M[3][2];
	float a16 = M[3][3];

	//Matrix minor
	Matrix3 s1(a6, a7, a8, a10, a11, a12, a14, a15, a16);
	Matrix3 s2(a5, a7, a8, a9, a11, a12, a13, a15, a16);
	Matrix3 s3(a5, a6, a8, a9, a10, a12, a13, a14, a16);
	Matrix3 s4(a5, a6, a7, a9, a10, a11, a13, a14, a15);
	Matrix3 s5(a2, a3, a4, a10, a11, a12, a14, a15, a16);
	Matrix3 s6(a1, a3, a4, a9, a11, a12, a13, a15, a16);
	Matrix3 s7(a1, a2, a4, a9, a10, a12, a13, a14, a16);
	Matrix3 s8(a1, a2, a3, a9, a10, a11, a13, a14, a15);
	Matrix3 s9(a2, a3, a4, a6, a7, a8, a14, a15, a16);
	Matrix3 s10(a1, a3, a4, a5, a7, a8, a13, a15, a16);
	Matrix3 s11(a1, a2, a4, a5, a6, a8, a13, a14, a16);
	Matrix3 s12(a1, a2, a3, a5, a6, a7, a13, a14, a15);
	Matrix3 s13(a2, a3, a4, a6, a7, a8, a10, a11, a12);
	Matrix3 s14(a1, a3, a4, a5, a7, a8, a9, a11, a12);
	Matrix3 s15(a1, a2, a4, a5, a6, a8, a9, a10, a12);
	Matrix3 s16(a1, a2, a3, a5, a6, a7, a9, a10, a11);

	// Creating a matrix4 to hold the matrix minor
	Matrix4 minor; 

	// Using the determinant function to find the determinant of the matrix minor and apply 
	// the checkerboard of minuses for the cofactor
	minor[0][0] = s1.determinant3();
	minor[0][1]	= s2.determinant3() * -1; 
	minor[0][2]	= s3.determinant3(); 
	minor[0][3]	= s4.determinant3() * -1;
					
	minor[1][0]	= s5.determinant3() * -1;
	minor[1][1]	= s6.determinant3(); 
	minor[1][2]	= s7.determinant3() * -1;
	minor[1][3]	= s8.determinant3(); 
				
	minor[2][0]	= s9.determinant3(); 
	minor[2][1]	= s10.determinant3() * -1;
	minor[2][2]	= s11.determinant3();
	minor[2][3]	= s12.determinant3() * -1;
				
	minor[3][0]	= s13.determinant3() * -1;
	minor[3][1]	= s14.determinant3();
	minor[3][2]	= s15.determinant3() * -1;
	minor[3][3]	= s16.determinant3();

	// Creating a new matrix4 to hold the adjucate
	Matrix4 adjucate;

	// Transpose the minor and place the result in the adjucate matrix
	adjucate = minor.Transpose();
	
	float det1 = M[0][0] * minor[0][0];
	float det2 = M[0][1] * minor[0][1] * -1;
	float det3 = M[0][2] * minor[0][2];
	float det4 = M[0][3] * minor[0][3] * -1;

	// Creating a float to hold the determinant result
	float detRes = det1 - det2 + det3 - det4;

	// The transposed matrix * 1/determinant result
	adjucate = adjucate * (1 / detRes);
}

//--------------------------------------------------------------------------------------
// Checks whether the matrix4 is the same as an identity matrix
//
// Return:
//		Returns true or false if it's an identity matrix or not
//--------------------------------------------------------------------------------------
bool Matrix4::IsIdentity()
{
	//If the matrix being compared to this is the same as an identity matrix return true.
	if (
		M[0][0] == 1 &&
		M[0][1] == 0 &&
		M[0][2] == 0 &&
		M[0][3] == 0 &&

		M[1][0] == 0 &&
		M[1][1] == 1 &&
		M[1][2] == 0 &&
		M[1][3] == 0 &&

		M[2][0] == 0 &&
		M[2][1] == 0 &&
		M[2][2] == 1 &&
		M[2][3] == 0 &&

		M[3][0] == 0 &&
		M[3][1] == 0 &&
		M[3][2] == 0 &&
		M[3][3] == 1
		)
		return true;

	//If the matrix being compared is anything other than an identity matrix then return false.
	else
		return false;
}

//--------------------------------------------------------------------------------------
// Calculates and creates a transposed matrix
//
// Return:
//		Returns the transposed matrix
//--------------------------------------------------------------------------------------
Matrix4 Matrix4::Transpose()
{
	// Creates a matrix for transposed matrix
	Matrix4 result;
	
	// Calculates the transposed matrix
	result[0][0] = M[0][0];
	result[0][1] = M[1][0];
	result[0][2] = M[2][0];
	result[0][3] = M[3][0];

	result[1][0] = M[0][1];
	result[1][1] = M[1][1];
	result[1][2] = M[2][1];
	result[1][3] = M[3][1];

	result[2][0] = M[0][2];
	result[2][1] = M[1][2];
	result[2][2] = M[2][2];
	result[2][3] = M[3][2];

	result[3][0] = M[0][3];
	result[3][1] = M[1][3];
	result[3][2] = M[2][3];
	result[3][3] = M[3][3];

	return result;
}

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
void Matrix4::LookAt(Vector3 from, Vector3 target, Vector3 up)
{
	// zAxis is the target value - the from value 
	Vector3 zAxis = target - from;
	// Normalise the zAxis
	zAxis.normalise();

	// xAxis is the cross product of the zAxis with the up value parsed in
	Vector3 xAxis = zAxis.cross(up);
	// Normalise the xAxis
	xAxis.normalise();

	// yAxis is the cross product of the xAxis with the zAxis parsed in
	Vector3 yAxis = xAxis.cross(zAxis);
	// Normalise the yAxis
	yAxis.normalise();

	(*this)[0] = Vector4 (xAxis);
	(*this)[1] = Vector4 (yAxis);
	(*this)[2] = Vector4 (zAxis);
	(*this)[3] = Vector4 (from);

	M[3][3] = 1;
}

