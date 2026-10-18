#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);

        dp[n-1] = 1;
        for (int r = m-1; r >= 0; r--)
        {
            for (int c = n-1; c >= 0; c--)
            {
                if (obstacleGrid[r][c])
                {
                    dp[c] = 0;
                }
                else
                {
                    if (c != n-1)
                    {
                        dp[c] += dp[c+1];
                    }
                }

            }
        }
        return dp[0];
    }
};