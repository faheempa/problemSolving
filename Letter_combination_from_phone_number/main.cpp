// Question
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/

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
    vector<string> mp;
    string s;
    vector<string> ans;
    string word;

public:
    Solution()
    {
        mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    }
    vector<string> solve(string digits)
    {
        if (digits.length() == 0)
            return {};
        this->s = digits;

        dfs(0);
        return ans;
    }
    void dfs(int i)
    {
        if (i == s.length())
        {
            ans.push_back(word);
            return;
        }
        for (const auto &c : mp[s[i] - '0'])
        {
            word.push_back(c);
            dfs(i + 1);
            word.pop_back();
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
        print(sol.solve(s));
        cout << endl;
    }
}
