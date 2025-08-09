#include "iter.hpp"
#include <iostream>
#include <string>

// Functions that take NON-CONST references (can modify)
void printInt(int &n)
{
    std::cout << n << " ";
}

void printString(std::string &str)
{
    std::cout << str << " ";
}

void incrementInt(int &n)
{
    n++;
}

void uppercaseString(std::string &str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
}

void printChar(char &c)
{
    std::cout << c << " ";
}

void incrementChar(char &c)
{
    c++;
}

// Functions that take CONST references (read-only)
void printConstInt(const int &n)
{
    std::cout << n << " ";
}

void printConstString(const std::string &str)
{
    std::cout << str << " ";
}

void printConstChar(const char &c)
{
    std::cout << c << " ";
}

// Template function that works with any type
template<typename T>
void printAny(const T &element)
{
    std::cout << element << " ";
}

int main(void)
{
    std::cout << "=== Testing iter function template ===" << std::endl << std::endl;

    // Test with integers - NON-CONST functions
    std::cout << "Test 1: Array of integers (non-const functions)" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original array: ";
    iter(intArray, intSize, printInt);
    std::cout << std::endl;
    
    std::cout << "After incrementing: ";
    iter(intArray, intSize, incrementInt);
    iter(intArray, intSize, printInt);
    std::cout << std::endl << std::endl;

    // Test with integers - CONST functions
    std::cout << "Test 2: Array of integers (const functions)" << std::endl;
    const int constIntArray[] = {10, 20, 30, 40, 50};
    size_t constIntSize = sizeof(constIntArray) / sizeof(constIntArray[0]);
    
    std::cout << "Const array with const function: ";
    iter(constIntArray, constIntSize, printConstInt);
    std::cout << std::endl;
    
    std::cout << "Non-const array with const function: ";
    iter(intArray, intSize, printConstInt);
    std::cout << std::endl << std::endl;

    // Test with strings - NON-CONST functions
    std::cout << "Test 3: Array of strings (non-const functions)" << std::endl;
    std::string stringArray[] = {"hello", "world", "cpp", "templates"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Original strings: ";
    iter(stringArray, stringSize, printString);
    std::cout << std::endl;
    
    std::cout << "After uppercasing: ";
    iter(stringArray, stringSize, uppercaseString);
    iter(stringArray, stringSize, printString);
    std::cout << std::endl << std::endl;

    // Test with strings - CONST functions
    std::cout << "Test 4: Array of strings (const functions)" << std::endl;
    const std::string constStringArray[] = {"const", "string", "array", "test"};
    size_t constStringSize = sizeof(constStringArray) / sizeof(constStringArray[0]);
    
    std::cout << "Const string array: ";
    iter(constStringArray, constStringSize, printConstString);
    std::cout << std::endl << std::endl;

    // Test with characters
    std::cout << "Test 5: Array of characters (mixed functions)" << std::endl;
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
    
    std::cout << "Original characters: ";
    iter(charArray, charSize, printChar);
    std::cout << std::endl;
    
    std::cout << "Same with const function: ";
    iter(charArray, charSize, printConstChar);
    std::cout << std::endl;
    
    std::cout << "After incrementing: ";
    iter(charArray, charSize, incrementChar);
    iter(charArray, charSize, printChar);
    std::cout << std::endl << std::endl;

    // Test with template function
    std::cout << "Test 6: Template function test" << std::endl;
    double doubleArray[] = {3.14, 2.71, 1.41, 1.73};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Double array with template function: ";
    iter(doubleArray, doubleSize, printAny<double>);
    std::cout << std::endl;
    
    std::cout << "String array with template function: ";
    iter(stringArray, stringSize, printAny<std::string>);
    std::cout << std::endl << std::endl;

    // Test with empty array (edge case)
    std::cout << "Test 7: Empty array (edge case)" << std::endl;
    int *emptyArray = NULL;
    std::cout << "Testing with empty array (length 0): ";
    iter(emptyArray, 0, printInt);
    std::cout << "No output expected." << std::endl;

    std::cout << std::endl << "=== All tests completed ===" << std::endl;
    std::cout << "✅ iter function works with both const and non-const functions!" << std::endl;

    return 0;
}