
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MyLinkedList
{

private:
    struct Node {
        int val;
        Node * next = nullptr;
    };

    Node * head = nullptr;
    Node * tail = nullptr;
    int size = 0;

public:
    MyLinkedList()
    {
    }

    ~MyLinkedList()
    {
        Node * curr = head;
        while (curr)
        {
            Node * to_delete = curr;
            curr = curr->next;
            delete to_delete;
        }
    }

    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList& operator=(const MyLinkedList&) = delete;
    
    void print_list() const
    {
        cout << "printing list of size " << size << endl;
        if (size == 0)
        {
            return;
        }
        Node * curr = head;
        for (int i = 0; i < size; ++i)
        {
            cout << curr->val << ", ";
            curr = curr->next;
        }
        cout << endl;
    }

    int get(int index) const
    {
        if (index < 0 || index > size-1)
        {
            return -1;
        }
        Node * curr = head;
        for (int i = 0; i < index; ++i)
        {
            curr = curr->next;
        }
        return curr->val;
    }
    
    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }
    
    void addAtIndex(int index, int val)
    {
        if (index > size) return;
        if (index < 0) index = 0;

        Node * new_node = new Node{val, nullptr};
        if (index == 0)
        {
            new_node->next = head;
            head = new_node;
            if (tail == nullptr) tail = new_node;
        }
        else
        {
            Node * prev = head;
            for (int i = 0; i < index-1; ++i)
            {
                prev = prev->next;
            }
            new_node->next = prev->next;
            prev->next = new_node;
            if (new_node->next == nullptr) tail = new_node;
        }
        size++;
    }
    
    void deleteAtIndex(int index)
    {
        if (index >= size || index < 0) return;

        Node * Nodeo_delete = nullptr;

        if (index == 0)
        {
            Nodeo_delete = head;
            head = head->next;
            if (head == nullptr) tail = nullptr;
        }
        else
        {
            Node * prev = head;
            for (int i = 0; i < index-1; ++i)
            {
                prev = prev->next;
            }
            Nodeo_delete = prev->next;
            prev->next = Nodeo_delete->next;
            if (Nodeo_delete == tail) tail = prev;
        }
        delete Nodeo_delete;
        size--;
    }
};


void check_output(vector<string> input_functions, vector<vector<int>> input_vals)
{
    MyLinkedList mll;
    vector<string> out;
    for (int i = 0; i < size(input_functions); ++i)
    {
        if (input_functions[i] == "addAtHead")
        {
            cout << " addAtHead : " << input_vals[i][0] << endl;
            mll.addAtHead(input_vals[i][0]);
            mll.print_list();
            out.push_back("null");
        }
        else if (input_functions[i] == "addAtTail")
        {
            cout << " addAtTail : " << input_vals[i][0] << endl;
            mll.addAtTail(input_vals[i][0]);
            mll.print_list();
            out.push_back("null");
        }
        else if (input_functions[i] == "addAtIndex")
        {
            cout << " addAtIndex : index = " << input_vals[i][0] << ", val = " << input_vals[i][1] << endl;
            mll.addAtIndex(input_vals[i][0], input_vals[i][1]);
            mll.print_list();
            out.push_back("null");
        }
        else if (input_functions[i] == "get")
        {
            cout << " get" << endl;
            mll.print_list();
            out.push_back(to_string(mll.get(input_vals[i][0])));
        }
        else if (input_functions[i] == "deleteAtIndex")
        {
            cout << " deleteAtIndex : " << input_vals[i][0] << endl;
            mll.deleteAtIndex(input_vals[i][0]);
            mll.print_list();
            out.push_back("null");
        }
    }

    cout << "[";
    for (const string& out_str : out)
    {
        cout << out_str << ", ";
    }
    cout << "]" << endl;
}

// int main()
//     {

//     vector<string> input_functions = {
//         "MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"
//     };
//     vector<vector<int>> input_vals = {
//         {}, {1}, {3}, {1, 2}, {1}, {1}, {1}
//     };

//     check_output(input_functions, input_vals);

//     input_functions = {
//         "MyLinkedList","addAtHead","addAtHead","addAtHead","addAtIndex","deleteAtIndex","addAtHead","addAtTail","get","addAtHead","addAtIndex","addAtHead"
//     };
    
//     input_vals = {
//         {}, {7}, {2}, {1}, {3, 0}, {2}, {6}, {4}, {4}, {4}, {5,0}, {6}
//     };

//     check_output(input_functions, input_vals);


//     return 0;
// }