#include<iostream>
#include<fstream>
#include<iomanip>
#include<limits>

using namespace std;

// ============================================================
//                STUDENT MANAGEMENT SYSTEM
// ============================================================
//
// This project is made using:
// ? Arrays
// ? 2D Arrays
// ? Functions
// ? Loops
// ? Conditions
// ? File Handling
// ? Input Validation
//
// ------------------------------------------------------------
// Subjects:
// 1. Programming Fundamental
// 2. AICT
// 3. Calculus
// ------------------------------------------------------------
//
// Features:
// ? Add Student
// ? Display Students
// ? Search Student
// ? Update Student
// ? Delete Student
// ? Show Topper
// ? Subject Average
// ? Pass / Fail Ratio
// ? Save Data
// ? Load Data
// ? Auto Save
// ? Auto Load
//
// ============================================================


// ============================================================
//                  GLOBAL CONSTANTS
// ============================================================

// Maximum students
const int MAX = 100;

// Total subjects
const int SUBJECTS = 3;


// ============================================================
//                   GLOBAL ARRAYS
// ============================================================

// Student IDs
int studentID[MAX];

// Student Names
string studentName[MAX];

// 2D Array for marks
float marks[MAX][SUBJECTS];

// Average marks
float averageMarks[MAX];

// GPA
float gpa[MAX];

// Grade
char grade[MAX];

// Current total students
int totalStudents = 0;


// ============================================================
//            FUNCTION FOR INTEGER INPUT
// ============================================================
//
// This function prevents infinite loop.
// It only accepts integer values.
//
// ============================================================

