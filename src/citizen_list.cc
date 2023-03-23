#include <citizen/citizen.h>
#include <stdexcept>
using namespace citizen;
using namespace std;

Citizen_list::Citizen_list() : _size(0) { }

int Citizen_list::size() const {
    return _size; 
}

Citizen Citizen_list::operator[](const int index) const {
    if (index < 0 || _size <= index) {
        throw out_of_range("[Citizen_list::operator[]] Index is out of range.");
    }
    return _citizen[index];
}

void Citizen_list::add(const Citizen citizen) {
    if (_size == CAPACITY) {
        throw runtime_error("[Citizen_list::add] Capacity is reached.");
    }
    _citizen[_size] = citizen;
    _size++;
}

void Citizen_list::insert(int index, const Citizen citizen) {
    if (_size == CAPACITY) {
        throw runtime_error("[Citizen_list::add] Capacity is reached.");
    }
    for (int i = _size-1; i >= index; i--)
        _citizen[i+1] = _citizen[i];

    _citizen[index] = citizen;
    _size++;
}

void Citizen_list::remove(int index) {
    for(int i = index; i < _size; i++)
        _citizen[i] = _citizen[i + 1];
    _size--;
}