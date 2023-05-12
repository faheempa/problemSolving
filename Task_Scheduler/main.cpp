// Question
// https://leetcode.com/problems/task-scheduler/description/

#include <bits/stdc++.h>
using namespace std;

template <class T>
void read_vector(vector<T> &vec, int &n)
{
    T a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}

template <class T>
vector<pair<T, int>> count(vector<T> &arr)
{
    unordered_map<T, int> mp;
    for (const auto &a : arr)
        mp[a]++;

    vector<pair<T, int>> result;
    for (const auto &c : mp)
        result.push_back({c.first, c.second});

    return result;
}

int solve(vector<char> &tasks, int n)
{
    if (n == 0)
        return tasks.size();
        
    priority_queue<int> tq;
    queue<pair<int, int>> cq;
    int time = 0;

    for (const auto &c : count(tasks))
        if (c.second > 0)
            tq.push(c.second);

    while (not tq.empty() or not cq.empty())
    {
        if (not tq.empty())
        {
            int t = tq.top();
            tq.pop();
            if (t != 1)
                cq.push({t - 1, time + n});
        }
        if (not cq.empty() and cq.front().second <= time)
        {
            tq.push(cq.front().first);
            cq.pop();
        }
        time++;
    }

    return time;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<char> tasks;
        int n, count;
        cin >> count;
        read_vector(tasks, count);
        cin >> n;

        cout << "Case #" << i << ": ";
        cout << solve(tasks, n);
        cout << endl;
    }
}
