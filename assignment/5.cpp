#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;
struct activity
{
    int start;
    int end;

};

bool compare(activity &a,activity &b)
{
    return a.end<b.end;
}

void greedyactivity(vector<activity>&v, int n)
{
    sort( v.begin(), v.end(),compare);

    int i=0;
    cout<<"selected activity is :";
    cout<<"("<<v[i].start<<" "<<v[i].end<<")"<<endl;
    int count=1;

    for(int j=1;j<n;j++)
    {
        if(v[j].start>=v[i].end)
        {
            cout<<"("<<v[j].start<<" "<<v[j].end<<")"<<endl;
            i = j;
            count++;
        }
    }
    cout<<"total activity: "<<count<<endl;
}

int main()
{
    cout<<"enter the activity:";
    int n;
    cin>>n;
    vector<activity>v(n);

    cout<<"enter the start and end time:";

    for(int i=0;i<n;i++)
    {
        cin>>v[i].start>>v[i].end;
    }

    greedyactivity(v,n);
    return 0;

}