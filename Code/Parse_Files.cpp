#include <string>
#include <fstream>
#include <sstream>
using namespace std;

class Parse_Files{
    private:
        string filename;
        string studentCode;

    public:
        void Parse_Classes(){

        }

        void Parse_UC_Classes(){

        }

        void Parse_Students(string filename, string studentCode){
            filename = "Information/students_classes.csv";
            ifstream file(filename);
            string line;
            while(getline(file, line)){

            }
        }
};
