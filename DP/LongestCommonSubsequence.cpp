#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.length(), len2 = text2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1,0));
        for (int i = len1-1; i >= 0; --i)
        {
            for (int j = len2-1; j >= 0; --j)
            {
                if (text1[i] == text2[j])
                {
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        return dp[0][0];
    }
};
