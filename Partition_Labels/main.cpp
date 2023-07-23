// question
// https://leetcode.com/problems/partition-labels/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

vector<int> solve(string s)
{
    if (s.length() == 1)
        return {1};
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
        mp[s[i]] = i;
    int end = 0, size = 0;
    vector<int> res;
    for (int i = 0; i < s.length(); i++)
    {
        end = max(end, mp[s[i]]);
        size++;
        if (end == i)
        {
            res.push_back(size);
            size = 0;
        }
    }
    return res;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;

        cout << "Case #" << i << ": ";
        print(solve(s));
        cout << endl;
    }
}