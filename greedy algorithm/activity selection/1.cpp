#include <bits/stdc++.h>
using namespace std;

struct activity {
    int s;
    int f;
    int idx;
};

bool compareActivity(const activity &a, const activity &b) {
    return a.f < b.f;
}

void printMaxActivities(vector<activity> &acts) {
    if (acts.empty()) return;

    sort(acts.begin(), acts.end(), compareActivity);

    cout << "Following activities are selected (original_index: (start,finish))\n";

    int last_finish = acts[0].f;
    cout << acts[0].idx << ": (" << acts[0].s << "," << acts[0].f << ")\n";

    for (int i = 1; i < acts.size(); i++) {
        if (acts[i].s >= last_finish) {
            cout << acts[i].idx << ": (" << acts[i].s << "," << acts[i].f << ")\n";
            last_finish = acts[i].f;
        }
    }
}

int main() {
  //s = { 1, 3, 0, 5, 8, 5 };
  //f = { 2, 4, 6, 7, 9, 9 };
    int n,s,f;

    cin>>n;

    vector<activity> acts;
    for (int i = 0; i < n; ++i) {
        cout<<"Enter The start and finish time of activity: "<<i<<endl;
        cin>>s>>f;
        acts.push_back(activity{s, f, i});

}

    printMaxActivities(acts);
    return 0;
}
