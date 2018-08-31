//--------------------------------------------------------------------------------------
// Class for the Vector2
//
//--------------------------------------------------------------------------------------
#pragma once

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
// Vector2 class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Vector2
{
public:

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2();

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2(float scopex, float scopey);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector2();
	
	//--------------------------------------------------------------------------------------
	// Overloading the + operator to add a Vector2 to a Vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator +(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the - operator to subtract a Vector2 from a Vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator -(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector2 with a float
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator *(float rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the / operator to divide a vector2 with a vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//
	// Return:
	//		Returns a Vector2 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator /(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the == operator to check if a vector2 is equal to another vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//		
	// Return:
	//		Returns true or false depending on whether the vectors are the same or not
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator ==(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the != operator to check whether a vector2 is not equal to another vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//		
	// Return:
	//		True if result is not equal to rhs, otherwise return false
	//--------------------------------------------------------------------------------------
	MATH_DLL bool operator !=(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the > operator to return the larger vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//		
	// Return:
	//		Returns the larger vector2 
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator >(Vector2 rhs);

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
	MATH_DLL Vector2 operator >=(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the < operator to return the smaller vector2
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//		
	// Return:
	//		Returns the smaller vector2 
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector2 operator <(Vector2 rhs);

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
	MATH_DLL Vector2 operator <=(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the dot product of a vector2
	//
	// Param:
	//		rhs: The right hand side of the equation
	//
	// Return:
	//		Returns a vector2 with the result of the dot product
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector2::dot(Vector2 rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the magnitude of a vector2
	//
	// Return:
	//		Returns the magnitude of a vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector2::magnitude();

	//--------------------------------------------------------------------------------------
	// Normalises a vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL void Vector2::normalise();

	//--------------------------------------------------------------------------------------
	// Overloading the [] operator to allow for checking which value is in the x or y axis
	//
	// Param:
	//		a: Takes in a value 0 or 1 to determine which axis to check. 0 = x, else = y
	//		
	// Return:
	//		x if input is 0, otherwise it returns y
	//--------------------------------------------------------------------------------------
	MATH_DLL float& operator [](int a);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to return the x of a vector2
	//
	// Return:
	//		the x in a vector2
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

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
	MATH_DLL Vector2 Vector2::lerp(Vector2 a, Vector2 b, float t);

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
	MATH_DLL Vector2 Vector2::quadtraticBezier(Vector2 a, Vector2 b, Vector2 c, float t);

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
	MATH_DLL Vector2 Vector2::hermiteCurve(Vector2 point0, Vector2 tangent0, Vector2 point1, Vector2 tangent1, float t);

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
	MATH_DLL Vector2 Vector2::Max(Vector2 a, Vector2 b);

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
	MATH_DLL Vector2 Vector2::Min(Vector2 a, Vector2 b);
	
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
	MATH_DLL Vector2 xx();
	MATH_DLL Vector2 xy();
	MATH_DLL Vector2 yx();
	MATH_DLL Vector2 yy();

	float x;
	float y;

};

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float by a Vector2
//
// Param:
//		rhs: The right hand side of the equation.
//		lhs: The left hand side of the equation.
// Return:
//		Returns a Vector2 containing the result.
//--------------------------------------------------------------------------------------
MATH_DLL Vector2 operator *(float lhs, Vector2 rhs);

