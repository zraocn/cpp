// cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Enum.h"

//#define ENABLE_BITMASK_OPERATORS(x) template<> struct EnableBitMaskOperators<x> { static const bool enable = true; };

enum class Permissions
{
    Readable = 0x4,
    Writable = 0x2,
    Executable = 0x1
};
ENABLE_BITMASK_OPERATORS(Permissions)

void testTypeSafeEnum() {
    // all ok
    Permissions p = Permissions::Readable | Permissions::Writable;
    p |= Permissions::Executable;
    p &= ~Permissions::Writable;

    enum class Color { Red, Green, Blue };

    // compilation fails, as intended
    // Color yellow = Color::Red | Color::Green;
}

int main()
{
    std::cout << "Hello World!\n"; 
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
