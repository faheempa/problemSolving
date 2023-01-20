// question
// consider the following algorithm:
// while n > 1 do
//     if n mod 2 = 0:
//         n=n/2
//     else:
//         n=3*n+3
//
// An input number n is given, check whether the number loop forever?
// print yes if it loops forever, else print no.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
class Timer
{
    std::chrono::_V2::system_clock::time_point start, end;

public:
    Timer() { start = std::chrono::high_resolution_clock::now(); }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "\nRun time: " << std::fixed << std::setprecision(3) << duration.count() / 1000000 << "s " << (duration.count() / 1000) % 1000 << "ms"
                  << "\n";
    }
};
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);
void fastscanInt(int &number);

class Problem
{
private:
    int n;
    string ans;

public:
    Problem()
    {
    }
    void read_input()
    {
        fastscanInt(n);
    }
    void solve()
    {
        if ((n ^ (n - 1) & n ^ n) == false)
            ans = "no";
        else
            ans = "yes";
    }
    void print_output()
    {
        cout << ans;
    }
};

int main()
{
    // runtime counter
    Timer runtime = Timer();

    // multiple test cases
    vector<class Problem> cases;
    int no_of_cases;
    fastscanInt(no_of_cases);

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
        cin >> a;
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