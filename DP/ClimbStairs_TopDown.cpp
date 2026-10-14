#include <vector>
using namespace std;

class Solution {
public:

    int memoization(int n, vector<int>& cache)
    {
        if (n <= 1) {
            cache[n] = 1;
        }
        if (cache[n] > 0) {
            return cache[n];
        }
        cache[n] = memoization(n-1, cache) + memoization(n-2, cache);
        return cache[n];
    }

    int climbStairs(int n) {
        vector<int> cache(n+1, 0);
        return memoization(n, cache);
    }
};
