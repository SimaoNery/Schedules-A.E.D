#include <fstream>
#include <iostream>
#include <sstream>
#include "Parse_Files.h"

//list with all uc classes("turmas de cada Uc")
void Parse_Files::Parse_Classes(){
    ifstream file("../Information/classes.csv");
    if(!file.is_open()){ //Check if we can open the file
        cout << "Impossible to open the file!" << endl;
    }

    string line; getline(file, line); //Ignore the first line

    string lastUc; //Will be necessary to compare Uc codes

    //Loop through all lines and creates a class('aula')
    while(getline(file, line)){

        istringstream iss(line);

        string Ccode, Ucode, Wday, Type,Shour, Dur;

        getline(iss, Ccode, ',');
        getline(iss, Ucode, ',');
        getline(iss, Wday, ',');
        getline(iss, Shour, ',');
        getline(iss, Dur, ',');
        getline(iss, Type, '\r');

        double hour = stod(Shour); //convert string to integer
        double duration = stod(Dur); //convert string to integer

        Class aula(Wday, Type, hour, duration);

        //If we encounter a new Uc, we create a new Uc_class "turma"
        if(Ucode != lastUc){
            list<Class> schedule;
            schedule.push_back(aula);
            Uc_class turma(Ucode, Ccode, schedule);
            Uc_classes.push_back(turma);
        }
        //Otherwise we search in Uc_classes for the same class("turma") in the same Uc and add a new class("aula") to the schedule if it is already there, or create a new class if it doesn't
        else{
            bool existing_class = false;
            for(auto itr = Uc_classes.begin(); itr != Uc_classes.end(); itr++){
                if(Ccode == itr->get_classCode() && Ucode == itr->get_ucCode()){
                    auto new_schedule = itr->get_schedule();
                    new_schedule.push_back(aula);
                    itr->set_schedule(new_schedule);
                    existing_class = true;
                }
            }
            //If there isn't the same class for this Uc in the Uc_classes list we create a new class and add it to the list
            if(existing_class != true){
                list<Class> schedule;
                schedule.push_back(aula);
                Uc_class turma(Ucode, Ccode, schedule);
                Uc_classes.push_back(turma);
            }
        }
        lastUc = Ucode;
    }
}

//set with all students and their information
void Parse_Files::Parse_Students() {
    ifstream file("../Information/students_classes.csv");
    if(!file.is_open()){ //Check if we can open the file
        cout << "Impossible to open the file!" << endl;
    }

    string line; getline(file, line); //Ignore the first line

    int first = 0;//Will be used to check if we are looping for the first time
    Student atual("","");//Student that is being treated

    while(getline(file, line)){

        istringstream iss(line);

        string Scode, Sname, Ucode, Ccode;

        getline(iss, Scode, ',');
        getline(iss, Sname, ',');
        getline(iss, Ucode, ',');
        getline(iss, Ccode, '\r');

        if(Scode != atual.get_studentCode()){//If the student changes we need to create a new one

            if(first != 0) {//If we are looping for the first time we need to change the "atual" so that is represents a student correctly, so we jump the insert

                Students.insert(atual);//Insert the student being treated so that we can treat a new one(since once a student changes, it won't appear again)

            }
            atual = Student(Scode, Sname);
            for(auto itr = Uc_classes.begin(); itr != Uc_classes.end();itr++){
                if(Ucode == itr->get_ucCode() && Ccode == itr->get_classCode()){

                    atual.update_studentSchedule(*itr); //Iterate through Uc_classes so that we can create the student schedule

                }
            }
        }
        else{//Otherwise we just change the one already being treated
            for(auto itr = Uc_classes.begin(); itr != Uc_classes.end();itr++){
                if(Ucode == itr->get_ucCode() && Ccode == itr->get_classCode()){
                    atual.update_studentSchedule(*itr);
                }
            }
        }
        first = 1;//To inform that we have looped at least once
    }
    Students.insert(atual);
    //cout << "Students size: " << Students.size() << endl;-->Testing
}


vector<Uc_class> Parse_Files::get_Uc_classes(){
    return Uc_classes;
}
set<Student> Parse_Files::get_Students(){
    return Students;
}

void Parse_Files::set_Students(set<Student> &students) {
    this->Students = students;
}

