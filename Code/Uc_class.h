#ifndef UNTITLED_UC_CLASS_H
#define UNTITLED_UC_CLASS_H
#include <string>
#include <list>
#include "Class.h"
using namespace std;
///information about every class("turma")
class Uc_class {
private:
    ///uc of a Uc_class
    string ucCode;
    ///class of a Uc_class
    string classCode;
    ///classes of a Uc_class
    list<Class> schedule;
public:
    ///default constructor
    Uc_class()= default;
    /// constructor
    /// \param ucCode
    /// \param classCode
    /// \param schedule
    Uc_class(string ucCode, string classCode, list<Class> schedule);
    ///
    /// \return ucCode
    string get_ucCode() const;
    /// \return classCode
    string get_classCode() const;
    /// \return schedule
    list<Class> get_schedule() const;
    ///
    /// \param classCode
    void set_classCode(string classCode);
    ///
    /// \param ucCode
    void set_ucCode(string ucCode);
    ///
    /// \param schedule
    void set_schedule(list<Class>schedule);
    ///override of operator ">" for class Uc_class
    bool operator > (const Uc_class& other) {
        return (this->ucCode > other.get_ucCode());
    }
    /// override of operator '<<' for class Uc_class
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