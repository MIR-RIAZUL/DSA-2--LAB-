#include<iostream>
using namespace std;


void change(int &x)
{
    x=x+5;
    cout<<"Value of x inside function: "<<x<<endl;
}
int main()
{
    int a=10;
    change(a);
    cout<<"Value of a after function call: "<<a<<endl;
}