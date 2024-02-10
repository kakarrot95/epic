#include<iostream>
#include<string>
using namespace std;


int solve(string s){
    int n = s.size();
    int dp[n + 1];
    for (auto &x:dp)
        x = 0;
    for (int i = 1; i <= n; i++)
    {
        int new_dp[n + 1];
        for (auto &x:new_dp)
            x = 0;
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == s[j - 1] && i != j)
            {
                new_dp[j] = dp[j - 1] + 1;
            }
            else
            {
                new_dp[j] = max(dp[j], new_dp[j - 1]);
            }
        }
        for (int j = 0; j <= n; j++)
            dp[j] = new_dp[j];
        }
    return dp[n];
}

int main(){
    string s;
    cin >> s;
    cout << solve(s);
}