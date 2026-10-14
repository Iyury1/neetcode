#include <vector>

using namespace std;

class Solution {
public:

    int dfs(int n, vector<int>& nums, vector<int>& cache)
    {
        if (n >= static_cast<int>(nums.size())) return 0;
        if (cache[n] != -1) return cache[n];

        cache[n] = max(nums[n] + dfs(n+2, nums, cache), dfs(n+1, nums, cache));
        return cache[n];
    }

    int rob(vector<int>& nums) {
        vector<int> cache(static_cast<int>(nums.size()), -1);
        return dfs(0, nums, cache);
    }
};