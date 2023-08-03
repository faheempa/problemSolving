// question
// https://leetcode.com/problems/spiral-matrix/

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

vector<int> solve(vector<vector<int>> &matrix)
{
    int b = matrix.size() - 1;
    int r = matrix[0].size() - 1;
    int t{0}, l{0};
    vector<int> res;

    while (l <= r and t <= b)
    {
        for (int i = l; i <= r; i++)
            res.push_back(matrix[t][i]);
        t++;
        for (int i = t; i <= b; i++)
            res.push_back(matrix[i][r]);
        r--;
        if (!(l <= r and t <= b))
            break; // incase of single row or single column matrix
        for (int i = r; i >= l; i--)
            res.push_back(matrix[b][i]);
        b--;
        for (int i = b; i >= t; i--)
            res.push_back(matrix[i][l]);
        l++;
    }

    return res;
}

// function to read data from a webpage ?


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; i++)
            read_int_vector(matrix[i]);

        cout << "Case #" << i << ": ";
        print(solve(matrix));

        cout << endl;
    }
}