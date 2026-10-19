#include <vector>

using namespace std;

class Solution {
public:
    
    void dfs(size_t n, vector<int>& nums, vector<vector<int>>& ret, vector<int>& curr)
    {
        if (n == nums.size())
        {
            ret.push_back(curr);
            return;
        }

        curr.push_back(nums[n]);
        dfs(n+1, nums, ret, curr);
        curr.pop_back();
        dfs(n+1, nums, ret, curr);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ret;
        vector<int> curr;
        dfs(0, nums, ret, curr);

        return ret;
    }
};
