// quesion
// give an array of numbers(can have -ve values and zeros)
// return a array of products of all elements in the given array, except the element at current index
// nums: 1 2 3 4
// ans: 24 12 8 6
// explanation: 2*3*4=24, 1*3*4=12, 1*2*4=8, 1*2*3=6

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
#define pll pair<long, long>
#define pb push_back
#define um(a, b) unordered_map<a, b>
vector<int> read_an_int_vector();
vector<int> read_an_int_vector(int n);

class Problem
{
private:
    vi nums;
    vi ans;

public:
    Problem()
    {
    }
    void read_input()
    {
        nums = read_an_int_vector();
    }
    void solve()
    {
        int product = 1;
        bool zero = false;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) != 0)
                product *= nums.at(i);
            else
                zero = true;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.at(i) != 0 and zero)
                ans.push_back(0);
            else if (nums.at(i) != 0)
                ans.push_back(product / nums.at(i));
            else
                ans.push_back(product);
        }
    }
    void print_output()
    {
        for (int var : ans)
        {
            cout << var << " ";
        }
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