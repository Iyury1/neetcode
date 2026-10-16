#include <vector>
#include <utility>
#include <stack>

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


    class IterativeSolution {
    public:

        void dfs(int sr, int sc, int rows, int cols, vector<vector<char>>& grid)
        {
            stack<pair<int,int>> s;
            grid[sr][sc] = '0';
            s.push({sr,sc});

            int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

            while(!s.empty())
            {
                auto [r, c] = s.top();
                s.pop();
                for (auto [dr, dc] : dirs)
                {
                    int nr = r + dr, nc = c + dc;
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] == '0')
                    {
                        continue;
                    }
                    grid[nr][nc] = '0';
                    s.push({nr,nc});
                }
            }

        }


        int numIslands(vector<vector<char>>& grid) {
            if (grid.empty() || grid[0].empty()) return 0;
            int rows = static_cast<int>(grid.size()), cols = static_cast<int>(grid[0].size());
            int ret = 0;
            for (int r = 0; r < rows; ++r)
            {
                for (int c = 0; c < cols; ++c)
                {
                    if (grid[r][c] == '1')
                    {
                        ret++;
                        dfs(r, c, rows, cols, grid);
                    }
                }
            }
            return ret;
        }
    };