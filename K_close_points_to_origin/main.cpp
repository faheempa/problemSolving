// Question
// https://leetcode.com/problems/k-closest-points-to-origin/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

// alternate solution - same logic
// class Solution
// {
// public:
//     vector<vector<int>> solve(vector<vector<int>> &points, int k)
//     {
//         vector<vector<int>> triples;
//         for (auto &p : points)
//             triples.push_back({p[0] * p[0] + p[1] * p[1], p[0], p[1]});

//         priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq(triples.begin(), triples.end());
//         vector<vector<int>> res;
//         while (k--)
//         {
//             vector<int> el = pq.top();
//             pq.pop();
//             res.push_back({el[1], el[2]});
//         }
//         return res;
//     }
// };

class Solution
{
    struct point
    {
        int x;
        int y;
        bool operator<(const point &o) const
        {
            return std::sqrt((x * x) + (y * y)) > std::sqrt((o.x * o.x) + (o.y * o.y));
        }
    };
    std::priority_queue<point> q;

public:
    vector<vector<int>> solve(vector<vector<int>> &points, int k)
    {
        for (const auto &point : points)
        {
            int x = point[0];
            int y = point[1];
            q.push({x, y});
        }
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back({q.top().x, q.top().y});
            q.pop();
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> nums;
        int r, k;
        cin >> r;
        for (int i = 0; i < r; i++)
        {
            vector<int> t;
            read_int_vector(t);
            nums.push_back(t);
        }
        cin >> k;

        Solution sol;
        cout << "Case #" << i << ": ";
        for (const auto &point : sol.solve(nums, k))
        {
            cout << "[ ";
            print(point);
            cout << "]";
        }
        cout << endl;
    }
}
