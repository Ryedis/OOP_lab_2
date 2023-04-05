#pragma once
#include<string>

namespace citizen {
	
	const int min_wage = 16200;
	const float EPSILON = 0.00001f;
	
	enum class CitizenType{
		Schoolboy,
		Student,
		Pensioner
	};

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

	public:
		Citizen();
		Citizen(CitizenType _type, std::string last_name, std::string first_name, std::string middle_name, std::string school_name, int shool_ID_number, bool large_fam); //Schoolboy
		Citizen(CitizenType _type, std::string last_name, std::string first_name, std::string middle_name, std::string university_name, int student_ID_number, double average_grade); //Student
		Citizen(CitizenType _type, std::string last_name, std::string first_name, std::string middle_name, std::string snils, int experience); //Pensioner
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

	};

	bool operator==(const Citizen& lhs, const Citizen& rhs);

	class Citizen_list {
    public:
        static const int CAPACITY = 11;

    private:
        Citizen _citizen[CAPACITY];
        int _size;

    public:
        Citizen_list();
		int size() const;
        Citizen operator[](int index) const;
		void add(const Citizen citizen);
		void insert(int index, Citizen citizen);
		void remove(int index);
    };
}
