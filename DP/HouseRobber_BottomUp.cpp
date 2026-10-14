
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int rob(vector<int>& nums) {
        int length = static_cast<int>(nums.size());
        int prev = 0, curr = 0;
        for (int i = 0; i < length; ++i)
        {
            int temp = max(nums[i]+prev,curr);
            prev = curr;
            curr = temp;
        }
        return curr;
    }
};
