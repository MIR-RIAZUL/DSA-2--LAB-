#include <iostream>
using namespace std;

pair<int, int> FindMaxMin(int A[], int low, int high) {
    if (low == high) {
        return { A[low], A[low] };
    }
    else if (high == low + 1) {
        if (A[low] < A[high])
            return { A[high], A[low] };
        else
            return { A[low], A[high] };
    }
    else {
        int mid = (low + high) / 2;

        pair<int, int> left = FindMaxMin(A, low, mid);
        pair<int, int> right = FindMaxMin(A, mid + 1, high);

        int finalMax = max(left.first, right.first);
        int finalMin = min(left.second, right.second);

        return { finalMax, finalMin };
    }
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    pair<int, int> result = FindMaxMin(arr, 0, n - 1);

    cout << "Maximum value = " << result.first << endl;
    cout << "Minimum value = " << result.second << endl;

    return 0;
}