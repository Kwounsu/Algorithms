#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, nx, ny, c=2;
int grid[128][128];
int dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
set<int> adj[10010];
queue<pair<int,int>> q;
int visited[10010];
int limits[10010];
int ans = 100000;

void bfs(int st){
    q.push({st,1});
    int dist=0;
    while(!q.empty()){
        int cur = q.front().X, step = q.front().Y; q.pop();
        if(visited[cur]) continue;
        visited[cur] = step;
        dist = step-1;
        for(auto a:adj[cur])
            q.push({a,step+1});
    }
    for(int i=2;i<c;i++){
        if(limits[i] >= ans) continue;
        limits[i] = max(visited[i]-1, dist-visited[i]+1);
    }
    if(dist>0 || c<=3)
        ans = min(ans, dist);
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
//    ifstream fin("input.txt");
//    fin>>n>>m;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<m;j++)
//            fin>>grid[i][j];

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
        if(limits[i] >= ans) continue;
        memset(visited,0,sizeof(visited));
        bfs(i);
    }

    cout<<ans<<'\n';

    return 0;
}
