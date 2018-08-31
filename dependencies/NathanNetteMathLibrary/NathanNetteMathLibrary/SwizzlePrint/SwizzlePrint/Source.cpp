
//-------------------------------------------------------------------------------
// HOW TO USE THIS PROGRAM
// 
// This program has a function for generating swizzle headers and cpp for
// vector 2, 3 and 4.
// 
// By default all of the functions are active, to isolate a function, simply
// comment out the functions that you DON'T want used.
// 
// For the longer swizzle prints, you will need to go into your console options
// and change the maximum lines used to the maximum. 
//-------------------------------------------------------------------------------

#include <iostream>
using namespace std;

void v2CPP();
void v2H();
void v3CPP();
void v3H();
void v4CPP();
void v4H();

//-------------------------------------------------------------------------------
// Main
//-------------------------------------------------------------------------------
int main()
{
	v2H();
	v2CPP();
	
	v3H();
	v3CPP();
	
	v4H();
	v4CPP();
	
	system("pause");
}

//-------------------------------------------------------------------------------
// Vector 2 Header
//-------------------------------------------------------------------------------
void v2H()
{
	for (char x = 120; x < 122; x++)
	{
		for (char y = 120; y < 122; y++)
		{
			cout << "MATH_DLL Vector2 " << x << y << "()" << endl;
		}
	}
}

//-------------------------------------------------------------------------------
// Vector 2 CPP
//-------------------------------------------------------------------------------
void v2CPP()
{
	for (char x = 120; x < 122; x++)
	{
		for (char y = 120; y < 122; y++)
		{
			cout << "Vector2 Vector2::" << x << y << "()" << endl;
			cout << "{" << endl;
			cout << "Vector2 result;" << endl << endl;
			cout << "result.x = " << x << ";" << endl;
			cout << "result.y = " << y << ";" << endl;
			cout << "return result;" << endl;
			cout << "}" << endl << endl;
		}
	}
}

//-------------------------------------------------------------------------------
// Vector 3 Header
//-------------------------------------------------------------------------------
void v3H()
{
	for (char x = 120; x < 123; x++)
	{
		for (char y = 120; y < 123; y++)
		{
			for (char z = 120; z < 123; z++)
			{
				cout << "MATH_DLL Vector3 " << x << y << z << "()" << endl;
			}
		}
	}
}

//-------------------------------------------------------------------------------
// Vector 3 CPP
//-------------------------------------------------------------------------------
void v3CPP()
{
	for (char x = 120; x < 123; x++)
	{
		for (char y = 120; y < 123; y++)
		{
			for (char z = 120; z < 123; z++)
			{
				cout << "Vector3 Vector3::" << x << y << z << "()" << endl;
				cout << "{" << endl;
				cout << "Vector3 result;" << endl << endl;
				cout << "result.x = " << x << ";" << endl;
				cout << "result.y = " << y << ";" << endl;
				cout << "result.z = " << z << ";" << endl;
				cout << "return result;" << endl;
				cout << "}" << endl << endl;
			}
		}
	}
}

//-------------------------------------------------------------------------------
// Vector 4 Header
//-------------------------------------------------------------------------------
void v4H()
{
	for (char x = 119; x < 123; x++)
	{
		for (char y = 119; y < 123; y++)
		{
			for (char z = 119; z < 123; z++)
			{
				for (char w = 119; w < 123; w++)
				{
					cout << "MATH_DLL Vector4 " << x << y << z << w << "()" << endl;
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------
// Vector 4 CPP
//-------------------------------------------------------------------------------
void v4CPP()
{
	for (char x = 119; x < 123; x++)
	{
		for (char y = 119; y < 123; y++)
		{
			for (char z = 119; z < 123; z++)
			{
				for (char w = 119; w < 123; w++)
				{
					cout << "Vector4 Vector4::" << x << y << z << w << "()" << endl;
					cout << "{" << endl;
					cout << "Vector4 result;" << endl << endl;
					cout << "result.x = " << x << ";" << endl;
					cout << "result.y = " << y << ";" << endl;
					cout << "result.z = " << z << ";" << endl;
					cout << "result.w = " << w << ";" << endl;
					cout << "return result;" << endl;
					cout << "}" << endl << endl;
				}
			}
		}
	}
}

