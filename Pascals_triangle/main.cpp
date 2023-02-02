// Question
// https://leetcode.com/problems/pascals-triangle/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

vector<vector<int>> solve(int numRows)
{
    vector<vector<int>> r(numRows);
    for (int i = 0; i < numRows; i++)
    {
        r[i].resize(i + 1);
        r[i][0] = r[i][i] = 1;

        for (int j = 1; j < i; j++)
            r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
    }

    return r;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        cout << "Case #" << i << ": ";
        for (auto var : solve(n))
        {
            cout << endl;
            print(var);
        }
        cout << endl;
    }
}
