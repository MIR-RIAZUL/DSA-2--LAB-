#include <iostream>
#include <climits>
using namespace std;

struct Result {
    int sum;
    int start;
    int end;
};

// Function to compute max crossing subarray
Result maxCrossing(int a[], int low, int mid, int high) {
    int leftSum = INT_MIN, sum = 0, maxLeft = mid;

    for (int i = mid; i >= low; i--) {
        sum += a[i];
        if (sum > leftSum) {
            leftSum = sum;
            maxLeft = i;
        }
    }

    int rightSum = INT_MIN;
    sum = 0;
    int maxRight = mid + 1;

    for (int j = mid + 1; j <= high; j++) {
        sum += a[j];
        if (sum > rightSum) {
            rightSum = sum;
            maxRight = j;
        }
    }

    Result r;
    r.sum = leftSum + rightSum;
    r.start = maxLeft;
    r.end = maxRight;
    return r;
}

Result maxSubarray(int a[], int low, int high) {
    if (low == high) {
        return {a[low], low, high};
    }

    int mid = (low + high) / 2;

    Result left = maxSubarray(a, low, mid);
    Result right = maxSubarray(a, mid + 1, high);
    Result cross = maxCrossing(a, low, mid, high);

    if (left.sum >= right.sum && left.sum >= cross.sum)
        return left;

    if (right.sum >= left.sum && right.sum >= cross.sum)
        return right;

    return cross;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int a[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Result ans = maxSubarray(a, 0, n - 1);

    cout << "\nMaximum Subarray Sum = " << ans.sum << endl;
    cout << "Start index = " << ans.start << endl;
    cout << "End index = " << ans.end << endl;

    cout << "Subarray: ";
    for (int i = ans.start; i <= ans.end; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
