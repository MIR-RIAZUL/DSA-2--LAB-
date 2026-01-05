#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> h;

int solve(int i)
{
   
    if(i == 0)
        return 0;
    if(i == 1)
        return abs(h[1] - h[0]);

    int cost1=solve(i - 1)+abs(h[i]-h[i-1]);
    int cost2=solve(i - 2)+abs(h[i]-h[i-2]);

    return min(cost1,cost2);
}

int main()
{
    int n;

    cout<<"enter the array size:";
    cin>>n;

    h.resize(n);
    cout<<"enter the array:";
    for(int i=0;i<n;i++)
        cin>>h[i];

    cout << solve(n - 1) << endl;
    return 0;
}
