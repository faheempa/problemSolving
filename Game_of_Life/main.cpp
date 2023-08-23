// question
// https://leetcode.com/problems/game-of-life/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

int no_of_neighbors(vector<vector<int>> &board, int i, int j)
{
    int count{0}, n = 7;
    int row = board.size(), col = board[0].size();
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    while (n >= 0)
    {
        // if valid
        if (i + dx[n] >= 0 and i + dx[n] < row and j + dy[n] >= 0 and j + dy[n] < col)
        {
            int val = board[i + dx[n]][j + dy[n]];
            if (val == 1 or val == 3)
                count++;
        }
        n--;
    }
    return count;
}
void solve(vector<vector<int>> &board)
{
    // 0 to 0 => 0
    // 1 to 0 => 1
    // 0 to 1 => 2
    // 1 to 1 => 3
    int row = board.size(), col = board[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int neighbors = no_of_neighbors(board, i, j);
            if (board[i][j] == 1 or board[i][j] == 3)
            {
                if (neighbors == 2 or neighbors == 3)
                    board[i][j] = 3;
                else
                    board[i][j] = 1;
            }
            else
            {
                if (neighbors == 3)
                    board[i][j] = 2;
                else
                    board[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == 2 or board[i][j] == 3)
                board[i][j] = 1;
            else
                board[i][j] = 0;
        }
    }
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> board;
        int row, col;
        cin >> row >> col;
        for (int i = 0; i < row; i++)
        {
            vector<int> temp;
            read_int_vector(temp);
            board.push_back(temp);
        }
        cout << "Case #" << i << ": " << endl;
        solve(board);
        for (auto row : board)
        {
            print(row);
            cout << endl;
        }
        cout << endl;
    }
}