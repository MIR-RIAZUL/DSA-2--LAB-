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
