#include <fstream>
#include <iostream>
#include <sstream>
#include "Parse_Files.h"

void Parse_Files::Parse_Classes() {
    ifstream file("../Information/classes.csv");
    if(!file.is_open()) {
        cerr << "Couldn´t open the file" << endl;
        return;
    }
    //ignore first line
    string line;
    getline(file,line);

    //next lines
    while(getline(file,line)) {
        istringstream iss(line);
        string aux, aux2;
        double startHour, duration;
        Class clas;
        //new class to add in vector classes
        if((getline(iss,aux,',')) && (getline(file,aux2,','))) {
            clas = Class(aux, aux2);
        }
        if(getline(iss,aux,',')) {
            clas.set_weekday(aux);
        }
        if(getline(iss,aux,',')) {
            startHour = stod(aux);          //stod converts string to double
            clas.set_startHour(startHour);
        }
        if(getline(iss,aux,',')) {
            duration = stod(aux);           //stod converts string to double
            clas.set_duration(duration);
        }
        if(getline(iss,aux,'\n')) {
            clas.set_type(aux);
        }
        classes.push_back(clas);
    }
    file.close();
}

void Parse_Files::Parse_UC_Classes() {
    ifstream file("../Information/classes_per_uc.csv");
    if(!file.is_open()) {
        cerr << "Couldn´t open the file" << endl;
        return;
    }
    //ignore first line
    string line;
    getline(file,line);
    //next lines
    while(getline(file,line)) {
        istringstream iss(line);
        string aux, aux2;
        //new uc to add in ucs vector
        Uc_class uc;
        if((getline(iss,aux,',')) && (getline(iss,aux2,'\n'))) {
            uc = Uc_class(aux,aux2);
        }
        ucs.push_back(uc);
    }
    file.close();
}

void Parse_Files::Parse_Students() {
    string aux, aux2;
    vector<Uc_class> schedule;
    ifstream file("../Information/students_classes.csv");
    if(!file.is_open()) {
        cerr << "couldn´t open the file" << endl;
        return;
    }

    //ignore first line
    string line;
    getline(file,line);

    //second line
    getline(file, line);
    istringstream iss(line);
    //StudentCode and StudentName
    getline(iss,aux,',');
    getline(iss,aux2,',');
    //new student
    Student student = Student(aux,aux2);
    //UcCode and ClassCode
    getline(iss,aux,',');
    getline(iss,aux2,'\n');
    Uc_class uc = Uc_class(aux,aux2);
    schedule.push_back(uc);

    //next lines
    while(getline(file,line)) {
        istringstream iss2(line);
        //StudentCode
        getline(iss2,aux,',');
        //different student
        if(aux != student.get_studentCode()){
            //set schedule for the previous student
            student.set_studentSchedule(schedule);
            //previous student to add in students vector
            students.push_back(student);
            //free schedule memory
            schedule.clear();
            //StudentName
            getline(iss,aux2,',');
            //new student
            Student student2 = Student(aux,aux2);
            //UcCode and ClassCode
            getline(iss,aux,',');
            getline(iss,aux2,'\n');
            uc = Uc_class(aux,aux2);
            //add UC to new student schedule
            schedule.push_back(uc);
        }
            //same student
        else{
            //ignore StudentName
            getline(iss,aux,',');
            //UcCode and ClassCode
            getline(iss,aux,',');
            getline(iss,aux2,'\n');
            uc = Uc_class(aux,aux2);
            //add UC to student schedule
            schedule.push_back(uc);
            //check if the actual line is the last line of the file
            if(file.eof()){
                student.set_studentSchedule(schedule);
                students.push_back(student);
            }
        }
    }
    file.close();
}

vector<Class> Parse_Files::get_classes(){
    return classes;
}

vector<Uc_class> Parse_Files::get_ucs(){
    return ucs;
}

vector<Student> Parse_Files::get_students(){
    return students;
}
