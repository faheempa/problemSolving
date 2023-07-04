// Question
// https://leetcode.com/problems/n-queens/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

class Solution
{
    vector<vector<string>> ans;
    vector<string> board;
    string row;
    unordered_set<int> cols;        // c
    unordered_set<int> posDiagonal; // c+r
    unordered_set<int> negDiagonal; // c-r
    int n;

public:
    vector<vector<string>> solve(int n)
    {
        this->n = n;
        string p;
        for (int i = 0; i < n; i++)
            p += '.';

        board = vector<string>(n, p);
        dfs(0);
        return ans;
    }
    void dfs(int r)
    {
        if (r == n)
        {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++)
        {
            if (position_ok(r, c))
            {
                board[r][c] = 'Q';
                add(r, c);
                dfs(r + 1);
                remove(r, c);
                board[r][c] = '.';
            }
        }
    }
    bool position_ok(int r, int c)
    {
        if (cols.find(c) != cols.end() or
            posDiagonal.find(c + r) != posDiagonal.end() or
            negDiagonal.find(c - r) != negDiagonal.end())
            return false;

        return true;
    }
    void remove(int r, int c)
    {
        cols.erase(c);
        posDiagonal.erase(c + r);
        negDiagonal.erase(c - r);
    }
    void add(int r, int c)
    {
        cols.insert(c);
        posDiagonal.insert(c + r);
        negDiagonal.insert(c - r);
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        Solution sol;
        cout << "Case #" << i << ": " << endl;
        for (const auto val : sol.solve(n))
        {
            cout << "[ ";
            print(val);
            cout << "]";
            cout << endl;
        }
        cout << endl;
    }
}
