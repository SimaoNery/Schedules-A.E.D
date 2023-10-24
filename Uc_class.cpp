#include "Uc_class.h"
Uc_class::Uc_class(string ucCode, string classCode) {
    this->ucCode = ucCode;
    this->classCode = classCode;
}

void Uc_class::set_schedule(list<Class> schedule) {
    this->schedule = schedule;
}

string Uc_class::get_ucCode() const {
    return ucCode;
}

string Uc_class::get_classCode() const {
    return classCode;
}

list<Class> Uc_class::get_schedule() const {
    return schedule;
}