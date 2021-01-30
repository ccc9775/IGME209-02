// PE1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << "Hello World!\n";
    int decemberSeconds = 60 * 60 * 24 * 31;
    double circleArea = 3.14 * (6.2 * 6.2);
    int a = 5;
    int b = 2;


    
    //std::cout << decemberSeconds << "\n";
    std::cout << "my answer is " << decemberSeconds << std::endl;
    std::cout << std::setprecision(4) << circleArea << "\n";

    //integer division returns an integer, rounding down
    std::cout << a / b;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
