#include<iostream>
#include<algorithm>
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

void activitySelection(activity arr[],int n)
{
    sort(arr,arr+n,compare);
    cout<<"selected activity:"<<endl;
    int i=0;

    cout<<"(" << arr[i].start<<","<<arr[i].end<<")";

    //select remaing activities
    for(int j=1;j<n;j++)
    {
        if(arr[j].start>=arr[i].end)
        {
            cout<<"("<<arr[j].start<<","<<arr[j].end<<")"<<endl;
            i=j;
        }
    }

}


int main()
{
    cout<<"enter the total activity:";
    int n;
    cin>>n;
     activity arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"enter the start and finish time of activity:"<<i+1<<":";
        cin>>arr[i].start>>arr[i].end;
    }
    activitySelection(arr,n);
}