void Parse_Files::set_UC_Classes(vector<Uc_class> &clas) {
    this->Uc_classes = clas;
}

void Parse_Files::add_request(const Requests& request) {
    this->requests.push(request);
}

void Parse_Files::Check_Request() {
    while(!requests.empty()) {
        Requests request = requests.front();
        switch(request.choice) {
            case 1:
                if(!check_number_UC_student(request.data[0])) {
                    cout << "The student " << request.data[0] << " has reached the max number of UC's" <<endl;
                    break;
                }
                if(!check_UC_class_cap(request.data[1])) {
                    cout << "The student " << request.data[0] << " cannot enroll at UC " << request.data[1] << " because there are no vacancies" << endl;
                    break;
                }
                if(find_class_free(request.data[0], request.data[1]).empty()) {
                    cout << "The student " << request.data[0] << " cannot enroll at UC " << request.data[1] << " because there are no classes compatible with student schedule" << endl;
                    break;
                }
                analyzedRequests.push(request);
                cout << "The request of student " << request.data[0] << " was approved!" << endl;
                break;

            case 2:
                analyzedRequests.push(request);
                cout << "The request of student " << request.data[0] << " was approved!" << endl;
                break;

            case 3:
                if(!check_class_cap(request.data[1], request.data[3])) {
                    cout << "The student " << request.data[0] << " cannot enroll at class " << request.data[3] << " of U.C " << request.data[1] << " because this class don´t have free space" << endl;
                    break;
                }
                if(check_conflict_schedule(request.data[0], request.data[1], request.data[3])) {
                    cout << "The student " << request.data[0] << " cannot enroll at class " << request.data[3] << " of U.C " << request.data[1] << " because there is a conflict with student schedule" << endl;
                    break;
                }
                if(!check_class_balance(request.data[1], request.data[3])) {
                    cout << "The student " << request.data[0] << " cannot enroll at class " << request.data[3] << " of U.C " << request.data[1] << " because there is a balance disturb" << endl;
                    break;
                }
                analyzedRequests.push(request);
                cout << "The request of student " << request.data[0] << " was approved!" << endl;
                break;

        }
        requests.pop();
    }
}


void Parse_Files::Process_Request() {
    string classCode;
    while(!analyzedRequests.empty()) {
        Requests analyzedRequest = analyzedRequests.front();
        switch (analyzedRequest.choice) {
            case 1:
                add_student_UC(analyzedRequest.data[0], analyzedRequest.data[1]);
                if(!find_student_UC(analyzedRequest.data[0], analyzedRequest.data[1])) {
                    cout << "Error in registration of student " << analyzedRequest.data[0] << " in U.C " << analyzedRequest.data[1] << endl;
                    break;
                }
                cout << "The registration of student " << analyzedRequest.data[0] << " in U.C " << analyzedRequest.data[1] <<" was approved! Registered in class " << get_class_student(analyzedRequest.data[0], analyzedRequest.data[1]) << endl;
                analyzedRequest.id = id++;
                approvedRequestsHistory.push_back(analyzedRequest);
                break;

            case 2:
                remove_student_UC(analyzedRequest.data[0], analyzedRequest.data[1]);
                if(find_student_UC(analyzedRequest.data[0], analyzedRequest.data[1])) {
                    cout << "Error on cancellation of the registration of student " << analyzedRequest.data[0] << " in U.C " << analyzedRequest.data[1] << endl;
                    break;
                }
                cout << "The request of cancellation of the registration of student " << analyzedRequest.data[0] << " in U.C " << analyzedRequest.data[1] << " was approved!" << endl;
                analyzedRequest.id = id++;
                approvedRequestsHistory.push_back(analyzedRequest);
                break;

            case 3:
                switch_student_class(analyzedRequest.data[0], analyzedRequest.data[1], analyzedRequest.data[3]);
                if(!find_student_class(analyzedRequest.data[0], analyzedRequest.data[1], analyzedRequest.data[3])) {
                    cout << "Error on the swap of student " << analyzedRequest.data[0] << " from class " << analyzedRequest.data[2] << " to class " << analyzedRequest.data[3] << " of U.C " << analyzedRequest.data[1] << endl;
                    break;
                }
                cout << "The swap of student " << analyzedRequest.data[0] << " from class " << analyzedRequest.data[2] << " to class " << analyzedRequest.data[3] << " of U.C " << analyzedRequest.data[1] << " was approved!" << endl;
                analyzedRequest.id = id++;
                approvedRequestsHistory.push_back(analyzedRequest);
                break;

        }
        analyzedRequests.pop();
    }
    print_changes_history();
}

