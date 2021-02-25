#include "pch.h"
#include "CppUnitTest.h"
#include <cstring>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

__declspec(dllimport) char* GetTeam();
__declspec(dllimport) void SetMaze(const int** data, int width, int height);
__declspec(dllimport) int** GetMaze(int& width, int& height);
//__declspec(dllimport) void GetNextPosition(int& xPos, int& yPos);
__declspec(dllimport) void SetStart(int xPos, int yPos);
__declspec(dllimport) void GetStart(int& xPos, int& yPos);
__declspec(dllimport) void SetEnd(int xPos, int yPos);
__declspec(dllimport) void GetEnd(int& xPos, int& yPos);

namespace Part1UnitTests
{
	TEST_CLASS(Part1UnitTests)
	{
	public:
		
		TEST_METHOD(TestGetTeam)
		{
			Assert::IsTrue(strcmp(GetTeam(), "Chase Call") == 0);
		}

		TEST_METHOD(TestSetMaze)
		{
			const int** data = (const int**)25;
			int height = 20;
			int width = 15;

			try {
				SetMaze(data, height, width);
			}
			catch (const std::exception&) {
				Assert::Fail(L"set maze threw an exception");
			}
		}

		TEST_METHOD(TestGetMaze)
		{

			int height = 20;
			int width = 15;

			try {
				GetMaze(height, width);
			}
			catch (const std::exception&) {
				Assert::Fail(L"get maze threw an exception");
			}
		}

		TEST_METHOD(TestSetStart)
		{
			try {
				SetStart(2, 5);
			}
			catch (const std::exception&) {
				Assert::Fail(L"set start threw an exception");
			}
		}
		TEST_METHOD(TestGetStart)
		{

			int x = 2;
			int y = 1;

			try {
				GetStart(x, y);
			}
			catch (const std::exception&) {
				Assert::Fail(L"get start threw an exception");
			}
		}

		TEST_METHOD(TestSetEnd)
		{
			try {
				SetEnd(10, 2);
			}
			catch (const std::exception&) {
				Assert::Fail(L"set end threw an exception");
			}
		}
		TEST_METHOD(TestGetEnd)
		{

			int x = 12;
			int y = 17;

			try {
				GetEnd(x, y);
			}
			catch (const std::exception&) {
				Assert::Fail(L"get end threw an exception");
			}
		}
	};
}
