#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <vector>
#include "Uc_class.h"
using namespace std;

class Student {
    private:
        string studentCode;
        string studentName;
        list<Uc_class> schedule;

    public:
        Student(string studentCode,string studentName);

        void update_studentSchedule(Uc_class schedule);

        string get_studentCode() const;
        string get_studentName() const;
        list<Uc_class> get_studentSchedule() const;


       bool operator < (const Student& other) const{
            return (this->studentCode < other.get_studentCode());
       }
};


#endif //UNTITLED_STUDENT_H
