#include <citizen/citizen.h>
#include <string>
#include <stdexcept>

using namespace citizen;
using namespace std;

Citizen::Citizen( CitizenType _type, string last_name, string first_name, string middle_name, string school_name, int shool_ID_number, bool large_fam ) {
	this->_type = _type;
	this->last_name = last_name;
	this->first_name = first_name;
	this->middle_name = middle_name;
	this->school_name = school_name;
	this->shool_ID_number = shool_ID_number;
	this->large_fam = large_fam;
}

Citizen::Citizen( CitizenType _type, string last_name, string first_name, string middle_name, string university_name, int student_ID_number, double average_grade ) {
	this->_type = _type;
	this->last_name = last_name;
	this->first_name = first_name;
	this->middle_name = middle_name;
	this->university_name = university_name;
	this->student_ID_number = student_ID_number;
	this->average_grade = average_grade;
}
Citizen::Citizen( CitizenType _type, string last_name, string first_name, string middle_name, string SNILS, int experience ) {
	this->_type = _type;
	this->last_name = last_name;
	this->first_name = first_name;
	this->middle_name = middle_name;
	this->SNILS = SNILS;
	this->experience = experience;
}

Citizen::Citizen() : _type(CitizenType::Schoolboy), last_name(""), first_name(""), middle_name(""), school_name(""), shool_ID_number(0), large_fam(false) { }

double Citizen::payment() {
	double payment = 0;
	switch (_type) {
	case CitizenType::Schoolboy:
		if (large_fam == true)
			payment = 0.5 * min_wage;
		break;

	case CitizenType::Student:
		if (average_grade >= 3.5 && average_grade <= 5)
			payment = (-0, 2 + 0, 2 * average_grade) * min_wage;
		break;

	case CitizenType::Pensioner:
		if (experience >= 5 && experience <= 30)
			payment = (0, 4 + 0, 12 * experience) * min_wage;
		if (experience > 30)
			payment = 5 * min_wage;
		break;
	default:
		throw runtime_error("[Citizen::payment] Invalid function type.");
		return payment;
	}
}

string Citizen::get_last_name() const {
	return last_name;
}
string Citizen::get_first_name() const {
	return first_name;
}
string Citizen::get_middle_name() const {
	return middle_name;
}
string Citizen::get_school_name() const {
	return school_name;
}
int Citizen::get_school_ID_number() const {
	return shool_ID_number;
}
bool Citizen::get_large_fam() const {
	return large_fam;
}
string Citizen::get_university_name() const {
	return university_name;
}
int Citizen::get_student_ID_number() const {
	return student_ID_number;
}
double Citizen::get_average_grade() const {
	return average_grade;
}
string Citizen::get_SNILS() const {
	return SNILS;
}
int Citizen::get_experience() const {
	return experience;
}

void Citizen::set_large_fam(bool large_fam) {
	this->large_fam = large_fam;
}
void Citizen::set_average_grade(double average_grade) {
	this->average_grade = average_grade;

}
void Citizen::set_experience(int experience) {
	this->experience = experience;

}

//заху€рить исключени€ нада