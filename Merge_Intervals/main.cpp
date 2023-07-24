// question
// https://leetcode.com/problems/merge-intervals/description/

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    input += " ";
    for (auto var : input)
    {
        if (var == ' ')
        {
            if (word.length() == 0)
                continue;
            vec.push_back(word);
            word = "";
        }
        else
            word += var;
    }
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


vector<vector<int>> solve(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return {};
        vector<vector<int>> res;

        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
           return a[0] < b[0]; 
        });

        int beg=intervals[0][0], end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0]>end)
            {
                res.push_back({beg, end});
                beg=intervals[i][0];
                end=intervals[i][1];
            }
            else
            {
                end = max(end, intervals[i][1]);
            }
        }
        res.push_back({beg, end});
        return res;
    }


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for(int i=0; i<n; i++)
        {
            cin>>intervals[i][0]>>intervals[i][1];
        }

        cout << "Case #" << i << ": ";
        auto res = solve(intervals);
        for(auto var: res)
        {
            cout<<"["<<var[0]<<" "<<var[1]<<"] ";
        }
        cout << endl;
    }
}