#include <iostream>
#include <string>
using namespace std;

struct student
{
    string name;
    int rollNo;
    float marks;
};

const int MAX = 100;
;
student students[MAX];
int totalStudents = 0;

void addStudent()
{
    if (totalStudents < MAX)
    {
        cout << "Enter Roll No: ";
        cin >> students[totalStudents].rollNo;
        cin.ignore();
        cout << "Enter name: ";
        getline(cin, students[totalStudents].name);
        cout << "Enter marks: ";
        cin >> students[totalStudents].marks;
        totalStudents++;
        cout << "Student added successfully!\n";
    }
    else
    {
        cout << "Student limit reached\n";
    }
}

void displayStudents()
{
    if (totalStudents == 0)
    {
        cout << "No record found.\n";
        return;
    }
    cout << "\n--- Student Records ---\n";
    for (int i = 0; i < totalStudents; i++)
    {
        cout << "Roll No: " << students[i].rollNo << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Marks: " << students[i].marks << "\n";
        cout << "----------------------\n";
    }
}

void searchStudent()
{
    int roll;
    cout << "Enter Roll No to search: ";
    cin >> roll;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            cout << "Record Found:\n";
            cout << "Name: " << students[i].name << ", Marks: " << students[i].marks << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent()
{
    int roll;
    cout << "Enter Roll No to delete: ";
    cin >> roll;

    for (int i = 0; i < totalStudents; i++)
    {
        if (students[i].rollNo == roll)
        {
            for (int j = i; j < totalStudents - 1; j++)
            {
                students[j] = students[j + 1];
            }
            totalStudents--;
            cout << "Student record updated.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Student Record System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display all Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
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
            deleteStudent();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid Choice.\n";
        }
    } while (choice != 5);
    return 0;
}