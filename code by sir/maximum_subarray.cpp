#include <iostream>
#include<algorithm>
#include <climits>



using namespace std;

int MaxCrossingSubarray(int A[], int low, int mid, int high) {
    int leftSum = INT_MIN;
    int sum = 0;

    cout<<"left sum"<<endl<<"____________"<<endl<<endl;
    for (int i = mid; i >= low; i--) {
        sum += A[i];
        cout<<"sum"<<i<<":"<<sum<<endl;
        leftSum = max(leftSum, sum);
        cout<<"ls"<<i<<":"<<leftSum<<endl;

    }
    cout<<"____________"<<endl<<endl;
    int rightSum = INT_MIN;
    sum = 0;

    cout<<"right sum"<<endl<<"__________"<<endl<<endl;
    for (int j = mid + 1; j <= high; j++) {
        sum += A[j];
        cout<<"sum"<<j<<":"<<sum<<endl;
        rightSum = max(rightSum, sum);
        cout<<"rs"<<j<<":"<<rightSum<<endl;

   }
   cout<<"____________"<<endl<<endl;

   cout<<"Final sum"<<leftSum+rightSum<<endl;
    return leftSum + rightSum;
}

int MaxSubarray(int A[], int low, int high) {
    if (low == high)
        return A[low];

    int mid = (low + high) / 2;

    int leftSum = MaxSubarray(A, low, mid);
    int rightSum = MaxSubarray(A, mid + 1, high);
    int crossSum = MaxCrossingSubarray(A, low, mid, high);

    return max(leftSum, max(rightSum, crossSum));
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int A[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int maxSum = MaxSubarray(A, 0, n - 1);
    cout << "Maximum Subarray Sum = " << maxSum << endl;

    return 0;
}