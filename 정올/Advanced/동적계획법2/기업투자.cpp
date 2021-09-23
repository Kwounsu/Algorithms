#include<bits/stdc++.h>
using namespace std;
int M,N,m,d[21][301],a[21][301],path[21][301];

void track(int n, int m){
    if(n<=0) return;
    track(n-1,m-path[n][m]);
    cout<<path[n][m]<<' ';
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin>>M>>N;
    for(int i=1;i<=M;i++){
        cin>>m;
        for(int j=1;j<=N;j++)
            cin>>a[j][i];
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            for(int k=0;k<=j;k++){
                if(d[i][j]<d[i-1][k]+a[i][j-k]){
                    d[i][j]=d[i-1][k]+a[i][j-k];
                    path[i][j]=j-k;
                }
            }
        }
    }
    cout<<d[N][M]<<'\n';
    track(N,M);
    return 0;
}
