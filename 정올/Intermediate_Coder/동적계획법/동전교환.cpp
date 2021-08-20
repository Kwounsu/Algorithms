#include <bits/stdc++.h>
using namespace std;

#define REP(i,s,e) for (int i = s; i < e; i++)
#define rep(i,e) for (int i = 0; i < e; i++)
#define INF 100000

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, target;
    cin>>n;
    vector<int> coins(n);
    rep(i,n)
        cin>>coins[i];
    cin>>target;

    vector<int> dp(target+1);
    dp[0] = 0;
    REP(i,1,target+1){
        dp[i] = INF;
        for (auto c : coins)
            if (i-c >= 0)
                dp[i] = min(dp[i], dp[i-c]+1);
    }

    if (dp[target] >= INF) cout<<"impossible";
    else cout<<dp[target];

    return 0;
}
