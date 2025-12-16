#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct activity
{
    int start;
    int end;
};

// Sort activities by finish time
bool compare(activity &a, activity &b)
{
    return a.end < b.end;
}

void activitySelection(vector<activity> &acts)
{
    sort(acts.begin(), acts.end(), compare);

    cout << "\nSelected activities:\n";

    int i = 0;
    cout << "(" << acts[i].start << ", " << acts[i].end << ")\n";

    // Select remaining activities
    for (int j = 1; j < acts.size(); j++)
    {
        if (acts[j].start >= acts[i].end)
        {
            cout << "(" << acts[j].start << ", " << acts[j].end << ")\n";
            i = j;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the total number of activities: ";
    cin >> n;

    vector<activity> acts;

    for (int i = 0; i < n; i++)
    {
        activity a;
        cout << "Enter start and finish time of activity " << i + 1 << ": ";
        cin >> a.start >> a.end;
        acts.push_back(a);
    }

    activitySelection(acts);
    return 0;
}


//........................................
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
//..........................................................................
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
 struct item
 {
    int value;
    int weight;
 };

 bool compare(item &a,item b)
 {
    double r1= (double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
 }

double fractionalKNapsack(int w,vector<item>items)
{
    sort(items.begin(),items.end(),compare);
    double total_value=0.0;
    for(int i=0;i<items.size();i++)
    {
        if(w>=items[i].weight)
        {
            w-=items[i].weight;
            total_value+=items[i].value;
        }
        else
        {
            total_value+=items[i].value * ((double)w/items[i].weight);
        }
    }
}

int main()
{
    int n,w;
    cout<<"enter the number of item:";
    cin>>n;
    vector<item>items(n);
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value and weight of item:"<<i+1<<":";
        cin>>items[i].value>>items[i].weight;
    }
    cout<<"enter the knapsack capacity:";
    cin>>w;
    double maxvalue=fractionalKNapsack(w,items);

    cout<<"maximum value in knapsack: "<<maxvalue<<endl;

}