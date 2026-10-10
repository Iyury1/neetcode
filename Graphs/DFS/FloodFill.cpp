#include <vector>

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