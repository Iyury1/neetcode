#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution_Set {
public:

    void dfs(size_t i, vector<int>& nums, set<vector<int>>& perms)
    {
        if (i == nums.size())
        {
            auto [it, inserted] = perms.insert(nums);
            return;
        }

        for (size_t j = i; j < nums.size(); ++j)
        {
            swap(nums[i], nums[j]);
            dfs(i+1, nums, perms);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perms;
        dfs(0, nums, perms);
        vector<vector<int>> ret;
        for (const auto& p : perms)
        {
            ret.push_back(p);
        }
        return ret;
    }
};

class Solution {
public:

    void dfs(size_t i, vector<int>& nums, vector<vector<int>>& perms)
    {
        if (i == nums.size())
        {
            perms.push_back(nums);
            return;
        }

        unordered_set<int> seen;
        for (size_t j = i; j < nums.size(); ++j)
        {
            if (!seen.insert(nums[j]).second) continue;
            swap(nums[i], nums[j]);
            dfs(i+1, nums, perms);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> perms;
        dfs(0, nums, perms);
        return perms;
    }
};