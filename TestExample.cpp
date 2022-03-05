/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
// string nospaces(string input) {
// 	std::erase(input, ' ');
// 	std::erase(input, '\t');
// 	std::erase(input, '\n');
// 	std::erase(input, '\r');
// 	return input;
// }
string nospaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}
 


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	
	/* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));// only odd number 
	CHECK_THROWS(mat(7,5,'@','@'));  // cannot use the same sign 


}


/* Add more test cases here */
