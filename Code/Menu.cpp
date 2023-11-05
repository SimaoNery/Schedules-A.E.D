#include "Menu.h"
#include "Parse_Files.h"
#include <algorithm>
#include <map>
#include <queue>


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

//where everything happens
void Menu::menu(){
    //Get the information in their data structures
    Parse_Files aux;
    aux.Parse_Classes();
    aux.Parse_Students();
    string studentCode, ucCode, ucCodeDestiny, classCode, classCodeDestiny;
    Requests request(0); //Request object to store info to verify and process the request

    string choice1;
    int checks = 0;
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
        cout << "|                                    | 6-> Revert Request                |" << endl;
        cout << "|                                    |                                   |" << endl;
        cout << "|                                    |                                   |" << endl;
        cout << "| Number of operations needing check = " << checks <<"                                 |" << endl;
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

            //Useful Variables in the Switch
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
                        for (const Student &student: aux.get_Students()) {
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
                        for(const Student &student : aux.get_Students()){
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
                        for(Student student : aux.get_Students()){
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
                    for(Student student : aux.get_Students()){
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
                    for(const Student& student : aux.get_Students()){
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
                    for(const Student& student : aux.get_Students()){
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
                    for(auto aula : aux.get_Uc_classes()){
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
                    for(char& c : code2){c = tolower(c);}
                    if(code2 == "saturday" || code2 == "sunday"){
                        cout << "You have all day free!" << endl;
                        break;
                    }
                    else if(code2 == "monday"  || code2 == "tuesday" || code2 == "wednesday" || code2 == "thursday" || code2 == "friday") {
                        for (Student student: aux.get_Students()) {
                            if (student.get_studentCode() == code1) {
                                schedule = student.get_studentSchedule();
                                break;
                            }
                        }
                        code2[0] = toupper(code2[0]);
                        for (Uc_class turma: schedule) {
                            auxil = turma.get_schedule();
                            for (Class aula: auxil) {
                                if (aula.get_weekday() == code2) {
                                    day.insert(aula);
                                }
                            }
                        }
                        for (Class aula: day) {
                            double start = aula.get_startHour();
                            double free = start - previous;
                            if (free > 0) {
                                cout << "You have some free time from " << previous << " to " << start << endl;
                            }
                            previous = start + aula.get_duration();
                        }
                        if (previous == 0) {
                            cout << "You have all day free!" << endl;
                            break;
                        }
                        if (previous < end) {
                            cout << "You have some free time from " << previous << " to " << end << endl;
                        }
                        break;
                    }
                    else{cout << "Day inserted doesn't exist!" << endl;break;}

                default:
                    cout << "Invalid Operation! Please insert a valid input:" << endl;
                    break;
            }
        }

        else if(choice1 == "C"){
            int choice2 = 0;
            cout << "What type of Changes you want to do? (1,2,3,4,5,6)" << endl;
            cin >> choice2;

            switch (choice2) {
                case 1:
                    cout << "Insert student code: ";
                    cin >> studentCode;
                    if (!aux.find_student(studentCode)) {
                        cout << "Invalid student code!" << endl;
                        break;
                    }
                    cout << "Insert the code of the U.C you want to register:" << endl;
                    cin >> ucCode;
                    if (!aux.find_UC(ucCode)) {
                        cout << "Invalid U.C!" << endl;
                        break;
                    }
                    if(aux.find_student_UC(studentCode, ucCode)) {
                        cout << "The student is already registered in this U.C" << endl;
                        break;
                    }
                    request = Requests(choice2); //stores the option of the user
                    request.data.push_back(studentCode);
                    request.data.push_back(ucCode);
                    aux.add_request(request); //store the data inserted by user on queue to check the validation of the requests
                    cout << "Your request has been registered!" << endl;
                    checks++;
                    break;
                    //option is Change Inscription In A U.C.
                case 2:
                    cout << "Insert student code: " << endl;
                    cin >> studentCode;
                    if(!aux.find_student(studentCode)) {
                        cout << "Invalid student code!" << endl;
                        break;
                    }
                    cout << "Insert the code of the U.C you want to leave: ";
                    cin >> ucCode;
                    if (!aux.find_UC(ucCode)) {
                        cout << "Invalid U.C!" << endl;
                        break;
                    }
                    if(!aux.find_student_UC(studentCode, ucCode)) {
                        cout << "The student is not registered in this U.C" << endl;
                        break;
                    }
                    request = Requests(choice2);
                    request.data.push_back(studentCode);
                    request.data.push_back(ucCode);
                    aux.add_request(request); //stores the data inserted by user on queue to check the validation of the requests
                    cout << "Your request has been registered!" << endl;
                    checks++;
                    break;
                    //option is Change Class.
                case 3:
                    cout << "Insert student code: " << endl;
                    cin >> studentCode;
                    if (!aux.find_student(studentCode)) {
                        cout << "Invalid student code!" << endl;
                        break;
                    }
                    cout << "Insert the code of the U.C you want to make changes to: ";
                    cin >> ucCode;
                    if (!aux.find_UC(ucCode)) {
                        cout << "Invalid U.C!" << endl;
                        break;
                    }
                    if(!aux.find_student_UC(studentCode, ucCode)) {
                        cout << "The student is not registered in this U.C" << endl;
                        break;
                    }
                    cout << "Insert the class that you are enrolled in: ";
                    cin >> classCode;
                    if(!aux.find_UC_class(ucCode, classCode)) {
                        cout << "Invalid class" << endl;
                        break;
                    }
                    if(!aux.find_student_class(studentCode, ucCode, classCode)) {
                        cout << "The student is not enrolled in this class" << endl;
                        break;
                    }
                    cout << "Insert the class that you want to join: ";
                    cin >> classCodeDestiny;
                    if(!aux.find_UC_class(ucCode, classCodeDestiny)) {
                        cout << "Invalid class" << endl;
                        break;
                    }
                    request = Requests(choice2);
                    request.data.push_back(studentCode);
                    request.data.push_back(ucCode);
                    request.data.push_back(classCode);
                    request.data.push_back(classCodeDestiny);
                    aux.add_request(request); //stores the data inserted by user on queue to check the validation of the requests
                    cout << "Your request has been registered!" << endl;
                    checks++;
                    break;

                case 4:
                    cout << "Analyzing requests..." << endl;
                    aux.Check_Request();
                    checks = 0;
                    break;

                case 5:
                    cout << "Processing requests..." << endl;
                    aux.Process_Request();
                    break;


                case 6:
                    cout << "Reverting request..." << endl;
                    aux.Revert_Request();
                    break;

                default:
                    cout << "Invalid Operation! PLease Try Again" << endl;
                    break;
            }
        }

        else if(choice1 == "Q"){
            aux.print_students();
            cout << "Save completed!" << endl;
            cout << "See you next time!";
            exit(0);
        }

        else{
            cout << "The operation inserted doesn't exist!" << endl;
        }
    }
}
