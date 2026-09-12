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

void print_list_node(ListNode* head)
{
    ListNode *curr = head;
    while(curr != nullptr)
    {
        cout << curr->val << " " ;
        curr = curr->next;
    }
    cout << endl;
}


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp;
        ListNode* ret;
        bool start = false;
        if (!list1 && !list2)
        {
            return list1;
        }
        if (!list1 && list2)
        {
            return list2;
        }
        else if (!list2 && list1)
        {
            return list1;
        }
        while(list1 && list2)
        {
            bool hit = false;
            temp = list1;
            while (temp && temp->val <= list2->val)
            {
                if (!start)
                {
                    ret = list1;
                    start = true;
                }
                hit = true;
                list1 = temp;
                temp = temp->next;
            }
            if (!temp)
            {
                temp = list1;
                list1 = list1->next;
                break;
            }
            if (hit)
            {
                temp = list1->next;
                list1->next = list2;
                list1 = temp;
                hit = false;
            }
            temp = list2;
            while (temp && temp->val <= list1->val)
            {
                if (!start)
                {
                    ret = list2;
                    start = true;
                }
                hit = true;
                list2 = temp;
                temp = temp->next;
            }
            if (!temp) 
            {
                temp = list2;
                list2 = list2->next;
                break;
            }
            if (hit)
            {
                temp = list2->next;
                list2->next = list1;
                list2 = temp;
            }
        }
        if (!list1 && list2)
        {
            list1 = temp;
            list1->next = list2;
        }
        else if (!list2 && list1)
        {
            list2 = temp;
            list2->next = list1;
        }
        return ret;
    }
};


int main()
{
    std::vector<int> list1_val = {
        1, 2, 4
    };
    std::vector<int> list2_val = {
        1, 3, 5
    };

    ListNode * list1 = new ListNode(list1_val[0]);
    for (int i = 1; i < list1_val.size(); ++i)
    {
        list1->next = new ListNode(list1_val[i]);
    }
    ListNode * list2 = new ListNode(list2_val[0]);
    for (int i = 1; i < list2_val.size(); ++i)
    {
        list2->next = new ListNode(list2_val[i]);
    }

    Solution sol;
    print_list_node(sol.mergeTwoLists(list1, list2));

    return 0;
}