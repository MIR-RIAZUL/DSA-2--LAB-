#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct activity
{
    int s, f, idx;
};

bool compareactivity(activity &a, activity &b)
{
    return a.f < b.f;
}

void printMaxActivity(vector<activity> acts)
{
    if (acts.empty())
        return;
    sort(acts.begin(), acts.end(), compareactivity);
    cout << "following activity are selected:(index: (start, finish))" << endl;
    int last_finsh = acts[0].f;
    cout << acts[0].idx << " : (" << acts[0].s << "," << acts[0].f << ")" << endl;

    for (int i = 1; i < acts.size(); i++)
    {
        if (acts[i].s > last_finsh)
        {
            cout << acts[i].idx << ": (" << acts[i].s << "," << acts[i].f << ")" << endl;
            last_finsh = acts[i].f;
        }
    }
}

int main()
{
    int n, s, f;
    cout << "enter the total activity:";
    cin >> n;
    vector<activity> acts;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the start and finish time of activity:";
        cin >> s >> f;
        acts.push_back(activity{s, f, i});
    }
    printMaxActivity(acts);
}