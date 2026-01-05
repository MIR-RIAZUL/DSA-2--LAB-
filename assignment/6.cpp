#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int>a(n);
    for(int i =0;i<n;i++)
        cin>>a[i];

    sort(a.begin(),a.end());

    int m = a[n/2];
    int cost=0;

    for(int i=0;i<n;i++)
        cost+=abs(a[i] -m);

    cout <<cost<<endl;
    return 0;
}
