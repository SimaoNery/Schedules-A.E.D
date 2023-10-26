#include "Request.h"

void Request::menu(){
    int choice;
    while (true) {
        cout << "|---------------------------------|" << endl;
        cout << "|    Inscrições e Alterações      |" << endl;
        cout << "|---------------------------------|" << endl;
        cout << "| 1   Inscrição em UCs            |"<< endl;
        cout << "| 2   Anular inscrição em UCs     |" << endl;
        cout << "| 3   Troca de UCs                |" << endl;
        cout << "| 4   Inscrição em turma          |" << endl;
        cout << "| 5   Alteração de turma          |" << endl;
        cout << "| 0   Retornar ao menu principal  |" << endl;
        cout << "|---------------------------------|" << endl;
        cout << "Escolha a opção que pretende: ";
        cin >> choice;
        option(choice);
    }
}

void Request::option(int choice) {
    string studentCode, ucCode, ucCodeDestino;
    Parse_Files helper;
    helper.Parse_Students();
    helper.Parse_UC_Classes();
    switch (choice) {
        case 1:
            cout << "Indique por favor o seu número de estudante: ";
            cin >> studentCode;
            if (!helper.find_student(studentCode)) {
                cout << "O número de estudante que forneceu não existe." << endl;
                break;
            }
            cout << "e a UC a que deseja se inscrever: ";
            cin >> ucCode;
            if (!helper.find_UC(ucCode)) {
                cout << "A UC que forneceu não existe." << endl;
                break;
            }
            if(helper.find_student_UC(studentCode, ucCode)) {
                cout << "O estudante já se encontra inscrito a essa UC." << endl;
            }


            break;

        case 2:
            cout << "Indique por favor o seu número de estudante: ";
            cin >> studentCode;
            if (!helper.find_student(studentCode)) {
                cout << "O número de estudante que forneceu não existe." << endl;
                break;
            }
            cout << "e a UC que a deseja anular a inscrição: ";
            cin >> ucCode;
            if (!helper.find_UC(ucCode)) {
                cout << "A UC que forneceu não existe." << endl;
                break;
            }
            if(!helper.find_student_UC(studentCode, ucCode)) {
                cout << "O estudante não se encontra inscrito na UC." << endl;
            }


            break;

        case 3:
            cout << "Indique por favor o seu número de estudante: ";
            cin >> studentCode;
            if (!helper.find_student(studentCode)) {
                cout << "O número de estudante que forneceu não existe." << endl;
                break;
            }
            cout << "a UC que a deseja anular a inscrição: ";
            cin >> ucCode;
            if (!helper.find_UC(ucCode)) {
                cout << "A UC que forneceu não existe." << endl;
                break;
            }
            if(!helper.find_student_UC(studentCode, ucCode)) {
                cout << "O estudante não se encontra inscrito a essa UC." << endl;
            }
            cout << "e a UC a que deseja se inscrever: ";
            cin >> ucCodeDestino;
            if (!helper.find_UC(ucCode)) {
                cout << "A UC que forneceu não existe." << endl;
                break;
            }
            if(helper.find_student_UC(studentCode, ucCodeDestino)) {
                cout << "O estudante já se encontra inscrito a essa UC." << endl;
            }


            break;

        case 4:

            break;
        case 5:

            break;
        case 0:

            exit(0);
        default:
            cout << "Foi selecionada uma opção inexistente. Volte a selecionar." << endl;
    }
}
