#include <citizen/citizen.h>
#include <gtest/gtest.h>
#include <string.h>

using namespace citizen;
using namespace std;


TEST(citizen_test, payment_Schoolboy)
{
	Citizen Schoolboy1();
	Schoolboy1.set_large_fam(true);
	Schoolboy1.set_min_wage(16000);


	Citizen Schoolboy2;
	Schoolboy2.set_large_fam(false);
	Schoolboy2.set_min_wage(200);


	EXPECT_NEAR(Schoolboy1.payment(), 8000.0, EPSILON);
	EXPECT_NEAR(Schoolboy2.payment(), 0.0, EPSILON);
}

TEST(citizen_test, payment_Student)
{
	Citizen Student1;
	Student1.set_citizen_type(CitizenType::Student);
	Student1.set_average_grade(1.5);
	Student1.set_min_wage(16200);

	Citizen Student2;
	Student2.set_citizen_type(CitizenType::Student);
	Student2.set_average_grade(3.5);
	Student2.set_min_wage(16200);


	Citizen Student3;
	Student3.set_citizen_type(CitizenType::Student);
	Student3.set_average_grade(4.3);
	Student3.set_min_wage(16200);


	Citizen Student4;
	Student4.set_citizen_type(CitizenType::Student);
	Student4.set_average_grade(5.0);
	Student4.set_min_wage(16200);


	EXPECT_NEAR(Student1.payment(), 0.0, EPSILON);
	EXPECT_NEAR(Student2.payment(), 8100.0, EPSILON);
	EXPECT_NEAR(Student3.payment(), 10692.0, EPSILON);
	EXPECT_NEAR(Student4.payment(), 12960.0, EPSILON);
}

TEST(citizen_test, payment_Pensioner)
{
	Citizen Pensioner1;
	Pensioner1.set_citizen_type(CitizenType::Pensioner);
	Pensioner1.set_experience(0);
	Pensioner1.set_min_wage(16200);


	Citizen Pensioner2;
	Pensioner2.set_citizen_type(CitizenType::Pensioner);
	Pensioner2.set_experience(3);
	Pensioner2.set_min_wage(16200);


	Citizen Pensioner3;
	Pensioner3.set_citizen_type(CitizenType::Pensioner);
	Pensioner3.set_experience(5);
	Pensioner3.set_min_wage(16200);


	Citizen Pensioner4;
	Pensioner4.set_citizen_type(CitizenType::Pensioner);
	Pensioner4.set_experience(23);
	Pensioner4.set_min_wage(16200);


	Citizen Pensioner5;
	Pensioner5.set_citizen_type(CitizenType::Pensioner);
	Pensioner5.set_experience(30);
	Pensioner5.set_min_wage(16200);


	Citizen Pensioner6;
	Pensioner6.set_citizen_type(CitizenType::Pensioner);
	Pensioner6.set_experience(31);
	Pensioner6.set_min_wage(16200);



	EXPECT_NEAR(Pensioner1.payment(), 0, EPSILON);
	EXPECT_NEAR(Pensioner2.payment(), 0, EPSILON);
	EXPECT_NEAR(Pensioner3.payment(), 16200, EPSILON);
	EXPECT_NEAR(Pensioner4.payment(), 51192, EPSILON);
	EXPECT_NEAR(Pensioner5.payment(), 64800, EPSILON);
	EXPECT_NEAR(Pensioner6.payment(), 81000, EPSILON);
}

TEST(citizen_test, schoolboy_get_test) {
	Citizen student(CitizenType::Schoolboy, "Samantha", "Sims", "Pace", "Massachusetts", 165237, true);
	EXPECT_EQ(student.get_type(), CitizenType::Schoolboy);
	EXPECT_EQ(student.get_last_name(), "Samantha");
	EXPECT_EQ(student.get_first_name(), "Sims");
	EXPECT_EQ(student.get_middle_name(), "Pace");
	EXPECT_EQ(student.get_school_name(), "Massachusetts");
	EXPECT_EQ(student.get_school_ID_number(), 165237);
	EXPECT_EQ(student.get_large_fam(), true);
}

TEST(citizen_test, student_get_test){
	Citizen student(CitizenType::Student, "Samantha", "Sims", "Pace", "Massachusetts", 615234, 3.0);
	EXPECT_EQ(student.get_type(), CitizenType::Student);
	EXPECT_EQ(student.get_last_name(), "Samantha");
	EXPECT_EQ(student.get_first_name(), "Sims");
	EXPECT_EQ(student.get_middle_name(), "Pace");
	EXPECT_EQ(student.get_university_name(), "Massachusetts");
	EXPECT_EQ(student.get_student_ID_number(), 615234);
	EXPECT_NEAR(student.get_average_grade(), 3.0, EPSILON);

}

TEST(citizen_test, pensioner_get_test) {
	Citizen student(CitizenType::Pensioner, "Samantha", "Sims", "Pace", "677-351-892-48", 24);
	EXPECT_EQ(student.get_type(), CitizenType::Pensioner);
	EXPECT_EQ(student.get_last_name(), "Samantha");
	EXPECT_EQ(student.get_first_name(), "Sims");
	EXPECT_EQ(student.get_middle_name(), "Pace");
	EXPECT_EQ(student.get_snils(), "677-351-892-48");
	EXPECT_EQ(student.get_experience(), 24);

}

TEST(citizen_test, exceptions) {
	EXPECT_THROW(Citizen incorrect_student1(CitizenType::Student, "Samantha", "Sims", "Pace", "Massachusetts", 615234, -3.0), invalid_argument);
	EXPECT_THROW(Citizen incorrect_student2(CitizenType::Student, "Kiera", "Sanchez", "Cain", "SamaraUniversity", 134324, 7.0), invalid_argument);

	Citizen Student1;
	EXPECT_THROW(Student1.set_average_grade(-2), invalid_argument);
	EXPECT_THROW(Student1.set_average_grade(7), invalid_argument);

	EXPECT_THROW(Citizen incorrect_pensioner(CitizenType::Pensioner, "Riley", "Knight", "Ray", "677-351-892-48", -23), invalid_argument);
	Citizen Pensioner1;
	EXPECT_THROW(Pensioner1.set_experience(-1), invalid_argument);
}