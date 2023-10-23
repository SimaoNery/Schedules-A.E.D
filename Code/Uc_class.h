#ifndef UNTITLED_UC_CLASS_H
#define UNTITLED_UC_CLASS_H
#include <string>
#include <list>
#include "Class.h"
using namespace std;

class Uc_class {
    private:
        string classCode;
        list<Class> schedule;

    public:
        Uc_class(){}
        Uc_class(string classCode, list<Class> schedule);

        void set_classCode(string classCode);
        void set_schedule(list<Class> schedule);

        list<Class> get_schedule() const;
        string get_classCode() const;
};


#endif //UNTITLED_UC_CLASS_H
