// Question
// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

#include <bits/stdc++.h>
#include "ll.h"
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

struct Node
{
    int val;
    Node *next;
    Node(int x = 0) : val(x), next(nullptr) {}
};
std::ostream &operator<<(std::ostream &o, const Node &a)
{
    o << a.val;
    return o;
}

class Solution
{
public:
    Node *solve(Node *head, int k)
    {
        Node *kth_node = getKthNode(head, k-1);

        if (not kth_node)
            return head;
            
        Node* next_grp = solve(kth_node->next, k);
        head = reverse(head, k);
        Node*ptr=head;

        while(ptr->next)
            ptr=ptr->next;

        ptr->next=next_grp;
        return head;
    }
    Node *reverse(Node *head, int k)
    {
        Node *ptr = head;
        Node *prev = nullptr, *nxt = head;
        ptr = head;
        while (ptr and k--)
        {
            nxt = ptr->next;
            ptr->next = prev;
            prev = ptr;
            ptr = nxt;
        }
        return prev;
    }
    Node *getKthNode(Node *ptr, int k)
    {
        while (ptr and k)
        {
            if (k-- == 0)
                break;
            ptr = ptr->next;
        }
        return ptr;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        LinkedList<Node> l_list;
        vector<int> nums;
        read_int_vector(nums);
        for (const auto &num : nums)
        {
            l_list.push_back(num);
        }
        int k;
        cin >> k;

        Solution sol;
        cout << "Case #" << i << ": ";
        l_list.set_head(sol.solve(l_list.get_head(), k));
        l_list.print(" ");
        cout << endl;
    }
}
