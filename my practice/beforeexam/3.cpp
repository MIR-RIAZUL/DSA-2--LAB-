#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct item
{
    int value;
    int weight;
};

bool compare(item &a, item &b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return r1>r2;
}

double knapsack(vector<item>&items,int w)
{
    sort(items.begin(),items.end(),compare);

    double total_value=0;
    
    for(int i=0;i<items.size();i++)
    {
        if(w>=items[i].weight)
        {
            total_value+=items[i].value;
            w-=items[i].weight;
        }
        else
        {
            total_value+=items[i].value *((double)w/items[i].weight);
            break;
        }

    }
    return total_value;
}

int main()
{
    int n;
    cout<<"enter the number of item :";
    cin>>n;
    vector<item>items(n);

    for(int i=0;i<n;i++)
    {
        cout<<"enter the value and weight: ";
        cin>>items[i].value>>items[i].weight;
    }
    cout<<"entr the total capacity:";
    int w;
    cin>>w;
    double maxval=knapsack(items,w);
    cout<<"total value is :"<<maxval<<endl;
    return 0;

}