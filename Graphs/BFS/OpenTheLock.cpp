#include <vector>
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>

using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if (find(deadends.begin(), deadends.end(), "0000") != deadends.end()) return -1;

        queue<pair<string,int>> q;

        q.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");
        for (const auto& deadend : deadends)
        {
            visited.insert(deadend);
        }

        auto neighbors = [&](string combo)  {
            vector<string> ret;
            for (int i = 0; i < 4; ++i)
            {
                string next = combo;
                next[i] = (next[i] - '0' + 1) % 10 + '0';
                ret.push_back(next);

                next = combo;
                next[i] = (next[i] - '0' + 9) % 10 + '0';
                ret.push_back(next);
            }
            return ret;

        };

        while(!q.empty())
        {
            auto [combo, turns] = q.front();
            q.pop();
            if (combo == target)
            {
                return turns;
            }
            for (auto neighbor : neighbors(combo))
            {
                auto [it, inserted] = visited.insert(neighbor);
                if (inserted)
                {
                    q.push({neighbor, turns+1});
                }
            }
        }
        return -1;

    }
};