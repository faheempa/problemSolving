// Question
// https://leetcode.com/problems/odd-even-linked-list/description/

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

void solve(Node *head)
{
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return;
    Node *odd = head, *even = head->next, *p = even;
    while (odd and even and odd->next->next)
    {
        odd->next = odd->next->next, odd = odd->next;
        even->next = even->next->next, even = even->next;
    }
    odd->next = p;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        LinkedList<Node> l;
        int n, a;
        cin >> n;
        for (int i = 0; i < n; i++)
                cin >>
            a,
            l.push_back(new Node(a));

        cout << "Case #" << i << ": ";
        solve(l.get_head());
        l.print(" ");
        cout << endl;
    }
}
