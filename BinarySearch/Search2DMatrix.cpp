#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        size_t rows = matrix.size(), cols = matrix[0].size();

        int left = 0, right = rows * cols - 1;

        while (left <= right)
        {
            int mid = (left+right)/2;
            int row = mid / cols;
            int col = mid % cols;

            int curr = matrix[row][col];

            if (target < curr)
            {
                right = mid-1;
            }
            else if (target > curr)
            {
                left = mid+1;
            }
            else
            {
                return true;
            }

        }
        return false;
    }
};