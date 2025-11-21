#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> grade;
    int n;

    cout << "How many students? ";
    cin >> n;

    string name;
    int marks;

    for (int i = 0; i < n; i++) {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter marks for " << name << ": ";
        cin >> marks;

        grade[name] = marks;
    }

    cout << "\nStudent Grades:\n";
    for (auto i = grade.begin(); i != grade.end(); i++) {
        cout << i->first << " : " << i->second << endl;
    }


}
