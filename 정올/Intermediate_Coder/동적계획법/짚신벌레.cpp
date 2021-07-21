#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
    int a,b,d,N;
    cin>>a>>b>>d>>N;
 
    int dp[N+100000] = {0};
    dp[0] = dp[a] = 1;
 
    // a일 이후 증식, 그리고 b일부터 b일전 개체수 만큼 증식 멈추기
    for(int i = a + 1; i <= N; i++){
        if(i<b)
            dp[i] = (dp[i - 1] + dp[i-a]) % 1000;
        else
            dp[i] = (dp[i - 1] + dp[i - a] - dp[i - b] + 1000) % 1000;
    }
 
    int sum = 0;
    for(int i = N - d + 1; i <= N; i++){
        sum += dp[i];
        sum %= 1000;
    }
 
    sum = (sum + 1000) % 1000;
    printf("%d", sum);
 
    return 0;
}
