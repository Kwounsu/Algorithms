#include<bits/stdc++.h>
using namespace std;
 
#define X first
#define Y second
 
struct loc{int h,r,c,d;};
int M,N,H, fresh, x,y,z,t, nx,ny, val;
queue<loc> q;
bool visited[110][110][110];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
 
int bfs(){
    while (!q.empty()){
        z = q.front().h;
        x = q.front().r;
        y = q.front().c;
        t = q.front().d;
        q.pop();
        if (z<=0 || H<z || x<=0 || N<x || y<=0 || M<y|| visited[z][x][y]) continue;
        visited[z][x][y] = true;
        fresh--;
        if (fresh <= 0) return t;
        for (int i=0; i<4; i++){
            nx = x+dx[i], ny = y+dy[i];
            q.push({z,nx,ny,t+1});
        }
        q.push({z+1,x,y,t+1});
        q.push({z-1,x,y,t+1});
    }
    return -1;
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
 
    cin>>M>>N>>H;
    for(int i=1;i<=H;i++){
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                cin>>val;
                if (val == -1)
                    visited[i][j][k] = true;  // 토마토가 없는 곳
                else {
                    if (val == 1) {
                        q.push({i,j,k,0});  // 익은 토마토 위치
                    }
                    fresh++;  // 익혀야 하는 토마토 수
                }
            }
        }
    }
 
    cout<<bfs()<<'\n';
 
    return 0;
}
