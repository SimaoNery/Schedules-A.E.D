//
// Created by afonso on 17-10-2023.
//

#ifndef UNTITLED_UC_CLASS_H
#define UNTITLED_UC_CLASS_H
#include <string>
#include <vector>
#include "Class.h"
using namespace std;

class Uc_class {
    private:
        string classCode;
        vector<Class> schedule;

    public:
        Uc_class(){}
        Uc_class(string classCode, vector<Class> schedule);

        void set_classCode(string classCode);
        void set_schedule(vector<Class> schedule);

        vector<Class> get_schedule() const;
        string get_classCode() const;
};


#endif //UNTITLED_UC_CLASS_H
