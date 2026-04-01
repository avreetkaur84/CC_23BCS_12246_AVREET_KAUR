#include <bits/stdc++.h>
using namespace std;

// -------------BRUTE FORCE-----------------
int sumBitDifferences(vector<int>& arr) {
    int n = arr.size();
    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int x = arr[i] ^ arr[j];

            // count set bits
            while(x > 0) {
                ans += (x & 1);
                x = x >> 1;
            }
        }
    }

    return ans * 2; // remove *2 if unordered required
}

// TIME COMPLEXITY - O(N^2 *32)



// ----------------OPTIMAL -------------------
int sumBitDifferences(vector<int>& arr) {
    int n = arr.size();
    long long ans = 0;

    for(int bit = 0; bit < 32; bit++) {
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(arr[i] & (1 << bit))
                count++;
        }

        ans += (long long)count * (n - count) * 2;
    }

    return ans;
}

// TIME COMPLEXITY -- O(32*N)