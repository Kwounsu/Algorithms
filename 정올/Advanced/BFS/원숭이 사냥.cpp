#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;

int n, m, step, cur, tmp, nxt;
vector<int> adj[22];
queue<pair<int,int>> q;  // <bit, step>
int visited[1<<21], path[1<<21], path_i[1<<21];

void track(int x){
    if(x == (1<<n)-1) return;
    track(path[x]);
    cout<<' '<<path_i[x];
}

void bfs(){
    q.push({(1<<n)-1, 1});
    visited[(1<<n)-1] = 1;
    path_i[(1<<n)-1] = -1;
    while(!q.empty()){
        cur = q.front().X, step = q.front().Y; q.pop();
        if(cur == 0) break;
        for(int i=0; i<n; i++){
            tmp = cur^(1<<i);  // 총쏘기
            nxt = 0;
            for(int j=0; j<n; j++){
                int sz = adj[j].size();
                for(int k=0; k<sz; k++){
                    if((tmp>>adj[j][k]) & 1){
                        nxt |= (1<<j);
                        break;
                    }
                }
            }
            if(!visited[nxt]){
                q.push({nxt, step+1});
                path[nxt] = cur;
                visited[nxt] = step+1;
                path_i[nxt] = i;
            }
        }
    }
    if(!visited[0]) cout<<"Impossible\n";
    else{
        cout<<visited[0]-1<<':';
        track(0);
        cout<<'\n';
    }
}

void init(){
    for(int i=0; i<22; i++) adj[i].clear();
    while(!q.empty()) q.pop();
    memset(visited,0,sizeof(visited));
    memset(path   ,0,sizeof(path));
    memset(path_i ,0,sizeof(path_i));
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    while(1){
        init();
        cin>>n>>m;
        if(n==0 && m==0) break;
        int a, b;
        for(int i=0; i<m; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs();
    }
    return 0;
}
