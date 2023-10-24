#ifndef SCHEDULES_PARSE_FILES_H
#define SCHEDULES_PARSE_FILES_H

#include "Class.h"
#include "Uc_class.h"
#include "Student.h"
#include <string>
using namespace std;

class Parse_Files {
private:
    vector<Class> classes;
    vector<Uc_class> ucs;
    vector<Student> students;

public:
    void Parse_Classes();
    void Parse_UC_Classes();
    void Parse_Students();

    vector<Class> get_classes();
    vector<Uc_class> get_ucs();
    vector<Student> get_students();
};
#endif //SCHEDULES_PARSE_FILES_H
