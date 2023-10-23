#include "Uc_class.h"


Uc_class::Uc_class(string classCode, list<Class> schedule) {
    this->schedule = schedule;
    this->classCode = classCode;
}

void Uc_class::set_schedule(list<Class> schedule) {
    this->schedule = schedule;
}

void Uc_class::set_classCode(string classCode) {
    this->classCode = classCode;
}

list<Class> Uc_class::get_schedule() const {
    return schedule;
}

string Uc_class::get_classCode() const {
    return classCode;
}
