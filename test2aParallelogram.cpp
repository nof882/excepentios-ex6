#include "Parallelogram.h"
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

bool test1Parallelogram()
{
	bool result = false;

	try
	{
		// Tests Ex6 part 2a - shape execptions - parrallelogram

		set_console_color(TEAL);
		cout <<
			"**************************\n" <<
			"Test 1 - Parallelogram \n" <<
			"**************************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Trying to initialize a new parallelogram par(\"r\", \"par\", 2, 3.5, 120, 60) ... \n" << endl;

		Parallelogram par("r", "par", 2, 3.5, 120, 60);
		set_console_color(GREEN);
		cout << "OK" << std::endl;
		set_console_color(WHITE);

		try
		{
			cout <<
				"\nTrying to initialize a new parallelogram p0(\"r\", \"P0\", -2, 3.5, 119.7, 60.3) ... \n" << endl;

			cout <<
				"Height is negative - Expecting ShapeException... \n" << endl;
			Parallelogram p0("r", "P0", -2, 3.5, 119.7, 60.3);

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
				"\nTrying to initialize a new parallelogram p1(\"r\", \"P1\", 2, -3.5, 119.7, 60.3) ... \n" << endl;

			cout <<
				"Width is negative - Expecting ShapeException... \n" << endl;
			Parallelogram p1("r", "P1", 2, -3.5, 119.7, 60.3);
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
				"\nTrying to initialize a new parallelogram p2(\"r\", \"P2\", 2, 3.5, -120, 60) ... \n" << endl;

			cout <<
				"First angle is negative - Expecting ShapeException... \n" << endl;
			Parallelogram p2("r", "P2", 2, 3.5, -120, 60);
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
				"\nTrying to initialize a new parallelogram p3(\"r\", \"P3\", 2, 3.5, 120, -60) ... \n" << endl;

			cout <<
				"Second angle is negative - Expecting ShapeException... \n" << endl;

			Parallelogram p3("r", "P3", 2, 3.5, 120, -60);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;
		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException\n" << std::endl;
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
				"\nTrying to initialize a new parallelogram p4(\"r\", \"P4\", 2, 3.5, 190, 60) ... \n" << endl;

			cout <<
				"First angle is bigger than 180 degrees - Expecting ShapeException... \n" << endl;

			Parallelogram p4("r", "P4", 2, 3.5, 190, 60);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;
		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException\n" << std::endl;
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
				"\nTrying to initialize a new parallelogram p5(\"r\", \"P5\", 2, 3.5, 120, 181) ... \n" << endl;

			cout <<
				"Second angle is bigger than 180 degrees - Expecting ShapeException... \n" << endl;

			Parallelogram p5("r", "P5", 2, 3.5, 120, 181);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;
		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException\n" << std::endl;
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
				"\nTrying to initialize a new parallelogram p6(\"r\", \"P6\", 2, 3.5, 180, 0) ... \n" << endl;

			Parallelogram p6("r", "P6", 2, 3.5, 0, 180);

			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);

			cout <<
				"\nTrying to initialize a new parallelogram p7(\"r\", \"P7\", 2, 3.5, 0, 180) ... \n" << endl;

			Parallelogram p7("r", "P7", 2, 3.5, 0, 180);

			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);

		}
		catch (const ShapeException& e)
		{
			set_console_color(RED);
			cout << "Got ShapeException\n" << std::endl;
			cout << "FAILED: exception should not be thrown\n";
			set_console_color(WHITE);
			return false;
		}
		catch (const std::exception& e)
		{
			set_console_color(RED);
			cout << "Got <" << typeid(e).name() << ">" << std::endl;
			cout << "FAILED: exception should not be thrown\n";
			set_console_color(WHITE);
			return false;
		}
		catch (...)
		{
			set_console_color(RED);
			cout << "Object thrown" << std::endl;
			cout << "FAILED: catched a non-exception object, object shouln't be thrown\n";
			set_console_color(WHITE);
			return false;
		}

		try
		{
			cout <<
				"\nTrying to initialize a new parallelogram p8(\"r\", \"P8\", 2, 3.5, 81, 100) ... \n" << endl;

			cout <<
				"Sum of both angles is bigger than 180 degrees - Expecting ShapeException... \n" << endl;

			Parallelogram p8("r", "P8", 2, 3.5, 81, 100);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;
		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException\n" << std::endl;
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
				"\nInitializing a new parallelogram p(\"r\", \"P\", 2, 3.5, 99.9, 80.1) ... \n" << endl;
			Parallelogram p("r", "P", 2, 3.5, 99.9, 80.1);

			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);

			cout <<
				"\nTrying to set angle p.setAngle(120 , 60) ... \n" << endl;

			p.setAngle(120, 60);

			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);

			
		}
		catch (const ShapeException& e)
		{
			set_console_color(RED);
			cout << "Got ShapeException\n" << std::endl;
			cout << "FAILED: exception should not be thrown\n";
			set_console_color(WHITE);
			return false;
		}
		catch (const std::exception& e)
		{
			set_console_color(RED);
			cout << "Got <" << typeid(e).name() << ">" << std::endl;
			cout << "FAILED: exception should not be thrown\n";
			set_console_color(WHITE);
			return false;
		}
		catch (...)
		{
			set_console_color(RED);
			cout << "Object thrown" << std::endl;
			cout << "FAILED: catched a non-exception object, object shouln't be thrown\n";
			set_console_color(WHITE);
			return false;
		}

		try
		{
			cout <<
				"\nInitializing a new parallelogram p(\"r\", \"P\", 2, 3.5, 99.9, 80.1) ... \n" << endl;
			Parallelogram p("r", "P", 2, 3.5, 99.9, 80.1);

			set_console_color(GREEN);
			cout << "OK" << std::endl;
			set_console_color(WHITE);

			cout <<
				"\nTrying to set angle p.setAngle(120 , 61) ... \n" << endl;

			cout <<
				"Sum of both angles is bigger than 180 degrees - Expecting ShapeException... \n" << endl;

			p.setAngle(120, 61);
			std::cout << "Should have thrown an exception" << std::endl;
			return false;

		}
		catch (const ShapeException& e)
		{
			cout << "Got ShapeException\n" << std::endl;
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
	cout << "\n########## Shape Exceptions - Parallelogram TEST Passed!!! ##########\n\n";
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

	bool testResult = test1Parallelogram();

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