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
