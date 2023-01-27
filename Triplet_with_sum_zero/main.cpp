// Question
// from the given list of values, find the number of triplets those sum is 0
// eg: -2 4 -1 3 -3
// output: 1 (that is {0,-3,3})

#include <bits/stdc++.h>
using namespace std;

void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}

class Problem
{
private:
    vector<int> numbers;
    int n;
    int ans;

public:
    Problem()
    {
        ans = 0;
    }
    void input()
    {
        read_int_vector(numbers);
        n = numbers.size();
    }
    void solve()
    {
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < n && numbers.at(i) < 0; i++)
        {
            int target = 0 - numbers.at(i);
            for (int j = i + 1; j < n - 1 && numbers.at(j) < target; j++)
                if (binary_search(numbers.begin() + j + 1, numbers.end(), target - numbers.at(j)) == true)
                    ans++;
        }
    }

    void output()
    {
        cout << ans;
    }
};

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        Problem obj = Problem();
        obj.input();
        obj.solve();
        cout << "Case #" << i << ": ";
        obj.output();
        cout << endl;
    }
}
