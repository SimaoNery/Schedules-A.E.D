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
        vector<Uc_class> schedule;

    public:
        Student(){}
        Student(string studentCode,string studentName);

        void set_studentSchedule(vector<Uc_class> schedule); //VER COMO DAR SET//

        string get_studentCode() const;
        string get_studentName() const;
        vector<Uc_class> get_studentSchedule() const;

        bool operator < (const Student& other) const{
            return (this->studentName < other.get_studentName());
        }
};


#endif //UNTITLED_STUDENT_H
