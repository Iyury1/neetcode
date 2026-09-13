#include <vector>
#include <string>
#include <iostream>

using namespace std;
class BrowserHistory {
public:
    struct ListNode {
        string val = "";
        ListNode * next = nullptr;
        ListNode * prev = nullptr;
        ListNode(string val) : val(val) {}
    };
    ListNode * curr = nullptr;
    BrowserHistory(string homepage) {
        curr = new ListNode(homepage);
    }
    // void print_list()
    // {
    //     ListNode * temp = head;
    //     while(temp != nullptr)
    //     {
    //         cout << temp->val << " ";
    //         temp = temp->next;
    //     }
    //     cout << endl;
    // }
    void visit(string url) {
        curr->next = new ListNode(url);
        curr->next->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        for (int i = 0; i < steps; ++i)
        {
            if (curr->prev == nullptr)
            {
                return curr->val;
            }
            curr = curr->prev;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        for (int i = 0; i < steps; ++i)
        {
            if (curr->next == nullptr)
            {
                return curr->val;
            }
            curr = curr->next;
        }
        return curr->val;
    }
};

int main()
{
    std::vector<string> ops = {
        "BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"
    };
    std::vector<string> params = {
        "neetcode.com","google.com","facebook.com","youtube.com","1","1","1","linkedin.com","2","2","7"
    };


    BrowserHistory sol(params[0]);

    for (int i = 1; i < ops.size(); ++i)
    {
        if (ops[i] == "visit")
        {
            sol.visit(params[i]);
            sol.print_list();
        }
        else if (ops[i] == "back")
        {
            cout << sol.back(stoi(params[i])) << endl;
            sol.print_list();
        }
        else if (ops[i] == "forward")
        {
            cout << sol.forward(stoi(params[i])) << endl;
            sol.print_list();
        }

    }
    return 0;
}