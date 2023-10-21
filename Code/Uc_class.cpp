//
// Created by afonso on 17-10-2023.
//

#include "Uc_class.h"


Uc_class::Uc_class(string classCode, vector<Class> schedule) {
    this->schedule = schedule;
    this->classCode = classCode;
}

void Uc_class::set_schedule(vector<Class> schedule) {
    this->schedule = schedule;
}

void Uc_class::set_classCode(string classCode) {
    this->classCode = classCode;
}

vector<Class> Uc_class::get_schedule() const {
    return schedule;
}

string Uc_class::get_classCode() const {
    return classCode;
}
