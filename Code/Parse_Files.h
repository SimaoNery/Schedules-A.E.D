#ifndef SCHEDULES_PARSE_FILES_H
#define SCHEDULES_PARSE_FILES_H

#include "Class.h"
#include "Uc_class.h"
#include "Student.h"
#include <string>
#include <set>
using namespace std;

class Parse_Files {
private:
    list<Uc_class> Uc_classes;
    set<Student> Students;

public:
    void Parse_Classes();
    void Parse_Students();

    list<Uc_class> get_Uc_classses();
    set<Student> get_Students();
};
#endif //SCHEDULES_PARSE_FILES_H
