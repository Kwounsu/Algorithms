#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    char s1[1001], s2[1001];
    int len1, len2;
    cin>>len1>>s1>>len2>>s2;

    for (int i = 0; i <= len1; i++) dp[i][0] = i;
    for (int i = 0; i <= len2; i++) dp[0][i] = i;

    // Minimum Edit Distance (최소 편집 거리)
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s2[j-1])  // 같은경우 편집x
                dp[i][j] = dp[i-1][j-1];
            else  // min(삭제, 추가, 교체)
                dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
        }
    }

    cout<<dp[len1][len2];

    return 0;
}
