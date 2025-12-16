#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct item
{
    int value;
    int weight;
};

bool compare(item &a,item &b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}

double knapsack(vector<item>items,int w)
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
        total_value+=items[i].value *((double)w/items[i].weight);
        }
    }
    return total_value;
}
int main()
{
    int n,w;

    cout<<"enter the number of item:";
    cin>>n;
    vector<item>items(n);
    for(int i=0;i<n;i++)
    {
        cout<<"enter the value and weight of "<<i+1<<":";
        cin>>items[i].value>>items[i].weight;
    }
    cout<<"enter the total knapsack capacity:";
    cin>>w;
    double maxvalue=knapsack(items,w);

    cout<<"max value by knapsack is :"<<maxvalue<<endl;
}