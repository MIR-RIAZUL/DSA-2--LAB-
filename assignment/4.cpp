#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
     cout<<"enter the student number:";
    cin >> n ;

    cout<<"enter the number of room:";
    cin>>m;

    
    vector<int> students(n);
    vector<int> rooms(m);
    cout<<"enter the student recourment:";
    
    for (int i = 0; i < n; i++) cin >> students[i];

    cout<<"enter the room capacity:";
    for (int i = 0; i < m; i++) cin >> rooms[i];
    
    sort(students.begin(), students.end()); 
    sort(rooms.begin(), rooms.end());      
    
    int assigned = 0;
    int j = 0; 
    
    for (int i = 0; i < n; i++) {
        
        while (j < m && rooms[j] < students[i]) {
            j++;
        }
        if (j < m) { 
            assigned++;
            j++; 
        }
    }
    
    cout << assigned << endl;
    return 0;
}
