#include <vector>
using namespace std;

class Solution {

private:
    vector<vector<int>> cache;
    int m, n;

public:

    int memoization(int r, int c)
    {
        if (r >= m || c >= n) return 0;
        if (r == m-1 && c == n-1) return 1;

        if (cache[r][c] > 0) return cache[r][c];

        cache[r][c] = memoization(r+1, c) + memoization(r,c+1);

        return cache[r][c];
    }

    int uniquePaths(int m, int n) {
        this->m = m;
        this->n = n;
        cache.assign(m, vector<int>(n, 0));

        int r = 0, c = 0; 

        return memoization(r, c);
    }
};
