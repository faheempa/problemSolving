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
    Node *slow = head, *fast = head;
    stack<int> s;
    while (fast && fast->next)
        s.push(slow->val), fast = fast->next->next, slow = slow->next;
    if (fast)
        slow=slow->next;
    while (slow)
        if (s.top() != slow->val)
            return false;
        else
            slow = slow->next, s.pop();

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
