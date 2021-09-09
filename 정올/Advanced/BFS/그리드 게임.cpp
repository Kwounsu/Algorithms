#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, nx, ny, c=2;
int grid[124][124];
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
set<int> adj[1<<14];
bool visited[124][124];
queue<pair<int,int>> q;

void bfs(){
    q.push(0)

}

void find_adj(int x, int y){
    for(int i=0;i<4;i++){
        nx = x+dx[i], ny = y+dy[i];
        if(0<=nx&&nx<n&&0<=ny&&ny<m && grid[x][y] != grid[nx][ny]){
            adj[grid[x][y]].insert(grid[nx][ny]);
            adj[grid[nx][ny]].insert(grid[x][y]);
        }
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

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            find_adj(i,j);

    for(int i=2;i<c;i++){
        fill(&visited[0][0], &visited[n][m], false);
        q.push()  // TODO
        bfs();
    }

//    for(int i=0;i<n;i++){
//        for(int j=0;j<m;j++)
//            cout<<grid[i][j]<<' ';
//        cout<<'\n';
//    }
//
//    for(int i=2;i<c;i++){
//        cout<<i<<": ";
//        for(auto x:adj[i])
//            cout<<x<<' ';
//        cout<<'\n';
//    }

    return 0;
}
