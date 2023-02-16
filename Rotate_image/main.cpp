// Question
// https://leetcode.com/problems/rotate-image/description/

#include <bits/stdc++.h>
using namespace std;
template<class T>
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
    int t = 0, b = matrix.size() - 1, l = 0, r = b;
    while (l < r)
    {
        for (int i = 0; i < r-l; i++)
        {
            int temp = matrix[t][l + i];
            matrix[t][l+i] = matrix[b-i][l];
            matrix[b-i][l] = matrix[b][r-i];
            matrix[b][r-i] = matrix[t+i][r];
            matrix[t+i][r] = temp;
        }
        l++, r--, t++, b--;
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> matrix;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            read_int_vector(temp);
            matrix.push_back(temp);
        }
        cout << "Case #" << i << ": " << endl;
        solve(matrix);
        for (const auto &a : matrix)
            print(a), cout << endl;
    }
}
