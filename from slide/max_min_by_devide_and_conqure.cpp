#include <iostream>

using namespace std;

pair<int, int> MAXxMIN(int arr[], int low, int high)
{
    if (low == high)
    {
        return {arr[low], arr[low]};
    }
    else if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            return {arr[high], arr[low]};
        }
        else 
        {
             return {arr[low], arr[high]};
        }
    }
    else
    {
        int mid = (low + high) / 2;
        pair<int, int> left = MAXxMIN(arr, low, mid);
        pair<int, int> right = MAXxMIN(arr, mid + 1, high);

        int finalMAX = max(left.first, right.first);
        int finalMIn = min(left.second, right.second);
        return {finalMAX, finalMIn};
    }
}

int main()
{
    cout << "enter the size of the array:";
    int n;
    cin >> n;
    int arr[n];
    cout << "enter the array:";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    pair<int, int> max_min = MAXxMIN(arr, 0, n - 1);
    cout << "maximum value is " << max_min.first << endl;
    cout << "minimumvalue is " << max_min.second << endl;

    return 0;
}