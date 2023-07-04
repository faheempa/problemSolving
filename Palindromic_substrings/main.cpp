// Question
// https://leetcode.com/problems/palindromic-substrings/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(string s)
    {
        int result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            middleOut(s, i, i, result);
            middleOut(s, i, i + 1, result);
        }

        return result;
    }

    void middleOut(string s, int i, int j, int &result)
    {
        while (i >= 0 && j < s.size() && s[i] == s[j])
        {
            result++;
            i--;
            j++;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin>>s;
        Solution sol;
        cout << "Case #" << i << ": ";
        cout << sol.solve(s);
        cout << endl;
    }
}
