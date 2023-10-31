#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

// Default constructor definition
Student::Student() : Name(""), numCourses(0), courseList(new string[numCourses]) {
    cout << "\n---------------------------" << endl;
    cout << "Default Constructor called" << endl;
    cout << "---------------------------" << endl;
}

// Copy constructor definition
Student::Student(const Student& that) : Name(that.Name), numCourses(that.numCourses) {
    cout << "\n---------------------------" << endl;
    cout << "Copy Constructor called" << endl;
    cout << "---------------------------" << endl;

    courseList = new string[numCourses];
    for (int i = 0; i < numCourses; ++i) {
        courseList[i] = that.courseList[i];
    }
}

// Assignment operator definition
Student& Student::operator=(const Student& that) {
    cout << "\n---------------------------" << endl;
    cout << "Assignment operator called" << endl;
    cout << "---------------------------" << endl;

    if (this != &that) {
        delete[] courseList;
        Name = that.Name;
        numCourses = that.numCourses;
        courseList = new string[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            courseList[i] = that.courseList[i];
        }
    }
    return *this;
}

// Destructor definition
Student::~Student() {
    cout << "\n---------------------------" << endl;
    cout << "Destructor called" << endl;
    cout << "---------------------------" << endl;

    if (courseList != nullptr) { // not null test
        delete[] courseList;
        courseList = nullptr; // Assigning null after deleting
    }
}

// String constructor definition
Student::Student(const std::string& name) : Name(name), numCourses(0), courseList(new string[numCourses]) {
    cout << "\n---------------------------" << endl;
    cout << "String Constructor called" << endl;
    cout << "---------------------------" << endl;
} // String constructor



void Student::setName(const string& name) {
    cout << "\n---------------------------" << endl;
    cout << "Set Name called" << endl;
    cout << "---------------------------" << endl;
    Name = name;
}

void Student::addCourse(const string& courseName) {
    cout << "\n---------------------------" << endl;
    cout << "Add Course called" << endl;
    cout << "---------------------------" << endl;

    string* newCourseList = new string[numCourses + 1];

    for (int i = 0; i < numCourses; ++i) {
        newCourseList[i] = courseList[i];
    }

    newCourseList[numCourses] = courseName;

    delete[] courseList;

    courseList = newCourseList;
    numCourses++;

}

void Student::print() {
    cout << "\n---------------------------" << endl;
    cout << "Print called" << endl;
    cout << "---------------------------" << endl;

    cout << "Student: " << Name << endl; // Display student name
    cout << "Number of courses: " << numCourses << endl;
    cout << "Enrolled courses: " << endl;
    if (numCourses == 0) {
        cout << "- Not enrolled yet" << endl;
    }
    for (int i = 0; i < numCourses; ++i) {
        cout << "- " << courseList[i] << endl;
    }


}

// Overloaded friend function
ostream& operator<<(std::ostream& os, const Student& student) {
    cout << "\n---------------------------" << endl;
    cout << "Overloaded called" << endl;
    cout << "---------------------------" << endl;
    os << "Student: " << student.Name << endl;
    os << "Number of courses: " << student.numCourses << endl;
    os << "Enrolled courses: " << endl;
    if (student.numCourses == 0) {
        os << "- Not enrolled yet" << endl;
    }
    for (int i = 0; i < student.numCourses; ++i) {
        os << "- " << student.courseList[i] << endl;
    }


    return os;
}

void Student::resetCourses() {
    cout << "\n---------------------------" << endl;
    cout << "Reset Courses called" << endl;
    cout << "---------------------------" << endl;
    numCourses = 0; // Set number of courses to zero
    delete[] courseList; // Delete the previous course list
    courseList = new string[numCourses]; // Create a new empty list
}