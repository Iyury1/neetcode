#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {

        vector<int> dp(capacity+1, 0);

        for (size_t i = 0; i < profit.size(); ++i)
        {
            int p = profit[i], w = weight[i];
            for (int c = capacity; c >= w; --c)
            {
                dp[c] = max(dp[c], p + dp[c-w]);
            }
        }
        return dp[capacity];
    }
};


class Solution_mxn {
public:
    int maximumProfit(vector<int>& profit, vector<int>& weight, int capacity) {
        size_t n = profit.size(), m = capacity;

        vector<vector<int>> dp(n, vector<int>(m+1, 0));

        for (int c = 0; c < m; ++c)
        {
            if (weight[0] <= c)
            {
                dp[0][c] = profit[0];
            }
        }

        for (size_t i = 1; i < n; ++i)
        {
            for (size_t c = 0; c <= m; ++c)
            {
                int skip = dp[i-1][c];
                int include = 0;
                if (weight[i] <= c)
                {
                    include = profit[i] + dp[i-1][c-weight[i]];
                }
                dp[i][c] = max(skip, include);
            }
        }
        return dp[n-1][m];
    }
};