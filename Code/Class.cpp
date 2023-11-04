#include "Class.h"

Class::Class(string weekday, string type, double startHour, double duration) {
    this->weekday = weekday;
    this->type = type;
    this->startHour = startHour;
    this->duration = duration;
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

bool Class::conflict(const Class& c2) const {
    if (this->weekday != c2.get_weekday()) {
        return false;
    }
    else{
        if(this->startHour + this->duration < c2.get_startHour() || this->startHour == c2.get_startHour()){
            return false;
        }
        return true;
    }
}

