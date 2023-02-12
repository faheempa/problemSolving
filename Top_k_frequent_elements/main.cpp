// Question
// https://leetcode.com/problems/top-k-frequent-elements/description/

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


vector<int> solve(vector<int> &nums, int k)
{
    map<int, int> map;
    for (const auto &n : nums)
        map[n]++;
    struct Node
    {
        int a;
        int b;
        bool operator<(const Node &other) const
        {
            return b < other.b;
        }
    };
    std::priority_queue<Node> q;
    vector<int> ans;
    ans.reserve(k);
    for (auto const &it : map)
        q.push({it.first, it.second});
    while (k--)
        ans.push_back(q.top().a), q.pop();

    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        vector<int> nums;
        int k;
        read_int_vector(nums);
        cin>>k;
        cout << "Case #" << i << ": ";
        print(solve(nums, k));
        cout << endl;
    }
}
