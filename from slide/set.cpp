#include<iostream>
#include<set>

using namespace std;

int main()
{

    set<int>s;
    s.insert(10);
    s.insert(20);
    s.insert(10);
    s.insert(5);

    for(int val: s)
    {
        cout<<val<<" ";
    }
    cout<<endl;

    cout<< *s.begin() <<endl;

    cout<<s.size()<<endl;

    // we can do multiple of operation with set ...
}
