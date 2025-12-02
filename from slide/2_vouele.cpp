#include <iostream>
#include <string>
using namespace std;

int countVowels(string str, int low, int high)
{

    if (low == high)
    {
        char ch = tolower(str[low]);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return 1;
        else
            return 0;
    }

    int mid = (low + high) / 2;

    return countVowels(str, low, mid) + countVowels(str, mid + 1, high);
}

int main()
{
    string str;
     cout << "Enter a string: ";
    //getline(cin, str);
    cin>>str;

    int totalVowels = countVowels(str, 0, str.length() - 1);
    cout << "Total vowels = " << totalVowels << endl;

    return 0;
}
