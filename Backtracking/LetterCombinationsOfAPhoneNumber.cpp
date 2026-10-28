#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<string> letters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
public:

    void dfs(vector<string>& ret, string& curr, const string& digits, size_t i)
    {
        if (i == digits.length())
        {
            ret.push_back(curr);
            return;
        }

        int digit = digits[i] - '0';
        for (const auto c : letters[digit])
        {
            curr.push_back(c);
            dfs(ret, curr, digits, i+1);
            curr.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty()) return ret;
        string curr;
        curr.reserve(digits.size());
        dfs(ret, curr, digits, 0);
        return ret;
    }
};



class Solution_Iterative {
    const array<string, 10> letters = {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
    };
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ret = {""};
        if (digits.empty()) return {};
        
        for (const char digit : digits)
        {
            string options = letters[digit - '0'];
            vector<string> next;
            next.reserve(ret.size() * options.size());
            for (const string& str : ret)
            {
                for (const char c : options)
                {
                   next.push_back(str + c);
                }
            }
            ret = std::move(next);
        }

        return ret;
    }
};