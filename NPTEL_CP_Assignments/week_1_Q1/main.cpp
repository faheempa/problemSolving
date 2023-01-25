#include <bits/stdc++.h>
using namespace std;

struct min_max_heap
{
    int val;
    pair<int, int> range;
    bool operator<(const min_max_heap &b) const
    {
        return val < b.val;
    }
};

class Problem
{
private:
    vector<int> nums;
    int n;
    priority_queue<min_max_heap> Q;
    int ans;

public:
    Problem()
    {
        ans = 0;
    }

    void input()
    {
        cin >> n;
        nums = vector<int>(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
    }

    void solve()
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                Q.push({abs(nums[i] - nums[j]), {i, j}});

        while (!Q.empty())
        {
            auto value = Q.top();
            int l = value.range.first, r = value.range.second;
            if (l == 0 || r == n - 1 || r == l - 1)
            {
                ans = value.val;
                return;
            }
            Q.pop();
        }
    }

    void output()
    {
        cout << ans;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Problem problem;
        problem.input();
        problem.solve();
        cout << "Case #" << i << ": ";
        problem.output();
        cout << endl;
    }
}
