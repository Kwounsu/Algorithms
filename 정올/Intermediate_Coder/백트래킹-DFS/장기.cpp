#include <bits/stdc++.h>
using namespace std;

int n, m, s, k, chk[101][101];

void dfs(int lv, int r, int c) {
    // if (r == s && c == k){
    //     if (_min > lv) _min = lv;
    //     return;
    // }
    
    if (r < 1 || r > n || c < 1 || c > m ||
       lv >= chk[r][c] || lv >= chk[s][k])
        return;
    
    chk[r][c] = lv;
    
    dfs(lv + 1, r - 1, c - 2);
    dfs(lv + 1, r - 2, c - 1);
    dfs(lv + 1, r - 1, c + 2);
    dfs(lv + 1, r - 2, c + 1);
    dfs(lv + 1, r + 1, c - 2);
    dfs(lv + 1, r + 2, c - 1);
    dfs(lv + 1, r + 1, c + 2);
    dfs(lv + 1, r + 2, c + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            chk[i][j] = 100;
    
    cin>>n>>m;
    int r, c;
    cin>>r>>c>>s>>k;
    dfs(0, r, c);
    cout<<chk[s][k]<<'\n';
}
