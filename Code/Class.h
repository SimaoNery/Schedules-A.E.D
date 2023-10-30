#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <iostream>
#include <string>
using namespace std;

class Class{
    private:
        string weekday;
        string type;
        double startHour;
        double duration;

    public:
        Class(string weekday, string type, double startHour, double duration);

        void set_weekday(string weekday);
        void set_startHour(double startHour);
        void set_duration(double duration);
        void set_type(string type);

        string get_weekday() const;
        double get_startHour() const;
        double get_duration() const;
        string get_type() const;

    bool operator == (const Class& other) const{
        return(this->weekday == other.weekday && this->startHour == other.startHour && this->duration == other.duration && this->type == other.type);
    }

    bool operator < (const Class& other) const{
        return(this->startHour < other.get_startHour());
    }

    friend std::ostream& operator<<(std::ostream& os, const Class& c) {
        os << "(W: " << c.get_weekday() << "; ";
        os << "Type: " << c.get_type() << "; ";
        os << "Start Hour: " << c.get_startHour() << "; ";
        os << "Duration: " << c.get_duration() << ")";
        return os;
    }


};
#endif //UNTITLED_CLASS_H
