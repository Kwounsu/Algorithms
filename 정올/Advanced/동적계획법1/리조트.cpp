#include<bits/stdc++.h>
using namespace std;
#define MAX 98765432
int d[128][41], N, M, x, C;
bool enable[128];

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<M;i++) {
        cin>>x;
        enable[x] = true;
    }
    C = N/5*2+N%5/3;
    for(int i=1;i<=C;i++) d[0][i] = MAX;
    for(int i=1;i<=N;i++) for(int j=0;j<=C;j++){
        d[i][j] = MAX;
        if(5<=i && 2<=j)                                d[i][j] = d[i-5][j-2] + 37000;
        if(3<=i && 1<=j && d[i][j] > d[i-3][j-1]+25000) d[i][j] = d[i-3][j-1] + 25000;
        if(d[i][j] > d[i-1][j]+10000)                   d[i][j] = d[i-1][j]   + 10000;
        if(enable[i] && d[i][j] > d[i-1][j])            d[i][j] = d[i-1][j];
        if(j+3 <= C && d[i][j] > d[i-1][j+3])           d[i][j] = d[i-1][j+3];
    }
    int ans = MAX;
    for(int i=0;i<=C;i++) ans = min(ans,d[N][i]);
    cout<<ans;
    return 0;
}
