#include "Uc_class.h"
Uc_class::Uc_class(string ucCode, string classCode, list<Class> schedule) {
    this->ucCode = ucCode;
    this->classCode = classCode;
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

void Uc_class::set_classCode(string classCode){
    this->classCode = classCode;
}

void Uc_class::set_ucCode(string ucCode){
    this->ucCode = ucCode;
}

void Uc_class::set_schedule(list<Class>schedule) {
        this->schedule = schedule;
}
