//--------------------------------------------------------------------------------------
// Class for the Vector3
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
class Vector3
{
public:

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3();

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3(float scopex, float scopey, float scopez);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector3();

	//--------------------------------------------------------------------------------------
	// Overloading the + operator to add a Vector3 to a Vector3
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator +(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the - operator to subtract a Vector3 from a Vector3
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator -(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector3 with a Vector3
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator *(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector3 by a float
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//
	// Return:
	//		Returns a Vector3 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 operator *(float rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the dot product of a vector3
	//
	// Param:
	//		rhs: The right hand side of the equation
	//
	// Return:
	//		Returns a vector3 with the result of the dot product
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector3::dot(Vector3 rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the cross product of a vector3
	//
	// Param:
	//		rhs: The right hand side of the equation
	//
	// Return:
	//		Returns a vector3 with the result of the cross product
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector3 Vector3::cross(Vector3 rhs);
	
	//--------------------------------------------------------------------------------------
	// Calculates the magnitude of a vector3
	//
	// Return:
	//		Returns a float containing the magnitude
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector3::magnitude();

	//--------------------------------------------------------------------------------------
	// Normalises a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL void Vector3::normalise();

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
	MATH_DLL float& operator [](int a);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to return the x of a vector3
	//		
	// Return:
	//		The x in a Vector3
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Finds the distance between 2 vector3s
	//
	// Param:
	//		dis: This is parsed in to find the distance between it and another vector3
	//		
	// Return:
	//		The distance between 2 vector3s as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector3::Distance(Vector3 dis);

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
	MATH_DLL Vector3 Vector3::lerp(Vector3 a, Vector3 b, float t);

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
	MATH_DLL Vector3 Vector3::quadtraticBezier(Vector3 a, Vector3 b, Vector3 c, float t);

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
	MATH_DLL Vector3 Vector3::hermiteCurve(Vector3 point0, Vector3 tangent0, Vector3 point1, Vector3 tangent1, float t);

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
	MATH_DLL Vector3 Vector3::Max(Vector3 a, Vector3 b);

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
	MATH_DLL Vector3 Vector3::Min(Vector3 a, Vector3 b);
	
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
	MATH_DLL Vector3 xxx();
	MATH_DLL Vector3 xxy();
	MATH_DLL Vector3 xxz();
	MATH_DLL Vector3 xyx();
	MATH_DLL Vector3 xyy();
	MATH_DLL Vector3 xyz();
	MATH_DLL Vector3 xzx();
	MATH_DLL Vector3 xzy();
	MATH_DLL Vector3 xzz();
	MATH_DLL Vector3 yxx();
	MATH_DLL Vector3 yxy();
	MATH_DLL Vector3 yxz();
	MATH_DLL Vector3 yyx();
	MATH_DLL Vector3 yyy();
	MATH_DLL Vector3 yyz();
	MATH_DLL Vector3 yzx();
	MATH_DLL Vector3 yzy();
	MATH_DLL Vector3 yzz();
	MATH_DLL Vector3 zxx();
	MATH_DLL Vector3 zxy();
	MATH_DLL Vector3 zxz();
	MATH_DLL Vector3 zyx();
	MATH_DLL Vector3 zyy();
	MATH_DLL Vector3 zyz();
	MATH_DLL Vector3 zzx();
	MATH_DLL Vector3 zzy();
	MATH_DLL Vector3 zzz();

	float x;
	float y;
	float z;
};

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float by a Vector3
//
// Param:
//		rhs: The right hand side of the equation.
//		lhs: The left hand side of the equation.
// Return:
//		Returns a Vector3 containing the result.
//--------------------------------------------------------------------------------------
MATH_DLL Vector3 operator *(float lhs, Vector3 rhs);

