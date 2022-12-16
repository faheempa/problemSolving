// question
// https://leetcode.com/problems/roman-to-integer/

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
    string roman;
    int ans;
    um(char, int) mp;

public:
    Problem()
    {
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        ans = 0;
    }
    void read_input()
    {
        cin >> roman;
    }
    void solve()
    {
        int pre = 0;
        for (auto var : roman)
        {
            if (pre == 1 and (var == 'V' or var == 'X'))
                ans += mp.at(var) - 2*pre;
            else if (pre == 10 and (var == 'L' or var == 'C'))
                ans += mp.at(var) - 2*pre;
            else if (pre == 100 and (var == 'D' or var == 'M'))
                ans += mp.at(var) - 2*pre;
            else
                ans += mp.at(var);

            pre = mp.at(var);
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