// Question
// https://leetcode.com/problems/word-search-ii/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    input += " ";
    for (auto var : input)
    {
        if (var == ' ')
        {
            if (word.length() == 0)
                continue;
            vec.push_back(word);
            word = "";
        }
        else
            word += var;
    }
}
template <class T>
void read_vector(vector<T> &vec, int &n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}

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

public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        int idx;
        TrieNode *node = root;

        for (const auto &l : word)
        {
            idx = l - 'a';
            if (node->children[idx] == NULL)
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->end = true;
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

vector<string> ans;

void search(vector<vector<char>> &board, int i, int j, TrieNode *node, string word)
{
    int r = board.size(), c = board[0].size();
    if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == '#')
        return;

    char ch = board[i][j];

    node = node->children[ch - 'a'];
    if (node == NULL)
        return;

    word += board[i][j];
    if (node->end)
    {
        ans.push_back(word);
        node->end = false;
    }

    board[i][j] = '#';

    search(board, i - 1, j, node, word);
    search(board, i + 1, j, node, word);
    search(board, i, j - 1, node, word);
    search(board, i, j + 1, node, word);

    board[i][j] = ch;
}

vector<string> solve(vector<vector<char>> &board, vector<string> &words)
{
    Trie t = Trie();
    for (int i = 0; i < words.size(); i++)
    {
        t.insert(words[i]);
    }

    int r = board.size(), c = board[0].size();

    TrieNode *node = t.root;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            search(board, i, j, node, "");
        }
    }

    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<char>> board;
        vector<string> words;
        int r, c;
        string s;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            vector<char> row;
            read_vector(row, c);
            board.push_back(row);
        }
        read_string_vector(words);

        cout << "Case #" << i << ": ";
        print(solve(board, words));
        cout << endl;
    }
}
