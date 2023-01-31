// Question
// https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void insert(int val, ListNode *&head)
{
    ListNode *n = new ListNode(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    ListNode *ptr = head;
    while (ptr->next != nullptr)
        ptr = ptr->next;
    ptr->next = n;
}
void read_data(ListNode *&l, int n)
{
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        insert(data, l);
    }
}
void print_list(ListNode *head)
{
    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

void deallocate(ListNode *head)
{
    if (head == nullptr)
        return;
    ListNode *ptr = head;
    while (ptr->next != nullptr)
    {
        ListNode *del = ptr;
        ptr = ptr->next;
        delete del;
    }
    delete ptr;
    head = nullptr;
}

ListNode *solve(ListNode *&l1, ListNode *&l2)
{
    if (l1 == NULL)
        return l2;

    if (l2 == NULL)
        return l1;

    if (l1->val <= l2->val)
    {
        l1->next = solve(l1->next, l2);
        return l1;
    }
    else
    {
        l2->next = solve(l1, l2->next);
        return l2;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ListNode *l1 = nullptr;
        ListNode *l2 = nullptr;
        int n;
        cin >> n;
        read_data(l1, n);
        cin >> n;
        read_data(l2, n);
        ListNode *merged = solve(l1, l2);

        cout << "Case #" << i << ": ";
        print_list(merged);
        cout << endl;
        deallocate(merged);
    }
}