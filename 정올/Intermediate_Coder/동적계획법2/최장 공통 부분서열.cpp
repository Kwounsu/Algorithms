#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char s1[1001], s2[1001];
    cin>>s1>>s2;

    int len1 = strlen(s1), len2 = strlen(s2);

    // LCS
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }

    cout<<dp[len1][len2];

    return 0;
}
