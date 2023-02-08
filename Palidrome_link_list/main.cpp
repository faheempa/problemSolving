// Question
// https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
#include "ll.h"
using namespace std;

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

bool solve(Node *head)
{
    Node *slow = head, *fast = head, *prev, *nex;
    while (fast && fast->next)
        slow = slow->next, fast = fast->next->next;

    prev = slow, slow = slow->next, prev->next = NULL;
    while (slow)
        nex = slow->next, slow->next = prev, prev = slow, slow = nex;

    fast = head, slow = prev;
    while (slow)
        if (fast->val != slow->val)
            return false;
        else
            fast = fast->next, slow = slow->next;

    return true;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        LinkedList<Node> l;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            l.push_back(new Node(a));
        }
        cout << "Case #" << i << ": ";
        cout << std::boolalpha << solve(l.get_head());
        cout << endl;
    }
}
