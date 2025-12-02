#include <iostream>
#include <vector>
using namespace std;

// Divide and Conquer function to find majority element
int majorityElementDC(vector<int>& nums, int low, int high) {
    // Base case: only one element
    if (low == high) return nums[low];

    int mid = (low + high) / 2;

    // Recurse on left and right halves
    int leftMajor = majorityElementDC(nums, low, mid);
    int rightMajor = majorityElementDC(nums, mid + 1, high);

    // If both halves agree
    if (leftMajor == rightMajor) return leftMajor;

    // Count occurrences of both candidates in current range
    int leftCount = 0, rightCount = 0;
    for (int i = low; i <= high; i++) {
        if (nums[i] == leftMajor) leftCount++;
        else if (nums[i] == rightMajor) rightCount++;
    }

    return (leftCount > rightCount) ? leftMajor : rightMajor;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> nums[i];

    int majority = majorityElementDC(nums, 0, n - 1);
    cout << "Majority element: " << majority << endl;

    return 0;
}
