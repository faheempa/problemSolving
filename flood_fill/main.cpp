// Question

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
#define um(a, b) unordered_map<a, b>
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
void fastscanInt(int &number);

class Problem
{
private:
    vector<vector<int>> arr;
    int color;
    int x;
    int y;

public:
    Problem()
    {
    }
    void read_input()
    {
        for (int i = 0; i < 10; i++)
        {
            vi v = read_an_int_vector();
            arr.pb(v);
        }
        fastscanInt(x);
        fastscanInt(y);
        fastscanInt(color);
    }
    void solve()
    {
        helper(x, y);
    }
    void helper(int x, int y)
    {
        int old_color = arr.at(x).at(y);
        arr.at(x).at(y) = color;
        if (x - 1 >= 0 && arr.at(x - 1).at(y) == old_color)
            helper(x - 1, y);
        if (y - 1 >= 0 && arr.at(x).at(y - 1) == old_color)
            helper(x, y - 1);
        if (x + 1 < 10 && arr.at(x + 1).at(y) == old_color)
            helper(x + 1, y);
        if (y + 1 < 10 && arr.at(x).at(y + 1) == old_color)
            helper(x, y + 1);
    }
    void print_output()
    {
        cout << e;
        for (auto vec : arr)
        {
            for (auto elm : vec)
                cout << elm << " ";
            cout << e;
        }
    }
};

int main()
{
    // runtime counter
    // Timer runtime = Timer();

    // multiple test cases
    vector<class Problem> cases;
    int no_of_cases;
    fastscanInt(no_of_cases);

    for (int i = 0; i < no_of_cases; i++)
    {
        Problem obj = Problem();
        obj.read_input();
        cases.push_back(obj);
    }
    for (int i = 0; i < no_of_cases; i++)
    {
        cases.at(i).solve();
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).print_output();
        cout << e;
    }

    // single test case
    // Problem obj = Problem();
    // obj.read_input();
    // obj.read_input();
    // obj.solve();
    // obj.print_output();
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
        fastscanInt(a);
        vec.push_back(a);
    }
    return vec;
}
void fastscanInt(int &number)
{
    bool negative = false;
    int c;
    number = 0;
    c = getchar();
    if (c == '-')
    {
        negative = true;
        c = getchar();
    }
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;
    if (negative)
        number *= -1;
}