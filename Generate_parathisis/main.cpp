// Question
// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

vector<string> ans;
int n;
void fun(string s, int open, int close)
{
    if (open == close and open == n)
    {
        ans.push_back(s);
        return;
    }

    if (open < n)
        fun(s + "(", open + 1, close);
    if (close < open)
        fun(s + ")", open, close + 1);
}
vector<string> solve(int n1)
{
    n = n1;
    fun("", 0, 0);
    return ans;
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
        print(solve(n));
        cout << endl;
    }
}
