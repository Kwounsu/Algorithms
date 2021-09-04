#include <bits/stdc++.h>
using namespace std;
#define REP(i,s,e) for(int i=(s);i<=(e);i++)
 
int n, dice[10101][6], u, ans;
int match[6] = {5,3,4,1,2,0};
 
void dfs(int step, int up, int sum){
    if(step > n) {
        ans = max(ans,sum);
        return;
    }
    int idx, m=0;
    REP(j,0,5)
        if(dice[step][j] == up){
            idx=j;
            break;
        }
    int down = dice[step][match[idx]];
    REP(j,0,5){
        if(j == idx || j == match[idx]) continue;
        else m = max(m,dice[step][j]);
    }
    dfs(step+1, down, sum+m);
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
 
    cin>>n;
    REP(i,1,n) REP(j,0,5) cin>>dice[i][j];
 
    REP(i,0,5) dfs(1, dice[1][i], 0);
 
    cout<<ans<<'\n';
 
    return 0;
}