void Parse_Files::Revert_Request(const int& id) {
    string aux;
    Requests request1(0,0);
    for(auto &request : approvedRequestsHistory) {
        if(request.id == id) {
            switch (request.choice) {
                case 1:
                    request1.choice = 2;
                    request1.id = request.id;
                    request1.data.push_back(request.data[0]);
                    request1.data.push_back(request.data[1]);
                    add_request(request1);
                    break;

                case 2:
                    request1.choice = 1;
                    request1.id = request.id;
                    request1.data.push_back(request.data[0]);
                    request1.data.push_back(request.data[1]);
                    add_request(request1);
                    break;

                case 3:
                    request1.choice = request.choice;
                    request1.id = request.id;
                    request1.data.push_back(request.data[0]);
                    request1.data.push_back(request.data[1]);
                    request1.data.push_back(request.data[3]);
                    request1.data.push_back(request.data[2]);
                    add_request(request1);
                    break;

                default:
                    cout << "Error in the reversing process" << endl;
                    break;
            }
        }
    }
}

void Parse_Files::update_students(const Student& student) {
    auto it = Students.begin();
    while(it != Students.end()) {
        if(it->get_studentCode() == student.get_studentCode()) {
            it = Students.erase(it);
            Students.insert(student);
        }else {
            ++it;
        }
    }
}


bool Parse_Files::find_UC(const string& ucCode) {
    for(const Uc_class &ucClass : Uc_classes) {
        if(ucClass.get_ucCode() == ucCode) {
            return true;
        }
    }
    return false;
}

bool Parse_Files::find_student(const string& studentCode) {
    for(const Student &student : Students) {
        if(student.get_studentCode() == studentCode) {
            return true;
        }
    }
    return false;
}

bool Parse_Files::find_UC_class(const string& ucCode, const string& classCode) {
    for(const Uc_class& uc : Uc_classes) {
        if(uc.get_ucCode() == ucCode) {
            if(uc.get_classCode() == classCode) {
                return true;
            }
        }
    }
    return false;
}

