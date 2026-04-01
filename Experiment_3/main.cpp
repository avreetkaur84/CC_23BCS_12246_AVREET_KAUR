#include <bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int nthMagicalNumber(int n, int a, int b) {
    long long low = min(a, b);
    long long high = (long long) n * min(a, b);
    long long lcm = (a / gcd(a, b)) * b;
    while (low < high) {
        long long mid = (low + high) / 2;
        long long count = (mid / a) + (mid / b) - (mid / lcm);
        if (count >= n) high = mid;
        else low = mid + 1;
    }

    return low % M;
}
int main() {
    // your code goes here
    int a, b, n;
    cin >> n >> a >> b;
    cout << nthMagicalNumber(n, a, b);
}