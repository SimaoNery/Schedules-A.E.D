#include "Student.h"

Student::Student(string studentCode, string studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;
}

void Student::update_studentSchedule(Uc_class info) {
    this->schedule.push_back(info);
}

string Student::get_studentCode() const {
    return studentCode;
}

string Student::get_studentName() const {
    return studentName;
}

list<Uc_class> Student::get_studentSchedule() const {
    return schedule;
}
