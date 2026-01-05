#include<iostream>
#include <algorithm>
#include <climits>

using namespace std;


int maxcrossSum(int arr[],int l,int m,int r)
{
    int sum=0;
    int leftsum=INT_MIN;
    for( int i=m;i>=l;i--)
    {
        sum=sum+arr[i];
        leftsum=max(leftsum,sum);
    }

       sum=0;
    int rightsum=INT_MIN;
    for( int i=m+1;i<=r;i++)
    {
        sum=sum+arr[i];
        rightsum=max(rightsum,sum);
    }
    return leftsum+rightsum;
}


int maxsubarray(int arr[],int l,int r)
{
    if(l==r)
    {
        return arr[l];
    }
    int m=(l+r)/2;
    return max(
        {
            maxsubarray(arr,l,m),
            maxsubarray(arr,m+1,r),
            maxcrossSum(arr,l,m,r)

        }
    );

}

int main()
{
    cout<<"enter the array size:";
    int n;
    cin>>n;
    int arr[n];

    cout<<"enter the array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int v=maxsubarray(arr,0,n-1);

    cout<<v<<endl;

}
