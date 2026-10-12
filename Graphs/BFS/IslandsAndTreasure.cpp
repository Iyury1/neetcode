#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        if (grid.empty() || grid[0].empty()) return;
        int rows = static_cast<int>(grid.size()), cols = static_cast<int>(grid[0].size());
        int neighbors[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        const int INF = 2147483647;
        queue<pair<int,int>> q;

        for (int r = 0; r < rows; ++r)
        {
            for (int c = 0; c < cols; ++c)
            {
                if (grid[r][c] == 0)
                {
                    q.push({r,c});
                }
            }
        }
        int length = 1;
        while(!q.empty())
        {
            int levelSize = static_cast<int>(q.size());
            for (int i = 0; i < levelSize; ++i)
            {
                auto [r, c] = q.front();
                q.pop();
                for (const auto& n : neighbors)
                {
                    int nr = r + n[0], nc = c + n[1];
                    if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || grid[nr][nc] != INF)
                    {
                        continue;
                    }
                    grid[nr][nc] = length;
                    q.push({nr,nc});
                }
            }
            length++;
        }
    }
};