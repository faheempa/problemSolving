// question
// https://leetcode.com/problems/detect-squares/description/

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

class DetectSquares
{
public:
    DetectSquares() {}

    void add(vector<int> point)
    {
        mp[{point[0], point[1]}]++;
    }

    int count(vector<int> point)
    {
        int res{0};
        int dx = point[0], dy = point[1];
        for (auto &m : mp)
        {
            int x = m.first.first, y = m.first.second;
            if (abs(x - dx) == abs(y - dy) and (x != dx and y != dy))
            {
                int d2count = mp[{x, y}];
                int a1count = mp[{x, dy}];
                int a2count = mp[{dx, y}];
                res = d2count * a1count * a2count;
            }
        }
        return res;
    }

private:
    map<pair<int, int>, int> mp;
};

int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": " << endl;
        auto *obj = new DetectSquares();
        int q;
        cin >> q;
        while (q--)
        {
            string s;
            cin >> s;
            if (s == "add")
            {
                vector<int> point;
                read_int_vector(point);
                obj->add(point);
                cout << "added " << point[0] << " " << point[1] << endl;
            }
            else if (s == "count")
            {
                vector<int> point;
                read_int_vector(point);
                cout << "count: " << obj->count(point) << " " << endl;
            }
        }
        cout << endl;
    }
}