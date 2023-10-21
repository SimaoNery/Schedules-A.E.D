//
// Created by afonso on 17-10-2023.
//

#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <vector>
#include "Class.h"
using namespace std;

class Student {
    private:
        string studentCode;
        string studentName;
        vector<Class> schedule;

    public:
        Student();
        Student(string studentCode,string studentName);

        void set_studentCode(string studentCode);
        void set_studentName(string studentName);
        void set_studentClass(string ucCode, string classCode);

        string get_studentCode() const;
        string get_studentName() const;
        vector<Class> get_studentSchedule() const;

        bool operator < (const Student& other) const{
            return (this->studentName < other.get_studentName());
        }
};


#endif //UNTITLED_STUDENT_H
