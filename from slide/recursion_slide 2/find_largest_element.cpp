#include<iostream>
#include<vector>
#include <climits>


using namespace std;

int largest(int arr[],int n)
{
    if(n<0) return INT_MIN;
    return max(arr[n],largest(arr,n-1));
}

int main()
{
    int a[]={23,45,65,345,56,87,56,4};

    int m= sizeof(a);

    cout<<m<<endl;


    int l=largest(a,sizeof(a)/sizeof(int)-1);

    cout<<"largets: "<<l<<endl;

}