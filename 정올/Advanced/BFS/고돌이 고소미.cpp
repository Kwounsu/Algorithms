#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int, int>
#define X first
#define Y second
 
struct loc{int x1,y1,x2,y2,step;} c;
 
int n, sx1, sy1, ex1, ey1, sx2, sy2, ex2, ey2, nx1, ny1, nx2, ny2;
bool visited[30][30][30][30];
int grid[30][30];
int dx[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dy[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
queue<loc> q;
 
bool is_close(int x1, int y1, int x2, int y2){
    if(abs(x1-x2) <= 1 && abs(y1-y2) <= 1) return true;
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin>>n>>sx1>>sy1>>ex1>>ey1>>sx2>>sy2>>ex2>>ey2;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>grid[i][j];
 
    q.push({sx1, sy1, sx2, sy2});
    while(!q.empty()){
        c = q.front(); q.pop();
        if (visited[c.x1][c.y1][c.x2][c.y2]) continue;
        visited[c.x1][c.y1][c.x2][c.y2] = true;
        if (c.x1 == ex1 && c.y1 == ey1 && c.x2 == ex2 && c.y2 == ey2){
            cout<<c.step<<'\n';
            break;
        }
        for (int i=0; i<9; i++) for (int j=0; j<9; j++){
            if (i==0 && j==0) continue;
            nx1 = c.x1+dx[i], ny1 = c.y1+dy[i], nx2 = c.x2+dx[j], ny2 = c.y2+dy[j];
            if (nx1<1 || ny1<1 || nx2<1 || ny2<1 || nx1>n || ny1>n || nx2>n || ny2>n || grid[nx1][ny1] || grid[nx2][ny2] || is_close(nx1,ny1,nx2,ny2)) continue;
            q.push({nx1,ny1,nx2,ny2,c.step+1});
        }
    }
 
    return 0;
}