bool Parse_Files::find_student_UC(const string &studentCode, const string &ucCode) {
    for(const Student& student : Students) {
        if(student.get_studentCode() == studentCode) {
            for(const Uc_class& uc : student.get_studentSchedule()) {
                if(uc.get_ucCode() == ucCode) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Parse_Files::find_student_class(const string& studentCode, const string& ucCode, const string& classCode) {
    for(const Student& student : Students) {
        if(student.get_studentCode() == studentCode) {
            for(const Uc_class& uc : student.get_studentSchedule()) {
                if(uc.get_ucCode() == ucCode) {
                    if(uc.get_classCode() == classCode) {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

string Parse_Files::find_class_free(const string& studentCode, const string &ucCode) {
    string empty;
    for(const Uc_class& uc : Uc_classes) {
        if(uc.get_ucCode() == ucCode) {
            if(check_class_cap(ucCode, uc.get_classCode()) && check_class_balance(ucCode, uc.get_classCode())) {
                if(!check_conflict_schedule(studentCode, ucCode, uc.get_classCode())) {
                    return uc.get_classCode();
                }
            }
        }
    }
    return empty;
}


int Parse_Files::get_number_student_class(const string &ucCode, const string &classCode) {
    int count = 0;
    for(const Student& student : Students) {
        for(const Uc_class& uc : student.get_studentSchedule()) {
            if((uc.get_ucCode() == ucCode) && (uc.get_classCode() == classCode)) {
                count++;
            }
        }
    }
    return count;
}

string Parse_Files::get_class_student(const string &studentCode, const string &ucCode) {
    for(const Student& student : Students) {
        for(const Uc_class& uc : student.get_studentSchedule()) {
            if(uc.get_ucCode() == ucCode) {
                return uc.get_classCode();
            }
        }
    }
}

bool Parse_Files::check_number_UC_student(const string &studentCode) {
    for(const Student& student : Students) {
        if(student.get_studentCode() == studentCode) {
            if((student.get_studentSchedule()).size() >= 7) {
                return false;
            }
        }
    }
    return true;
}

bool Parse_Files::check_UC_class_cap(const string &ucCode) {
    int cap = 25;
    for(const Uc_class& uc : Uc_classes) {
        if(uc.get_ucCode() == ucCode) {
            if((get_number_student_class(ucCode, uc.get_classCode())) < cap) {
                return true;
            }
        }
    }
    return false;
}

bool Parse_Files::check_class_cap(const string &ucCode, const string &classCode) {
    int cap = 25;
    if((get_number_student_class(ucCode, classCode)) < cap) {
        return true;
    }
    return false;
}

bool Parse_Files::check_conflict_schedule(const string &studentCode, const string &ucCode, const string &classCode) { //Tentar Simplificar!
    for(const Uc_class& clas : Uc_classes) {
        if(clas.get_ucCode() == ucCode && clas.get_classCode() == classCode) {
            for(const Student& student : Students) {
                if(student.get_studentCode() == studentCode) {
                    for(const Uc_class& uc : student.get_studentSchedule()) {
                        for(const Class &schedule : uc.get_schedule()) {
                            for(const Class &clasSchedule : clas.get_schedule()) {
                                if(schedule.conflict(clasSchedule)) {
                                    return true;
                                }
                            }
                        }
                    }
                    return false;
                }
            }
        }
    }
}

bool Parse_Files::check_class_balance(const string &ucCode, const string &classCode) {
    for(Uc_class& ucs : Uc_classes) {
        if(ucs.get_ucCode() == ucCode) {
            if((get_number_student_class(ucCode, classCode)+1) - get_number_student_class(ucCode, ucs.get_ucCode()) > 4) {
                return false;
            }
        }
    }
    return true;
}

bool Parse_Files::check_id(const int& id) {
    for(auto &request : approvedRequestsHistory) {
        if(request.id == id) {
            return true;
        }
    }
    return false;
}

void Parse_Files::add_student_UC(const string &studentCode, const string &ucCode) {
    Uc_class uc;
    uc.set_ucCode(ucCode);
    uc.set_classCode(find_class_free(studentCode, ucCode));
    for(Student student : Students) {
        if(student.get_studentCode() == studentCode) {
            student.update_studentSchedule(uc);
            update_students(student);
        }
    }
}

void Parse_Files::remove_student_UC(const string &studentCode, const string &ucCode) {
    for(const Student& student : Students) {
        if(student.get_studentCode() == studentCode) {
            auto ucs = student.get_studentSchedule();
            for(auto it = ucs.begin(); it != ucs.end();) {
                if(it->get_ucCode() == ucCode) {
                    it = ucs.erase(it);
                    update_students(student);
                }else {
                    it++;
                }
            }
        }
    }
}

void Parse_Files::switch_student_class(const string &studentCode, const string &ucCode, const string &classCode) {
    for(const Student& student : Students) {
        if(student.get_studentCode() == studentCode) {
            for(Uc_class& uc : student.get_studentSchedule()) {
                if(uc.get_ucCode() == ucCode) {
                    uc.set_classCode(classCode);
                    update_students(student);
                }
            }
        }
    }
}

void Parse_Files::print_students() {
    ofstream file("../Information/output.csv");
    if(!file.is_open()) {
        cout << "Impossible to open the file!" << endl;
    }
    set<Student, SortStudentNames> sortedStudents;
    for(const Student& student : Students) {
        sortedStudents.insert(student);
    }

    file << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    for(const Student& student : sortedStudents) {
        for(const Uc_class& ucs : student.get_studentSchedule()) {
            file << student.get_studentCode() << "," << student.get_studentName() << "," << ucs.get_ucCode() << "," << ucs.get_classCode() << endl;
        }
    }
}

void Parse_Files::print_changes_history() {
    ofstream file ("../Information/changes_history.csv");
    if(!file.is_open()) {
        cout << "Impossible to open the file!" << endl;
    }
    file << "Choice,ID,ChangesData" << endl;
    for(const Requests& info : approvedRequestsHistory) {
        file << info.choice << "," << info.choice << ",";
        for(auto &d : info.data) {
            file << d << " ";
        }
        file << endl;
    }
}