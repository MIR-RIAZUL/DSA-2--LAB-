#include <iostream>
#include <algorithm>
using namespace std;

struct item
{
    int value;
    int weight;
};

// sort by value/weight ratio
bool compare(item a, item b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

int main()
{
    // Items: Rice, Salt, Saffron, Sugar
    item items[4] = {
        {840, 12},
        {870, 10},
        {2000, 8},
        {500, 5}
    };

    int n = 4;
    int capacity = 9;
    int thief = 1;

    // sort items once
    sort(items, items + n, compare);

    while (n > 0)
    {
        int w = capacity;
        double profit = 0;

        cout << "\nThief " << thief << " takes:\n";

        for (int i = 0; i < n && w > 0; i++)
        {
            if (items[i].weight <= w)
            {
                cout << items[i].weight << " kg item (value = "
                     << items[i].value << ")\n";

                w -= items[i].weight;
                profit += items[i].value;

                // remove item by shifting
                for (int j = i; j < n - 1; j++)
                    items[j] = items[j + 1];

                n--;
                i--;
            }
            else
            {
                double fracValue = items[i].value * ((double)w / items[i].weight);

                cout << w << " kg item (value = "
                     << fracValue << ")\n";

                profit += fracValue;
                items[i].weight -= w;
                items[i].value -= fracValue;
                w = 0;
            }
        }

        cout << "Profit of Thief " << thief << " = " << profit << " taka\n";
        thief++;
    }

    cout << "\nTotal thieves needed = " << thief - 1 << endl;

    return 0;
}
