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
    Uc_class(string ucCode, string classCode, list<Class> schedule);

    string get_ucCode() const;
    string get_classCode() const;
    list<Class> get_schedule() const;

    void set_schedule(list<Class>schedule);
    void set_classCode(string classCode);
    void set_ucCode(string icCode);

    friend std::ostream& operator<<(std::ostream& os, const Uc_class& uc) {
        os << "Uc_code: " << uc.get_ucCode() << "; ";
        os << "Class_code: " << uc.get_classCode() << "; ";
        os << "Schedule: ";
        for (const Class &c: uc.get_schedule()) {
            os << c << " ";
        }
        return os;
    }
};


#endif //UNTITLED_UC_CLASS_H