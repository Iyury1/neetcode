#include <vector>

using namespace std;

class Solution {
public:

    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& visited, int num_rows, int num_cols)
    {
        if (r < 0 || c < 0 || r >= num_rows || c >= num_cols || visited[r][c] || grid[r][c] != 1)
        {
            return 0;
        }
        visited[r][c] = true;
        int sum = 1;
        sum += dfs(grid, r-1, c, visited, num_rows, num_cols);
        sum += dfs(grid, r+1, c, visited, num_rows, num_cols);
        sum += dfs(grid, r, c-1, visited, num_rows, num_cols);
        sum += dfs(grid, r, c+1, visited, num_rows, num_cols);
        return sum;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int num_rows = static_cast<int>(grid.size());
        int num_cols = static_cast<int>(grid[0].size());
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        int ret = 0;
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                ret = max(ret, dfs(grid, i, j, visited, num_rows, num_cols));
            }
        }
        return ret;
    }
};