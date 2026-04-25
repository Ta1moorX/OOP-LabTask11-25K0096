#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main() {

    time_t now = time(0);
    char* timestamp = ctime(&now);

    string ts(timestamp);
    if (!ts.empty() && ts.back() == '\n') ts.pop_back();

    ofstream file("system_log.txt", ios::app);
    if (!file) { cout << "Error opening file!" << endl; return 1; }

    file << "System started at: " << ts << endl;
    file.close();

    cout << "Log entry added: System started at: " << ts << endl;
    return 0;
}