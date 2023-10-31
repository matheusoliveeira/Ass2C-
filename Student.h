#ifndef ASSIGNMENT2_STUDENT_H
#define ASSIGNMENT2_STUDENT_H

#include <string>

using namespace std;

class Student {

private:
    string Name;
    int numCourses; // length of course list
    string* courseList;

public:
    Student(); // Default constructor
    Student(const Student& that); // Copy constructor
    Student& operator=(const Student& that); // Assignment operator
    ~Student(); // Destructor
    Student(const string& name);  // String constructor

    void setName(const std::string& name);
    void addCourse(const std::string& courseName);
    void print();
    void resetCourses();

    friend ostream& operator<<(ostream& os, const Student& student); // Overloaded << as a friend function

};

#endif //ASSIGNMENT2_STUDENT_H
