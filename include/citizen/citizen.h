#pragma once
#include<iostream>
#include<string>

namespace citizen {
	
	const int min_wage = 16200;
	const float EPSILON = 0.00001f;
	
	enum class CitizenType{
		Schoolboy,
		Student,
		Pensioner
	};

	class Citizen;

	using CitizenPtr = Citizen*;

	std::ostream& operator<<(std::ostream& stream, const CitizenPtr& people);

	class Citizen {
		CitizenType _type;

		std::string last_name;
		std::string first_name;
		std::string middle_name;

		std::string school_name;
		int shool_ID_number;
		bool large_fam;

		std::string university_name;
		int student_ID_number;
		double average_grade;

		std::string snils;
		int experience;

		Citizen(CitizenType _type, std::string last_name, std::string first_name, std::string middle_name, std::string school_name, int shool_ID_number, bool large_fam); //Schoolboy
		Citizen(CitizenType _type, std::string last_name, std::string first_name, std::string middle_name, std::string university_name, int student_ID_number, double average_grade); //Student
		Citizen(CitizenType _type, std::string last_name, std::string first_name, std::string middle_name, std::string snils, int experience); //Pensioner
		
	public:
		Citizen();
		static CitizenPtr create_schoolboy(std::string last_name, std::string first_name, std::string middle_name, std::string school_name, int shool_ID_number, bool large_fam);
		static CitizenPtr create_student(std::string last_name, std::string first_name, std::string middle_name, std::string university_name, int student_ID_number, double average_grade);
		static CitizenPtr create_pensioner(std::string last_name, std::string first_name, std::string middle_name, std::string snils, int experience);
		double payment();
		CitizenType get_type() const;
		std::string get_last_name() const;
		std::string get_first_name() const;
		std::string get_middle_name() const;
		std::string get_school_name() const;
		int get_school_ID_number() const;
		bool get_large_fam() const;
		std::string get_university_name() const;
		int get_student_ID_number() const;
		double get_average_grade() const;
		std::string get_snils() const;
		int get_experience() const;

		void set_citizen_type(CitizenType _type);
		void set_large_fam(bool large_fam);
		void set_average_grade(double average_grade);
		void set_experience(int experience);

		CitizenPtr clone() const;
	};

	bool operator==(const Citizen& lhs, const Citizen& rhs);

	class CitizenList {

		CitizenPtr* _citizen;
        int _size;

    public:
        CitizenList();
		CitizenList(const CitizenList& other);
		int size() const;
		CitizenList& operator=(const CitizenList& rhs);
		CitizenPtr operator[](int index) const;
		void add(CitizenPtr citizen);
		void swap(CitizenList& other);
		void insert(CitizenPtr citizen, int index);
		void remove(int index);
		void installation(CitizenPtr citizen, int index);
		~CitizenList();

    };
	int search_max_payment(const CitizenList& _citizen);
}
