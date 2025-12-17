#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct activity {
    int start;
    int end;
};

// Sort activities by finish time
 bool compare(activity &a, activity &b) {
     return a.end < b.end;
 }

void activitySelection(vector<activity> &acts) {
    sort(acts.begin(), acts.end(),compare);

    cout << "\nSelected activities:\n";

    int i = 0;
    cout << "(" << acts[i].start << ", " << acts[i].end << ")\n";

    // Select remaining activities
    for (int j = 1; j < acts.size(); j++) {
        if (acts[j].start >= acts[i].end+10) {
            cout << "(" << acts[j].start << ", " << acts[j].end << ")\n";
            i = j;
        }
    }
}

int main() {
    int n;
    cout << "Enter the total number of activities: ";
    cin >> n;

    vector<activity> acts;

    for (int i = 0; i < n; i++) {
        activity a;
        cout << "Enter start and finish time of activity " << i + 1 << ": ";
        cin >> a.start >> a.end;
        acts.push_back(a);
    }

    activitySelection(acts);
    return 0;
}
