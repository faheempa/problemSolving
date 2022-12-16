// question
// https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vf vector<float>
#define vb vector<bool>
#define vll vector<long long>
#define ll long long
#define e endl
#define PQ priority_queue<int, std::vector<int>, std::greater<int>>
#define PQ_rev priority_queue<int>
#define PQL priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define PQL_rev priority_queue<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define um(a, b) unordered_map<a, b>

const double PI = 3.1415926535897932384626433;

vector<int> read_an_int_vector()
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_an_int_vector();
    istringstream is(input);
    vector<int> vec((istream_iterator<int>(is)), istream_iterator<int>());
    return vec;
}
vector<int> read_an_int_vector(int n)
{
    int a;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    return vec;
}

class Problem
{
private:
    vi nums;
    int target;
    pii ans;

public:
    Problem()
    {
        ans = pair(-1, -1);
    }
    void read_input()
    {
        nums = read_an_int_vector();
        cin >> target;
    }
    void solve()
    {
        int n = nums.size();
        um(int, int) mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums.at(i)) > 0)
            {
                ans = pair(mp.at(nums.at(i)), i);
                return;
            }
            mp[target - nums.at(i)] = i;
        }
    }
    void print_output()
    {
        cout << ans.first << " " << ans.second;
    }
};

int main()
{
    int no_of_cases;
    vector<class Problem> cases;
    cin >> no_of_cases;

    for (int i = 0; i < no_of_cases; i++)
    {
        Problem obj = Problem();
        obj.read_input();
        obj.solve();
        cases.push_back(obj);
    }
    for (int i = 0; i < no_of_cases; i++)
    {
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).print_output();
        cout << e;
    }

    return 0;
}



