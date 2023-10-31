#include <iostream>
#include "Student.h"

int main() {
    bool keepRunning = true;  // Variable to control the program loop

    while (keepRunning) {
        string nameS1; // Variable to store the name of the first student.
        string courseName; // Variable to store course names

        cout << "Please insert your name:" << endl;
        getline(cin, nameS1);
        Student S1(nameS1);  // Creating a Student object and Setting the name for the first student

        while (true) {
            cout << "Please insert a course you intend to enter or press 'Q' to quit?" << endl;
            getline(cin, courseName);

            // Check if the user typed 'Q' to quit entering courses
            if (courseName == "Q") {
                cout << "Quitting..\n" << endl;
                break; // Exit the course entry loop
            } else if (courseName.empty()) {
                cout << "This field cannot be empty" << endl;
                continue;
            }

            S1.addCourse(courseName); // Add courses to the first student
        }

        // Display information for the first student
        S1.print();

        // Ask for the name of the second student
        Student S2(S1); // Creating a second student with the information from the first
        string nameS2;
        cout << "\nPlease insert your name:" << endl;
        getline(cin, nameS2);
        S2.setName(nameS2); // Setting the name for the second student

        // Print information for the second student
        S2.print();

        // Display the first student's information after resetting courses
        S1.resetCourses(); // Resetting the first student's course information
        S1.print(); // Displaying the first student's updated information

        // Display information for the second student (deep copy)
        cout << S2 << endl;

        // Creating a third student by assignment
        Student S3;
        S3 = S2; // Assigning the second student's information to the third student

        string nameS3; // Variable to store the name of the third student.

        cout << "Please insert your name:" << endl;
        getline(cin, nameS3);
        S3.setName(nameS3);

        S3.print(); // Displaying the third student's information

        char choice;
        cout << "Do you want to enter another set of students? (Y/N): ";
        cin >> choice;
        cin.ignore(); // to clear the newline character from the input buffer


        // Check user's choice to continue or exit the program
        if (toupper(choice) != 'Y') {
            keepRunning = false; // Exiting the program loop
        }
    }

    return 0;
}
