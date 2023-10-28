#include <iostream>
#include "Code/Class.h"
#include "Code/Uc_class.h"
#include "Code/Student.h"
#include "Code/Parse_Files.h"
using namespace std;

int main() {
    std::cout << "Iniciate Testing...." << endl;

   Parse_Files test;
   test.Parse_Classes();
   test.Parse_Students();

   auto test1 = test.get_Uc_classses();
   auto test2 = test.get_Students();

   /*for (Uc_class& c : test1) {
       cout << "Class Code: " << c.get_classCode() << " | Uc Code: " << c.get_ucCode() << " | Schedule:" << endl;

       for (const Class& aclass : c.get_schedule()) {
           cout << aclass << endl;
       }

       cout << "-------------------" << endl;
   }*/

    for (Student s : test2) {
        cout << "Student Code: " << s.get_studentCode() << " | Student Name: " << s.get_studentName() << " | Schedule:" << endl;

        for (const Uc_class& aclass : s.get_studentSchedule()) {
            cout << aclass << endl;
        }

        cout << "-------------------" << endl;
    }
   return 0;
}
