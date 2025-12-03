#include <iostream>
using namespace std;

int even(int arr[], int low, int high)
{
    if (low == high)
    {
        if (arr[low] % 2 ==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int mid = (low + high) / 2;
    int left = even(arr, low, mid);
    int right = even(arr, mid + 1, high);
    return left + right;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int m = even(arr, 0, n - 1);
    cout << m << endl;
}