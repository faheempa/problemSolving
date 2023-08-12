// question
// https://leetcode.com/problems/zigzag-conversion/description/

#include <bits/stdc++.h>
using namespace std;

string solve(string s, int rowsNo)
{
    if (rowsNo == 1 or s.size() == 1)
        return s;
    int row{1}, i{0};
    vector<string> res(rowsNo + 1);
    while (i < s.size())
    {
        while (i < s.size() and row <= rowsNo)
            res[row++] += s[i++];
        row -= 2;
        while (i < s.size() and row > 0)
            res[row--] += s[i++];
        row += 2;
    }
    string result;
    for (auto &a : res)
        result += a;

    return result;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        int rowsNo;
        cin >> s >> rowsNo;
        cout << "Case #" << i << ": ";
        cout << solve(s,rowsNo);
        cout << endl;
    }
}