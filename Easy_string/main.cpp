// Question
// https://www.codechef.com/ALGQ2023/problems/ALGQ7

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
void fastscanInt(int &number);

class Problem
{
private:
    string s;
    um(char, int) map;
    bool ans;

public:
    Problem()
    {
        ans=true;
    }
    void input()
    {
        cin >> s;
        map['e']=0;
        map['a']=1;
        map['s']=2;
        map['y']=3;
    }
    void solve()
    {

        bool condition[]{false, false, false, false};
        for (auto var : s)
        {
            if(map.count(var)>0)
                condition[map[var]]=true;
        }
        for(auto var : condition)
        {
            if(var==false)
            {
                ans=false;
                return;
            }
        }
    }
    void output()
    {
        if(ans)
            cout<<"YES";
        else
            cout<<"NO";
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