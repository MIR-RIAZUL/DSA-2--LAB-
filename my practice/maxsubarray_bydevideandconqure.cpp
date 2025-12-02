#include <iostream>
#include <climits>

using namespace std;

int maxCrosssum(int a[], int low, int mid, int high)
{
    int leftsum = INT_MIN;
    int sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum = sum + a[i];
        leftsum = max(leftsum, sum);
    }
    int rightsum = INT_MIN;
    sum = 0;

    for (int j = mid + 1; j <= high; j++)
    {
        sum = sum + a[j];
        rightsum = max(rightsum, sum);
    }
    return leftsum + rightsum;
}

int maxsubarray(int a[], int low, int high)
{
    if (low == high)
    {
        return a[low];
    }

    int mid = (low + high) / 2;
    int leftsum = maxsubarray(a, low, mid);
    int rightsum = maxsubarray(a, mid + 1, high);
    int crosssum = maxCrosssum(a, low, mid, high);

    return max(leftsum, max(rightsum, crosssum));
}

int main()
{
    int n;
    cout << "enter the size of the array:";
    cin >> n;
    cout << "enter the element:";
    int a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int maxsum = maxsubarray(a, 0, n - 1);
    cout << "Maximum sunarray sum=" << maxsum << endl;
    return 0;
}