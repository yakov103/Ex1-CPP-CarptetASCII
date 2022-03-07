/*

AUTHOR: Yakov Khodorkovski

*/

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

// string nospaces(string str)
// {
// 	str.erase(remove(str.begin(), str.end(), ' '), str.end());
// 	str.erase(remove(str.begin(), str.end(), '\n'), str.end());
// 	return str;
// }
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input")
{
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n@-------@\n@-@@@@@-@\n@-@---@-@\n@-@@@@@-@\n@-------@\n@@@@@@@@@"));
	CHECK(nospaces(mat(5, 5, '@', '-')) == nospaces("@@@@@\n@---@\n@-@-@\n@---@\n@@@@@"));
	CHECK(nospaces(mat(7, 7, '+', '-')) == nospaces("+++++++\n+-----+\n+-+++-+\n+-+-+-+\n+-+++-+\n+-----+\n+++++++"));
	CHECK(nospaces(mat(9, 9, '&', '*')) == nospaces("&&&&&&&&&\n&*******&\n&*&&&&&*&\n&*&***&*&\n&*&*&*&*&\n&*&***&*&\n&*&&&&&*&\n&*******&\n&&&&&&&&&"));
	CHECK(nospaces(mat(99, 1, '$', '-')) == nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"));
	CHECK(nospaces(mat(1, 1, '$', '-')) == nospaces("$"));
	CHECK(nospaces(mat(33,51,'@','-'))== nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-------------------------------@@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@@-@---------------------------@-@@-@-@@@@@@@@@@@@@@@@@@@@@@@@@-@-@@-@-@-----------------------@-@-@@-@-@-@@@@@@@@@@@@@@@@@@@@@-@-@-@@-@-@-@-------------------@-@-@-@@-@-@-@-@@@@@@@@@@@@@@@@@-@-@-@-@@-@-@-@-@---------------@-@-@-@-@@-@-@-@-@-@@@@@@@@@@@@@-@-@-@-@-@@-@-@-@-@-@-----------@-@-@-@-@-@@-@-@-@-@-@-@@@@@@@@@-@-@-@-@-@-@@-@-@-@-@-@-@-------@-@-@-@-@-@-@@-@-@-@-@-@-@-@@@@@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@---@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@---@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@@@@@-@-@-@-@-@-@-@@-@-@-@-@-@-@-------@-@-@-@-@-@-@@-@-@-@-@-@-@@@@@@@@@-@-@-@-@-@-@@-@-@-@-@-@-----------@-@-@-@-@-@@-@-@-@-@-@@@@@@@@@@@@@-@-@-@-@-@@-@-@-@-@---------------@-@-@-@-@@-@-@-@-@@@@@@@@@@@@@@@@@-@-@-@-@@-@-@-@-------------------@-@-@-@@-@-@-@@@@@@@@@@@@@@@@@@@@@-@-@-@@-@-@-----------------------@-@-@@-@-@@@@@@@@@@@@@@@@@@@@@@@@@-@-@@-@---------------------------@-@@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@@-------------------------------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@") );
	CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@\n@\n@"));
	CHECK(nospaces(mat(99,99,'@','-'))== nospaces("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-------------------------------------------------------------------------------------------------@@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@@-@---------------------------------------------------------------------------------------------@-@@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@@-@-@-----------------------------------------------------------------------------------------@-@-@@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@@-@-@-@-------------------------------------------------------------------------------------@-@-@-@@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@@-@-@-@-@---------------------------------------------------------------------------------@-@-@-@-@@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@@-@-@-@-@-@-----------------------------------------------------------------------------@-@-@-@-@-@@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@@-@-@-@-@-@-@-------------------------------------------------------------------------@-@-@-@-@-@-@@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@---------------------------------------------------------------------@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-----------------------------------------------------------------@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-------------------------------------------------------------@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@---------------------------------------------------------@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-----------------------------------------------------@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-------------------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@---------------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@---------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@---------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@---------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@---------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@---------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@---------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@-----------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@---------------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@-------------------------------------------------@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@-----------------------------------------------------@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@---------------------------------------------------------@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@-------------------------------------------------------------@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@-----------------------------------------------------------------@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@---------------------------------------------------------------------@-@-@-@-@-@-@-@@-@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@-@@-@-@-@-@-@-@-------------------------------------------------------------------------@-@-@-@-@-@-@@-@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@-@@-@-@-@-@-@-----------------------------------------------------------------------------@-@-@-@-@-@@-@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@-@@-@-@-@-@---------------------------------------------------------------------------------@-@-@-@-@@-@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@-@@-@-@-@-------------------------------------------------------------------------------------@-@-@-@@-@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@-@@-@-@-----------------------------------------------------------------------------------------@-@-@@-@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@-@@-@---------------------------------------------------------------------------------------------@-@@-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@-@@-------------------------------------------------------------------------------------------------@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@")); 
	CHECK(nospaces(mat(3,5, '^', '.')) == nospaces("^^^^.^^.^^.^^^^"));
	CHECK(nospaces(mat(15,15,'$','$')) == nospaces("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"));

}

TEST_CASE("Bad input")
{
	CHECK_THROWS(mat(10, 5, '$', '%'));	 // only odd number
	CHECK_THROWS(mat(3, 2, '$', '%'));	 // only odd number
	CHECK_THROWS(mat(6, 6, '$', '%'));	 // only odd number
	CHECK_THROWS(mat(0, 0, '$', '%'));	 // empty table
	CHECK_THROWS(mat(-3, 5, '%', '^'));	 // cannot do with negative numbers
	CHECK_THROWS(mat(3, -5, '$', '-'));	 // cannot do with negative numbers
	CHECK_THROWS(mat(-5, -5, '$', '-')); // cannot do with negative numbers
	CHECK_THROWS(mat(-1, -1, '$', '-')); // cannot do with negative numbers
}