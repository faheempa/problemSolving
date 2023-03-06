// Question
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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

void solve(Node *head, int n)
{
    Node *dummy = new Node(-1);
    Node *ptr = head;
    Node *ptr2 = dummy;
    dummy->next=head;
    while (n--)
        ptr = ptr->next;
    while (ptr)
        ptr = ptr->next, ptr2 = ptr2->next;
    if (ptr2 != dummy)
        ptr2->next = ptr2->next->next;
    else
        return;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        LinkedList<Node> l;
        vector<int> nums;
        read_int_vector(nums);
        for (const auto &a : nums)
            l.push_back(a);
        cin >> n;

        cout << "Case #" << i << ": ";
        solve(l.get_head(), n);
        l.print(" ");
        cout << endl;
    }
}
