#include <fstream>
#include <iostream>
#include <sstream>
#include "Parse_Files.h"

//list with call uc classes("turmas de cada Uc")
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

        double hour = stod(Shour); //converter strings para integer
        double duration = stod(Dur); //converter strings para integer

        Class aula(Wday, Type, hour, duration);

        //If we encounter a new Uc, we create a new Uc_class "turma"
        if(Ucode != lastUc){
            list<Class> schedule;
            schedule.push_back(aula);
            Uc_class turma(Ucode, Ccode, schedule);
            Uc_classes.push_back(turma);
        }
            //Otherwise we search in Uc_classes for the same class in the same Uc and add a new class to the schedule if it is already there
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
    //cout << "Uc_classes size: " << Uc_classes.size() << endl;-->Testing
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
    //cout << "Students size: " << Students.size() << endl;-->Testing
}


list<Uc_class> Parse_Files::get_Uc_classses(){
    return Uc_classes;
}
set<Student> Parse_Files::get_Students(){
    return Students;
}