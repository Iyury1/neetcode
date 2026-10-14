class Solution {
public:
    int climbStairs(int n) {

        int steps[2] = {1,1};
        for (int i = 2; i <=n; ++i)
        {
            int temp = steps[1];
            steps[1] = steps[0] + temp;
            steps[0] = temp;
        }

        return steps[1];
    }
};
