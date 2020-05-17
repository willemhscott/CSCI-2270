#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Student {
    int idNumber;
    string name;
    string dept;
};

int main(int argc, char *argv[]) {
    if (argc < 1) {
        cout << "Invalid file name!" << endl;
        return 1;
    }

    ifstream dataFile;
    dataFile.open(argv[1]);

    if (!dataFile.is_open()) {
        cout << "Invalid file name!" << endl;
        return 1;
    }
    int size = 4;
    Student *sarr = new Student[size];
    string line;
    int i = 0;
    while (getline(dataFile, line)) {
        if (i > size) {
            break;
        }
        stringstream ss(line);

        string name, dept, id;

        getline(ss, name, ',');
        getline(ss, dept, ',');
        getline(ss, id);

        name.erase(std::remove_if(name.begin(), name.end(), ::isspace), name.end());
        dept.erase(std::remove_if(dept.begin(), dept.end(), ::isspace), dept.end());
        id.erase(std::remove_if(id.begin(), id.end(), ::isspace), id.end());

        sarr[i].name = name;
        sarr[i].dept = dept;
        sarr[i].idNumber = stoi(id);

        i++;
    }
    size = i;
    dataFile.close();

    for (int j = 0; j < size; j++) {
        Student student = sarr[j];
        cout << student.name << ": " << student.semester << " " << student.year << endl;
    }

    return 0;
}