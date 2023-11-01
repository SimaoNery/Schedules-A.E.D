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
    ///all classes available and their classes
    vector<Uc_class> Uc_classes;
    ///all students and their information
    set<Student> Students;
public:
    ///reads the files and creates a vector with all classes
    /// O(n^2)
    void Parse_Classes();
    ///reads the files and creates a set with all students
    ///O(n^2)
    void Parse_Students();
    /// \return Uc_classes
    vector<Uc_class> get_Uc_classes();
    /// \return Students
    set<Student> get_Students();
};
#endif //SCHEDULES_PARSE_FILES_H
