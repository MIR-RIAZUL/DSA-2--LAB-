#include <iostream>
#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;
};

int main()
{
    cout<<"enter the ponit number:";
    int n;
    cin >> n;

    Point p[n];
    cout<<"enter the point start and end:";

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].x >> p[i].y;
    }

    double d[n * n]; 
    int k = 0;       

 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double dxx = p[i].x - p[j].x;
            double dyy = p[i].y - p[j].y;
            double dist = sqrt(dxx * dxx+ dyy * dyy);

            d[k] = dist; 
            k++;
        }
    }

  
    double min = d[0];
    for (int i = 1; i < k; i++)
    {
        if (d[i] < min)
            min= d[i];
    }

    cout<<"the minimum distance: "<<min<<endl;

    return 0;
}
