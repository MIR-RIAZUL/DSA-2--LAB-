#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>greedycoinchange(vector<int>coins, int amount){

   sort(coins.rbegin(),coins.rend());
       vector<int> result;
       int k=0;
       while(amount>0 && k<coins.size()){
        if(amount>=coins[k]){
            result.push_back(coins[k]);
            amount-=coins[k];

        }else{
        k++;
        }
       }

return result;

}
int main()
{
    vector<int>coins={1,2,5,10,20,50,100,500,1000};
    int amount;
    cout<<"Enter amount: ";
    cin>>amount;

    vector<int>usedCoin= greedycoinchange(coins,amount);
    cout<<"Coins Used ";
    int count=0;
    for(int c: usedCoin){
        cout<<c<<"  ";
            count++;
    }
    cout<<endl;
    cout<<"Total coin count: "<<count<<endl;




    return 0;




}
