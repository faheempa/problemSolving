// question
// https://www.lintcode.com/problem/919/

#include <bits/stdc++.h>
using namespace std;


int solve(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int end{INT_MAX};
    int count{0};
    int res{0};
    for (int i = 0; i < intervals.size(); i++)
    {
        int nextBeg=intervals[i][0];
        int nextEnd=intervals[i][1];
        
        if(nextBeg < end)
        {
            count++;
            res=max(res, count);
            end=min(end, nextEnd);
        }
        else
        {
            count--;
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
        int n;
        cin>>n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for(int i=0; i<n; i++)
        {
            cin>>intervals[i][0]>>intervals[i][1];
        }

        cout << "Case #" << i << ": ";
        cout << solve(intervals);
        cout << endl;
    }
}