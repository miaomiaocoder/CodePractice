#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    double n;
    scanf("%lf", &n);

    double l = -10000, r = 10000;
    const long double eps = 1e-8;
    while (r - l > eps) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }

    printf("%lf\n", l);

    return 0;
}