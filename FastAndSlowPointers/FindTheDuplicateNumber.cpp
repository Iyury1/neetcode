#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        size_t slow = nums[0], fast = nums[nums[0]];

        while (fast != slow)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        size_t head = 0;
        while(head != slow)
        {
            head = nums[head];
            slow = nums[slow];
        }
        return slow;
    }
};
