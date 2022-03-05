/* 

AUTHOR: Yakov Khodorkovski

*/

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;


string nospaces(string str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    return str;
}



TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
   	CHECK(nospaces(mat(5, 5, '@', '-')) == nospaces("@@@@@\n@---@\n@-@-@\n@---@\n@@@@@"));
	CHECK(nospaces(mat(7, 7, '+', '-')) == nospaces("+++++++\n+-----+\n+-+++-+\n+-+-+-+\n+-+++-+\n+-----+\n+++++++")); 
	CHECK(nospaces(mat(9, 9, '&', '*')) == nospaces("&&&&&&&&&\n&*******&\n&*&&&&&*&\n&*&***&*&\n&*&*&*&*&\n&*&***&*&\n&*&&&&&*&\n&*******&\n&&&&&&&&&"));
	CHECK(nospaces(mat(99, 1, '$', '-')) == nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"));
	CHECK(nospaces(mat(1,1,'$','-')) == nospaces("$"));


	/* Add more test here */
}

TEST_CASE("Bad input") {
    CHECK_THROWS(mat(10, 5, '$', '%'));// only odd number 
	CHECK_THROWS(mat(7,5,'@','@'));  // cannot use the same sign 
    CHECK_THROWS(mat(7,5,'@',10)); // valid char
	CHECK_THROWS(mat(7,5,15 ,10)); // valid char
	CHECK_THROWS(mat(7,5,15 ,'^')); // valid char 
	
    

}