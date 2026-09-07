#include <unordered_map>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> match_for_c = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        stack<char> open_stack;
        string open_parens = "({[";
        for (char c : s)
        {
            if (open_parens.find(c) != string::npos)
            {
                open_stack.push(c);
                continue;
            }
            if (open_stack.empty() || open_stack.top() != match_for_c[c])
            {
                return false;
            }
            open_stack.pop();
        }
        return open_stack.empty();
    }
};

int main()
{
    Solution sol;
    cout << sol.isValid("[]");
    return 0;
}