#include "MathUtils.h"
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

bool test1MathUtils()
{
	bool result = false;

	try
	{
		// Tests Ex6 part 2b - math utils

		set_console_color(LIGHT_BLUE);
		cout <<
			"***********************\n" <<
			"Test 1 - Math Utils \n" <<
			"***********************\n" << endl;
		set_console_color(WHITE);

		cout <<
			"Calling MathUtils::CalHexagonArea(1)... \n" << endl;

		std::string expected = "2.598076";
		std::string got = std::to_string(MathUtils::CalHexagonArea(1));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalHexagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalHexagonArea(36)... \n" << endl;

		expected = "3367.106770";
		got = std::to_string(MathUtils::CalHexagonArea(36));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalHexagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalHexagonArea(15)... \n" << endl;

		expected = "584.567148";
		got = std::to_string(MathUtils::CalHexagonArea(15));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalHexagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalHexagonArea(1789)... \n" << endl;

		expected = "8315197.474037";
		got = std::to_string(MathUtils::CalHexagonArea(1789));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalHexagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalPentagonArea(1)... \n" << endl;

		expected = "1.720477";
		got = std::to_string(MathUtils::CalPentagonArea(1));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalPentagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalPentagonArea(12)... \n" << endl;

		expected = "247.748746";
		got = std::to_string(MathUtils::CalPentagonArea(12));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalPentagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalPentagonArea(119)... \n" << endl;

		expected = "24363.680470";
		got = std::to_string(MathUtils::CalPentagonArea(119));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalPentagonArea()\n";
			set_console_color(WHITE);
			return false;
		}

		cout <<
			"\nCalling MathUtils::CalPentagonArea(8200)... \n" << endl;

		expected = "115684900.415602";
		got = std::to_string(MathUtils::CalPentagonArea(8200));
		cout << "Expected: " << expected << endl;
		cout << "Got     : " << got << endl;
		if (got != expected)
		{
			set_console_color(RED);
			cout << "FAILED: Math Utils information is not as expected\n" <<
				"check static function MathUtils::CalPentagonArea()\n";
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
	cout << "\n########## Math Utils - TEST Passed!!! ##########\n\n";
	set_console_color(WHITE);

	return true;

}


int main()
{
	set_console_color(LIGHT_YELLOW);
	std::cout <<
		"#############################\n" <<
		"Exercise 6 - Shapes\n" <<
		"Part 2b - Math Utils\n" <<
		"#############################\n" << std::endl;
	set_console_color(WHITE);

	bool testResult = test1MathUtils();

	if (testResult)
	{
		set_console_color(GREEN);
		std::cout << "\n########## Ex6 Math Utils Tests Passed!!! ##########" << "\n\n";
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