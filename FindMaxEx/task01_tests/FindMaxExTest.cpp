#include "stdafx.h"
#include "../task01/FindMaxEx.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(FindMaxEx)

BOOST_AUTO_TEST_CASE(can_not_find_the_max_value_when_vector_is_empty)
{
	string maxValue;
	BOOST_CHECK(!FindMax(vector<string>(), maxValue, [](string const & first, string const &  second) {
		return first.length() < second.length(); }));
}
BOOST_AUTO_TEST_CASE(can_find_the_max_value_when_vector_numbers_is_initialized)
{
	int maxValue = 0;
	vector<int> arr = { 5, 48, 230, 97, 23, 97, 2 };
	BOOST_CHECK(FindMax(arr, maxValue, [](int first, int second) {return first < second; }));
	BOOST_CHECK_EQUAL(maxValue, 230);
}
BOOST_AUTO_TEST_CASE(can_find_the_max_value_when_vector_contain_negative_numbers)
{
	int maxValue = 0;
	vector<int> arr = { 1, -2, 3, -10 };
	BOOST_CHECK(FindMax(arr, maxValue, [](int first, int second) {return first < second; }));
	BOOST_CHECK_EQUAL(maxValue, 3);
}
BOOST_AUTO_TEST_CASE(can_find_the_max_length_of_a_string_in_a_vector_of_strings)
{
	string maxLenghtStr;
	vector<string> arr = { "parallelepiped", "min", "max", "some" };
	BOOST_CHECK(FindMax(arr, maxLenghtStr, [](string const & first, string const &  second) {
		return first.length() < second.length(); }));
	BOOST_CHECK_EQUAL(maxLenghtStr, "parallelepiped");
}
BOOST_AUTO_TEST_CASE(can_replace_the_existing_max_value)
{
	float maxFloat = 555.f;
	vector<float> arr = { 54.3f, 548.f, -78.f, 98.f };
	BOOST_CHECK(FindMax(arr, maxFloat));
	BOOST_CHECK_EQUAL(maxFloat, 548.f);
}
BOOST_AUTO_TEST_SUITE_END()