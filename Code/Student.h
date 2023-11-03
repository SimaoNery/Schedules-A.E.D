#ifndef UNTITLED_STUDENT_H
#define UNTITLED_STUDENT_H
#include <string>
#include <vector>
#include "Uc_class.h"
using namespace std;

class Student {
    private:
        ///up code of the student
        string studentCode;
        ///name of the student
        string studentName;
        ///schedule of the student
        list<Uc_class> schedule;
    public:
        ///constructor
        /// \param studentCode
        /// \param studentName
        Student(string studentCode,string studentName);
        ///sets the schedule of an already existing student
        void update_studentSchedule(Uc_class schedule);
        /// \return the student code
        string get_studentCode() const;
        /// \return the student name
        string get_studentName() const;
        /// \return the schedule of a student
        list<Uc_class> get_studentSchedule() const;
        ///override of the operator '<' for class Student
       bool operator < (const Student& other) const{
            return (this->studentCode < other.get_studentCode());
       }
};
#endif //UNTITLED_STUDENT_H
