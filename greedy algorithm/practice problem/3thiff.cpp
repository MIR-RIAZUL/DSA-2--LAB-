#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct item
{
    int value;
    int weight;
};

bool compare(item &a, item &b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// function in YOUR style
double fractionalKNapsack(int w, vector<item> &items)
{
    sort(items.begin(), items.end(), compare);

    double total_value = 0.0;

    for (int i = 0; i < items.size() && w > 0; )
    {
        if (items[i].weight <= w)
        {
            w -= items[i].weight;
            total_value += items[i].value;

            // remove item after stealing
            items.erase(items.begin() + i);
        }
        else
        {
            total_value += items[i].value * ((double)w / items[i].weight);

            items[i].value -= items[i].value * ((double)w / items[i].weight);
            items[i].weight -= w;
            w = 0;
        }
    }
    return total_value;
}

int main()
{
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<item> items(n);

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    int thief = 1;

    while (!items.empty())
    {
        cout << "\nThief " << thief << ":\n";

        double profit = fractionalKNapsack(capacity, items);

        cout << "Profit = " << profit << " taka\n";
        thief++;
    }

    cout << "\nTotal thieves needed = " << thief - 1 << endl;

    return 0;
}
