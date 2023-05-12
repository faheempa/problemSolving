// Question
// https://leetcode.com/problems/implement-trie-prefix-tree/

#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26];
    bool end;

    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        end = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;
        for (const auto &l : word)
        {
            int idx = l - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->end = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;
        for (const auto &l : word)
        {
            if (node->children[l - 'a'] == nullptr)
                return false;
            node = node->children[l - 'a'];
        }
        return node->end;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (const auto &l : prefix)
        {
            if (node->children[l - 'a'] == nullptr)
                return false;
            node = node->children[l - 'a'];
        }
        return true;
    }

private:
    void deallocate(TrieNode *node)
    {
        for (int i = 0; i < 26; i++)
        {
            if (node->children[i] != nullptr)
                deallocate(node->children[i]);
        }
        delete node;
    }

public:
    ~Trie()
    {
        deallocate(root);
    }
};

int main()
{
    Trie t = Trie();

    t.insert("apple");
    t.insert("orange");
    t.insert("banana");

    cout << boolalpha;

    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.search("banana") << endl;
    cout << t.search("grapes") << endl;

    cout << t.startsWith("apple") << endl;
    cout << t.startsWith("app") << endl;
    cout << t.startsWith("bat") << endl;
    cout << t.startsWith("grape") << endl;
}