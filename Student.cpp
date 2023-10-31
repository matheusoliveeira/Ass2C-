#include <iostream>
#include <string>

#include "Student.h"

using namespace std;

// Default constructor definition
Student::Student() : Name(""), numCourses(0), courseList(new string[numCourses]) {}

// Copy constructor definition
Student::Student(const Student& that) : Name(that.Name), numCourses(that.numCourses) {
    courseList = new string[numCourses];
    for (int i = 0; i < numCourses; ++i) {
        courseList[i] = that.courseList[i];
    }
    cout << "\nCopy Constructor called\n" << endl;
}

// Assignment operator definition
Student& Student::operator=(const Student& that) {
    if (this != &that) {
        delete[] courseList;
        Name = that.Name;
        numCourses = that.numCourses;
        courseList = new string[numCourses];
        for (int i = 0; i < numCourses; ++i) {
            courseList[i] = that.courseList[i];
        }
    }
    cout << "\nAssignment operator called\n" << endl;
    return *this;
}

// Destructor definition
Student::~Student() {
    if (courseList != nullptr) { // not null test
        delete[] courseList;
        courseList = nullptr; // Assigning null after deleting
    }
    cout << "\nDestructor called\n" << endl;
}

// String constructor definition
Student::Student(const std::string& name) : Name(name), numCourses(0), courseList(new string[numCourses]) {} // String constructor



void Student::setName(const string& name) {
    Name = name;
}

void Student::addCourse(const string& courseName) {
    string* newCourseList = new string[numCourses + 1];

    for (int i = 0; i < numCourses; ++i) {
        newCourseList[i] = courseList[i];
    }

    newCourseList[numCourses] = courseName;

    delete[] courseList;

    courseList = newCourseList;
    numCourses++;
    cout << "\nAdd Course called\n" << endl;

}

void Student::displayInfo() {
    cout << "\nStudent: " << Name << endl; // Display student name
    cout << "Number of courses: " << numCourses << endl;
    cout << "Enrolled courses: " << endl;
    if (numCourses == 0) {
        cout << "- Not enrolled yet" << endl;
    }
    for (int i = 0; i < numCourses; ++i) {
        cout << "- " << courseList[i] << endl;
    }

    cout << "\nPrint called\n" << endl;

}

// Overloaded friend function
ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Student: " << student.Name << endl;
    os << "Number of courses: " << student.numCourses << endl;
    os << "Enrolled courses: " << endl;
    if (student.numCourses == 0) {
        os << "- Not enrolled yet" << endl;
    }
    for (int i = 0; i < student.numCourses; ++i) {
        os << "- " << student.courseList[i] << endl;
    }

    cout << "\nOverloaded called\n" << endl;
    return os;
}

void Student::resetCourses() {
    numCourses = 0; // Set number of courses to zero
    delete[] courseList; // Delete the previous course list
    courseList = new string[numCourses]; // Create a new empty list
}