int inputInt()
{
    int value;

    while(!(cin >> value))
    {
        cout << "Invalid Input! Enter Numbers Only: ";

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}


// ============================================================
//             FUNCTION FOR FLOAT INPUT
// ============================================================

float inputFloat()
{
    float value;

    while(!(cin >> value))
    {
        cout << "Invalid Input! Enter Numbers Only: ";

        cin.clear();

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return value;
}


// ============================================================
//             FUNCTION TO CALCULATE GPA
// ============================================================

float calculateGPA(float average)
{
    if(average >= 90)
        return 4.0;

    else if(average >= 80)
        return 3.5;

    else if(average >= 70)
        return 3.0;

    else if(average >= 60)
        return 2.5;

    else if(average >= 50)
        return 2.0;

    else
        return 0.0;
}


// ============================================================
//            FUNCTION TO CALCULATE GRADE
// ============================================================

char calculateGrade(float average)
{
    if(average >= 90)
        return 'A';

    else if(average >= 80)
        return 'B';

    else if(average >= 70)
        return 'C';

    else if(average >= 60)
        return 'D';

    else
        return 'F';
}


// ============================================================
//               FUNCTION TO ADD STUDENT
// ============================================================

void addStudent()
{
    cout << "\n================================================\n";
    cout << "                 ADD STUDENT\n";
    cout << "================================================\n";

    // Check storage limit
    if(totalStudents >= MAX)
    {
        cout << "Storage Full!\n";
        return;
    }

    // Input student ID
    cout << "Enter Student ID: ";

    studentID[totalStudents] = inputInt();

    // Check duplicate ID
    for(int i=0; i<totalStudents; i++)
    {
        if(studentID[i] == studentID[totalStudents])
        {
            cout << "Student ID Already Exists!\n";
            return;
        }
    }

    // Input student name
    cout << "Enter Student Name: ";

    cin.ignore();

    getline(cin, studentName[totalStudents]);

    float total = 0;

    // ================= PF Marks =================

    cout << "Enter Programming Fundamental Marks: ";

    marks[totalStudents][0] = inputFloat();

    while(marks[totalStudents][0] < 0 ||
          marks[totalStudents][0] > 100)
    {
        cout << "Enter Marks Between 0 and 100: ";

        marks[totalStudents][0] = inputFloat();
    }

    total += marks[totalStudents][0];


    // ================= AICT Marks =================

    cout << "Enter AICT Marks: ";

    marks[totalStudents][1] = inputFloat();

    while(marks[totalStudents][1] < 0 ||
          marks[totalStudents][1] > 100)
    {
        cout << "Enter Marks Between 0 and 100: ";

        marks[totalStudents][1] = inputFloat();
    }

    total += marks[totalStudents][1];


    // ================= Calculus Marks =================

    cout << "Enter Calculus Marks: ";

    marks[totalStudents][2] = inputFloat();

    while(marks[totalStudents][2] < 0 ||
          marks[totalStudents][2] > 100)
    {
        cout << "Enter Marks Between 0 and 100: ";

        marks[totalStudents][2] = inputFloat();
    }

    total += marks[totalStudents][2];

    // Calculate average
    averageMarks[totalStudents] = total / SUBJECTS;

    // Calculate GPA
    gpa[totalStudents] =
    calculateGPA(averageMarks[totalStudents]);

    // Calculate grade
    grade[totalStudents] =
    calculateGrade(averageMarks[totalStudents]);

    // Increase total students
    totalStudents++;

    cout << "\nStudent Added Successfully!\n";
}


// ============================================================
//            FUNCTION TO DISPLAY STUDENTS
// ============================================================

void displayStudents()
{
    cout << "\n================================================\n";
    cout << "                ALL STUDENTS\n";
    cout << "================================================\n";

    // Check records
    if(totalStudents == 0)
    {
        cout << "No Records Found!\n";
        return;
    }

    // Table headings
    cout << left
         << setw(10) << "ID"
         << setw(20) << "Name"
         << setw(10) << "PF"
         << setw(10) << "AICT"
         << setw(12) << "Calculus"
         << setw(10) << "Avg"
         << setw(10) << "GPA"
         << setw(10) << "Grade"
         << endl;

    cout << "-----------------------------------------------------------------\n";

    // Display all students
    for(int i=0; i<totalStudents; i++)
    {
        cout << left
             << setw(10) << studentID[i]
             << setw(20) << studentName[i]
             << setw(10) << marks[i][0]
             << setw(10) << marks[i][1]
             << setw(12) << marks[i][2]
             << setw(10) << averageMarks[i]
             << setw(10) << gpa[i]
             << setw(10) << grade[i]
             << endl;
    }
}


// ============================================================
//              FUNCTION TO SEARCH STUDENT
// ============================================================

void searchStudent()
{
    cout << "\n================================================\n";
    cout << "               SEARCH STUDENT\n";
    cout << "================================================\n";

    int searchID;

    bool found = false;

    cout << "Enter Student ID: ";

    searchID = inputInt();

    // Search student
    for(int i=0; i<totalStudents; i++)
    {
        if(studentID[i] == searchID)
        {
            found = true;

            cout << "\nStudent Found!\n";

            cout << "Student ID : "
                 << studentID[i]
                 << endl;

            cout << "Student Name : "
                 << studentName[i]
                 << endl;

            cout << "Programming Fundamental : "
                 << marks[i][0]
                 << endl;

            cout << "AICT : "
                 << marks[i][1]
                 << endl;

            cout << "Calculus : "
                 << marks[i][2]
                 << endl;

            cout << "Average : "
                 << averageMarks[i]
                 << endl;

            cout << "GPA : "
                 << gpa[i]
                 << endl;

            cout << "Grade : "
                 << grade[i]
                 << endl;
        }
    }

    // If student not found
    if(found == false)
    {
        cout << "Student Not Found!\n";
    }
}


// ============================================================
//               FUNCTION TO UPDATE STUDENT
// ============================================================

void updateStudent()
{
    cout << "\n================================================\n";
    cout << "               UPDATE STUDENT\n";
    cout << "================================================\n";

    int updateID;

    bool found = false;

    cout << "Enter Student ID: ";

    updateID = inputInt();

    // Search student
    for(int i=0; i<totalStudents; i++)
    {
        if(studentID[i] == updateID)
        {
            found = true;

            float total = 0;

            // Update PF Marks
            cout << "Enter Programming Fundamental Marks: ";

            marks[i][0] = inputFloat();

            while(marks[i][0] < 0 ||
                  marks[i][0] > 100)
            {
                cout << "Enter Marks Between 0 and 100: ";

                marks[i][0] = inputFloat();
            }

            total += marks[i][0];


            // Update AICT Marks
            cout << "Enter AICT Marks: ";

            marks[i][1] = inputFloat();

            while(marks[i][1] < 0 ||
                  marks[i][1] > 100)
            {
                cout << "Enter Marks Between 0 and 100: ";

                marks[i][1] = inputFloat();
            }

            total += marks[i][1];


            // Update Calculus Marks
            cout << "Enter Calculus Marks: ";

            marks[i][2] = inputFloat();

            while(marks[i][2] < 0 ||
                  marks[i][2] > 100)
            {
                cout << "Enter Marks Between 0 and 100: ";

                marks[i][2] = inputFloat();
            }

            total += marks[i][2];

            // Recalculate average
            averageMarks[i] = total / SUBJECTS;

            // Recalculate GPA
            gpa[i] = calculateGPA(averageMarks[i]);

            // Recalculate Grade
            grade[i] = calculateGrade(averageMarks[i]);

            cout << "\nRecord Updated Successfully!\n";
        }
    }

    // If student not found
    if(found == false)
    {
        cout << "Student Not Found!\n";
    }
}


// ============================================================
//               FUNCTION TO DELETE STUDENT
// ============================================================

void deleteStudent()
{
    cout << "\n================================================\n";
    cout << "               DELETE STUDENT\n";
    cout << "================================================\n";

    int deleteID;

    bool found = false;

    cout << "Enter Student ID: ";

    deleteID = inputInt();

    // Search student
    for(int i=0; i<totalStudents; i++)
    {
        if(studentID[i] == deleteID)
        {
            found = true;

            // Shift data backward
            for(int j=i; j<totalStudents-1; j++)
            {
                studentID[j] = studentID[j+1];

                studentName[j] = studentName[j+1];

                averageMarks[j] = averageMarks[j+1];

                gpa[j] = gpa[j+1];

                grade[j] = grade[j+1];

                for(int k=0; k<SUBJECTS; k++)
                {
                    marks[j][k] = marks[j+1][k];
                }
            }

            totalStudents--;

            cout << "\nStudent Deleted Successfully!\n";

            break;
        }
    }

    // If student not found
    if(found == false)
    {
        cout << "Student Not Found!\n";
    }
}


// ============================================================
//                 FUNCTION TO SHOW TOPPER
// ============================================================

void showTopper()
{
    cout << "\n================================================\n";
    cout << "                    TOPPER\n";
    cout << "================================================\n";

    // Check records
    if(totalStudents == 0)
    {
        cout << "No Records Found!\n";
        return;
    }

    int topper = 0;

    // Find highest GPA
    for(int i=1; i<totalStudents; i++)
    {
        if(gpa[i] > gpa[topper])
        {
            topper = i;
        }
    }

    // Display topper
    cout << "Student ID : "
         << studentID[topper]
         << endl;

    cout << "Student Name : "
         << studentName[topper]
         << endl;

    cout << "Average : "
         << averageMarks[topper]
         << endl;

    cout << "GPA : "
         << gpa[topper]
         << endl;

    cout << "Grade : "
         << grade[topper]
         << endl;
}


// ============================================================
//             FUNCTION FOR SUBJECT AVERAGES
// ============================================================

void subjectAverage()
{
    cout << "\n================================================\n";
    cout << "              SUBJECT AVERAGES\n";
    cout << "================================================\n";

    // Check records
    if(totalStudents == 0)
    {
        cout << "No Records Found!\n";
        return;
    }

    float pfTotal = 0;
    float aictTotal = 0;
    float calculusTotal = 0;

    // Calculate totals
    for(int i=0; i<totalStudents; i++)
    {
        pfTotal += marks[i][0];

        aictTotal += marks[i][1];

        calculusTotal += marks[i][2];
    }

    // Display averages
    cout << "Programming Fundamental Average : "
         << pfTotal / totalStudents
         << endl;

    cout << "AICT Average : "
         << aictTotal / totalStudents
         << endl;

    cout << "Calculus Average : "
         << calculusTotal / totalStudents
         << endl;
}


// ============================================================
//              FUNCTION FOR PASS / FAIL
// ============================================================

void passFailRatio()
{
    cout << "\n================================================\n";
    cout << "               PASS / FAIL RATIO\n";
    cout << "================================================\n";

    int pass = 0;
    int fail = 0;

    // Count pass and fail students
    for(int i=0; i<totalStudents; i++)
    {
        if(grade[i] == 'F')
            fail++;

        else
            pass++;
    }

    cout << "Pass Students : "
         << pass
         << endl;

    cout << "Fail Students : "
         << fail
         << endl;
}


// ============================================================
//               FUNCTION TO SAVE DATA
// ============================================================

void saveToFile()
{
    ofstream file("StudentData.txt");

    // Check file
    if(!file)
    {
        cout << "File Error!\n";
        return;
    }

    // Save total students
    file << totalStudents << endl;

    // Save all student records
    for(int i=0; i<totalStudents; i++)
    {
        file << studentID[i] << endl;

        file << studentName[i] << endl;

        for(int j=0; j<SUBJECTS; j++)
        {
            file << marks[i][j] << " ";
        }

        file << endl;

        file << averageMarks[i] << endl;

        file << gpa[i] << endl;

        file << grade[i] << endl;
    }

    file.close();

    cout << "\nData Saved Successfully!\n";
}


// ============================================================
//               FUNCTION TO LOAD DATA
// ============================================================

void loadFromFile()
{
    ifstream file("StudentData.txt");

    // Check file
    if(!file)
    {
        return;
    }

    // Load total students
    file >> totalStudents;

    file.ignore();

    // Load all records
    for(int i=0; i<totalStudents; i++)
    {
        file >> studentID[i];

        file.ignore();

        getline(file, studentName[i]);

        for(int j=0; j<SUBJECTS; j++)
        {
            file >> marks[i][j];
        }

        file >> averageMarks[i];

        file >> gpa[i];

        file >> grade[i];

        file.ignore();
    }

    file.close();
}


// ============================================================
//                    MENU FUNCTION
// ============================================================

void menu()
{
    cout << "\n================================================\n";
    cout << "          STUDENT MANAGEMENT SYSTEM\n";
    cout << "================================================\n";

    cout << "1.  Add Student\n";
    cout << "2.  Display Students\n";
    cout << "3.  Search Student\n";
    cout << "4.  Update Student\n";
    cout << "5.  Delete Student\n";
    cout << "6.  Show Topper\n";
    cout << "7.  Subject Average\n";
    cout << "8.  Pass / Fail Ratio\n";
    cout << "9.  Save Data\n";
    cout << "10. Load Data\n";
    cout << "0.  Exit\n";

    cout << "================================================\n";
}


// ============================================================
//                    MAIN FUNCTION
// ============================================================

int main()
{
    // Auto load data when program starts
    loadFromFile();

    int choice;

    do
    {
        // Display menu
        menu();

        cout << "Enter Your Choice: ";

        choice = inputInt();

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                showTopper();
                break;

            case 7:
                subjectAverage();
                break;

            case 8:
                passFailRatio();
                break;

            case 9:
                saveToFile();
                break;

            case 10:
                loadFromFile();
                cout << "\nData Loaded Successfully!\n";
                break;

            case 0:

                // Auto save before exit
                saveToFile();

                cout << "\nProgram Closed Successfully!\n";

                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    }while(choice != 0);

    return 0;
}