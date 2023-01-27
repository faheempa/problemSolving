// question
// [25, 10, 5, 3, 1, 1, 2, 3, 7, 3]
// k = 15
// return the size of biggest subarray that add upto k
// 6

#include <bits/stdc++.h>
using namespace std;

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

int solve(vector<int> numbers, int k)
{
    int ans = 0, i = 0, sum = 0, n = numbers.size();
    queue<int> Q;
    Q.push(numbers.at(i));
    sum += numbers.at(i++);
    while (!Q.empty())
    {
        if (Q.front() > k and i < n)
        {
            while (!Q.empty())
                Q.pop();
            sum = 0;
            Q.push(numbers.at(i));
            sum += numbers.at(i++);
            continue;
        }
        if (sum < k and i < n)
        {
            Q.push(numbers.at(i));
            sum += numbers.at(i++);
        }
        else if (sum == k)
        {
            if (ans < int(Q.size()))
                ans = Q.size();
            sum -= Q.front();
            Q.pop();
            if (Q.empty())
            {
                Q.push(numbers.at(i));
                sum += numbers.at(i++);
            }
        }
        else
        {
            sum -= Q.front();
            Q.pop();
        }
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<int> numbers;
        int k;
        numbers = read_an_int_vector();
        cin >> k;
        cout << solve(numbers, k) << endl;
    }

    return 0;
}

