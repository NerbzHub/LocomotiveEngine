//--------------------------------------------------------------------------------------
// Class for the Vector4
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
// Vector2 class
// Stores functions and data used by the class
//--------------------------------------------------------------------------------------
class Vector4
{
public:

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4();

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4(float scopex, float scopey, float scopez, float scopew);

	//--------------------------------------------------------------------------------------
	//	Constructor
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4(Vector3 & rhs);

	//--------------------------------------------------------------------------------------
	// Default Destructor
	//--------------------------------------------------------------------------------------
	MATH_DLL ~Vector4();
	 

	//MATH_DLL Vector4 setPos();


	//--------------------------------------------------------------------------------------
	// Overloading the + operator to add a Vector4 to a Vector4
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator +(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the - operator to subtract a Vector4 from a Vector4
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator -(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector4 with a Vector4
	//
	// Param:
	//		rhs: The right hand side of the equation.
	// Return:
	//		Returns a Vector4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator *(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to multiply a Vector4 by a float
	//
	// Param:
	//		rhs: The right hand side of the equation.
	//
	// Return:
	//		Returns a Vector4 containing the result.
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 operator *(float rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the cross product of a vector4
	//
	// Param:
	//		rhs: The right hand side of the equation
	//
	// Return:
	//		Returns a vector4 with the result of the cross product
	//--------------------------------------------------------------------------------------
	MATH_DLL Vector4 Vector4::cross(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the dot product of a vector4
	//
	// Param:
	//		rhs: The right hand side of the equation
	//
	// Return:
	//		Returns a vector4 with the result of the dot product
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector4::dot(Vector4 rhs);

	//--------------------------------------------------------------------------------------
	// Calculates the magnitude of a vector4
	//
	// Return:
	//		Returns a float containing the magnitude
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector4::magnitude();

	//--------------------------------------------------------------------------------------
	// Finds the squared magnitude
	//		
	// Return:
	//		The squared magnitude as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector4::sqrMagnitude();

	//--------------------------------------------------------------------------------------
	// Normalises a Vector4
	//--------------------------------------------------------------------------------------
	MATH_DLL void Vector4::normalise();

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
	MATH_DLL float& operator [](int a);

	//--------------------------------------------------------------------------------------
	// Overloading the * operator to return the x of a vector4 
	//		
	// Return:
	//		The x in a Vector4
	//--------------------------------------------------------------------------------------
	MATH_DLL operator float*();

	//--------------------------------------------------------------------------------------
	// Finds the distance between 2 vector4s
	//
	// Param:
	//		dis: This is parsed in to find the distance between it and another vector4
	//		
	// Return:
	//		The distance between 2 vector4s as a float
	//--------------------------------------------------------------------------------------
	MATH_DLL float Vector4::Distance(Vector4 dis);

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
	MATH_DLL Vector4 Vector4::lerp(Vector4 a, Vector4 b, float t);

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
	MATH_DLL Vector4 Vector4::quadtraticBezier(Vector4 a, Vector4 b, Vector4 c, float t);

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
	MATH_DLL Vector4 Vector4::hermiteCurve(Vector4 point0, Vector4 tangent0, Vector4 point1, Vector4 tangent1, float t);

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
	MATH_DLL Vector4 Vector4::Max(Vector4 a, Vector4 b);

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
	MATH_DLL Vector4 Vector4::Min(Vector4 a, Vector4 b);

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
	MATH_DLL Vector4 wwww();
	MATH_DLL Vector4 wwwx();
	MATH_DLL Vector4 wwwy();
	MATH_DLL Vector4 wwwz();
	MATH_DLL Vector4 wwxw();
	MATH_DLL Vector4 wwxx();
	MATH_DLL Vector4 wwxy();
	MATH_DLL Vector4 wwxz();
	MATH_DLL Vector4 wwyw();
	MATH_DLL Vector4 wwyx();
	MATH_DLL Vector4 wwyy();
	MATH_DLL Vector4 wwyz();
	MATH_DLL Vector4 wwzw();
	MATH_DLL Vector4 wwzx();
	MATH_DLL Vector4 wwzy();
	MATH_DLL Vector4 wwzz();
	MATH_DLL Vector4 wxww();
	MATH_DLL Vector4 wxwx();
	MATH_DLL Vector4 wxwy();
	MATH_DLL Vector4 wxwz();
	MATH_DLL Vector4 wxxw();
	MATH_DLL Vector4 wxxx();
	MATH_DLL Vector4 wxxy();
	MATH_DLL Vector4 wxxz();
	MATH_DLL Vector4 wxyw();
	MATH_DLL Vector4 wxyx();
	MATH_DLL Vector4 wxyy();
	MATH_DLL Vector4 wxyz();
	MATH_DLL Vector4 wxzw();
	MATH_DLL Vector4 wxzx();
	MATH_DLL Vector4 wxzy();
	MATH_DLL Vector4 wxzz();
	MATH_DLL Vector4 wyww();
	MATH_DLL Vector4 wywx();
	MATH_DLL Vector4 wywy();
	MATH_DLL Vector4 wywz();
	MATH_DLL Vector4 wyxw();
	MATH_DLL Vector4 wyxx();
	MATH_DLL Vector4 wyxy();
	MATH_DLL Vector4 wyxz();
	MATH_DLL Vector4 wyyw();
	MATH_DLL Vector4 wyyx();
	MATH_DLL Vector4 wyyy();
	MATH_DLL Vector4 wyyz();
	MATH_DLL Vector4 wyzw();
	MATH_DLL Vector4 wyzx();
	MATH_DLL Vector4 wyzy();
	MATH_DLL Vector4 wyzz();
	MATH_DLL Vector4 wzww();
	MATH_DLL Vector4 wzwx();
	MATH_DLL Vector4 wzwy();
	MATH_DLL Vector4 wzwz();
	MATH_DLL Vector4 wzxw();
	MATH_DLL Vector4 wzxx();
	MATH_DLL Vector4 wzxy();
	MATH_DLL Vector4 wzxz();
	MATH_DLL Vector4 wzyw();
	MATH_DLL Vector4 wzyx();
	MATH_DLL Vector4 wzyy();
	MATH_DLL Vector4 wzyz();
	MATH_DLL Vector4 wzzw();
	MATH_DLL Vector4 wzzx();
	MATH_DLL Vector4 wzzy();
	MATH_DLL Vector4 wzzz();
	MATH_DLL Vector4 xwww();
	MATH_DLL Vector4 xwwx();
	MATH_DLL Vector4 xwwy();
	MATH_DLL Vector4 xwwz();
	MATH_DLL Vector4 xwxw();
	MATH_DLL Vector4 xwxx();
	MATH_DLL Vector4 xwxy();
	MATH_DLL Vector4 xwxz();
	MATH_DLL Vector4 xwyw();
	MATH_DLL Vector4 xwyx();
	MATH_DLL Vector4 xwyy();
	MATH_DLL Vector4 xwyz();
	MATH_DLL Vector4 xwzw();
	MATH_DLL Vector4 xwzx();
	MATH_DLL Vector4 xwzy();
	MATH_DLL Vector4 xwzz();
	MATH_DLL Vector4 xxww();
	MATH_DLL Vector4 xxwx();
	MATH_DLL Vector4 xxwy();
	MATH_DLL Vector4 xxwz();
	MATH_DLL Vector4 xxxw();
	MATH_DLL Vector4 xxxx();
	MATH_DLL Vector4 xxxy();
	MATH_DLL Vector4 xxxz();
	MATH_DLL Vector4 xxyw();
	MATH_DLL Vector4 xxyx();
	MATH_DLL Vector4 xxyy();
	MATH_DLL Vector4 xxyz();
	MATH_DLL Vector4 xxzw();
	MATH_DLL Vector4 xxzx();
	MATH_DLL Vector4 xxzy();
	MATH_DLL Vector4 xxzz();
	MATH_DLL Vector4 xyww();
	MATH_DLL Vector4 xywx();
	MATH_DLL Vector4 xywy();
	MATH_DLL Vector4 xywz();
	MATH_DLL Vector4 xyxw();
	MATH_DLL Vector4 xyxx();
	MATH_DLL Vector4 xyxy();
	MATH_DLL Vector4 xyxz();
	MATH_DLL Vector4 xyyw();
	MATH_DLL Vector4 xyyx();
	MATH_DLL Vector4 xyyy();
	MATH_DLL Vector4 xyyz();
	//MATH_DLL Vector4 xyzw();
	MATH_DLL Vector4 xyzx();
	MATH_DLL Vector4 xyzy();
	MATH_DLL Vector4 xyzz();
	MATH_DLL Vector4 xzww();
	MATH_DLL Vector4 xzwx();
	MATH_DLL Vector4 xzwy();
	MATH_DLL Vector4 xzwz();
	MATH_DLL Vector4 xzxw();
	MATH_DLL Vector4 xzxx();
	MATH_DLL Vector4 xzxy();
	MATH_DLL Vector4 xzxz();
	MATH_DLL Vector4 xzyw();
	MATH_DLL Vector4 xzyx();
	MATH_DLL Vector4 xzyy();
	MATH_DLL Vector4 xzyz();
	MATH_DLL Vector4 xzzw();
	MATH_DLL Vector4 xzzx();
	MATH_DLL Vector4 xzzy();
	MATH_DLL Vector4 xzzz();
	MATH_DLL Vector4 ywww();
	MATH_DLL Vector4 ywwx();
	MATH_DLL Vector4 ywwy();
	MATH_DLL Vector4 ywwz();
	MATH_DLL Vector4 ywxw();
	MATH_DLL Vector4 ywxx();
	MATH_DLL Vector4 ywxy();
	MATH_DLL Vector4 ywxz();
	MATH_DLL Vector4 ywyw();
	MATH_DLL Vector4 ywyx();
	MATH_DLL Vector4 ywyy();
	MATH_DLL Vector4 ywyz();
	MATH_DLL Vector4 ywzw();
	MATH_DLL Vector4 ywzx();
	MATH_DLL Vector4 ywzy();
	MATH_DLL Vector4 ywzz();
	MATH_DLL Vector4 yxww();
	MATH_DLL Vector4 yxwx();
	MATH_DLL Vector4 yxwy();
	MATH_DLL Vector4 yxwz();
	MATH_DLL Vector4 yxxw();
	MATH_DLL Vector4 yxxx();
	MATH_DLL Vector4 yxxy();
	MATH_DLL Vector4 yxxz();
	MATH_DLL Vector4 yxyw();
	MATH_DLL Vector4 yxyx();
	MATH_DLL Vector4 yxyy();
	MATH_DLL Vector4 yxyz();
	MATH_DLL Vector4 yxzw();
	MATH_DLL Vector4 yxzx();
	MATH_DLL Vector4 yxzy();
	MATH_DLL Vector4 yxzz();
	MATH_DLL Vector4 yyww();
	MATH_DLL Vector4 yywx();
	MATH_DLL Vector4 yywy();
	MATH_DLL Vector4 yywz();
	MATH_DLL Vector4 yyxw();
	MATH_DLL Vector4 yyxx();
	MATH_DLL Vector4 yyxy();
	MATH_DLL Vector4 yyxz();
	MATH_DLL Vector4 yyyw();
	MATH_DLL Vector4 yyyx();
	MATH_DLL Vector4 yyyy();
	MATH_DLL Vector4 yyyz();
	MATH_DLL Vector4 yyzw();
	MATH_DLL Vector4 yyzx();
	MATH_DLL Vector4 yyzy();
	MATH_DLL Vector4 yyzz();
	MATH_DLL Vector4 yzww();
	MATH_DLL Vector4 yzwx();
	MATH_DLL Vector4 yzwy();
	MATH_DLL Vector4 yzwz();
	MATH_DLL Vector4 yzxw();
	MATH_DLL Vector4 yzxx();
	MATH_DLL Vector4 yzxy();
	MATH_DLL Vector4 yzxz();
	MATH_DLL Vector4 yzyw();
	MATH_DLL Vector4 yzyx();
	MATH_DLL Vector4 yzyy();
	MATH_DLL Vector4 yzyz();
	MATH_DLL Vector4 yzzw();
	MATH_DLL Vector4 yzzx();
	MATH_DLL Vector4 yzzy();
	MATH_DLL Vector4 yzzz();
	MATH_DLL Vector4 zwww();
	MATH_DLL Vector4 zwwx();
	MATH_DLL Vector4 zwwy();
	MATH_DLL Vector4 zwwz();
	MATH_DLL Vector4 zwxw();
	MATH_DLL Vector4 zwxx();
	MATH_DLL Vector4 zwxy();
	MATH_DLL Vector4 zwxz();
	MATH_DLL Vector4 zwyw();
	MATH_DLL Vector4 zwyx();
	MATH_DLL Vector4 zwyy();
	MATH_DLL Vector4 zwyz();
	MATH_DLL Vector4 zwzw();
	MATH_DLL Vector4 zwzx();
	MATH_DLL Vector4 zwzy();
	MATH_DLL Vector4 zwzz();
	MATH_DLL Vector4 zxww();
	MATH_DLL Vector4 zxwx();
	MATH_DLL Vector4 zxwy();
	MATH_DLL Vector4 zxwz();
	MATH_DLL Vector4 zxxw();
	MATH_DLL Vector4 zxxx();
	MATH_DLL Vector4 zxxy();
	MATH_DLL Vector4 zxxz();
	MATH_DLL Vector4 zxyw();
	MATH_DLL Vector4 zxyx();
	MATH_DLL Vector4 zxyy();
	MATH_DLL Vector4 zxyz();
	MATH_DLL Vector4 zxzw();
	MATH_DLL Vector4 zxzx();
	MATH_DLL Vector4 zxzy();
	MATH_DLL Vector4 zxzz();
	MATH_DLL Vector4 zyww();
	MATH_DLL Vector4 zywx();
	MATH_DLL Vector4 zywy();
	MATH_DLL Vector4 zywz();
	MATH_DLL Vector4 zyxw();
	MATH_DLL Vector4 zyxx();
	MATH_DLL Vector4 zyxy();
	MATH_DLL Vector4 zyxz();
	MATH_DLL Vector4 zyyw();
	MATH_DLL Vector4 zyyx();
	MATH_DLL Vector4 zyyy();
	MATH_DLL Vector4 zyyz();
	MATH_DLL Vector4 zyzw();
	MATH_DLL Vector4 zyzx();
	MATH_DLL Vector4 zyzy();
	MATH_DLL Vector4 zyzz();
	MATH_DLL Vector4 zzww();
	MATH_DLL Vector4 zzwx();
	MATH_DLL Vector4 zzwy();
	MATH_DLL Vector4 zzwz();
	MATH_DLL Vector4 zzxw();
	MATH_DLL Vector4 zzxx();
	MATH_DLL Vector4 zzxy();
	MATH_DLL Vector4 zzxz();
	MATH_DLL Vector4 zzyw();
	MATH_DLL Vector4 zzyx();
	MATH_DLL Vector4 zzyy();
	MATH_DLL Vector4 zzyz();
	MATH_DLL Vector4 zzzw();
	MATH_DLL Vector4 zzzx();
	MATH_DLL Vector4 zzzy();
	MATH_DLL Vector4 zzzz();


	
	// Creating floats for x, y, z and w
	float x;
	float y;
	float z;
	float w;
};

//--------------------------------------------------------------------------------------
// Overloading the * operator to multiply a float by a Vector4
//
// Param:
//		rhs: The right hand side of the equation.
//		lhs: The left hand side of the equation.
// Return:
//		Returns a Vector4 containing the result.
//--------------------------------------------------------------------------------------
MATH_DLL Vector4 operator *(float lhs, Vector4 rhs);

