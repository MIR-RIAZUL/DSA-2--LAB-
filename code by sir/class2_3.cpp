#include <iostream>
#include <vector>
using namespace std;

void rfact(int i, int n, vector<int>& result, int cf) {
    if (i > n) return;

    cf *= i;
    result[i - 1] = cf;

    rfact(i + 1, n, result, cf);
}

vector<int> fact(int n) {
    vector<int> result(n);
    rfact(1, n, result, 1);
    return result;
}

void print(const vector<int>& fact) {
    for (size_t i = 0; i < fact.size(); i++) {
        cout << (i + 1) << "! = " << fact[i] << endl;
    }
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    vector<int> f = fact(n);

    cout << "\nFactorials from 1 to " << n << ":\n";
    print(f);

    return 0;
}

