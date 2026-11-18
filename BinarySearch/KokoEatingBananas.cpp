
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

    int checkPiles(const vector<int>& piles, int h, int k)
    {
        long long t = 0;
        for (int p : piles)
        {
            t += ((long long)p + k - 1) / k;
        }
        return t <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (checkPiles(piles, h, mid))
            {
                r = mid-1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};
