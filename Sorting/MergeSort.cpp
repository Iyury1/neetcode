#include <vector>
#include <utility>
#include <string>

using namespace std;

// Definition for a Pair
class Pair {
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};

class Solution_CustomMerge {
public:

    vector<Pair> merge(const vector<Pair>& left, const vector<Pair>& right)
    {
        int lp = 0, rp = 0;
        int leftLen = static_cast<int>(left.size()), rightLen = static_cast<int>(right.size());
        vector<Pair> ret;
        ret.reserve(leftLen + rightLen);
        while (lp < leftLen && rp < rightLen)
        {
            if (left[lp].key <= right[rp].key)
            {
                ret.push_back(left[lp]);
                lp++;
            }
            else
            {
                ret.push_back(right[rp]);
                rp++;
            }
        }
        while (lp < leftLen)
        {
            ret.push_back(left[lp++]);
        }
        while (rp < rightLen)
        {
            ret.push_back(right[rp++]);
        }
        return ret;
    }

    vector<Pair> mergeSort(const vector<Pair>& pairs) {
        int len = static_cast<int>(pairs.size());

        if (len <= 1) return pairs;

        int mid = len/2;

        vector<Pair> left = mergeSort(vector<Pair>(pairs.begin(), pairs.begin()+mid));
        vector<Pair> right = mergeSort(vector<Pair>(pairs.begin()+mid, pairs.end()));

        return merge(left, right);
    }
};