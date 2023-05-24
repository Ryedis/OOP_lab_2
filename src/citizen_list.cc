#include <citizen/citizen.h>
#include <stdexcept>
using namespace citizen;
using namespace std;

CitizenList::CitizenList() : _citizen(nullptr), _size(0) { }

int CitizenList::size() const {
    return _size; 
}

CitizenList::CitizenList(const CitizenList& other) : _citizen(new CitizenPtr[other._size]), _size(other._size)
{    
    for (int i = 0; i < _size; ++i) {
        _citizen[i] = other[i]->clone();
    }
}

CitizenPtr CitizenList::operator[](const int index) const {
    if (index < 0 || _size <= index) {
        throw out_of_range("[CitizenList::operator[]] Index is out of range.");
    }
    return _citizen[index];
}

CitizenList& CitizenList::operator=(const CitizenList& rhs) {
    CitizenList copy(rhs);
    copy.swap(*this);
    return *this;
}

std::ostream& citizen::operator<<(std::ostream& stream, const CitizenPtr& people)
{
    switch (people->get_type())
    {
    case::CitizenType::Schoolboy:
        stream << endl << "\tШкольник: \t" << endl << people->get_last_name() << " " << people->get_first_name() << " " << people->get_middle_name() << endl << "Название школы: " << people->get_school_name() << endl
            << "номер ученического билета: " << people->get_school_ID_number() << endl << "Принадлежность к многодетной семье: " << people->get_large_fam() << endl << "Размер выплаты: " << people->payment() << endl << endl;
        return stream;
    case::CitizenType::Student:
        stream << endl << "\tСтудент: \t" << endl << people->get_last_name() << " " << people->get_first_name() << " " << people->get_middle_name() << endl << "Название университета: " << people->get_university_name() << endl
            << "номер зачётной книжки: " << people->get_student_ID_number() << endl << "средний балл: " << people->get_average_grade() << endl << "Размер выплаты: " << people->payment() << endl << endl;
        return stream;
    case::CitizenType::Pensioner:
        stream << endl << "\tПенсионер: \t" << endl << people->get_last_name() << " " << people->get_first_name() << " " << people->get_middle_name() << endl << "СНИЛС: " << people->get_snils() << endl << "стаж: " << people->get_experience() << endl << "Размер выплаты: " << people->payment() << endl << endl;
        return stream;
    default:
        throw runtime_error("[Function::compute_derivative] Invalid function type.");
    }
}

void CitizenList::swap(CitizenList& other) {
    std::swap(this->_citizen, other._citizen);
    std::swap(this->_size, other._size);
}

void CitizenList::add(CitizenPtr const citizen) {
    auto new_citizen = new CitizenPtr[_size + 1];

    for (int i = 0; i < _size; ++i) {
        new_citizen[i] = _citizen[i];
    }
    new_citizen[_size] = citizen;

    delete[] _citizen;
    _citizen = new_citizen;
    ++_size;
}

void CitizenList::insert(CitizenPtr citizen, int index) {
    if (index < 0 || _size <= index) {
        throw out_of_range("[CitizenList::operator[]] Index is out of range.");
    }
    auto copy = new CitizenPtr[_size + 1];
    for (int i = 0; i < _size; i++)
    {
        if (i < index)
        {
            copy[i] = _citizen[i];
        }
        else
            copy[i + 1] = _citizen[i];
    }
    copy[index] = citizen;
    delete[] _citizen;
    _citizen = copy;
    _size++;
}

void CitizenList::installation(CitizenPtr citizen, int index) {
    if (index < 0 || _size <= index) {
        throw out_of_range("[CitizenList::operator[]] Index is out of range.");
    }
    auto copy = new CitizenPtr[_size];
    for (int i = 0; i < _size; i++)
    {
        copy[i] = _citizen[i];
    }
    copy[index] = citizen;
    delete[] _citizen;
    _citizen = copy;
}

void CitizenList::remove(int index) {
    if (index < 0 || _size <= index) {
        throw out_of_range("[CitizenList::remove()] Index is out of range.");
    }
    auto copy = new CitizenPtr[_size - 1];

    for (int i = 0; i != _size - 1; i++)
    {
        if (i < index)
        {
            copy[i] = _citizen[i];
        }
        else
            copy[i] = _citizen[i + 1];
    }
    delete[] _citizen;
    _citizen = copy;
    _size--;
}

CitizenList::~CitizenList() {
    for (int i = 0; i < _size; ++i) {
        delete _citizen[i];
    }
    delete[] _citizen;
}

int citizen::search_max_payment(const CitizenList& citizen)
{
    int max_index = -1;
    double max_payment = -1;

    auto n = citizen.size();

    for (int i = 0; i < n; i++)
    {
        auto value = citizen[i]->payment();
        if (value >= max_payment || max_index == -1)
        {
            max_index = i;
            max_payment = value;
        }
    }
    return max_index;
}