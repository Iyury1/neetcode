#include <vector>

using namespace std;

class Solution {
public:

    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited, int num_rows, int num_cols)
    {
        if (r < 0 || c < 0 || r >= num_rows || c >= num_cols || visited[r][c] || grid[r][c] != '1')
        {
            return;
        }
        visited[r][c] = true;
        dfs(grid, r-1, c, visited, num_rows, num_cols);
        dfs(grid, r+1, c, visited, num_rows, num_cols);
        dfs(grid, r, c-1, visited, num_rows, num_cols);
        dfs(grid, r, c+1, visited, num_rows, num_cols);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int num_rows = static_cast<int>(grid.size());
        int num_cols = static_cast<int>(grid[0].size());
        vector<vector<bool>> visited(num_rows, vector<bool>(num_cols, false));
        int count = 0;
        for (int i = 0; i < num_rows; ++i)
        {
            for (int j = 0; j < num_cols; ++j)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    count += 1;
                    dfs(grid, i, j, visited, num_rows, num_cols);
                }
            }
        }
        return count;
    }
};