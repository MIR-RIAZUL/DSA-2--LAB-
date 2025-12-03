#include <iostream>
using namespace std;

// returns index of the student with highest CGPA
int findTopper(const double cgpa[], int low, int high)
{
    if (low == high)
        return low;

    int mid = (low + high) / 2;

    int leftIndex  = findTopper(cgpa, low, mid);
    int rightIndex = findTopper(cgpa, mid + 1, high);

    return (cgpa[leftIndex] >= cgpa[rightIndex]) ? leftIndex : rightIndex;
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    string name[n];
    int id[n];
    double cgpa[n];

    cout << "\nEnter student details:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Student " << i + 1 << " name: ";
        cin >> name[i];
        cout << "Student " << i + 1 << " id: ";
        cin >> id[i];
        cout << "Student " << i + 1 << " cgpa: ";
        cin >> cgpa[i];
        cout << endl;
    }

    int topper = findTopper(cgpa, 0, n - 1);

    cout << "\n===== Top Student =====\n";
    cout << "Name: " << name[topper] << endl;
    cout << "ID:   " << id[topper] << endl;
    cout << "CGPA: " << cgpa[topper] << endl;

    return 0;
}
