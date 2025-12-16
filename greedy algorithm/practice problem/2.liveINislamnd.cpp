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
