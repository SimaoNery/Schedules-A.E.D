//
// Created by afonso on 17-10-2023.
//

#include "Student.h"

Student::Student() {
    this->studentCode = "";
    this->studentName = "";
}

Student::Student(string studentCode, string studentName) {
    this->studentCode = studentCode;
    this->studentName = studentName;
}

void Student::set_studentCode(string studentCode) {
    this->studentCode = studentCode;
}

void Student::set_studentName(string studentName) {
    this->studentName = studentName;
}

void Student::set_studentClass(string ucCode, string classCode) {
    Class c = Class(ucCode, classCode);
    schedule.push_back(c);
}

string Student::get_studentCode() const {
    return studentCode;
}

string Student::get_studentName() const {
    return studentName;
}

vector<Class> Student::get_studentSchedule() const {
    return schedule;
}
