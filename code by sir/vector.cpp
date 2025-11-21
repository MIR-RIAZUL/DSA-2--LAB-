#include<iostream>
#include<vector>

using namespace std;


void rfact(int i,int n,vector<int>& result, int cf)
{
    if(i>n) return;
    cf=cf*i;
    result[i-1]=cf;
    rfact(i+1,n,result,cf);

}
vector<int>fact(int n)
{
    vector<int>result(n);
    rfact(1,n,result,1);
    return result;
}

int  main()
{

    int n;
    cout<<"enter the number:";
    cin>>n;

    vector<int>f=fact(n);

    for(auto i:f)
    {
        cout<<i<<endl;
    }

}