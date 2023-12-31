#include <bits/stdc++.h>
using namespace std;
// must be a character array while tokenizing
// Delimiter means basis "$" or " " or "c"
vector<string> string_tokenize(char *s, char *delimiter)
{
    vector<string> v;
    char *token = strtok(s, delimiter);
    while (token != NULL)
    {
        v.push_back(token);
        token = strtok(NULL, delimiter);
    }
    return v;
}
vector<int> integer_tokenize(char *s, char *delimiter)
{
    vector<int> v;
    char *token = strtok(s, delimiter);
    while (token != NULL)
    {
        v.push_back(stoi(token));
        token = strtok(NULL, delimiter);
    }
    return v;
}

void read_full(string &s)
{
    getline(cin, s);
}

void read_input(vector<int> &v)
{
    int x;
    while (cin >> x)
        v.push_back(x);
}