// question
// https://leetcode.com/problems/longest-common-prefix/

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
#define q queue<int>
#define pb push_back
#define qll queue<ll>
#define um(a, b) unordered_map<a, b>
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);
vector<string> read_a_string_vector();
vector<string> read_a_string_vector(int n);

class Problem
{
private:
    vs words;
    string ans;

public:
    Problem()
    {
        ans = "";
    }
    void read_input()
    {
        words = read_a_string_vector();
    }
    void solve()
    {
        int i = 0;
        while (true)
        {
            char s = words.at(0)[i];
            for (auto word : words)
            {
                if (s != word[i])
                    return;
            }
            ans = ans + s;
            i++;
        }
    }
    void print_output()
    {
        cout << ans;
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
vector<string> read_a_string_vector()
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_a_string_vector();
    vector<string> vec;
    boost::split(vec, input, boost::is_any_of(" "));
    return vec;
}
vector<string> read_a_string_vector(int n)
{
    string a;
    vector<string> vec;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
    return vec;
}