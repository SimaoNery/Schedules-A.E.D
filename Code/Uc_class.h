#ifndef UNTITLED_UC_CLASS_H
#define UNTITLED_UC_CLASS_H
#include <string>
#include <list>
#include "Class.h"
using namespace std;

class Uc_class {
private:
    string ucCode;
    string classCode;
    list<Class> schedule;

public:
    Uc_class(){}
    Uc_class(string ucCode, string classCode);

    void set_schedule(list<Class> schedule);

    string get_ucCode() const;
    string get_classCode() const;
    list<Class> get_schedule() const;
};


#endif //UNTITLED_UC_CLASS_H
