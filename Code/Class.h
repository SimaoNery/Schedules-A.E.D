#ifndef UNTITLED_CLASS_H
#define UNTITLED_CLASS_H
#include <iostream>
#include <string>
using namespace std;

class Class{
    private:
    ///day of the week
        string weekday;
    ///type of class
        string type;
    ///starting hour
        double startHour;
    ///duration
        double duration;
    public:
        /// constructor
        /// \param weekday
        /// \param type
        /// \param startHour
        /// \param duration
        Class(string weekday, string type, double startHour, double duration);
        ///
        /// \return weekday
        string get_weekday() const;
        /// \return startHour
        double get_startHour() const;
        /// \return duration
        double get_duration() const;
        /// \return type
        string get_type() const;
        ///
        /// \param c2
        /// \return true if there are overlap between classes
        bool conflict(const Class& c2) const;
        ///
        ///override of operator '==' for class Class
        bool operator == (const Class& other) const{
            return(this->weekday == other.weekday && this->startHour == other.startHour && this->duration == other.duration && this->type == other.type);
        }
        ///override of operator '<' for class Class
        bool operator < (const Class& other) const{
            return(this->startHour < other.get_startHour());
        }
        ///override of operator '<<' for class Class
        friend std::ostream& operator<<(std::ostream& os, const Class& c) {
            os << "(W: " << c.get_weekday() << "; ";
            os << "Type: " << c.get_type() << "; ";
            os << "Start Hour: " << c.get_startHour() << "; ";
            os << "Duration: " << c.get_duration() << ")";
            return os;
        }
};
#endif //UNTITLED_CLASS_H
