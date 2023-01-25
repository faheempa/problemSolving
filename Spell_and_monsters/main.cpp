// Question
// https://codeforces.com/contest/1792/problem/0

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
#define print(a) for (auto var : a) cout << var << " "
#define size(a) int(a.size())
#define len(a) int(a.lenght())
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
void read_int_vector(vi &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}
void read_int_vector(vi &vec, int n)
{
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        vec.push_back(a);
    }
}



class Problem
{
private:
    int n;
    int count;

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
        // logic - monsters with health one can killed using spell 1 (in pair) and rest with spell 2
        int ones = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 1)
                ones++;
        }
        if (ones == 0)
            count = n;
        if (ones % 2 == 0)
            count = ones / 2 + n - ones;
        else
            count = ones / 2 + (n - ones) + 1;
    }
    void output()
    {
        cout << count;
    }
};

int main()
{
    // runtime counter
    Timer runtime = Timer();

    // testing multiple inputs
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        Problem obj = Problem();
        obj.input();
        obj.solve();
        cout << "Case #" << i << ": ";
        obj.output();
        cout << e;
    }
}
