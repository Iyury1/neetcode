#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr != nullptr)
        {
            ListNode * temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;

        }
        return prev;
    }
};


// void print_list_node(ListNode* head)
// {
//     ListNode *curr = head;
//     while(curr != nullptr)
//     {
//         cout << curr->val << " " ;
//         curr = curr->next;
//     }
//     cout << endl;
// }


// int main()
// {
//     vector<int> inputs = {
//         0,1,3,4
//     };

//     ListNode head(0);
//     ListNode *prev = &head;

//     for (int i = 1; i < inputs.size(); ++i)
//     {
//         ListNode *next = new ListNode(inputs[i]);
//         prev->next = next;
//         prev = next;
//     }


//     print_list_node(&head);
//     Solution sol;
//     ListNode * newHead = sol.reverseList(&head);
//     print_list_node(newHead);

//     return 0;
// }