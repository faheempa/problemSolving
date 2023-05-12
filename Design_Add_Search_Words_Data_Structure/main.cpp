// Question
// https://leetcode.com/problems/design-add-and-search-words-data-structure/description/

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

    void addWord(string word)
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
        return _search(root, word);
    }

private:
    bool _search(TrieNode *node, string word, int i = 0)
    {
        if (node == NULL)
            return false;

        if (i == word.size())
            return node->end;

        if (word[i] != '.')
            return _search(node->children[word[i] - 'a'], word, i + 1);

        for (int j = 0; j < 26; j++)
            if (_search(node->children[j], word, i + 1))
                return true;

        return false;
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

    t.addWord("hello");
    t.addWord("hey");
    t.addWord("hai");
    t.addWord("hloo");

    cout<<boolalpha;
    cout<<t.search("hey")<<endl;
    cout<<t.search("he.")<<endl;
    cout<<t.search("h.y")<<endl;
    cout<<t.search("..y")<<endl;
    cout<<t.search(".e.")<<endl;
    cout<<t.search("hxy")<<endl;
    cout<<t.search("h.y.")<<endl;
    cout<<t.search("..")<<endl;
    cout<<t.search(".")<<endl;
}
