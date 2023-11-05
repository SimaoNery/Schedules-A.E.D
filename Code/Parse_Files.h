#ifndef SCHEDULES_PARSE_FILES_H
#define SCHEDULES_PARSE_FILES_H

#include "Class.h"
#include "Uc_class.h"
#include "Student.h"
#include <string>
#include <set>
#include <queue>
#include <stack>
using namespace std;

///choice is the type of change and data are all process data to complete the request
struct Requests {
    int choice;
    vector<string> data;
    ///constructor
    /// \param choice
    explicit Requests(int choice) : choice(choice) {}
};
///Compares students names to able us to sort students
struct SortStudentNames {
    bool operator() (const Student& student1, const Student& student2) const {
        return student1.get_studentName() < student2.get_studentName();
    }
};

//--------------------------------------------------------------------------------------------------------------------//
///will parse the given files and have functions to allow us to change those files
class Parse_Files {
private:
    ///all classes available and their classes
    vector<Uc_class> Uc_classes;
    ///all students and their information
    set<Student> Students;
    ///where the requests will be checked
    queue<Requests> requests;
    ///where all requests will be processed
    queue<Requests> analyzedRequests;
    ///where all processed requests are stored to make it simpler to revert them after
    stack<Requests> approvedRequestsHistory;
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
    ///
    /// Adds a new request to the request queue
    /// \param request
    void add_request(const Requests& request);
    ///
    ///Checks the approval of all the requests in queue
    ///O(n^5)
    void Check_Request();
    ///
    ///Process and implements all the requests in queue
    ///O(n^3)
    void Process_Request();
    ///
    ///Reverts the request asked
    ///O(n)
    /// \param id
    void Revert_Request();
    ///
    ///Updates the information of a student after a request
    ///O(n^2)
    /// \param student
    void update_students(const Student& student);
    ///
    ///O(n)
    /// \param ucCode
    /// \return true if the UC exists
    bool find_UC(const string& ucCode);
    ///
    ///O(n)
    /// \param studentCode
    /// \return true if the students exists
    bool find_student(const string& studentCode);
    ///
    /// O(n)
    /// \param ucCode
    /// \param classCode
    /// \return true if the Uc_class exists
    bool find_UC_class(const string& ucCode, const string& classCode);
    ///
    /// O(n^2)
    /// \param studentCode
    /// \param ucCode
    /// \return true if the student is in the UC
    bool find_student_UC(const string &studentCode, const string &ucCode);
    ///
    /// O(n^2)
    /// \param studentCode
    /// \param ucCode
    /// \param classCode
    /// \return true if the student is in the Uc_class
    bool find_student_class(const string& studentCode, const string& ucCode, const string& classCode);
    ///
    /// O(n^6)
    /// \param ucCode
    /// \return the classCode of the first class with a free spot in a given UC
    string find_class_free(const string& studentCode, const string& ucCode);
    ///
    ///  O(n^2)
    /// \param ucCode
    /// \param classCode
    /// \return the number of students enrolled in a Uc_class
    int get_number_student_class(const string &ucCode, const string &classCode);
    ///
    /// O(n^2)
    /// \param studentCode
    /// \param ucCode
    /// \return (Is this well implemented student code is never used)
    string get_class_student(const string& studentCode, const string& ucCode);
    ///
    /// O(n)
    /// \param studentCode
    /// \return the number of UC's in which the student is registered
    bool check_number_UC_student(const string& studentCode);
    ///
    /// O(n)
    /// \param ucCode
    /// \return true if the capacity of a UC isn't reached(cap = 25)
    bool check_UC_class_cap(const string& ucCode); //Used in add to search in all Uc_classes
    ///
    /// O(n^2)
    /// \param ucCode
    /// \param classCode
    /// \return true if the capacity of a Uc_class isn't reached
    bool check_class_cap(const string& ucCode, const string& classCode); //Used in switch to search only the Uc_class desired
    ///
    /// O(n^5)
    /// \param studentCode
    /// \param ucCode
    /// \param classCode
    /// \return true if there are conflict between the student schedule and a given Uc_class
    bool check_conflict_schedule(const string& studentCode, const string& ucCode, const string& classCode);
    ///
    /// O(n^3)
    /// \param ucCode
    /// \param classCode
    /// \return true if the Uc_classes are balanced(used only in switch)
    bool check_class_balance_switch(const string& ucCode, const string& classatual, const string& classpretend);
    ///
    ///O(n^3)
    /// \param ucCode
    /// \param classCode
    /// \return true if the Uc_classes are balanced
    bool check_class_balance(const string& ucCode, const string& classCode);
    ///
    ///Adds  a new Uc_class to the student schedule
    ///O(n^3)
    /// \param studentCode
    /// \param ucCode
    void add_student_UC(const string& studentCode, const string& ucCode);
    ///
    ///Removes a Uc_class from the student schedule
    ///O(n^3)
    /// \param studentCode
    /// \param ucCode
    void remove_student_UC(const string& studentCode, const string& ucCode);
    ///
    ///Switch the Uc_class that a student is in for another one in the same UC
    ///O(n^3)
    /// \param studentCode
    /// \param ucCode
    /// \param classCode
    void switch_student_class(const string& studentCode, const string& ucCode, const string& classCode);
    ///
    ///Outputs a new file with updated info
    ///O(n^3)
    void print_students();
};
#endif //SCHEDULES_PARSE_FILES_H
