#include <bits/stdc++.h>
using namespace std;
vector<int> Generate_All_Possible_Sum(vector<int> &a, int sum)
{
    int n = a.size();
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = sum; j >= a[i]; --j)
            dp[j] += dp[j - a[i]];

    vector<int> possible_sums;
    for (int i = 1; i <= sum; i++)
        if (dp[i])
            possible_sums.push_back(i);
    return possible_sums;
}