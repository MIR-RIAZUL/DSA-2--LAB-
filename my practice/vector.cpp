#include<iostream>
#include<vector>

using namespace std;
void fact(int i,int n,vector<int>&v,int cf)
{
    if(i>n)return;
    cf=cf*i;
    v.push_back(cf);
    fact(i+1,n,v,cf);

}
int main()
{
    cout<<"enter the number: ";
    int n;
     cin>>n;

     vector<int>v; 
     fact(1,n,v,1);
     for(int val:v)
     {
        cout<<val<<endl;
     }


}