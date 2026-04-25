#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    char  name[50];
    int   id;
    float gpa;
};

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;
    cin.ignore();

    Student* students = new Student[n];

    ofstream wfile("students.dat", ios::binary);
    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i+1 << endl;
        cout << "Name: "; cin.getline(students[i].name, 50);
        cout << "ID:   "; cin >> students[i].id;
        cout << "GPA:  "; cin >> students[i].gpa;
        cin.ignore();
        wfile.write(reinterpret_cast<char*>(&students[i]), sizeof(Student));
    }
    wfile.close();
    cout << "\nData written to students.dat" << endl;


    ifstream rfile("students.dat", ios::binary);
    Student s;
    cout << "\n=== Student Records ===" << endl;
    while (rfile.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        cout << "Name: " << s.name
             << " | ID: " << s.id
             << " | GPA: " << s.gpa << endl;
    }
    rfile.close();

    delete[] students;
    return 0;
}