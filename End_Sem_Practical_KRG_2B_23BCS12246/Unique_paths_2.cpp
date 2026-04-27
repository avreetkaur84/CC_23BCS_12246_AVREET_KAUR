#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));

        auto cal = [&](auto &&self, int i, int j) -> int {
            if(i==0 && j==0) return 1;
            if(i<0 || j<0) return 0;
            if(obstacleGrid[i][j]==1) return 0;
            if(dp[i][j]!=-1) return dp[i][j];

            return dp[i][j] = self(self, i-1, j)+self(self, i, j-1);
        };

        return cal(cal, n-1, m-1);
    }
};