#include <citizen/citizen.h>
#include <gtest/gtest.h>
#include <string.h>

using namespace citizen;
using namespace std;

TEST(CitizenListTest, size_add) {
	CitizenList test_list;

	EXPECT_EQ(test_list.size(), 0);

	CitizenPtr Citizen = Citizen::create_pensioner("asd", "asd", "asd", "asd", 0);
	test_list.add(Citizen);

	EXPECT_EQ(test_list.size(), 1);
}

TEST(CitizenListTest, insert) {
	CitizenList test_list;
	CitizenPtr Citizen1 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	CitizenPtr Citizen2 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	CitizenPtr Citizen3 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	test_list.add(Citizen1);
	test_list.add(Citizen2);

	test_list.insert(Citizen3, 1);

	EXPECT_EQ(test_list[1], Citizen3);

}

TEST(CitizenListTest, installation) {
	CitizenList test_list;
	
	CitizenPtr Citizen1 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677", 24);
	CitizenPtr Citizen2 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677", 24);
	CitizenPtr Citizen3 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677", 24);
	test_list.add(Citizen1);
	test_list.add(Citizen2);

	test_list.installation(Citizen3, 1);

	EXPECT_EQ(test_list[1], Citizen3);

}

TEST(CitizenListTest, remove) {
	CitizenList test_list;
	CitizenPtr Citizen1 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	CitizenPtr Citizen2 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	test_list.add(Citizen1);
	test_list.add(Citizen2);

	test_list.remove(0);

	EXPECT_EQ(test_list[0], Citizen2);

}

TEST(CitizenListTests, size)
{
	CitizenList test_list;
	Citizen person;
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	
	ASSERT_EQ(test_list.size(), 6);
}

TEST(CitizenList, exceptions) {
	CitizenList test_list;
	Citizen person;
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	test_list.add(person.create_pensioner("Samantha", "Sims", "Pace", "67", 2));
	EXPECT_THROW(test_list[6], out_of_range);
}