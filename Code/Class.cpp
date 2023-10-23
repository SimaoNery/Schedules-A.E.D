#include "Class.h"

Class::Class(string classCode, string ucCode) {
    this->classCode = classCode;
    this->ucCode = ucCode;
}

void Class::set_ucCode(string classCode) {
    this->classCode = classCode;
}

void Class::set_weekday(string weekday) {
    this->weekday = weekday;
}

void Class::set_startHour(double startHour) {
    this->startHour = startHour;
}

void Class::set_duration(double duration) {
    this->duration = duration;
}

void Class::set_type(string type) {
    this->type = type;
}

string Class::get_classCode() const {
    return classCode;
}

string Class::get_ucCode() const {
    return ucCode;
}

string Class::get_weekday() const {
    return weekday;
}

double Class::get_startHour() const {
    return startHour;
}

double Class::get_duration() const {
    return duration;
}

string Class::get_type() const {
    return type;
}