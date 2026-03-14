#include <bits/stdc++.h>
using namespace std;
int bagOfTokensScore(vector<int>& tokens, int power) {
    sort(tokens.begin(), tokens.end());
    int l = 0;
    int r = tokens.size() - 1;
    int score = 0;
    int maxScore = 0;
    while (l <= r) {
        if (power >= tokens[l]) {
            power -= tokens[l];
            score++;
            l++;
            maxScore = max(maxScore, score);
        }
        else if (score > 0) {
            power += tokens[r];
            score--;
            r--;
        }
        else {
            break;
        }
    }
    return maxScore;
}

int main() {
    int n;
    cin >> n;
    vector<int> tokens(n);
    for (int i = 0; i < n; i++)
        cin >> tokens[i];
        
    int power;
    cin >> power;

    cout << bagOfTokensScore(tokens, power) << endl;

    return 0;
}