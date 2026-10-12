#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr)
        {
            return node;
        }
        stack<Node*> s;
        unordered_map<Node*, Node*> cloned;
        s.push(node);
        cloned[node] = new Node(node->val);

        while(!s.empty())
        {
            Node* curr = s.top();
            s.pop();
            Node* currClone = cloned[curr];
            for (Node* neighbor : curr->neighbors)
            {
                auto [it, inserted] = cloned.try_emplace(neighbor, nullptr);
                if (inserted)
                {
                    it->second = new Node(neighbor->val);
                    s.push(neighbor);
                }
                currClone->neighbors.push_back(it->second);
            }

        }
        return cloned[node];
    }
};