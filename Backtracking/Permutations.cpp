
#include <vector>

using namespace std;


class Solution_Iterative {
public:

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms = {{}};
        for (int n : nums)
        {
            vector<vector<int>> nextPerms;
            for (const auto& p : perms)
            {
                for (size_t i = 0; i <= p.size(); ++i)
                {
                    vector<int> pCopy = p;
                    pCopy.insert(pCopy.begin()+i, n);
                    nextPerms.push_back(move(pCopy));
                }
            }
            perms = move(nextPerms);
        }
        return perms;
    }
};


class Solution_Recusive_Insertion {
public:

    void dfs(size_t i, vector<int>& nums, vector<vector<int>>& res)
    {
        if (i == nums.size()) {
            res = {{}};
            return;
        }
        vector<vector<int>> resPerms;
        vector<vector<int>> perms;
        dfs(i+1, nums, perms);

        for (const auto& p : perms)
        {
            for (size_t j = 0; j <= p.size(); ++j)
            {
                vector<int> pCopy = p;
                pCopy.insert(pCopy.begin()+j, nums[i]);
                resPerms.push_back(move(pCopy));
            }
        }
        res = move(resPerms);
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        dfs(0, nums, res);
        return res;
    }
};


class Solution_Recusive_Backtrack {
public:

    void backtrack(size_t i, vector<int>& nums, vector<vector<int>>& res)
    {
        if (i == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (size_t j = i; j < nums.size(); ++j)
        {
            swap(nums[i], nums[j]);
            backtrack(i+1, nums, res);
            swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0, nums, res);
        return res;
    }
};
