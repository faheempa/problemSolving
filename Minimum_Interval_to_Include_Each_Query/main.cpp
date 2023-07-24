// question
// https://leetcode.com/problems/minimum-interval-to-include-each-query/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}

vector<int> solve(vector<vector<int>>& intervals, vector<int>& unSortedQueries) {
        unordered_map<int,int> mp;
        vector<int> queries = unSortedQueries;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int j=0;
        vector<int> res(queries.size(), -1);

        sort(intervals.begin(), intervals.end());
        sort(queries.begin(), queries.end());

        for(int i=0; i<queries.size(); i++)
        {
            int q=queries[i];

            while(j<intervals.size()){
                int r=intervals[j][1], l=intervals[j][0];
                if(l>q) break;
                pq.push({r-l+1, r});
                j++;
            }

            while(!pq.empty() and pq.top()[1]<q)
                pq.pop();


            mp[q] = (!pq.empty()) ? pq.top()[0] : -1;
        }

        for(int i=0; i<unSortedQueries.size(); i++)
            res[i]= mp[unSortedQueries[i]];

        return res;
    }


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        int n, m;
        cin >> n >> m;
        vector<vector<int>> intervals(n, vector<int>(2));
        vector<int> queries(m);
        for (int i = 0; i < n; i++)
        {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> queries[i];
        }
        vector<int> ans = solve(intervals, queries);
        print(ans);
        cout << endl;
    }
}