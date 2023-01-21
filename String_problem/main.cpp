// Question
// https://www.codechef.com/ALGQ2023/problems/ALGQ2

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
#define print_vector(a) \
    for (auto var : a)  \
    cout << var << " "
#define lenv(a) int(a.size())
#define lens(a) int(a.length())
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
    int n;
    vector<string> strs;
    int tn;
    string target;
    int size;

public:
    Problem()
    {
        size = 0;
    }
    void input()
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string a;
            cin >> a;
            strs.pb(a);
        }
        cin >> tn;
        cin >> target;
    }
    void solve()
    {
        string sub = "";
        for (int i = 0; i < lens(target) - 1; i++)
        {
            sub += target[i];
            for (int j = i + 1; j < lens(target); j++)
            {
                bool got = false;
                sub += target[j];
                for (auto str : strs)
                {
                    if (str.find(sub) != std::string::npos)
                    {
                        got = true;
                        break;
                    }
                }
                if (not got)
                    break;
            }
            if (lens(sub)>1)
            {
                size += lens(sub)-1;
                i += lens(sub)-2;
            }
            sub = "";
        }
    }
    void output()
    {
        cout << size;
    }
};

int main()
{
    // runtime counter
    // Timer runtime = Timer();

    // multiple test cases
    vector<class Problem> cases;
    int no_of_cases;
    cin >> no_of_cases;

    for (int i = 0; i < no_of_cases; i++)
    {
        Problem obj = Problem();
        obj.input();
        cases.push_back(obj);
    }
    for (int i = 0; i < no_of_cases; i++)
    {
        cases.at(i).solve();
        cout << "Case #" << i + 1 << ": ";
        cases.at(i).output();
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