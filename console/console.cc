#include <citizen/citizen.h>
#include<iostream>
#include <conio.h>

using namespace citizen;
using namespace std;

int GetKey()
{
	int key = _getch();
	if ((key == 0) || (key == 224))
	{
		key = _getch();
	}
	return key;
}
void Arrow(int position_real, int position)
{
	if (position_real == position)
	{
		printf("-->");
	}
	else
	{
		printf("   ");
	}
}
int Menu()
{
	int position = 1;
	int KeyPres = 0;
	while (KeyPres != 13)
	{
		cout<<"\tМеню\t"<< endl;
		Arrow(1, position); cout<< "Вставить элемент в список по указанному индексу"<<endl;
		Arrow(2, position); cout << "Удалить элемент из списка по указаному индексу" << endl;
		Arrow(3, position); cout << "Вывести список на экран"<<endl;
		Arrow(4, position); cout << "Поиск по максимальной выплате" << endl;
		Arrow(5, position); cout << "Добавить элемент в конец списка" << endl;
		Arrow(6, position); cout << "Выход" << endl << endl;
		KeyPres = GetKey();
		system("cls");
		if (KeyPres == 72 && position != 1)
			position--;
		else if (KeyPres == 80 && position != 6)
		{
			position++;
		}


	}
	return position;
}

int main() {
	setlocale(LC_ALL, "Russian");
	CitizenList List;
	CitizenPtr citizen1;
	while (true)
	{
		int choice1 = Menu();
		switch (choice1)
		{
		case 1:
		{
			cout << "Вы попали в подменю вставки элемента в список по указаному индексу" << endl;
			int index = 0;
			cout << "Введите индекс для вставки элемента" << endl;
			cin >> index;
			cout << "Выберите какого жителя вы хотите добавить: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
			int choice2 = 0;
			cin >> choice2;
			if (choice2 != 1 && choice2 != 2 && choice2 != 3)
			{
				cout << "Вы ввели некоректные данные!";
				break;
			}
			std::string first_name;
			std::string last_name;
			std::string middle_name;

			switch (choice2)
			{

				case 1: //школьник
				{
					std::string school_name;
					int shool_ID_number;
					bool large_fam;

					cout << "Введите фамилию: " << endl;
					cin >> last_name;
					cout << "Введите имя: " << endl;
					cin >> first_name;
					cout << "Введите отчество: " << endl;
					cin >> middle_name;
					cout << "Введите название школы: " << endl;
					cin >> school_name;
					cout << "Введите номер ученического билет: ";
					cin >> shool_ID_number;
					cout << "Введите флаг принадлежности к многодетной семье (1/0): ";
					cin >> large_fam;

					citizen1 = Citizen::create_schoolboy(last_name, first_name, middle_name, school_name, shool_ID_number, large_fam);
					break;
				}
				case 2:
				{
					std::string university_name;
					int student_ID_number;
					double average_grade;

					cout << "Введите фамилию: " << endl;
					cin >> last_name;
					cout << "Введите имя: " << endl;
					cin >> first_name;
					cout << "Введите отчество: " << endl;
					cin >> middle_name;
					cout << "Введите название университета: " << endl;
					cin >> university_name;
					cout << "Введите номер зачётной книжки: " << endl;
					cin >> student_ID_number;
					cout << "Введите средний балл " << endl;
					cin >> average_grade;

					citizen1 = Citizen::create_student(last_name, first_name, middle_name, university_name, student_ID_number, average_grade);
					break;

				}
				case 3:
				{

					std::string snils;
					int experience;

					cout << "Введите фамилию: " << endl;
					cin >> last_name;
					cout << "Введите имя: " << endl;
					cin >> first_name;
					cout << "Введите отчество: " << endl;
					cin >> middle_name;
					cout << "Введите снилс: " << endl;
					cin >> snils;
					cout << "Введите стаж: " << endl;
					cin >> experience;
					citizen1 = Citizen::create_pensioner(last_name, first_name, middle_name, snils, experience);
					break;

				}
			}	
				List.insert(citizen1, index);
			break;
		}
		case 2: {

			cout << "Вы попали в подменю удаление объекта" << endl;
			if (List.size() == 0)
			{
				cout << "В вашем списке нет работников!" << endl << "Добавьте работников и попробуйте снова!" << endl << endl;
				break;
			}
			cout << "Введите индекс объекта, который хотите удалить" << endl;
			int index = -1;
			cin >> index;
			List.remove(index);
			break;
		}
		case 3: {
			int size = List.size();
			if (size == 0)
			{
				cout << "В вашем списке нет работников!" << endl << "Добавьте работников и попробуйте снова!" << endl << endl;
				break;
			}
			for (int i = 0; i < size; i++)
			{
				cout << List[i];
			}
			break;
		}
		case 4: {
			if (List.size() == 0)
			{
				cout << "В вашем списке нет работников!" << endl << "Добавьте работников и попробуйте снова!" << endl << endl;
				break;
			}
			int index = search_max_payment(List);
			cout << "Работник с максимальной заработной платой: " << endl;
			cout << List[index];
			break;
		}
		case 5:
		{
				cout << "Выберите какого работника вы хотите добавить: Schoolboy - 1, Student - 2, Pensioner - 3" << endl;
				int choice2 = 0;
				cin >> choice2;
				if (choice2 != 1 && choice2 != 2 && choice2 != 3)
				{
					cout << "Вы ввели некоректные данные!";
					break;
				}
				std::string first_name;
				std::string last_name;
				std::string middle_name;

				switch (choice2)
				{

				case 1:
				{
					std::string school_name;
					int shool_ID_number;
					bool large_fam;

					cout << "Введите фамилию: " << endl;
					cin >> last_name;
					cout << "Введите имя: " << endl;
					cin >> first_name;
					cout << "Введите отчество: " << endl;
					cin >> middle_name;
					cout << "Введите название школы: " << endl;
					cin >> school_name;
					cout << "Введите номер ученического билет: " << endl;
					cin >> shool_ID_number;
					cout << "Введите флаг принадлежности к многодетной семье (1/0): " << endl;
					cin >> large_fam;

					citizen1 = Citizen::create_schoolboy(last_name, first_name, middle_name, school_name, shool_ID_number, large_fam);
					break;
				}
				case 2:
				{
					std::string university_name;
					int student_ID_number;
					double average_grade;

					cout << "Введите фамилию: " << endl;
					cin >> last_name;
					cout << "Введите имя: " << endl;
					cin >> first_name;
					cout << "Введите отчество: " << endl;
					cin >> middle_name;
					cout << "Введите название университета: " << endl;
					cin >> university_name;
					cout << "Введите номер зачётной книжки: " << endl;
					cin >> student_ID_number;
					cout << "Введите средний балл " << endl;
					cin >> average_grade;

					citizen1 = Citizen::create_student(last_name, first_name, middle_name, university_name, student_ID_number, average_grade);
					break;

				}
				case 3:
				{

					std::string snils;
					int experience;

					cout << "Введите фамилию: " << endl;
					cin >> last_name;
					cout << "Введите имя: " << endl;
					cin >> first_name;
					cout << "Введите отчество: " << endl;
					cin >> middle_name;
					cout << "Введите снилс: " << endl;
					cin >> snils;
					cout << "Введите стаж: " << endl;
					cin >> experience;
					citizen1 = Citizen::create_pensioner(last_name, first_name, middle_name, snils, experience);
					break;
				}
				}
				List.add(citizen1);
				break;
		}
			case 6: 
			{
				cout << "Работа программы завершена!" << endl;
				return 0;
			}
				
		}
	}
	return 0;
}