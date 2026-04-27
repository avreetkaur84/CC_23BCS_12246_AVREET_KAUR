#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rabinKarp(string text, string pattern) {
        vector<int> result;

        int n = text.length();
        int m = pattern.length();
        if (m > n) return result;

        int base = 256;
        int mod = 101;

        int patternHash = 0;
        int windowHash = 0;
        int h = 1;

        for (int i = 0; i < m - 1; i++) {
            h = (h * base) % mod;
        }

        for (int i = 0; i < m; i++) {
            patternHash = (base * patternHash + pattern[i]) % mod;
            windowHash = (base * windowHash + text[i]) % mod;
        }

        for (int i = 0; i <= n - m; i++) {
            if (patternHash == windowHash) {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (text[i + j] != pattern[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) result.push_back(i);
            }

            if (i < n - m) {
                windowHash = (base * (windowHash - text[i] * h) 
                                             + text[i + m]) % mod;

                if (windowHash < 0) windowHash += mod;
            }
        }

        return result;
    }
};

int main() {
    string text = "abcab";
    string pattern = "ab";

    Solution sol;
    vector<int> indices = sol.rabinKarp(text, pattern);

    cout << "Pattern found at indices: ";
    for (int index : indices) {
        cout << index << " ";
    }
    cout << "\n";

    return 0;
}