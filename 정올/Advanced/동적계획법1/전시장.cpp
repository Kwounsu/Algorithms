#include<bits/stdc++.h>
using namespace std;
#define H first
#define C second
#define pii pair<int,int>

int N, S;
vector<pii> v;
vector<int> dp;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>N>>S;
    v.resize(N+1), dp.resize(N+1);
    v[0] = {0,0};
    dp[0] = 0;
    for(int i=1;i<=N;i++)
        cin>>v[i].H>>v[i].C;

    sort(v.begin(), v.end());

    int last = 0;
    for(int i=1;i<=N;i++){
        for(int j=last;j<i;j++){
            if(v[j].H + S > v[i].H) break;
            last = j;
        }
        dp[i] = max(dp[i-1], dp[last] + v[i].C);
    }

    cout<<dp[N]<<' ';

    return 0;
}
