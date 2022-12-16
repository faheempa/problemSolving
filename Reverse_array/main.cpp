// quesion
// https://www.hackerrank.com/challenges/arrays-ds/problem?isFullScreen=true

#include <bits/stdc++.h>
#include <boost/algorithm/string.hpp>
using namespace std;
#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define vf vector<float>
#define vb vector<bool>
#define vll vector<long long>
#define ll long long
#define e endl
#define pq priority_queue<int, std::vector<int>, std::greater<int>>
#define pq_rev priority_queue<int>
#define pql priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define pql_rev priority_queue<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define q(a) queue<a>
#define pb push_back
#define qll queue<ll>
#define um(a, b) unordered_map<a, b>
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);

class Problem
{
private:
    vi nums;

public:
    Problem()
    {
    }
    void read_input()
    {
        nums = read_an_int_vector();
    }
    void solve()
    {
        int n = nums.size();
        int i = 0, j = n - 1;
        while (i < j)
            swap(nums.at(i++), nums.at(j--));
    }
    void print_output()
    {
        for (auto var : nums)
        {
            cout << var << " ";
        }
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

// user defined functions
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
