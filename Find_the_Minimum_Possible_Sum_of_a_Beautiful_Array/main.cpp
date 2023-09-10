// question
// https://leetcode.com/contest/weekly-contest-360/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

#include <bits/stdc++.h>
using namespace std;

long long solve(int n, int target)
{
    unordered_set<int> set;
    long long val{1};
    long long sum{0};
    for (int i = 0; i < n; i++)
    {
        while (set.find(val) != set.end() or set.find(target - val) != set.end())
        {
            val++;
        }
        set.insert(val);
        sum += val;
    }
    return sum;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n, target;
        cin >> n >> target;
        cout << "Case #" << i << ": ";
        cout << solve(n, target);
        cout << endl;
    }
}