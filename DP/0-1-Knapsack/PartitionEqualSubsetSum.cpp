#include <vector>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        size_t n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total % 2) != 0) return false;
        int target = total/2;

        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int x : nums)
        {
            for (int t = target; t >= x; --t)
            {
                dp[t] |= dp[t-x];
            }
        }
        return dp[target];
    }
};



class Solution_Set {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if ((total % 2) != 0) return false;
        int target = total/2;

        unordered_set<int> sums;
        sums.insert(0);

        for (int x : nums)
        {
            unordered_set<int> next_sums;
            for (int s : sums)
            {
                next_sums.insert(s);
                if (s + x <= target)
                {
                    next_sums.insert(s+x);
                }
            }
            sums = move(next_sums);
            if (sums.find(target) != sums.end()) return true;
        }

        return false;

    }
};