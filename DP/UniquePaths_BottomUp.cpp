#include <vector>

using namespace std;

class Solution {

public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n, 0);

        for (int r = m-1; r >= 0; --r)
        {
            vector<int> currRow(n, 0);
            currRow[n-1] = 1;

            for (int c = n-2; c >= 0; c--)
            {
                currRow[c] += prevRow[c] + currRow[c+1];
            }
            prevRow = currRow;
        }

        return prevRow[0];
    }
};