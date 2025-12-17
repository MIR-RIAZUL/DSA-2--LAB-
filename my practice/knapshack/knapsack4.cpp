#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

struct item
{
    string name;
    double value;
    double weight;
};

// compare by value/weight ratio
bool compare(item &a, item &b)
{
    return (a.value / a.weight) > (b.value / b.weight);
}

int main()
{
    // given items
    vector<item> items = {
        {"Rice", 840, 12},
        {"Salt", 870, 10},
        {"Saffron", 2000, 8},
        {"Sugar", 500, 5}
    };

    double capacity = 9.0; // knapsack capacity per thief

    // sort items by greedy ratio
    sort(items.begin(), items.end(), compare);

    int thief = 1;

    cout << fixed << setprecision(2);

    while (!items.empty())
    {
        double w = capacity;
        double profit = 0;

        cout << "\nThief " << thief << " carries:\n";

        for (int i = 0; i < items.size() && w > 0; )
        {
            if (items[i].weight <= w)
            {
                // take full item
                cout << "  " << items[i].weight << " kg " << items[i].name << endl;

                w -= items[i].weight;
                profit += items[i].value;

                // remove item
                items.erase(items.begin() + i);
            }
            else
            {
                // take fraction
                double frac = w;
                double val = items[i].value * (frac / items[i].weight);

                cout << "  " << frac << " kg " << items[i].name << endl;

                items[i].weight -= frac;
                items[i].value -= val;

                profit += val;
                w = 0;
            }
        }

        cout << "Profit of Thief " << thief << " = " << profit << " taka\n";
        thief++;
    }

    cout << "\nTotal thieves needed = " << thief - 1 << endl;

    return 0;
}
