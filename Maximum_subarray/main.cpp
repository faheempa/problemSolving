// question
//  

#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T elems)
{
    for (auto elem : elems)
        cout << elem << " ";
}
void read_string_vector(vector<string> &vec)
{
    string input;
    string word = "";
    getline(cin, input);
    if (input.length() == 0)
        return read_string_vector(vec);
    input += " ";
    for (auto var : input)
    {
        if (var == ' ')
        {
            if (word.length() == 0)
                continue;
            vec.push_back(word);
            word = "";
        }
        else
            word += var;
    }
}
void read_int_vector(vector<int> &vec)
{
    string input;
    getline(cin, input);
    if (input.length() == 0)
        return read_int_vector(vec);
    istringstream is(input);
    vec = vector<int>((istream_iterator<int>(is)), istream_iterator<int>());
}


int solve()
{
}


int main()
{

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {


        cout << "Case #" << i << ": ";
        cout << solve();
        cout << endl;
    }
}