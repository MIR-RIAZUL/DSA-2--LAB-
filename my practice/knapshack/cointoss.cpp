#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>coinuseed(vector<int>coins,int amount)
{
    sort(coins.rbegin(),coins.rend());
    vector<int>result;
    int k=0;
    
    while (amount>0 && k<coins.size())
    {
        if(amount>=coins[k])
        {
        amount-=coins[k];
        result.push_back(coins[k]);
        }
        else
        {
        k++;
    }

    }
   
    
    return result;
}

int main()
{
    vector<int>coins={1,2,5,10,20,100,200,500,1000};
    int amount;
    cout<<"enter amount: ";
    cin>>amount;

    vector<int>coinused=coinuseed(coins,amount);

    int count=0;
    cout<<"coin used :";
    for(int c:coinused)
    {
        cout<<c<<" ";
        count++;
    }
    cout<<endl;
    cout<<"total coin used: "<<count<<endl;
}