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
