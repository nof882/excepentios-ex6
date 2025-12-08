#include "Circle.h"
#include "ShapeException.h"
#include <iostream>
#include <windows.h> // WinApi header - needed for setting console color
#include <string>

using std::cout;
using std::endl;

#define GREEN 2
#define DARK_RED 4
#define PURPLE 5
#define YELLOW 6
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define TEAL 11
#define RED 12
#define LIGHT_PURPLE 13
#define LIGHT_YELLOW 14
#define WHITE 15

void set_console_color(unsigned int color)
{
	// colors are 0=black 1=blue 2=green and so on to 15=white
	// colorattribute = foreground + background * 16
	// to get red text on yellow use 4 + 14*16 = 228
	// light red on yellow would be 12 + 14*16 = 236
	// a Dev-C++ tested console application by vegaseat 07nov2004

	HANDLE hConsole;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}

bool test2Circle()
{
	bool result = false;

	try
	{
		// Tests Ex6 part 2a - shape execptions

		set_console_color(LIGHT_PURPLE);
		cout <<
			"*********************\n" <<
			"Test 2 - Circle \n" <<
			"*********************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Trying to initialize a new Circle c(\"r\", \"c\", 2) ... \n" << endl;

		Circle c("r", "par", 2);
		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		try
		{
			cout <<
				"\nTrying to initialize a new Circle p0(\"r\", \"P0\", -2) ... \n" << endl;

			cout <<
				"Radius is negative - Expecting ShapeException... \n" << endl;
			Circle p0("r", "P0", -2);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;
		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException \n" << std::endl;
			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);
		}
		catch (const std::exception& e)
		{
			set_console_color(RED);
			cout << "Got <" << typeid(e).name() << ">" << std::endl;
			cout << "FAILED: got a different exception, should be ShapeException\n";
			set_console_color(WHITE);
			return false;
		}
		catch (...)
		{
			set_console_color(RED);
			cout << "Object thrown" << std::endl;
			cout << "FAILED: catched a non-exception object, should be ShapeException\n";
			set_console_color(WHITE);
			return false;
		}

		try
		{
			cout <<
				"\nTrying to set radius p1.setRad(-20) ... \n" << endl;

			cout <<
				"Radius is negative - Expecting ShapeException... \n" << endl;
			c.setRad(-20);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;
		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException \n" << std::endl;
			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);
		}
		catch (const std::exception& e)
		{
			set_console_color(RED);
			cout << "Got <" << typeid(e).name() << ">" << std::endl;
			cout << "FAILED: got a different exception, should be ShapeException\n";
			set_console_color(WHITE);
			return false;
		}
		catch (...)
		{
			set_console_color(RED);
			cout << "Object thrown" << std::endl;
			cout << "FAILED: catched a non-exception object, should be ShapeException\n";
			set_console_color(WHITE);
			return false;
		}

	}
	catch (...)
	{
		set_console_color(RED);
		std::cerr << "Test crashed" << endl;
		std::cout << "FAILED: The program crashed, check the following things:\n" <<
			"1. Did you delete a pointer twice?\n2. Did you access index out of bounds?\n" <<
			"3. Did you remember to initialize array before accessing it?";
		set_console_color(WHITE);
		return false;
	}

	set_console_color(LIGHT_GREEN);
	cout << "\n########## Shape Exceptions - Circle TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"#############################\n" <<
		"Exercise 6 - Error Handling\n" <<
		"Part 2a - Shape exceptions\n" <<
		"#############################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test2Circle();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex6 Shape Exceptions Tests Passed!!! ##########" << "\n\n";
		set_console_color(WHITE);
	}
	else
	{
		set_console_color(DARK_RED);
		std::cout << "\n########## TEST Failed :( ##########\n";
		set_console_color(WHITE);
	}
	return testResult ? 0 : 1;
}