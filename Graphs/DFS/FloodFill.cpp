#include <vector>
#include <stack>

using namespace std;


class Solution {
public:

    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int orig)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size()
                || image[sr][sc] != orig) 
        {
            return;
        }
        image[sr][sc] = color;
        dfs(image, sr-1, sc, color, orig);
        dfs(image, sr+1, sc, color, orig);
        dfs(image, sr, sc+1, color, orig);
        dfs(image, sr, sc-1, color, orig);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || image[0].empty()) return image;
        int orig = image[sr][sc];
        if (orig == color) return image;
        dfs(image, sr, sc, color, orig);
        return image;
    }
};

class IterativeSolution {
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image.empty() || image[0].empty() || image[sr][sc] == color) return image;
        int rows = static_cast<int>(image.size()), cols = static_cast<int>(image[0].size());
        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
        stack<pair<int,int>> s;

        int same = image[sr][sc];
        image[sr][sc] = color;
        s.push({sr,sc});

        while (!s.empty())
        {
            auto [r,c] = s.top();
            s.pop();
            for (auto [dr, dc] : dirs)
            {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= rows || nc >= cols || image[nr][nc] != same)
                {
                    continue;
                }
                image[nr][nc] = color;
                s.push({nr,nc});
            }
        }
        return image;

    }
};