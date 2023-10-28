#include "Class.h"

Class::Class(string weekday, string type, double startHour, double duration) {
    this->weekday = weekday;
    this->type = type;
    this->startHour = startHour;
    this->duration = duration;
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

