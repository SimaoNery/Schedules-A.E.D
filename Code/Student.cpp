#include "Student.h"

Student::Student(string studentCode, string studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;
}

void Student::set_studentSchedule(vector<Uc_class> schedule) {
    this->schedule = schedule;
}

string Student::get_studentCode() const {
    return studentCode;
}

string Student::get_studentName() const {
    return studentName;
}

vector<Uc_class> Student::get_studentSchedule() const {
    return schedule;
}
