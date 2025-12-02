#include <iostream>
#include <climits>
using namespace std;

// Function to find largest pair using divide and conquer
pair<int,int> largestPair(int arr[], int low, int high) {
    // Base case: only one element
    if (low == high) {
        return {arr[low], INT_MIN};
    }

    // Base case: two elements
    if (high == low + 1) {
        if (arr[low] > arr[high])
            return {arr[low], arr[high]};
        else
            return {arr[high], arr[low]};
    }

    // Divide
    int mid = (low + high) / 2;
    pair<int,int> left = largestPair(arr, low, mid);
    pair<int,int> right = largestPair(arr, mid + 1, high);

    // Combine: simple comparisons
    int first, second;

    // Find the largest
    first = max(left.first, right.first);

    // Find the second largest
    if (left.first == first) 
        second = max(left.second, right.first);
    else
        second = max(left.first, right.second);

    // Ensure second is smaller than first
    if (second > first) swap(first, second);

    return {first, second};
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    pair<int,int> result = largestPair(arr, 0, n - 1);
    cout << "Largest pair: " << result.first << " and " << result.second << endl;
    cout << "Sum of largest pair: " << result.first + result.second << endl;

    return 0;
}
