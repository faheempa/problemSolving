// Question
// https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define e endl
#define vi vector<int>
#define vll vector<long long>
#define pq priority_queue<int, std::vector<int>, std::greater<int>>
#define pq_rev priority_queue<int>
#define pql priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define pql_rev priority_queue<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define um(a, b) unordered_map<a, b>
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);

class Problem
{
private:
    vi values;
    int cost;

public:
    Problem()
    {
        cost = 0;
    }
    void read_input()
    {
        int size;
        cin >> size;
        values = read_an_int_vector(size);
    }
    void solve()
    {
        for (int i = 0; i < values.size() - 1; i++)
        {
            int m = *min_element(values.begin() + i, values.end());
            auto x = find(values.begin(), values.end(), m);
            reverse(values.begin() + i, x + 1);
            cost += distance(values.begin(), x) - i + 1;
        }
    }
    void print_output()
    {
        cout<<cost;
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