#include <citizen/citizen.h>
#include <gtest/gtest.h>
#include <string.h>

using namespace citizen;
using namespace std;


TEST(citizen_test, payment_schoolboy)
{
	CitizenPtr Schoolboy1 = Citizen::create_schoolboy("asd", "asd", "asd", "asd", 123, true);
	CitizenPtr Schoolboy2 = Citizen::create_schoolboy("asd", "asd", "asd", "asd", 123, false);

	double a1 = Schoolboy1->payment();
	double a2 = Schoolboy2->payment();

	EXPECT_NEAR(a1, 8100.0, EPSILON);
	EXPECT_NEAR(a2, 0.0, EPSILON);
}

TEST(citizen_test, payment_student)
{
	CitizenPtr Student1 = Citizen::create_student("asd", "asd", "asd", "asd", 123, 1.5);
	CitizenPtr Student2 = Citizen::create_student("asd", "asd", "asd", "asd", 123, 3.5);
	CitizenPtr Student3 = Citizen::create_student("asd", "asd", "asd", "asd", 123, 4.3);
	CitizenPtr Student4 = Citizen::create_student("asd", "asd", "asd", "asd", 123, 5.0);
	
	double a1 = Student1->payment();
	double a2 = Student2->payment();
	double a3 = Student3->payment();
	double a4 = Student4->payment();

	EXPECT_NEAR(a1, 0.0, EPSILON);
	EXPECT_NEAR(a2, 8100.0, EPSILON);
	EXPECT_NEAR(a3, 10692.0, EPSILON);
	EXPECT_NEAR(a4, 12960.0, EPSILON);
}

TEST(citizen_test, payment_pensioner)
{
	CitizenPtr Pensioner1 = Citizen::create_pensioner("asd", "asd", "asd", "asd", 0);
	CitizenPtr Pensioner2 = Citizen::create_pensioner("asd", "asd", "asd", "asd", 3);
	CitizenPtr Pensioner3 = Citizen::create_pensioner("asd", "asd", "asd", "asd", 5);
	CitizenPtr Pensioner4 = Citizen::create_pensioner("asd", "asd", "asd", "asd", 23);
	CitizenPtr Pensioner5 = Citizen::create_pensioner("asd", "asd", "asd", "asd", 30);
	CitizenPtr Pensioner6 = Citizen::create_pensioner("asd", "asd", "asd", "asd", 31);
	
	EXPECT_NEAR(Pensioner1->payment(), 0, EPSILON);
	EXPECT_NEAR(Pensioner2->payment(), 0, EPSILON);
	EXPECT_NEAR(Pensioner3->payment(), 16200, EPSILON);
	EXPECT_NEAR(Pensioner4->payment(), 51192, EPSILON);
	EXPECT_NEAR(Pensioner5->payment(), 64800, EPSILON);
	EXPECT_NEAR(Pensioner6->payment(), 81000, EPSILON);
}

TEST(citizen_test, schoolboy_get_test) {
	CitizenPtr Schoolboy = Citizen::create_schoolboy("Samantha", "Sims", "Pace", "Massachusetts", 165237, true);
	EXPECT_EQ(Schoolboy->get_type(), CitizenType::Schoolboy);
	EXPECT_EQ(Schoolboy->get_last_name(), "Samantha");
	EXPECT_EQ(Schoolboy->get_first_name(), "Sims");
	EXPECT_EQ(Schoolboy->get_middle_name(), "Pace");
	EXPECT_EQ(Schoolboy->get_school_name(), "Massachusetts");
	EXPECT_EQ(Schoolboy->get_school_ID_number(), 165237);
	EXPECT_EQ(Schoolboy->get_large_fam(), true);
}

TEST(citizen_test, student_get_test){
	CitizenPtr Student = Citizen::create_student("Samantha", "Sims", "Pace", "Massachusetts", 615234, 3.0);
	EXPECT_EQ(Student->get_type(), CitizenType::Student);
	EXPECT_EQ(Student->get_last_name(), "Samantha");
	EXPECT_EQ(Student->get_first_name(), "Sims");
	EXPECT_EQ(Student->get_middle_name(), "Pace");
	EXPECT_EQ(Student->get_university_name(), "Massachusetts");
	EXPECT_EQ(Student->get_student_ID_number(), 615234);
	EXPECT_NEAR(Student->get_average_grade(), 3.0, EPSILON);

}

TEST(citizen_test, pensioner_get_test) {
	CitizenPtr Pensioner = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	EXPECT_EQ(Pensioner->get_type(), CitizenType::Pensioner);
	EXPECT_EQ(Pensioner->get_last_name(), "Samantha");
	EXPECT_EQ(Pensioner->get_first_name(), "Sims");
	EXPECT_EQ(Pensioner->get_middle_name(), "Pace");
	EXPECT_EQ(Pensioner->get_snils(), "677-351-892-48");
	EXPECT_EQ(Pensioner->get_experience(), 24);

}

TEST(citizen_test, exceptions) {
	EXPECT_THROW(CitizenPtr incorrect_student1 = Citizen::create_student("Samantha", "Sims", "Pace", "Massachusetts", 615234, -3.0), invalid_argument);
	EXPECT_THROW(CitizenPtr incorrect_student2 = Citizen::create_student("Samantha", "Sims", "Pace", "Massachusetts", 615234, 7.0), invalid_argument);

	CitizenPtr Student1 = Citizen::create_student("Samantha", "Sims", "Pace", "Massachusetts", 615234, 3.0);
	EXPECT_THROW(Student1->set_average_grade(-2), invalid_argument);
	EXPECT_THROW(Student1->set_average_grade(7), invalid_argument);

	EXPECT_THROW(CitizenPtr Pensioner = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", -24), invalid_argument);
	CitizenPtr Pensioner1 = Citizen::create_pensioner("Samantha", "Sims", "Pace", "677-351-892-48", 24);
	EXPECT_THROW(Pensioner1->set_experience(-1), invalid_argument);
}