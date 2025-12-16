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
