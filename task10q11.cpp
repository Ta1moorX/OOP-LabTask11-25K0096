#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

    ofstream create("article.txt");
    create << "Hello, World! This is a test." << endl;
    create << "C++ file handling is powerful." << endl;
    create << "It supports read, write, and seek operations!" << endl;
    create.close();

    ifstream file("article.txt");
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    int totalChars = 0, totalWords = 0, totalLines = 0, totalPunct = 0;
    string line;
    string punctMarks = ".,!?;:'\"()-";

    while (getline(file, line)) {
        totalLines++;
        totalChars += line.length();

        bool inWord = false;
        for (char ch : line) {
            if (ch != ' ' && ch != '\t') {
                if (!inWord) { totalWords++; inWord = true; }
            } else {
                inWord = false;
            }
            if (punctMarks.find(ch) != string::npos)
                totalPunct++;
        }
    }
    file.close();

    ofstream report("report.txt");
    report << "====== File Analysis Report ======" << endl;
    report << "Total Characters:      " << totalChars << endl;
    report << "Total Words:           " << totalWords << endl;
    report << "Total Lines:           " << totalLines << endl;
    report << "Total Punctuation:     " << totalPunct << endl;
    report.close();

    ifstream show("report.txt");
    string r;
    while (getline(show, r)) cout << r << endl;
    show.close();

    return 0;
}