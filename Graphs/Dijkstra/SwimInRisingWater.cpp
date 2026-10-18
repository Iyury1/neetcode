#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        using T = tuple<int,int,int>;
        priority_queue<T, vector<T>, greater<>> minHeap;

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        minHeap.push({grid[0][0],0,0});
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!minHeap.empty())
        {
            auto [t, r, c] = minHeap.top(); minHeap.pop();
            if (visited[r][c]) continue;

            visited[r][c] = true;
            if (r == rows-1 && c == cols-1)
            {
                return t;
            }

            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr == rows || nc == cols || visited[nr][nc])
                {
                    continue;
                }
                minHeap.push({max(t, grid[nr][nc]), nr, nc});
            }
        }
        return -1;
    }
};
