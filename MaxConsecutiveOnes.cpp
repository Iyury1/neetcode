#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0, count = 0;
        for (int num : nums)
        {
            if (num == 1)
            {
                count += 1;
                max_ones = max(max_ones, count);
            }
            else
            {
                count = 0;
            }
        }
        return max_ones;
    }
};

int main()
{

    return 0;
}