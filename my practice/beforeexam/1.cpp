#include<iostream>
#include<algorithm>
#include<vector>

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
void validactivity(vector<activity>&acts)
{
    sort(acts.begin(),acts.end(),compare);
    int i=0;
    cout<<"("<<acts[i].start<<","<<acts[i].end<<")"<<endl;

    for(int j=1;j<acts.size();j++)
    {
        if(acts[j].start>=acts[i].end)
        {
            cout<<"("<<acts[j].start<<","<<acts[j].end<<")"<<endl;
            i=j;
        }
    }
}

int main()
{
    int n;
    cout<<"enter the total activity: ";
    cin>>n;
    activity a;
     vector<activity>acts;
     for(int i=0;i<n;i++)
{
    cout<<"enter thee start and end value of "<<i+1<<" :";
    cin>>a.start>>a.end;
    acts.push_back(a);

}

validactivity(acts);
return 0;

}