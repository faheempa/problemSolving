// Question

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define e "\n"
#define vi vector<int>
#define vll vector<long long>
#define pq priority_queue<int, std::vector<int>, std::greater<int>>
#define pq_rev priority_queue<int>
#define pql priority_queue<long long, std::vector<long long>, std::greater<long long>>
#define pql_rev priority_queue<long long>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define um(a, b) unordered_map<a, b>
#define print(a)       \
    for (auto var : a) \
    cout << var << " "
#define lenv(a) int(a.size())
#define lens(a) int(a.lenght())
const long double PI = 3.141592653589793;
class Timer
{
    std::chrono::_V2::system_clock::time_point start, end;

public:
    Timer() { start = std::chrono::high_resolution_clock::now(); }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "\nRun time: " << std::fixed << std::setprecision(3) << float(duration.count()) / 1000 << " ms"
                  << "\n";
    }
};
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);

class Problem
{
private:
    int n;
    vector<vi> soln;

public:
    Problem()
    {
    }
    void input()
    {
        cin >> n;
    }
    void solve()
    {
        for (int i = 0; i < n; i++)
        {
            vi row;
            for (int j = 0; j <= i; j++)
                if (j == 0 || j == i)
                    row.pb(1);
                else
                    row.pb(soln.at(i - 1).at(j) + soln.at(i - 1).at(j - 1));
            soln.pb(row);
        }
    }
    void output()
    {
        for (auto var : soln)
        {
            cout << e;
            print(var);
        }
    }
};

int main()
{
    // runtime counter
    // Timer runtime = Timer();

    // multiple test cases
    int no_of_cases, c = 1;
    cin >> no_of_cases;
    vector<class Problem> problems(no_of_cases);
    for (auto problem : problems)
    {
        problem.input();
        problem.solve();
        cout << "Case #" << c++ << ": ";
        problem.output();
        cout << e;
    }

    // single test case
    // Problem obj = Problem();
    // obj.input();
    // obj.solve();
    // obj.output();
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