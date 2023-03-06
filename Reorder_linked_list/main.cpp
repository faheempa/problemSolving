// Question
// https://leetcode.com/problems/reorder-list/

#include "ll.h"
#include <bits/stdc++.h>
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
    bool operator==(const Node &a) const
    {
        return (val == a.val);
    }
};
std::ostream &operator<<(std::ostream &o, const Node &a)
{
    o << a.val;
    return o;
}

void solve(Node *head)
{
    if (not head)
        return;

    Node *fast = head->next, *slow = head;
    while (fast and fast->next)
        slow = slow->next, fast = fast->next->next;
    fast = slow->next, slow->next = nullptr, slow = fast;

    Node *pre = nullptr, *nex;
    while (slow)
    {
        nex = slow->next;
        slow->next = pre;
        pre = slow;
        slow = nex;
    }

    Node *head2 = pre;
    while (head and head2)
    {
        Node *t1 = head->next, *t2 = head2->next;
        head->next=head2;
        head2->next=t1;
        head=t1;
        head2=t2;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        LinkedList<Node> l;
        read_int_vector(nums);
        for (const auto &a : nums)
            l.push_back(a);
        cout << "Case #" << i << ": ";
        solve(l.get_head());
        l.print(" ");
        cout << endl;
    }
}
