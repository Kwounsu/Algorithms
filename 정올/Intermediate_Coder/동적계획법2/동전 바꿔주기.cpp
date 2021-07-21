#include <bits/stdc++.h>
using namespace std;

int t, k;
struct Coin{
    int p, n;
}coins[101];

int dp[101][10001]; // dp[k][t] = t원의 지폐를 k개의 동전으로 교환하는 경우의 수
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t>>k;
    for(int i = 1; i <= k; i ++){
        cin>>coins[i].p>>coins[i].n;
    }
    
    dp[0][0] = 1;
    for(int i = 1; i <= k; i ++){
        for(int j = 0; j <= coins[i].n; j ++){
            int val = coins[i].p * j;
            for(int k = val; k <= t; k ++){
                dp[i][k] += dp[i - 1][k - val];
            }
        }
    }
    
    printf("%d", dp[k][t]);
    
    return 0;
}
