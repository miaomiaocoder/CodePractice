#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0;
    while (n--) {
        int x;
        cin >> x;
        res ^= x;
    }

    if (res)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}