// question
// https://leetcode.com/problems/counting-bits/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

vector<int> solve(int n)
{
    int count = n + 1;
    vector<int> dp(count);
    int offset = 1;
    dp[0] = 0;
    for (int i = 1; i < count; i++)
    {
        if (i == offset * 2)
            offset = i;
        dp[i] = 1 + dp[i - offset];
    }
    return dp;
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