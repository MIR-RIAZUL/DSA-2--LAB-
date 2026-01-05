#include <iostream>
using namespace std;

struct type
{
    int start;
    int end;
};

int main()
{
    int n,m;
    cout<<"enter the size of array:";
    cin>>n;
    cout<<endl;
    cout<<"enter the array:";

    int array[n];
    for (int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    cout<<endl;
    cout<<"enter the query number:";

    cin>>m;
    type arr[m];

    cout<<endl;
    cout<<"enter the query start and end:";

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].start >> arr[i].end;
    }
    cout<<endl;
    cout<<"the number of zero is:"<<endl;

    for (int i = 0; i < m; i++)
    {
        int countzero = 0;

        for (int j = arr[i].start - 1; j <= arr[i].end - 1; j++)
        {
            if (array[j] == 0)
            {
                countzero++;
            }
        }

        cout << countzero << endl;
    }

    return 0;
}
