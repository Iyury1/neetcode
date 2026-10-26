#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& ret, vector<int>& curr, const vector<int>& nums, size_t idx)
    {
        if (idx == nums.size())
        {
            ret.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        dfs(ret, curr, nums, idx+1);
        curr.pop_back();

        size_t skip = idx+1;
        while(skip != nums.size() && nums[idx] == nums[skip]) skip++;          
        dfs(ret, curr, nums, skip);

    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        vector<int> curr;
        dfs(ret, curr, nums, 0);
        
        return ret;
    }
};
