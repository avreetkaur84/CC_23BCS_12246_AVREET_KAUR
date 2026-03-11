#include <bits/stdc++.h>
using namespace std;

#define ll long long
const ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;

    for (int b = 0; b < 32; b++) {
        ll k = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] & (1LL << b)) {
                k++;
            }
        }

        ll t = k * (n - k) % MOD;
        ll contribution = (t * ((1LL << b) % MOD)) % MOD;

        ans = (ans + contribution) % MOD;
    }

    cout << ans << endl;

    return 0;
}
