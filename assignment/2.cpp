#include<iostream>

using namespace std;


int main()
{
    cout<<"enter the size of array:";

    int n;
    cin>>n;
    cout<<endl;
    int array[n];
    cout<<"enter the array:";

    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }

    cout<<endl;
    cout<<"the number of inversion: ";
    int count=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(array[i]>array[j])
            {
                count++;
            }
        }
    }
    cout<<count<<endl;

    
}