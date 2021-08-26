#include<bits/stdc++.h>
using namespace std;

int n, m, c, v,w;
char a[1010], b[1010];
int dp[1010][1010];
stack<char> ans_a,ans_b;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    char *p1 = a+1, *p2 = b+1;
    cin>>n>>p1>>m>>p2;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            c = a[i] == b[j] ? 3:-2;
            dp[i][j] = max(dp[i][j], max(dp[i-1][j-1]+c, max(dp[i-1][j]-2, dp[i][j-1]-2)));
            if (dp[v][w] < dp[i][j]){
                v = i, w = j;
            }
        }
    }

    cout<<dp[v][w]<<'\n';

    ans_a.push(a[v]);
    ans_b.push(b[w]);
    while(dp[v][w]){
        if(dp[v][w] == dp[v-1][w]-2){
            v--;
            ans_a.push(a[v]);
        }else if(dp[v][w] == dp[v][w-1]-2){
            w--;
            ans_b.push(b[w]);
        }else{
            v--; w--;
            ans_a.push(a[v]);
            ans_b.push(b[w]);
        }
    }

    ans_a.pop(); ans_b.pop();
    while(!ans_a.empty()) {
        cout<<ans_a.top(); ans_a.pop();
    }
    cout<<'\n';
    while(!ans_b.empty()) {
        cout<<ans_b.top(); ans_b.pop();
    }
    cout<<'\n';

    return 0;
}
