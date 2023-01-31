// Question
// flood fill. 

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T &elems)
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

void solve(int x, int y, int color, vector<vector<int>> &arr)
{
    int old_color = arr.at(x).at(y);
    arr.at(x).at(y) = color;
    if (x - 1 >= 0 && arr.at(x - 1).at(y) == old_color)
        solve(x - 1, y, color, arr);
    if (y - 1 >= 0 && arr.at(x).at(y - 1) == old_color)
        solve(x, y - 1, color, arr);
    if (x + 1 < 10 && arr.at(x + 1).at(y) == old_color)
        solve(x + 1, y, color, arr);
    if (y + 1 < 10 && arr.at(x).at(y + 1) == old_color)
        solve(x, y + 1, color, arr);
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<vector<int>> arr;
        int color, x, y;
        for (int i = 0; i < 10; i++)
        {
            vector<int> v;
            read_int_vector(v);
            arr.push_back(v);
        }
        cin >> x >> y >> color;
        cout << "Case #" << i << ": "<<endl;
        solve(x, y, color, arr);
        for (auto var : arr)
        {
            print(var);
            cout << endl;
        }
        cout << endl;
    }
}
