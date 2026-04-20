#include <bits/stdc++.h>
using namespace std;

int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int maxVal = 0;
        for (int j = 1; j <= k && i - j >= 0; j++) {
            maxVal = max(maxVal, arr[i - j]);
            dp[i] = max(dp[i], dp[i - j] + maxVal * j);
        }
    }

    return dp[n];
}

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int k = 3;
    cout << maxSumAfterPartitioning(arr, k) << endl; // Output: 84
    return 0;
}