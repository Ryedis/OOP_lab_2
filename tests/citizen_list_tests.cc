#include <citizen/citizen.h>
#include <gtest/gtest.h>
#include <string.h>

using namespace citizen;
using namespace std;

TEST(citizen_list_test, size_add) {
	Citizen_list test_list;

	EXPECT_EQ(test_list.size(), 0);

	Citizen Citizen1;
	test_list.add(Citizen1);

	EXPECT_EQ(test_list.size(), 1);
}

TEST(citizen_list_test, insert) {
	Citizen_list test_list;
	Citizen Citizen1, Citizen2, Citizen3;
	test_list.add(Citizen1);
	test_list.add(Citizen2);

	test_list.insert(1, Citizen3);

	EXPECT_EQ(test_list[1], Citizen3);

}

TEST(citizen_list_test, remove) {
	Citizen_list test_list;
	Citizen Citizen1, Citizen2, Citizen3;
	test_list.add(Citizen1);
	test_list.add(Citizen2);
	test_list.add(Citizen3);

	test_list.remove(1);

	EXPECT_EQ(test_list[1], Citizen3);

}

TEST(citizen_list, exceptions) {
	Citizen_list test_list;
	EXPECT_THROW(test_list[6], out_of_range);

	Citizen Citizen1, Citizen2, Citizen3, Citizen4, Citizen5;
	test_list.add(Citizen1);
	test_list.add(Citizen2);
	test_list.add(Citizen3);
	test_list.add(Citizen3);	
	test_list.add(Citizen4);

	EXPECT_THROW(test_list.add(Citizen5), runtime_error);
	EXPECT_THROW(test_list.insert(2, Citizen5), runtime_error);

	test_list.remove(1);
	EXPECT_THROW(test_list.insert(6, Citizen4), out_of_range);
	EXPECT_THROW(test_list.remove(6), out_of_range);

}