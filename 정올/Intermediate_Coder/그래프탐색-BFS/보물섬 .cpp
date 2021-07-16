#include<bits/stdc++.h>
using namespace std;
 
char a[51][51];
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
queue<pair<int, int> > q;
 
int f(int y, int x){
    int d[51][51] = {0}, _max = 0;
    q.push({y,x});
 
    while(!q.empty()){
        y = q.front().first; x = q.front().second; q.pop();
        _max = max(_max,d[y][x]);
 
        for(int i = 0; i < 4; i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(a[ny][nx] == 'L' && d[ny][nx] == 0){
                d[ny][nx] = d[y][x] + 1;
                q.push({ny,nx});
            }
        }
    }
    return _max;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    int n, m, _max = 0;
 
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i]+1;
    }
 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(a[i][j] == 'L')
                _max = max(f(i,j),_max);
 
    cout<<_max;
 
    return 0;
}
