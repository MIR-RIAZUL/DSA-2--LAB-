#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> greedyCoinChange(vector<int>coins,int amount)
{
    sort(coins.rbegin(),coins.rend());
    vector<int>result;
    int k=0;
    while(amount>0 && k <coins.size())
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
    vector<int>coins={1,2,5,10,20,50,100,500,1000};
    int amount;
    cout<<"enetr amount:";
    cin>>amount;

    vector<int>usedCoin=greedyCoinChange(coins,amount);

    cout<<"coin used: ";
    int count=0;
    for(int c:usedCoin)
    {
        cout<<c<<" ";
           count++;
    }
    cout<<endl;
    cout<<"total coin count: "<<count<<endl;

}