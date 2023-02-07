// Question
// https://leetcode.com/problems/reverse-linked-list/

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

Node* solve(Node *head)
{
    Node *pre=nullptr, *nex;
    while(head)
    {
        nex=head->next;
        head->next=pre;
        pre=head;
        head=nex;
    }
    return pre;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        LinkedList<Node> l;
        int a;
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            Node *nd = new Node();
            cin >> nd->val;
            if (Node *t = l.find(Node(nd->val)); t == nullptr)
                l.push_back(nd);
            else
            {
                Node *h = l.get_head();
                while (h->next != nullptr)
                    h = h->next;
                h->next = t;
            }
        }

        cout << "Case #" << i << ": ";
        l.set_head(solve(l.get_head()));
        l.print(" ");
        cout<<endl;
    }
}
