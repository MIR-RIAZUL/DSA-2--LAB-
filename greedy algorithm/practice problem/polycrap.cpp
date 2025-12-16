#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int total = 0;

    while (a >= 1 && b >= 1) {
        if (a >= b && a >= 2) {
            // Craft shovel
            a -= 2;
            b -= 1;
        } 
        else if (b > a && b >= 2) {
            // Craft sword
            a -= 1;
            b -= 2;
        } 
        else {
            break; // Cannot craft any more tools
        }
        total++;
    }

    cout << total << endl;
    return 0;
}
