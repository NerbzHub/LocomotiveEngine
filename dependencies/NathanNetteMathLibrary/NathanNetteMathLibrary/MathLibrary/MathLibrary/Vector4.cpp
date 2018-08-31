#include "Vector4.h"
#include <math.h>

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector4::Vector4()
{
	x = 0;
	y = 0;
	z = 0;
	w = 0;
}

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector4::Vector4(float scopex, float scopey, float scopez, float scopew)
{
	x = scopex;
	y = scopey;
	z = scopez;
	w = scopew;
}

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector4::Vector4(Vector3 & rhs)
{
	Vector4 result;

	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = 0;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Vector4::~Vector4()
{
}

//--------------------------------------------------------------------------------------
// Overloading the + operator to add a Vector4 to a Vector4
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator +(Vector4 rhs)
{
	// Creates a vector4 to contain the result
	Vector4 result;

	// Calculates result + rhs
	result.x = x + rhs.x;
	result.y = y + rhs.y;
	result.z = z + rhs.z;
	result.w = w + rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the - operator to subtract a Vector4 from a Vector4
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator -(Vector4 rhs)
{
	// Creates a vector4 to contain the result
	Vector4 result;

	// Calculates the result - rhs
	result.x = x - rhs.x;
	result.y = y - rhs.y;
	result.z = z - rhs.z;
	result.w = w - rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector4 with a Vector4
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator *(Vector4 rhs)
{
	// Creates a vector4 to contain the result
	Vector4 result;

	// Calculates the result * rhs
	result.x = x * rhs.x;
	result.y = y * rhs.y;
	result.z = z * rhs.z;
	result.w = w * rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector4 by a float
//
// Param:
//		rhs: The right hand side of the equation.
//
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
Vector4 Vector4::operator *(float rhs)
{
	// Creates a vector4 to contain the result
	Vector4 result;

	// Calculates the x, y, z and w * rhs
	result.x = x * rhs;
	result.y = y * rhs;
	result.z = z * rhs;
	result.w = w * rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float by a Vector4
//
// Param:
//		rhs: The right hand side of the equation.
//		lhs: The left hand side of the equation.
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
Vector4 operator *(float lhs, Vector4 rhs)
{
	// Creates a vector4 to contain the result
	Vector4 result;

	// Calculates the lhs * rhs 
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;
	result.z = lhs * rhs.z;
	result.w = lhs * rhs.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the cross product of a vector4
//
// Param:
//		rhs: The right hand side of the equation
//
// Return:
//		Returns a vector4 with the result of the cross product
//--------------------------------------------------------------------------------------
Vector4 Vector4::cross(Vector4 rhs)
{
	// Creates a vector4 to contain the result
	Vector4 result;

	// Finds the cross product of a vector4
	result.x = (y * rhs.z) - (z * rhs.y);
	result.y = (z * rhs.x) - (x * rhs.z);
	result.z = (x * rhs.y) - (y * rhs.x);
	result.w = 0;

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the dot product of a vector4
//
// Param:
//		rhs: The right hand side of the equation
//
// Return:
//		Returns a vector4 with the result of the dot product
//--------------------------------------------------------------------------------------
float Vector4::dot(Vector4 rhs)
{
	// Creates a float for the result of the function
	float result;

	// Finds the dot product of a vector4
	result = (x * rhs.x) + (y * rhs.y) + (z * rhs.z) + (w * rhs.w);

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the magnitude of a vector4
//
// Return:
//		Returns a float containing the magnitude
//--------------------------------------------------------------------------------------
float Vector4::magnitude()
{
	// Calculates the magnitude 
	return sqrtf((x * x) + (y * y) + (z * z) + (w * w));
}

//--------------------------------------------------------------------------------------
// Finds the squared magnitude
//		
// Return:
//		The squared magnitude as a float
//--------------------------------------------------------------------------------------
float Vector4::sqrMagnitude()
{
	// Calculates the Squared magnitude.
	// This is basically calculating the magnitude without the square root function
	// and this is useful because square root functions are some of the hardest functions
	// a computer can do so in games to save the computing power of millions of square
	// roots, just simply use this without that step and it will still be consistant
	// and be much more efficient 
	return ((x * x) + (y * y) + (z * z) + (w * w));
}

//--------------------------------------------------------------------------------------
// Normalises a Vector4
//--------------------------------------------------------------------------------------
void Vector4::normalise()
{
	// Creates a float that contains the magnitude using the magnitude function
	float magres = magnitude();

	// If the result of the magnitude function does not equal 0 then divide the x, y and z
	// by the magnitude. 
	//No need for w because that is only 1 or 0
	if (magres != 0)
	{
		x = (x / magres);
		y = (y / magres);
		z = (z / magres);
	}
}

//--------------------------------------------------------------------------------------
// Overloading the [] operator to allow for checking which value is in the x, y, z or w
// axis
//
// Param:
//		a: Takes in a value between 0-3 to determine which axis to check. 0 = x, 1 = y
//		2 = z and else = w
//		
// Return:
//		x if input is 0, y if input is 1, z if input is 2 otherwise it returns w
//--------------------------------------------------------------------------------------
float& Vector4::operator [](int a)
{
	// If a is equal to 0, they are checking for x's value, therefore return x
	if (a == 0)
		return x;
	// If a is equal to 1, they are checking for y's value, therefore return y
	if (a == 1)
		return y;
	// If a is equal to 2, they are checking for z's value, therefore return z
	if (a == 2)
		return z;
	// If the input is anything other than anything between 0-3, they are checking for 
	// w, therefore return w
	else
		return w;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to return the x of a vector4 
//		
// Return:
//		The x in a Vector4
//--------------------------------------------------------------------------------------
Vector4::operator float*() 
{
	return &x;
}



//--------------------------------------------------------------------------------------
// Finds the distance between 2 vector4s
//
// Param:
//		dis: This is parsed in to find the distance between it and another vector4
//		
// Return:
//		The distance between 2 vector4s as a float
//--------------------------------------------------------------------------------------
float Vector4::Distance(Vector4 dis)
{
	// Creates a temporary vector4
	Vector4 temp;

	// Deducts one vector from the other to find the distance
	temp.x = dis.x - x;
	temp.y = dis.y - y;
	temp.z = dis.z - z;
	temp.w = dis.w - w;

	return temp.magnitude();
}

//--------------------------------------------------------------------------------------
// Finds the LERP of 2 vector4s
//
// Param:
//		a: A vector4 set as point one
//		b: A vector4 set as point two
//		t: Time
//		
// Return:
//		A vector4 containing the lerp
//--------------------------------------------------------------------------------------
Vector4 Vector4::lerp(Vector4 a, Vector4 b, float t)
{
	// Calculates and returns the lerp
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Calculates a quadratic bezier curve 
//
// Param:
//		a: A vector4 set as point one
//		b: A vector4 set as point two
//		c: A vector4 set as point three
//		t: Time
//		
// Return:
//		Return the lerp from the two intermediate points
//--------------------------------------------------------------------------------------
Vector4 Vector4::quadtraticBezier(Vector4 a, Vector4 b, Vector4 c, float t)
{
	// Lerp from the first point to the second
	Vector4 mid1 = lerp(a, b, t);

	// Lerp from the second point to the third
	Vector4 mid2 = lerp(b, c, t);

	return lerp(mid1, mid2, t);
}

//--------------------------------------------------------------------------------------
// Calculates a hermite curve 
//
// Param:
//		point0: A vector4 set as point 0
//		tangent0: The tangent of point 0
//		point1: A vector4 set as point 1
//		tangent1: The tangent of point 1
//		t: Time
//		
// Return:
//		Return the combined result
//--------------------------------------------------------------------------------------
Vector4 Vector4::hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t)
{
	// Calculate t-squared and t-cubed
	float tsq = t * t;
	float tcub = tsq * t;

	// Calculate the 4 basis functions
	float h00 = 2 * tcub - 3 * tsq + 1;
	float h01 = -2 * tcub + 3 * tsq;
	float h10 = tcub - 2 * tsq + t;
	float h11 = tcub - tsq;

	return h00 * point0 + h10 * tangent0 + h01 * point1 + h11 * tangent1;
}

//--------------------------------------------------------------------------------------
// Calculates the maxiumum vector4 by parsing in 2 vector4s and creating a new one with
// the largest of all the values
//
// Param:
//		a: A parsed in vector4 to be compared with b
//		b: A parsed in vector4 to be compared with a
//		
// Return:
//		A vector4 containing the largest x, y, z and w
//--------------------------------------------------------------------------------------
Vector4 Vector4::Max(Vector4 a, Vector4 b)
{
	// Creates new vector4 for the result
	Vector4 result;

	// This function determines which is the largest x, y, z and w and places the largest
	// ones inside the result vector4
	if (a.x > b.x)
		result.x = a.x;
	if (a.y > b.y)
		result.y = a.y;
	if (a.z > b.z)
		result.z = a.z;
	if (a.w > b.w)
		result.w = a.w;

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the minimum vector4 by parsing in 2 vector4s and creating a new one with
// the smallest of all the values
//
// Param:
//		a: A parsed in vector4 to be compared with b
//		b: A parsed in vector4 to be compared with a
//		
// Return:
//		A vector4 containing the smallest x, y, z and w
//--------------------------------------------------------------------------------------
Vector4 Vector4::Min(Vector4 a, Vector4 b)
{
	// Creates new vector4 for the result
	Vector4 result;

	// This function determines which is the smallest x, y, z and w and places the 
	// smallest ones inside the result vector4
	if (a.x < b.x)
		result.x = a.x;
	if (a.y < b.y)
		result.y = a.y;
	if (a.z < b.z)
		result.z = a.z;
	if (a.w > b.w)
		result.w = a.w;

	return result;
}

//--------------------------------------------------------------------------------------
// This starts the large list of swizzle functions.
//
// The xyzw changes depending on which swizzle is being done.
// They go in this order xyzw so typing whatever letter into whatever spot swizzles it
// to what you type in so wzyx would put the w in x, z in y, y in z and x in w.
//
// Vector4 Vector4::wzyx()
//
//	Vector4 result;
//
//	result.x = w; 
//	result.y = z;
//	result.z = y;
//	result.w = x;
//	return result;

// Return:
//		A vector4 containing the result
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// DISCLAIMER:
// There are only swizzle functions from this point on.
//--------------------------------------------------------------------------------------
Vector4 Vector4::wwww()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wwwx()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wwwy()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wwwz()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wwxw()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wwxx()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wwxy()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wwxz()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wwyw()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wwyx()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wwyy()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wwyz()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wwzw()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wwzx()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wwzy()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wwzz()
{
	Vector4 result;

	result.x = w;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::wxww()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wxwx()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wxwy()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wxwz()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wxxw()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wxxx()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wxxy()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wxxz()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wxyw()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wxyx()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wxyy()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wxyz()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wxzw()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wxzx()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wxzy()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wxzz()
{
	Vector4 result;

	result.x = w;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::wyww()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wywx()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wywy()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wywz()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wyxw()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wyxx()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wyxy()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wyxz()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wyyw()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wyyx()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wyyy()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wyyz()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wyzw()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wyzx()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wyzy()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wyzz()
{
	Vector4 result;

	result.x = w;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::wzww()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::wzwx()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::wzwy()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::wzwz()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::wzxw()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::wzxx()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::wzxy()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::wzxz()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::wzyw()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::wzyx()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::wzyy()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::wzyz()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::wzzw()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::wzzx()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::wzzy()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::wzzz()
{
	Vector4 result;

	result.x = w;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xwww()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xwwx()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xwwy()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xwwz()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xwxw()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xwxx()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xwxy()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xwxz()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xwyw()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xwyx()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xwyy()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xwyz()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xwzw()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xwzx()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xwzy()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xwzz()
{
	Vector4 result;

	result.x = x;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xxww()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xxwx()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xxwy()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xxwz()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xxxw()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xxxx()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xxxy()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xxxz()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xxyw()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xxyx()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xxyy()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xxyz()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xxzw()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xxzx()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xxzy()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xxzz()
{
	Vector4 result;

	result.x = x;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xyww()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xywx()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xywy()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xywz()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xyxw()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xyxx()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xyxy()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xyxz()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xyyw()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xyyx()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xyyy()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xyyz()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

//Vector4 Vector4::xyzw()
//{
//	Vector4 result;
//
//	result.x = x;
//	result.y = y;
//	result.z = z;
//	result.w = w;
//	return result;
//}

Vector4 Vector4::xyzx()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xyzy()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xyzz()
{
	Vector4 result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::xzww()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::xzwx()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::xzwy()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::xzwz()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::xzxw()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::xzxx()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::xzxy()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::xzxz()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::xzyw()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::xzyx()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::xzyy()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::xzyz()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::xzzw()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::xzzx()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::xzzy()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::xzzz()
{
	Vector4 result;

	result.x = x;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::ywww()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::ywwx()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::ywwy()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::ywwz()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::ywxw()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::ywxx()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::ywxy()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::ywxz()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::ywyw()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::ywyx()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::ywyy()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::ywyz()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::ywzw()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::ywzx()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::ywzy()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::ywzz()
{
	Vector4 result;

	result.x = y;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::yxww()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::yxwx()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::yxwy()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::yxwz()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::yxxw()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yxxx()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::yxxy()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::yxxz()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::yxyw()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::yxyx()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::yxyy()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::yxyz()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::yxzw()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::yxzx()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::yxzy()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::yxzz()
{
	Vector4 result;

	result.x = y;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::yyww()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::yywx()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::yywy()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::yywz()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::yyxw()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yyxx()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::yyxy()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::yyxz()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::yyyw()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::yyyx()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::yyyy()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::yyyz()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::yyzw()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::yyzx()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::yyzy()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::yyzz()
{
	Vector4 result;

	result.x = y;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::yzww()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::yzwx()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::yzwy()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::yzwz()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::yzxw()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::yzxx()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::yzxy()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::yzxz()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::yzyw()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::yzyx()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::yzyy()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::yzyz()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::yzzw()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::yzzx()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::yzzy()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::yzzz()
{
	Vector4 result;

	result.x = y;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zwww()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zwwx()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zwwy()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zwwz()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zwxw()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zwxx()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zwxy()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zwxz()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zwyw()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zwyx()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zwyy()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zwyz()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zwzw()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zwzx()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zwzy()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zwzz()
{
	Vector4 result;

	result.x = z;
	result.y = w;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zxww()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zxwx()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zxwy()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zxwz()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zxxw()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zxxx()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zxxy()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zxxz()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zxyw()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zxyx()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zxyy()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zxyz()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zxzw()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zxzx()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zxzy()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zxzz()
{
	Vector4 result;

	result.x = z;
	result.y = x;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zyww()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zywx()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zywy()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zywz()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zyxw()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zyxx()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zyxy()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zyxz()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zyyw()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zyyx()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zyyy()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zyyz()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zyzw()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zyzx()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zyzy()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zyzz()
{
	Vector4 result;

	result.x = z;
	result.y = y;
	result.z = z;
	result.w = z;
	return result;
}

Vector4 Vector4::zzww()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = w;
	result.w = w;
	return result;
}

Vector4 Vector4::zzwx()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = w;
	result.w = x;
	return result;
}

Vector4 Vector4::zzwy()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = w;
	result.w = y;
	return result;
}

Vector4 Vector4::zzwz()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = w;
	result.w = z;
	return result;
}

Vector4 Vector4::zzxw()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = x;
	result.w = w;
	return result;
}

Vector4 Vector4::zzxx()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = x;
	result.w = x;
	return result;
}

Vector4 Vector4::zzxy()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = x;
	result.w = y;
	return result;
}

Vector4 Vector4::zzxz()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = x;
	result.w = z;
	return result;
}

Vector4 Vector4::zzyw()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = y;
	result.w = w;
	return result;
}

Vector4 Vector4::zzyx()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = y;
	result.w = x;
	return result;
}

Vector4 Vector4::zzyy()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = y;
	result.w = y;
	return result;
}

Vector4 Vector4::zzyz()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = y;
	result.w = z;
	return result;
}

Vector4 Vector4::zzzw()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = z;
	result.w = w;
	return result;
}

Vector4 Vector4::zzzx()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = z;
	result.w = x;
	return result;
}

Vector4 Vector4::zzzy()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = z;
	result.w = y;
	return result;
}

Vector4 Vector4::zzzz()
{
	Vector4 result;

	result.x = z;
	result.y = z;
	result.z = z;
	result.w = z;
	return result;
}