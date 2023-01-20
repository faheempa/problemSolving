// Question
// https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb4d1/0000000000b20f15

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
    string password;
    bool condition[5]{false, false, false, false, false};

public:
    Problem()
    {
    }
    void read_input()
    {
        cin >> password;
    }
    void solve()
    {
        for (auto s : password)
        {
            // A-Z
            if (condition[1] == false && (s >= 65 && s <= 90))
                condition[1] = true;
            // a-Z
            else if (condition[2] == false && (s >= 97 && s <= 122))
                condition[2] = true;
            // 0-9
            else if (condition[3] == false && (s >= 48 && s <= 57))
            {
                // cout << password<< " here" <<e;
                condition[3] = true;
            }
            // # @ * &
            else if (condition[4] == false && (s == 35 || s == 64 || s == 42 || s == 38))
                condition[4] = true;
        }

        if (condition[1] == false)
            password += 'S';
        if (condition[2] == false)
            password += 'n';
        if (condition[3] == false)
            password += '5';
        if (condition[4] == false)
            password += '@';
        if (password.length() >= 7)
            condition[0] = true;
        else
            while (password.length() < 7)
                password += '1';
    }
    void print_output()
    {
        cout << password;
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