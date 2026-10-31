// Definition for singly-linked list.
#include <algorithm>

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
    int pairSum(ListNode* head) {
        

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *twin = nullptr;
        while (slow)
        {
            ListNode* temp = slow->next;
            slow->next = twin;
            twin = slow;
            slow = temp;
        }


        int maxTwins = 0;
        ListNode *i = head;
        while (twin)
        {
            maxTwins = max(maxTwins, i->val + twin->val);
            i = i->next;
            twin = twin->next;
        }

        return maxTwins;
    }
};