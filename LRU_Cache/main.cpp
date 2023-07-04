// Question
// https://leetcode.com/problems/lru-cache/description/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node(int x = 0, int y = 0) : key(x), val(y), next(nullptr), prev{nullptr} {}
};

class LRUCache
{
    Node *LRU;
    Node *MRU;
    unordered_map<int, Node *> mp;
    int cap;
    int size;

    Node *insert(int key, int val)
    {
        Node *new_node = new Node(key, val);
        MRU->prev->next = new_node;
        new_node->prev = MRU->prev;
        new_node->next = MRU;
        MRU->prev = new_node;
        size++;
        return new_node;
    }
    void remove(Node *node)
    {
        if (node == nullptr)
            return;

        node->next->prev = node->prev;
        node->prev->next = node->next;
        delete node;
        size--;
    }
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        LRU = new Node();
        MRU = new Node();
        LRU->next = MRU;
        MRU->prev = LRU;
        size = 0;
    }

    int get(int key)
    {
        if (mp.find(key) != mp.end() and mp[key])
        {
            int value = mp[key]->val;
            remove(mp[key]);
            mp[key] = insert(key, value);
            return value;
        }

        return -1;
    }

    void put(int key, int value)
    {
        remove(mp[key]);

        mp[key] = insert(key, value);

        if (size > cap)
        {
            mp[LRU->next->key] = nullptr;
            remove(LRU->next);
        }
    }

    ~LRUCache()
    {
        Node *del;
        while (LRU)
        {
            del = LRU;
            LRU = LRU->next;
            delete del;
        }
    }
};

int main()
{
    LRUCache lru{2};

    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4,4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
}
