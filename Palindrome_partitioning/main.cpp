// Question
// https://leetcode.com/problems/palindrome-partitioning/description/

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
    vector<string> grp;
    string s;

public:
    vector<vector<string>> solve(string s)
    {
        this->s = s;
        dfs(0);
        return ans;
    }
    void dfs(int idx)
    {
        if (idx == s.length())
        {
            ans.push_back(grp);
            return;
        }
        int len = 1;
        while (idx + len <= s.length())
        {
            if (palindrome(s.substr(idx, len)))
            {
                grp.push_back(s.substr(idx, len));
                dfs(idx + len);
                grp.pop_back();
            }
            len++;
        }
    }
    bool palindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;

        Solution sol;
        cout << "Case #" << i << ": ";

        for (const auto &a : sol.solve(s))
        {
            cout << "[ ";
            print(a);
            cout << "]";
        }
        cout << endl;
    }
}
