#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, nx, ny, c=2;
int grid[124][124];
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
vector<vector<int>> adj;
bool visited[124][124];

void find_adj(int x, int y){
    if(visited[x][y]) return;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        nx = x+dx[i], ny = y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)
            dfs(nx,ny,p);
    }
}

void dfs(int x, int y, int p){
    if(grid[x][y] != p) return;
    grid[x][y] = c;
    for(int i=0;i<4;i++){
        nx = x+dx[i], ny = y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m)
            dfs(nx,ny,p);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>grid[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 || grid[i][j] == 0){
                dfs(i,j,grid[i][j]);
                c++;
            }
        }

    adj.resize(c);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            find_adj(0,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<grid[i][j]<<' ';
        cout<<'\n';
    }

    return 0;
}
