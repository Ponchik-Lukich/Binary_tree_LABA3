#include "string"
#include "ostream"

#ifndef LAB3_STUDENT_H
#define LAB3_STUDENT_H

#endif
using namespace std;

class Person {
private:
    string first_name;
    string last_name;
    string ID;
public:
    Person(string first_name, string last_name, string ID) {
        this->first_name = first_name;
        this->last_name = last_name;
        this->ID = ID;
    }

    Person() {
        first_name = "";
        last_name = "";
        ID = "";
    }

    string get_surname() {
        return last_name;
    }

    string get_name() {
        return first_name;
    }

    string get_ID() {
        return ID;
    }


    friend bool operator==(const Person &s1, const Person &s2) {
        return s1.last_name == s2.last_name && s1.first_name == s2.first_name && s1.ID == s2.ID;
    }

    friend bool operator==(const Person &s1, int &) {
        return ((s1.last_name=="")&&(s1.first_name==""));
    }

    friend bool operator!=(const Person &s1, const Person &s2) {
        return !(s1.last_name == s2.last_name && s1.first_name == s2.first_name && s1.ID == s2.ID);
    }

    friend bool operator>(const Person &s1, const Person &s2) {
        return s1.first_name.length()+s1.last_name.length() > s2.first_name.length()+s2.last_name.length();
    }

    friend bool operator>=(const Person &s1, const Person &s2) {
        return s1.first_name.length()+s1.last_name.length() >= s2.first_name.length()+s2.last_name.length();
    }

    friend bool operator<(const Person &s1, const Person &s2) {
        return s1.first_name.length()+s1.last_name.length() < s2.first_name.length()+s2.last_name.length();
    }

    friend bool operator<=(const Person &s1, const Person &s2) {
        return s1.first_name.length()+s1.last_name.length() <= s2.first_name.length()+s2.last_name.length();
    }

    friend std::ostream& operator<<(std::ostream &out, Person person) {
        out << person.last_name + " " + person.first_name+" Group:" + person.ID;
        return out;
    }


    friend std::string to_string(Person const& person) {
        return person.first_name + " " + person.last_name;
    }
};