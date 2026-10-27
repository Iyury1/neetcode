#include <vector>

using namespace std;

class Solution {
public:

    void dfs(size_t idx, int target, vector<vector<int>>& ret,
        vector<int>& curr, vector<int>& nums)
    {
        if (target == 0)
        {
            ret.push_back(curr);
            return;
        }
        else if (idx == nums.size() || nums[idx] > target)
        {
            return;
        }

        curr.push_back(nums[idx]);
        dfs(idx, target - nums[idx], ret, curr, nums);
        curr.pop_back();
        dfs(idx+1, target, ret, curr, nums);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        dfs(0, target, ret, curr, nums);
        return ret;
    }
};
