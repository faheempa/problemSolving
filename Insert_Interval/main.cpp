// question
// https://leetcode.com/problems/insert-interval/description/

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

vector<vector<int>> solve(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int i = 0;
    int n = intervals.size();
    vector<vector<int>> result;

    while (i < n && intervals[i][1] < newInterval[0])
        result.push_back(intervals[i++]);

    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    result.push_back(newInterval);

    while (i < n)
        result.push_back(intervals[i++]);

    return result;
}

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> intervals;
        vector<int> newInterval;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            read_int_vector(temp);
            intervals.push_back(temp);
        }
        read_int_vector(newInterval);

        cout << "Case #" << i << ": ";
        auto result = solve(intervals, newInterval);
        for (auto var : result)
        {
            cout<<"["<<var[0]<<" "<<var[1]<<"] ";
        }
        cout << endl;
    }
}