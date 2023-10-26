#include <iostream>
#include <string>
using namespace std;

class Student{
private:
    std::string Name;
    int numCourses;
    std::string* courseList;
public:
    // A default constructor (i.e., creates a student object without a name and an empty course list).
    Student() : Name(""), numCourses(0), courseList(nullptr) {};

    // The “big three / rule of three” (i.e., copy constructor, assignment operator, destructor).
    // https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three
    // copy constructor
    Student(const Student& that) : Name(that.Name), numCourses(that.numCourses), courseList(that.courseList)
    {
    }
    // copy assignment operator
    Student& operator = (const Student& that)
    {
        Name = that.Name;
        numCourses = that.numCourses;
        courseList = that.courseList;
        return *this;
    }
    // destructor
    ~Student()
    {
        delete[] courseList;
        cout << "destructor called" << endl;
    };

    void setName(const string &name) {
        Name = name;
    }

    //An add function that will allow courses to be added to a student’s list of courses.
    void addCourse(const std::string& courseName) {
        // Create a new array with space for one more course
        std::string* newCourseList = new std::string[numCourses +1];

        // Copy the existing courses to the new array
        for (int i=0; i < numCourses; ++i) {
            newCourseList[i] = courseList[i];
        }

        // Add the new course to the end of the new array
        newCourseList[numCourses] = courseName;

        // Deallocate the old courseList
        delete[] courseList;

        // Update the courseList and numCourses
        courseList = newCourseList;
        numCourses++;
    }

    // Member function to display the enrolled courses
    void displayCourses() {
        std::cout << "Student: " << Name << std::endl;
        std::cout << "Enrolled courses: " << std::endl;
        for (int i = 0; i < numCourses; ++i) {
            std::cout << courseList[i] << std::endl;
        }
    }

}; // end class Student

int main() {
    Student myStudent;
    myStudent.setName("Matheus");


    // Add courses to the student's list
    myStudent.addCourse("Math");
    myStudent.addCourse("Physics");
    myStudent.addCourse("History");

    // Display the enrolled courses
    myStudent.displayCourses();

    return 0;
}
