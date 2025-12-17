//1..polucron
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int total = 0;

    while (a >= 1 && b >= 1) {
        if (a >= b && a >= 2) {
            // Craft shovel
            a -= 2;
            b -= 1;
        } 
        else if (b > a && b >= 2) {
            // Craft sword
            a -= 1;
            b -= 2;
        } 
        else {
            break; // Cannot craft any more tools
        }
        total++;
    }

    cout << total << endl;
    return 0;
}
//..................................................................................
//2.livein island
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    int requiredFood = S * M;
    
    // Step 1: Generate shop-open days
    vector<int> shopDays;
    for (int day = 1; day <= S; day++) {
        if (day % 7 != 0) { // shop closed on Sunday
            shopDays.push_back(day);
        }
    }

    int maxFood = shopDays.size() * N;
    if (requiredFood > maxFood) {
        cout << -1 << endl; // Impossible to survive
        return 0;
    }

    // Step 2: Sort shop days (greedy earliest first)
    sort(shopDays.begin(), shopDays.end());

    int totalBought = 0;
    int daysUsed = 0;

    // Step 3: Greedy buy maximum food each day
    for (int day : shopDays) {
        if (totalBought >= requiredFood) break;
        totalBought += N;
        daysUsed++;
    }

    cout << daysUsed << endl;

    return 0;
}





#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int S, N, M;

    // input
    cout << "Enter S, N, M: ";
    cin >> S >> N >> M;

    // total food required
    int totalFood = S * M;

    // check possibility
    if (6 * N < 7 * M)
    {
        cout << "Not possible to survive\n";
        return 0;
    }

    // minimum days to buy food
    int days = ceil((double)totalFood / N);

    cout << days << endl;

    return 0;
}


//............................................................................
//3.thif
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    double weight;
    double cost;
    double unitPrice() const { return cost / weight; }
};

int main() {
    vector<Item> items = {
        {"Rice", 12, 840},
        {"Salt", 10, 870},
        {"Saffron", 8, 2000},
        {"Sugar", 5, 500}
    };

    double thiefCapacity = 9.0;
    vector<vector<pair<string,double>>> thiefItems; // items each thief carries

    // Sort items by unit price descending
    sort(items.begin(), items.end(), [](Item a, Item b){
        return a.unitPrice() > b.unitPrice();
    });

    while(true) {
        double remainingCap = thiefCapacity;
        vector<pair<string,double>> currentThief;

        bool hasItems = false;
        for(auto &item : items) {
            if(item.weight > 0 && remainingCap > 0) {
                hasItems = true;
                double take = min(item.weight, remainingCap);
                currentThief.push_back({item.name, take});
                item.weight -= take;
                remainingCap -= take;
            }
        }

        if(!hasItems) break; // All items taken

        thiefItems.push_back(currentThief);
    }

    // Print results
    cout << "Number of thieves needed: " << thiefItems.size() << "\n\n";

    for(int i=0; i<thiefItems.size(); i++) {
        cout << "Thief " << i+1 << " carries:\n";
        for(auto &p : thiefItems[i]) {
            cout << "  " << p.first << " -> " << p.second << " kg\n";
        }
        cout << endl;
    }

    return 0;
}





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


//...........................
//4.maxtrain
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Train {
    int arrival;
    int departure;
};

// Compare trains by earliest departure
bool compare(Train a, Train b) {
    return a.departure < b.departure;
}

int main() {
    vector<Train> trains = {
        {8, 12}, {6, 9}, {11, 14}, {2, 7}, {1, 7}, {12, 20}, {7, 12}, {13, 19}
    };

    // Step 1: Sort by departure
    sort(trains.begin(), trains.end(), compare);

    vector<Train> selected;
    int lastDeparture = -1;

    // Step 2: Greedily select trains
    for(auto t : trains) {
        if(t.arrival >= lastDeparture + 1) { // 1-unit gap
            selected.push_back(t);
            lastDeparture = t.departure;
        }
    }

    // Step 3: Print selected trains
    cout << "Selected trains (arrival, departure):\n";
    for(auto t : selected) {
        cout << "[" << t.arrival << ", " << t.departure << ")\n";
    }

    cout << "Maximum number of trains: " << selected.size() << endl;

    return 0;
}
//...........
//5.remove nmr
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minMoves(vector<int> A) {
    sort(A.begin(), A.end());
    int moves = 0;
    int n = A.size();
    vector<bool> used(n, false);

    for(int i = 0; i < n; i++) {
        if(used[i]) continue;

        int X = A[i] + 1; // pick X as middle of current number
        used[i] = true;
        moves++;

        // Try to remove one more number in this move
        for(int j = i + 1; j < n; j++) {
            if(!used[j] && abs(A[j] - X) <= 1) {
                used[j] = true;
                break; // only remove one extra number
            }
        }
    }

    return moves;
}

int main() {
    vector<int> A = {1, 3, 5, 9};
    cout << "Minimum moves: " << minMoves(A) << endl;
    return 0;
}

///......................................................................
//6.arraival vs depeatal

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Train {
    int arrival;
    int departure;
};

// Compare trains by earliest departure
bool compare(Train a, Train b) {
    return a.departure < b.departure;
}

int main() {
    vector<Train> trains = {
        {1000, 1030},
        {840, 1030},
        {850, 1040},
        {1700, 2000},
        {800, 835},
        {1300, 1800},
        {1500, 1650},
        {1200, 1380}
    };

    // Step 1: Sort by departure
    sort(trains.begin(), trains.end(), compare);

    vector<Train> selected;
    int lastDeparture = -1;

    // Step 2: Select trains greedily
    for (auto t : trains) {
        if (t.arrival >= lastDeparture + 10) { // 10-minute safety
            selected.push_back(t);
            lastDeparture = t.departure;
        }
    }

    // Step 3: Print selected trains
    cout << "Selected trains (arrival, departure):\n";
    for (auto t : selected) {
        cout << "[" << t.arrival << ", " << t.departure << "]\n";
    }

    cout << "Maximum number of trains: " << selected.size() << endl;

    return 0;
}
