#include <vector>

using namespace std;

class Solution {
public:

    void dfs(int i, int n, int k, vector<vector<int>>& ret, vector<int>& curr)
    {
        if (int(curr.size()) == k)
        {
            ret.push_back(curr);
        }
        if (i > n) return;
        for (int j = i; j < n+1; ++j)
        {
            curr.push_back(j);
            dfs(j+1, n, k, ret, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> curr;

        dfs(1, n, k, ret, curr);

        return ret;
    }
};