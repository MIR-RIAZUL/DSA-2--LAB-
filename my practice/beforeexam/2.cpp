#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>greedy(vector<int>&coins,int amount)
{
    vector<int>result;
    sort(coins.rbegin(),coins.rend());
    int k=0;
    while(amount>0 &&k<coins.size())
    {
        if(amount>=coins[k])
        {
            result.push_back(coins[k]);
            amount-=coins[k];
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
    vector<int>coins={1,2,5,10,20,50,100,200,500};
    int amount;

    cout<<"enter the amount :";
    cin>>amount;
    vector<int>usedcoin=greedy(coins,amount);

    int count=0;
    cout<<"the coin is:";
    for(int c:usedcoin)
    {
        cout<<c<<" ";
        count++;
    }
    cout<<endl;
    cout<<"the total coin used : "<<count<<endl;
    

}