#include "Vector3.h"
#include <math.h>

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector3::Vector3()
{
	x = 0;
	y = 0;
	z = 0;
}

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector3::Vector3(float scopex, float scopey, float scopez)
{
	x = scopex;
	y = scopey;
	z = scopez;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Vector3::~Vector3()
{
}

//--------------------------------------------------------------------------------------
// Overloading the + operator to add a Vector3 to a Vector3
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator +(Vector3 rhs)
{
	// Creates a vector3 to contain the result
	Vector3 result;

	// Calculates result + rhs
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the - operator to subtract a Vector3 from a Vector3
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator -(Vector3 rhs)
{
	// Creates a vector3 to contain the result
	Vector3 result;

	// Calculates the result - rhs
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector3 with a Vector3
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator *(Vector3 rhs)
{
	// Creates a vector3 to contain the result
	Vector3 result;

	// Calculates the result * rhs
	result.x = x * rhs.x;
	result.y = y * rhs.y;
	result.z = z * rhs.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector3 by a float
//
// Param:
//		rhs: The right hand side of the equation.
//
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
Vector3 Vector3::operator *(float rhs)
{
	// Creates a vector3 to contain the result
	Vector3 result;

	// Calculates the x, y and z * rhs
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float by a Vector3
//
// Param:
//		rhs: The right hand side of the equation.
//		lhs: The left hand side of the equation.
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
Vector3 operator *(float lhs, Vector3 rhs)
{
	// Creates a vector4 to contain the result
	Vector3 result;

	// Calculates the lhs * rhs 
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	
	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the dot product of a vector3
//
// Param:
//		rhs: The right hand side of the equation
//
// Return:
//		Returns a vector3 with the result of the dot product
//--------------------------------------------------------------------------------------
float Vector3::dot(Vector3 rhs)
{
	// Creates a float for the result of the function
	float result;

	// Finds the dot product of a vector3
	result = (x * rhs.x) + (y * rhs.y) + (z * rhs.z);

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the cross product of a vector3
//
// Param:
//		rhs: The right hand side of the equation
//
// Return:
//		Returns a vector3 with the result of the cross product
//--------------------------------------------------------------------------------------
Vector3 Vector3::cross(Vector3 rhs)
{
	// Creates a vector3 to contain the result
	Vector3 result;

	// Finds the cross product of a vector3
	result.x = (y * rhs.z) - (z * rhs.y);
	result.y = (z * rhs.x) - (x * rhs.z);
	result.z = (x * rhs.y) - (y * rhs.x);

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the magnitude of a vector3
//
// Return:
//		Returns a float containing the magnitude
//--------------------------------------------------------------------------------------
float Vector3::magnitude()
{
	// Calculates the magnitude
	return sqrtf((x * x) + (y * y) + (z * z));
}

//--------------------------------------------------------------------------------------
// Normalises a Vector3
//--------------------------------------------------------------------------------------
void Vector3::normalise()
{
	// Creates a float that contains the magnitude using the magnitude function
	float magres = magnitude();

	// If the result of the magnitude function does not equal 0 then divide the x, y and z
	// by the magnitude. 
	if (magres != 0)
	{
		x = (x / magres);
		y = (y / magres);
		z = (z / magres);
	}
}

//--------------------------------------------------------------------------------------
// Overloading the [] operator to allow for checking which value is in the x, y or z
// axis
//
// Param:
//		a: Takes in a value between 0-3 to determine which axis to check. 0 = x, 1 = y
//		else = z
//		
// Return:
//		x if input is 0, y if input is 1 otherwise it returns z
//--------------------------------------------------------------------------------------
float& Vector3::operator [](int a)
{
	// If a is equal to 0, they are checking for x's value, therefore return x
	if (a == 0)
		return x;
	// If a is equal to 1, they are checking for y's value, therefore return y
	if (a == 1)
		return y;
	// If the input is anything other than 0 or 1, they are checking for 
	// z, therefore return z
	else
		return z;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to return the x of a vector3
//		
// Return:
//		The x in a Vector3
//--------------------------------------------------------------------------------------
Vector3::operator float*() 
{
	return &x;
}

//--------------------------------------------------------------------------------------
// Finds the distance between 2 vector3s
//
// Param:
//		dis: This is parsed in to find the distance between it and another vector3
//		
// Return:
//		The distance between 2 vector3s as a float
//--------------------------------------------------------------------------------------
float Vector3::Distance(Vector3 dis)
{
	// Creates a temporary vector3 
	Vector3 temp;

	// Deducts one vector from the other to find the distance
	temp.x = dis.x - x;
	temp.y = dis.y - y;
	temp.z = dis.z - z;

	return temp.magnitude();
}

//--------------------------------------------------------------------------------------
// Finds the LERP of 2 vector3s
//
// Param:
//		a: A vector3 set as point one
//		b: A vector3 set as point two
//		t: Time
//		
// Return:
//		A vector3 containing the lerp
//--------------------------------------------------------------------------------------
Vector3 Vector3::lerp(Vector3 a, Vector3 b, float t)
{
	// Calculates and returns the lerp
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Calculates a quadratic bezier curve 
//
// Param:
//		a: A vector3 set as point one
//		b: A vector3 set as point two
//		c: A vector3 set as point three
//		t: Time
//		
// Return:
//		Return the lerp from the two intermediate points
//--------------------------------------------------------------------------------------
Vector3 Vector3::quadtraticBezier(Vector3 a, Vector3 b, Vector3 c, float t)
{
	//lerp from the first point to the second
	Vector3 mid1 = lerp(a, b, t);

	//lerp from the second point to the third
	Vector3 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

//--------------------------------------------------------------------------------------
// Calculates a hermite curve 
//
// Param:
//		point0: A vector3 set as point 0
//		tangent0: The tangent of point 0
//		point1: A vector3 set as point 1
//		tangent1: The tangent of point 1
//		t: Time
//		
// Return:
//		Return the combined result
//--------------------------------------------------------------------------------------
Vector3 Vector3::hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t)
{
	//Calculate t-squared and t-cubed
	float tsq = t * t;
	float tcub = tsq * t;

	//calculate the 4 basis functions
	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

//--------------------------------------------------------------------------------------
// Calculates the maxiumum vector3 by parsing in 2 vector3s and creating a new one with
// the largest of all the values
//
// Param:
//		a: A parsed in vector3 to be compared with b
//		b: A parsed in vector3 to be compared with a
//		
// Return:
//		A vector4 containing the largest x, y and z
//--------------------------------------------------------------------------------------
Vector3 Vector3::Max(Vector3 a, Vector3 b)
{
	// Creates new vector3 for the result
	Vector3 result;

	// This function determines which is the largest x, y and z and places the largest
	// ones inside the result vector3
	if (a.x > b.x)
		result.x = a.x;
	if (a.y > b.y)
		result.y = a.y;
	if (a.z > b.z)
		result.z = a.z;

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the minimum vector3 by parsing in 2 vector3s and creating a new one with
// the smallest of all the values
//
// Param:
//		a: A parsed in vector3 to be compared with b
//		b: A parsed in vector3 to be compared with a
//		
// Return:
//		A vector3 containing the smallest x, y and z
//--------------------------------------------------------------------------------------
Vector3 Vector3::Min(Vector3 a, Vector3 b)
{
	// Creates new vector3 for the result
	Vector3 result;

	// This function determines which is the smallest x, y and z and places the 
	// smallest ones inside the result vector3
	if (a.x < b.x)
		result.x = a.x;
	if (a.y < b.y)
		result.y = a.y;
	if (a.z < b.z)
		result.z = a.z;

	return result;
}

//--------------------------------------------------------------------------------------
// This starts the large list of swizzle functions.
//
// The xyz changes depending on which swizzle is being done.
// They go in this order xyz so typing whatever letter into whatever spot swizzles it
// to what you type in so wzyx would put the z in x, y in z and x in y.
//
// Vector4 Vector4::zxy()
//
//	Vector4 result;
//
//	result.x = z; 
//	result.y = x;
//	result.z = y ;
//	return result;

// Return:
//		A vector3 containing the result
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// DISCLAIMER:
// There are only swizzle functions from this point on.
//--------------------------------------------------------------------------------------
Vector3 Vector3::xxx()
{
	Vector3 result;

	result.x = x;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::xxy()
{
	Vector3 result;

	result.x = x;
	result.y = x;
	result.z = y;
	return result;
}

Vector3 Vector3::xxz()
{
	Vector3 result;

	result.x = x;
	result.y = x;
	result.z = z;
	return result;
}

Vector3 Vector3::xyx()
{
	Vector3 result;

	result.x = x;
	result.y = y;
	result.z = x;
	return result;
}

Vector3 Vector3::xyy()
{
	Vector3 result;

	result.x = x;
	result.y = y;
	result.z = y;
	return result;
}

Vector3 Vector3::xyz()
{
	Vector3 result;

	result.x = x;
	result.y = y;
	result.z = z;
	return result;
}

Vector3 Vector3::xzx()
{
	Vector3 result;

	result.x = x;
	result.y = z;
	result.z = x;
	return result;
}

Vector3 Vector3::xzy()
{
	Vector3 result;

	result.x = x;
	result.y = z;
	result.z = y;
	return result;
}

Vector3 Vector3::xzz()
{
	Vector3 result;

	result.x = x;
	result.y = z;
	result.z = z;
	return result;
}

Vector3 Vector3::yxx()
{
	Vector3 result;

	result.x = y;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::yxy()
{
	Vector3 result;

	result.x = y;
	result.y = x;
	result.z = y;
	return result;
}

Vector3 Vector3::yxz()
{
	Vector3 result;

	result.x = y;
	result.y = x;
	result.z = z;
	return result;
}

Vector3 Vector3::yyx()
{
	Vector3 result;

	result.x = y;
	result.y = y;
	result.z = x;
	return result;
}

Vector3 Vector3::yyy()
{
	Vector3 result;

	result.x = y;
	result.y = y;
	result.z = y;
	return result;
}

Vector3 Vector3::yyz()
{
	Vector3 result;

	result.x = y;
	result.y = y;
	result.z = z;
	return result;
}

Vector3 Vector3::yzx()
{
	Vector3 result;

	result.x = y;
	result.y = z;
	result.z = x;
	return result;
}

Vector3 Vector3::yzy()
{
	Vector3 result;

	result.x = y;
	result.y = z;
	result.z = y;
	return result;
}

Vector3 Vector3::yzz()
{
	Vector3 result;

	result.x = y;
	result.y = z;
	result.z = z;
	return result;
}

Vector3 Vector3::zxx()
{
	Vector3 result;

	result.x = z;
	result.y = x;
	result.z = x;
	return result;
}

Vector3 Vector3::zxy()
{
	Vector3 result;

	result.x = z;
	result.y = x;
	result.z = y;
	return result;
}

Vector3 Vector3::zxz()
{
	Vector3 result;

	result.x = z;
	result.y = x;
	result.z = z;
	return result;
}

Vector3 Vector3::zyx()
{
	Vector3 result;

	result.x = z;
	result.y = y;
	result.z = x;
	return result;
}

Vector3 Vector3::zyy()
{
	Vector3 result;

	result.x = z;
	result.y = y;
	result.z = y;
	return result;
}

Vector3 Vector3::zyz()
{
	Vector3 result;

	result.x = z;
	result.y = y;
	result.z = z;
	return result;
}

Vector3 Vector3::zzx()
{
	Vector3 result;

	result.x = z;
	result.y = z;
	result.z = x;
	return result;
}

Vector3 Vector3::zzy()
{
	Vector3 result;

	result.x = z;
	result.y = z;
	result.z = y;
	return result;
}

Vector3 Vector3::zzz()
{
	Vector3 result;

	result.x = z;
	result.y = z;
	result.z = z;
	return result;
}
