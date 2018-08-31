#include "Vector2.h"
#include <math.h>

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector2::Vector2()
{
	x = 0;
	y = 0;
}

//--------------------------------------------------------------------------------------
//	Constructor
//--------------------------------------------------------------------------------------
Vector2::Vector2(float scopex, float scopey)
{
	x = scopex;
	y = scopey;
}

//--------------------------------------------------------------------------------------
// Default Destructor
//--------------------------------------------------------------------------------------
Vector2::~Vector2()
{
}

//--------------------------------------------------------------------------------------
// Overloading the + operator to add a Vector2 to a Vector2
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator +(Vector2 rhs)
{
	// Creates a vector2 to contain the result 
	Vector2 result;

	// Calculates result + rhs
	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the - operator to subtract a Vector2 from a Vector2
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator -(Vector2 rhs)
{
	// Creates a vector2 to contain the result
	Vector2 result;

	// Calculates result - rhs
	result.x = x - rhs.x;
	result.y = y - rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a Vector2 with a float
//
// Param:
//		rhs: The right hand side of the equation.
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator *(float rhs)
{
	// Creates a vector2 to contain the result
	Vector2 result;

	// Calculates result * rhs
	result.x = x * rhs;
	result.y = y * rhs;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float by a Vector2
//
// Param:
//		rhs: The right hand side of the equation.
//		lhs: The left hand side of the equation.
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
Vector2 operator *(float lhs, Vector2 rhs)
{
	// Creates a vector2 to contain the result
	Vector2 result;

	// Calculates the lhs * rhs
	result.x = lhs * rhs.x;
	result.y = lhs * rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the / operator to divide a vector2 with a vector2
//
// Param:
//		rhs: The right hand side of the equation.
//
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator /(Vector2 rhs)
{
	// Creates a vector2 for the result
	Vector2 result;

	// Calculates result / rhs
	result.x = x / rhs.x;
	result.y = y / rhs.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Overloading the == operator to check if a vector2 is equal to another vector2
//
// Param:
//		rhs: The right hand side of the equation.
//		
// Return:
//		Returns true or false depending on whether the vectors are the same or not
//--------------------------------------------------------------------------------------
bool Vector2::operator ==(Vector2 rhs)
{
	// Creates a vector2 for the result
	Vector2 result;

	// If result is equal to rhs return true
	if (result.x == rhs.x && result.y == rhs.y)
		return true;
	// If they aren't the same then return false
	else
		false;
}

//--------------------------------------------------------------------------------------
// Overloading the != operator to check whether a vector2 is not equal to another vector2
//
// Param:
//		rhs: The right hand side of the equation.
//		
// Return:
//		True if result is not equal to rhs, otherwise return false
//--------------------------------------------------------------------------------------
bool Vector2::operator !=(Vector2 rhs)
{
	// Creates a vector2 for the result
	Vector2 result;

	// If result's x is not the same as rhs's x OR result's y is not equal to rhs's y
	// return true
	if (x != rhs.x || y != rhs.y)
		return true;
	// Else, return false
	else
		return false;
}

//--------------------------------------------------------------------------------------
// Overloading the > operator to return the larger vector2
//
// Param:
//		rhs: The right hand side of the equation.
//		
// Return:
//		Returns the larger vector2 
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator >(Vector2 rhs)
{
	// Creates a vector2 for the result
	Vector2 result;

	// If result is greater than rhs then return result
	if (result.x > rhs.x && result.y > rhs.y)
		return result;
	// If rhs is greater than result then return rhs
	else
		return rhs;
}

//--------------------------------------------------------------------------------------
// Overloading the > operator to return the larger vector2 whether it's greater than
// or equal to
//
// Param:
//		rhs: The right hand side of the equation.
//		
// Return:
//		Returns the larger vector2 if it's greater than or equal to rhs
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator >=(Vector2 rhs)
{
	//Creates a vector2 for the result
	Vector2 result;

	// If result is greater than or equal to rhs then return result
	if (result.x > rhs.x && result.y > rhs.y || result.x == rhs.x && result.y == rhs.y)
		return result;
	// Otherwise just return rhs
	else
		return rhs;
}

//--------------------------------------------------------------------------------------
// Overloading the < operator to return the smaller vector2
//
// Param:
//		rhs: The right hand side of the equation.
//		
// Return:
//		Returns the smaller vector2 
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator <(Vector2 rhs)
{
	// Creates a vector2 for the result
	Vector2 result;

	// If result is less than rhs, return result
	if (result.x < rhs.x && result.y < rhs.y)
		return result;
	// Otherwise just return rhs
	else
		return rhs;
}

//--------------------------------------------------------------------------------------
// Overloading the <= operator to return the larger vector2 whether it's less than or
// equal to
//
// Param:
//		rhs: The right hand side of the equation.
//		
// Return:
//		Returns the smaller vector2 whether it's less than or equal to rhs
//--------------------------------------------------------------------------------------
Vector2 Vector2::operator <=(Vector2 rhs)
{
	// Creates a vector2 for the result
	Vector2 result;

	// If result is less than or equal to rhs then return result
	if (result.x < rhs.x && result.y < rhs.y || result.x == rhs.x && result.y == rhs.y)
		return result;
	// Otherwise return rhs
	else
		return rhs;
}

//--------------------------------------------------------------------------------------
// Calculates the dot product of a vector2
//
// Param:
//		rhs: The right hand side of the equation
//
// Return:
//		Returns a vector2 with the result of the dot product
//--------------------------------------------------------------------------------------
float Vector2::dot(Vector2 rhs)
{
	// Creates a float for the result of the function
	float result;

	// Finds the dot product of a vector2
	result = (x * rhs.x) + (y * rhs.y);

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the magnitude of a vector2
//
// Return:
//		Returns the magnitude of a vector2
//--------------------------------------------------------------------------------------
float Vector2::magnitude()
{
	// Returns the answer of the equation for getting the magnitude and returns it as a float
	return sqrtf((x * x) + (y * y));
}

//--------------------------------------------------------------------------------------
// Normalises a vector2
//--------------------------------------------------------------------------------------
void Vector2::normalise()
{
	// Creates a float that stores the magnitude
	float magres = magnitude();

	// If the magnitude result is not equal to 0 then divide the vector2 by the magnitude
	// this normalises the vector
	if (magres != 0)
	{
		x = (x / magres);
		y = (y / magres);
	}
}

//--------------------------------------------------------------------------------------
// Overloading the [] operator to allow for checking which value is in the x or y axis
//
// Param:
//		a: Takes in a value 0 or 1 to determine which axis to check. 0 = x, else = y
//		
// Return:
//		x if input is 0, otherwise it returns y
//--------------------------------------------------------------------------------------
float& Vector2::operator [](int a) 
{
	// If a is equal to 0, they are checking for x's value, therefore return x
	if (a == 0)
		return x;
	// If the input is anything other than 0, they are checking for y, therefore return y
	else
		return y;
}

//--------------------------------------------------------------------------------------
// Overloading the * operator to return the x of a vector2
//
// Return:
//		the x in a vector2
//--------------------------------------------------------------------------------------
Vector2::operator float*() 
{
	return &x;
}

//--------------------------------------------------------------------------------------
// Finds the LERP of 2 vector2s
//
// Param:
//		a: A vector2 set as point one
//		b: A vector2 set as point two
//		t: Time
//		
// Return:
//		A vector2 containing the lerp
//--------------------------------------------------------------------------------------
Vector2 Vector2::lerp(Vector2 a, Vector2 b, float t)
{
	return (a + b) * t;
}

//--------------------------------------------------------------------------------------
// Calculates a quadratic bezier curve 
//
// Param:
//		a: A vector2 set as point one
//		b: A vector2 set as point two
//		c: A vector2 set as point three
//		t: Time
//		
// Return:
//		Return the lerp from the two intermediate points
//--------------------------------------------------------------------------------------
Vector2 Vector2::quadtraticBezier(Vector2 a, Vector2 b, Vector2 c, float t)
{
	//lerp from the first point to the second
	Vector2 mid1 = lerp(a, b, t);

	//lerp from the second point to the third
	Vector2 mid2 = lerp(b, c, t);

	//return the lerp from the two intermediate points
	return lerp(mid1, mid2, t);
}

//--------------------------------------------------------------------------------------
// Calculates a hermite curve 
//
// Param:
//		point0: A vector2 set as point 0
//		tangent0: The tangent of point 0
//		point1: A vector2 set as point 1
//		tangent1: The tangent of point 1
//		t: Time
//		
// Return:
//		Return the combined result
//--------------------------------------------------------------------------------------
Vector2 Vector2::hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t)
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
// Calculates the maxiumum vector2 by parsing in 2 vector2s and creating a new one with
// the largest of all the values
//
// Param:
//		a: A parsed in vector2 to be compared with b
//		b: A parsed in vector2 to be compared with a
//		
// Return:
//		A vector2 containing the largest x and y
//--------------------------------------------------------------------------------------
Vector2 Vector2::Max(Vector2 a, Vector2 b)
{
	// Creates new vector2 for the result
	Vector2 result;

	// This function determines which is the largest x and y and places the largest
	// ones inside the result vector2
	if (a.x > b.x)
		result.x = a.x;
	if (a.y > b.y)
		result.y = a.y;

	return result;
}

//--------------------------------------------------------------------------------------
// Calculates the minimum vector2 by parsing in 2 vector2s and creating a new one with
// the smallest of all the values
//
// Param:
//		a: A parsed in vector2 to be compared with b
//		b: A parsed in vector2 to be compared with a
//		
// Return:
//		A vector2 containing the smallest x and y
//--------------------------------------------------------------------------------------
Vector2 Vector2::Min(Vector2 a, Vector2 b)
{
	// Creates new vector2 for the result
	Vector2 result;

	// This function determines which is the smallest x and y and places the 
	// smallest ones inside the result vector2
	if (a.x < b.x)
		result.x = a.x;
	if (a.y < b.y)
		result.y = a.y;

	return result;
}

//--------------------------------------------------------------------------------------
// This starts the large list of swizzle functions.
//
// The xx changes depending on which swizzle is being done.
// They go in this order xy so typing whatever letter into whatever spot swizzles it
// to what you type in so yx would put the y in the x and the y in the x
//
// Vector2 Vector2::xx()
//
//	Vector2 result;
//
//	result.x = y; 
//	result.y = x;
//	return result;

// Return:
//		A vector2 containing the result
//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------
// DISCLAIMER:
// There are only swizzle functions from this point on.
//--------------------------------------------------------------------------------------
Vector2 Vector2::xx()
{
	Vector2 result;

	result.x = x;
	result.y = x;
	return result;
}

Vector2 Vector2::xy()
{
	Vector2 result;

	result.x = x;
	result.y = y;
	return result;
}

Vector2 Vector2::yx()
{
	Vector2 result;

	result.x = y;
	result.y = x;
	return result;
}

Vector2 Vector2::yy()
{
	Vector2 result;

	result.x = y;
	result.y = y;
	return result;
}