#include "Student.h"
#include <string>
#include <fstream>
#include <sstream>

Student::Student(string studentCode, string studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;
    this->schedule = //VER ISTO COM A CLASSE READ_FILES;
}

void Student::set_studentCode(string studentCode) {
    this->studentCode = studentCode;
}

void Student::set_studentName(string studentName) {
    this->studentName = studentName;
}

void Student::set_schedule(vector<Uc_class> schedule) {
    //VER ISTO MELHOR//
}

string Student::get_studentCode() const {
    return studentCode;
}

string Student::get_studentName() const {
    return studentName;
}

vector<Uc_class> Student::get_schedule() const {
    return schedule;
}
