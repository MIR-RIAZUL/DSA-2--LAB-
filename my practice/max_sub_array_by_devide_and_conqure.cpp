#include <iostream>
#include <climits>
using namespace std;

// maxCrosssum calculates max sum crossing mid and updates start/end indices
int maxCrosssum(int a[], int low, int mid, int high, int &crossStart, int &crossEnd)
{
    int leftsum = INT_MIN;
    int sum = 0;
    int maxLeft = mid;

    for (int i = mid; i >= low; i--)
    {
        sum += a[i];
        if (sum > leftsum)
        {
            leftsum = sum;
            maxLeft = i;
        }
    }

    int rightsum = INT_MIN;
    sum = 0;
    int maxRight = mid + 1;

    for (int j = mid + 1; j <= high; j++)
    {
        sum += a[j];
        if (sum > rightsum)
        {
            rightsum = sum;
            maxRight = j;
        }
    }

    crossStart = maxLeft;
    crossEnd = maxRight;
    return leftsum + rightsum;
}

// maxsubarray calculates max sum and updates start/end indices
int maxsubarray(int a[], int low, int high, int &maxStart, int &maxEnd)
{
    if (low == high)
    {
        maxStart = low;
        maxEnd = high;
        return a[low];
    }

    int mid = (low + high) / 2;

    int leftStart, leftEnd, rightStart, rightEnd, crossStart, crossEnd;

    int leftsum = maxsubarray(a, low, mid, leftStart, leftEnd);
    int rightsum = maxsubarray(a, mid + 1, high, rightStart, rightEnd);
    int crosssum = maxCrosssum(a, low, mid, high, crossStart, crossEnd);

    if (leftsum >= rightsum && leftsum >= crosssum)
    {
        maxStart = leftStart;
        maxEnd = leftEnd;
        return leftsum;
    }
    else if (rightsum >= leftsum && rightsum >= crosssum)
    {
        maxStart = rightStart;
        maxEnd = rightEnd;
        return rightsum;
    }
    else
    {
        maxStart = crossStart;
        maxEnd = crossEnd;
        return crosssum;
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int a[n];
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int maxStart, maxEnd;
    int maxsum = maxsubarray(a, 0, n - 1, maxStart, maxEnd);

    cout << "Maximum subarray sum = " << maxsum << endl;
    cout << "Subarray elements: ";
    for (int i = maxStart; i <= maxEnd; i++)
        cout << a[i] << " ";
    cout << endl;

    return 0;
}
