#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <string>
using namespace std;

class Class{
    private:
        string classCode;
        string ucCode;
        string weekday;
        double startHour;
        double duration;
        string type;

    public:
        Class(){};
        Class(string classCode, string ucCode);

        void set_ucCode(string ucCode);
        void set_weekday(string weekday);
        void set_startHour(double startHour);
        void set_duration(double duration);
        void set_type(string type);

        string get_classCode() const;
        string get_ucCode() const;
        string get_weekday() const;
        double get_startHour() const;
        double get_duration() const;
        string get_type() const;

};
#endif //UNTITLED_CLASS_H
