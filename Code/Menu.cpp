#include "Menu.h"
#include "Parse_Files.h"

void Menu::menu(){

    Parse_Files aux;
    aux.Parse_Classes();
    aux.Parse_Students();
    auto Turmas = aux.get_Uc_classses();
    auto Students = aux.get_Students();


    string choice1;
    while(true){
        cout << "|------------------------------------------------------------------------|" << endl;
        cout << "|             Information            |             Changes               |" << endl;
        cout << "|------------------------------------------------------------------------|" << endl;
        cout << "| 1-> Number of Students             | 1-> Inscription In A U.C.         |" << endl;
        cout << "| 2-> Student Schedule               | 2-> Cancel Inscription In A U.C.  |" << endl;
        cout << "| 3-> U.C.'s With The Most Students  | 3-> Change U.C.                   |" << endl;
        cout << "| 4-> Students Enrolled In A Class   | 4-> Inscription In A Class        |" << endl;
        cout << "| 5-> U.C.'s Available In A Year     | 5-> Cancel Inscription In A Class |" << endl;
        cout << "| 6-> Free Time In A Student Day     | 6-> Change Class                  |" << endl;
        cout << "|                                                                        |" << endl;
        cout << "|                                                    #Press Q to leave   |" << endl;
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
            int count = 0;
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
                        cout << "Insert year: (1,2,3)";
                        cin >> code1;
                        for(const Student &student : Students){
                            auto horario = student.get_studentSchedule();
                            for(Uc_class& turma : horario){
                                string Ccode = turma.get_classCode();
                                if(Ccode.substr(0,1) == code1){
                                    count++;
                                    break;
                                }
                            }
                        }
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
                   

                //case 4:

                //case 5:

                //case 6:

                default:
                    cout << "Invalid Operation! Please Try Again" << endl;
                    break;
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
            cout << "The operation inserted doesn't exist!";
            break;
        }
    }
}