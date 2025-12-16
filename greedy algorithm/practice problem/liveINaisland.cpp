#include <iostream>
using namespace std;

int main() {
    int S, N, M;
    cin >> S >> N >> M;

    int requiredFood = S * M;
    int shopOpenDays = S - S / 7;

    // Check if survival is possible
    if (requiredFood > shopOpenDays * N) {
        cout << -1 << endl; // Impossible
    } else {
        // Greedy: buy maximum N units each day
        int minDays = (requiredFood + N - 1) / N; // ceil division
        cout << minDays << endl;
    }

    return 0;
}
