#include <bits/stdc++.h>
using namespace std;
 
int dp[1000001];
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, S, w[20], q[20];  // 슬롯수, 전투력, 중요도, 필수장착여부

    cin>>N>>S;
    for (int i = 0; i < N; i++)
        cin>>w[i]>>q[i];
    
    int base = 0;
    for (int i = 0; i < N; i++)
        base += w[i] * q[i];
    
    dp[base] = 1;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= S; j++)
            if (j + w[i] <= S)
                dp[j + w[i]] = (dp[j + w[i]] + dp[j]) % 1000000009;
    
    int ans = 0;
    for (int i = 0; i <= S; i++)
        ans = (ans + dp[i]) % 1000000009;
    
    cout<<ans;
 
    return 0;
}
