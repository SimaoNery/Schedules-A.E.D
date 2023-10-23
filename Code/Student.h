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
        Student(string studentCode,string studentName);

        void set_studentCode(string studentCode);
        void set_studentName(string studentName);
        void set_schedule(vector<Uc_class> schedule); //VER COMO DAR SET//

        string get_studentCode() const;
        string get_studentName() const;
        vector<Uc_class> get_schedule() const;

        bool operator < (const Student& other) const{
            return (this->studentName < other.get_studentName());
        }
};


#endif //UNTITLED_STUDENT_H
