// question
// https://leetcode.com/problems/set-matrix-zeroes/

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

void solve(vector<vector<int>> &matrix)
{
    int r = matrix.size();
    if (r == 0)
        return;
    int c = matrix[0].size();
    bool firstRow{false}, firstCol{false};

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (i == 0)
                    firstRow = true;
                if (j == 0)
                    firstCol = true;
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < r; i++)
        for (int j = 1; j < c; j++)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;

    if (firstRow)
        for (int j = 0; j < c; j++)
            matrix[0][j] = 0;

    if (firstCol)
        for (int i = 0; i < r; i++)
            matrix[i][0] = 0;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> matrix;
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            vector<int> row;
            read_int_vector(row);
            matrix.push_back(row);
        }
        
        cout << "Case #" << i << ": "<< endl;
        solve(matrix);
        for (auto row : matrix)
        {
            print(row);
            cout << endl;
        }
    }
}