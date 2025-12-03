#include <iostream>
using namespace std;


void merge(int arr[], int result[], int low, int mid, int high) {
    int n = high - low + 1;
    int temp[n];
    int i = low, j = mid + 1;
    int rightCount = 0;

    for (int k = 0; k < n; k++) {
        if (i > mid) { 
            temp[k] = arr[j++];
        } else if (j > high) { 
            result[i] += rightCount;
            temp[k] = arr[i++];
        } else if (arr[j] < arr[i]) { 
            rightCount++;
            temp[k] = arr[j++];
        } else { 
            result[i] += rightCount;
            temp[k] = arr[i++];
        }
    }

    
    for (int p = 0; p < n; p++)
        arr[low + p] = temp[p];
}

void countRightSmaller(int arr[], int result[], int low, int high) {
    if (low >= high) return;

    int mid = (low + high) / 2;
    countRightSmaller(arr, result, low, mid);
    countRightSmaller(arr, result, mid + 1, high);
    merge(arr, result, low, mid, high);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n], result[n];
    cout << "Enter the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        result[i] = 0;
    }

    countRightSmaller(arr, result, 0, n - 1);

    cout << "Number of smaller elements to the right: ";
    for (int i = 0; i < n; i++)
        cout << result[i] << " ";
    cout << endl;

    return 0;
}
