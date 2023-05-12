// Question
// https://leetcode.com/problems/word-search/description/

#include <bits/stdc++.h>
using namespace std;

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

bool check(int i, int j, vector<vector<char>> &board, string word, int idx)
{
    if (idx == word.length())
        return true;
    if (i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or board[i][j] != word[idx])
        return false;

    char temp = board[i][j];
    board[i][j] = '.';
    bool res = check(i + 1, j, board, word, idx + 1) or check(i, j + 1, board, word, idx + 1) or check(i - 1, j, board, word, idx + 1) or check(i, j - 1, board, word, idx + 1);
    board[i][j] = temp;
    return res;
}
bool solve(vector<vector<char>> &board, string word)
{
    if (word.size() > board.size() * board[0].size())
        return false;

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == word[0] and check(i, j, board, word, 0))
                return true;
        }
    }

    return false;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<char>> board;
        int r, c;
        string s;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            vector<char> row;
            read_vector(row, c);
            board.push_back(row);
        }
        cin >> s;

        cout << "Case #" << i << ": ";
        cout << boolalpha;
        cout << solve(board, s);
        cout << endl;
    }
}
