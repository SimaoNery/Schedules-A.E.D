#include "Menu.h"
#include "Parse_Files.h"
#include <algorithm>
#include <map>


//code so that we can sort and reverse_sort maps(used in listing->3)
bool comp(pair<string, int>& a, pair<string, int>& b){return a.second < b.second;}
bool reverse_comp(pair<string, int>& a, pair<string, int>& b){return a.second > b.second;}
void sort(map<string, int>& x){
    vector<pair<string, int>> a;
    for(auto& it : x){
        a.push_back(it);
    }
    sort(a.begin(), a.end(), comp);

    for(auto& it : a){
        cout << "U.C. " << it.first << " has: " << it.second << endl;
    }
}
void reverse_sort(map<string, int>& x){
    vector<pair<string, int>> a;
    for(auto& it : x){
        a.push_back(it);
    }
    sort(a.begin(), a.end(), reverse_comp);

    for(auto& it : a){
        cout << "U.C. " << it.first << " has: " << it.second << endl;
    }
}


void Menu::menu(){

    Parse_Files aux;
    aux.Parse_Classes();
    aux.Parse_Students();
    auto Turmas = aux.get_Uc_classes();
    auto Students = aux.get_Students();


    string choice1;
    while(true){
        cout << "|------------------------------------------------------------------------|" << endl;
        cout << "|             Information            |             Changes               |" << endl;
        cout << "|------------------------------------------------------------------------|" << endl;
        cout << "| 1-> Number of Students             | 1-> Inscription In A U.C.         |" << endl;
        cout << "| 2-> Student Schedule               | 2-> Cancel Inscription In A U.C.  |" << endl;
        cout << "| 3-> U.C.'s With The Most Students  | 3-> Change Class                  |" << endl;
        cout << "| 4-> Students Enrolled In A Class   |                                   |" << endl;
        cout << "| 5-> U.C.'s Available In A Year     | 4-> Check Request                 |" << endl;
        cout << "| 6-> Free Time In A Student Day     | 5-> Process Request               |" << endl;
        cout << "|                                    |                                   |" << endl;
        cout << "|                                    | 6->Revert Request                 |" << endl;
        cout << "|                                    |                                   |" << endl;
        cout << "|                                    |                                   |" << endl;
        cout << "|                                    |                #Press Q to leave  |" << endl;
        cout << "|------------------------------------------------------------------------|" << endl;
        cout << "What type of operation do you want to do? (I or C)" << endl;

        cin >> choice1;

        if(choice1 == "I"){
            int choice2 = 0;
            cout << "What type of Information you want to know? (1,2,3,4,5,6)" << endl;
            cin >> choice2;

            string code1;
            string code2;

            int choice3 = 0;
            auto count = 0;
            double previous = 0;
            double end = 24;

            map<string, int> result;
            set<string> names;
            list<Uc_class> schedule;
            list<Class> auxil;
            set<Class> day;

            switch (choice2){
                case 1:
                    cout << "Number of Students: 1->Class | 2->U.C | 3->Year (1,2,3)" << endl;
                    cin >> choice3;
                    if(choice3 == 1) {
                        cout << "Insert class code:";
                        cin >> code1;
                        cout << "Insert U.C code:";
                        cin >> code2;
                        for (const Student &student: Students) {
                            auto horario = student.get_studentSchedule();
                            for(Uc_class& turma : horario){
                                if(turma.get_classCode() == code1 && turma.get_ucCode() == code2){
                                    count++;
                                    break;
                                }
                            }
                        }
                        cout << "There are " << count << " students in the class." << endl;
                    }
                    else if(choice3 == 2){
                        cout << "Insert U.C. code:";
                        cin >> code1;
                        for(const Student &student : Students){
                            auto horario = student.get_studentSchedule();
                            for(Uc_class& turma : horario){
                                if(turma.get_ucCode() == code1){
                                    count++;
                                    break;
                                }
                            }
                        }
                        cout << "There are " << count << " students in the U.C." << endl;
                    }
                    else if(choice3 == 3){
                        cout << "Insert year: (1,2,3)" << endl;
                        cin >> code1;
                        vector<Student> terceiro;
                        vector<Student> segundo;
                        vector<Student> primeiro;
                        for(Student student : Students){
                            bool inserted = false;
                            auto horario = student.get_studentSchedule();
                            for(Uc_class& turma : horario) {
                                string Ccode = turma.get_classCode();
                                if (Ccode.substr(0, 1) == "3") {
                                    terceiro.push_back(student);
                                    inserted = true;
                                    break;
                                }
                            }
                            if(inserted){continue;}
                            for(Uc_class turma : horario){
                                string Ccode = turma.get_classCode();
                                if(Ccode.substr(0,1) == "2"){
                                    segundo.push_back(student);
                                    inserted = true;
                                    break;
                                }
                            }
                            if(inserted){continue;}
                            primeiro.push_back(student);
                        }
                        if(code1 == "1"){count = primeiro.size();}
                        else if(code1 == "2"){count = segundo.size();}
                        else if(code1 == "3"){count = terceiro.size();}
                        cout << "There are " << count << " students in the year" << endl;
                    }
                    else{
                        cout << "Invalid Option! Try again" << endl;
                    }
                    break;

                case 2:
                    cout << "Insert student code:";
                    cin >> code1;
                    for(Student student : Students){
                        if(student.get_studentCode() == code1){
                            cout << "This is " << student.get_studentName() << " weekly schedule:" << endl;
                            for (const Uc_class& aclass : student.get_studentSchedule()) {
                                cout << aclass << endl;
                            }
                        }
                    }
                    cout << endl;
                    cout << endl;
                    break;

               case 3:
                    cout << "Do you want the information in: 1->Ascending order | 2->Descending order | 3->U.C. Code" << endl;
                    cin >> choice3;
                    for(const Student& student : Students){
                        auto horario = student.get_studentSchedule();
                        for(const Uc_class &turma : horario){
                            result[turma.get_ucCode()]++;
                        }
                    }
                    if(choice3 == 3) {
                        for (auto valor: result) {
                            cout << "U.C. " << valor.first << " has: " << valor.second << " students" << endl;
                        }
                    }
                    else if(choice3 == 1){
                        sort(result);
                    }
                    else if(choice3 == 2){
                        reverse_sort(result);
                    }
                    break;

                case 4:
                    cout << "Do you want the information in: 1->Ascending order | 2->Descending Order" << endl;
                    cin >> choice3;
                    cout << "Insert the class code:" << endl;
                    cin >> code1;
                    cout << "Insert the U.C. code:" << endl;
                    cin >> code2;
                    for(const Student& student : Students){
                        auto horario = student.get_studentSchedule();
                        for(const Uc_class &turma : horario){
                            if(turma.get_classCode() == code1 && turma.get_ucCode() == code2){
                                names.insert(student.get_studentName());
                            }
                        }
                    }
                    if(choice3 == 1){
                        cout << "Students in class " << code1 << " of " << code2 << ":" << endl;
                        for(auto name : names){
                            cout  << name << endl;
                        }
                    }
                    else if(choice3 == 2){
                        cout << "Students in class " << code1 << " of " << code2 << ":" << endl;
                        for(auto it = names.rbegin(); it != names.rend(); it++){
                            cout << *it << endl;
                        }
                    }
                    break;

                case 5:
                    cout << "For each year do you wanna know the U.C.'s available? (1,2,3)" << endl;
                    cin >> choice3;
                    for(auto aula : Turmas){
                        if(aula.get_classCode().substr(0,1) == to_string(choice3)) {
                            names.insert(aula.get_ucCode());
                        }
                    }
                    for(auto name : names){
                        cout << "->" << name << endl;
                    }
                    break;

                case 6:
                    cout << "Insert the code of the student:" << endl;
                    cin >> code1;
                    cout << "Insert the day of the week:" << endl;
                    cin >> code2;
                    if(code2 == "Saturday" || code2 == "Sunday"){
                        cout << "You have all day free!" << endl;
                    }
                    for(Student student : Students){
                        if(student.get_studentCode() == code1){
                            schedule = student.get_studentSchedule();
                            break;
                        }
                    }
                    for(Uc_class turma : schedule){
                        auxil = turma.get_schedule();
                        for(Class aula : auxil){
                            if(aula.get_weekday() == code2){
                                day.insert(aula);
                            }
                        }
                    }
                    for(Class aula : day){
                        double start = aula.get_startHour();
                        double free = start - previous;
                        if(free > 0){cout << "You have some free time from " << previous << " to " << start << endl;}
                        previous = start + aula.get_duration();
                    }
                    if(previous == 0){cout << "You have all day free!" << endl; break;}
                    if(previous < end){cout << "You have some free time from " << previous << " to " << end << endl;}
                    break;

                default:
                    cout << "Invalid Operation!" << endl;
                    exit(0);
            }
        }

        else if(choice1 == "C"){
            int choice2 = 0;
            cout << "What type of Changes you want to do? (1,2,3,4,5,6)";
            cin >> choice2;

            //switch (choice2){
                //case 1:
            //}
        }

        else if(choice1 == "Q"){
            cout << "See you next time!";
            exit(0);
        }

        else{
            cout << "The operation inserted doesn't exist!" << endl;
        }
    }
}