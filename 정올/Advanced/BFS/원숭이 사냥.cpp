#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second

// N(1≤N≤21)과 이웃한 나무의 쌍 M(0≤M≤210)
int n, m, cur, tmp, nxt, step;
vector<vector<int>> adj;
vector<bool> visited;
queue<pii> q;
pii path[1<<21];
stack<int> ans;

void track(int x){
    if (path[x].X == 0) return;
    track(path[x].X);
    cout<<" "<<path[x].Y;
}

void bfs(){
    q.push({(1<<n)-1,1});
    while(!q.empty()){
        cur = q.front().X;
        step = q.front().Y;
        q.pop();
        if(visited[cur]) continue;
        visited[cur] = true;
        if(__builtin_popcount(cur)==1) {
            cout<<step<<":";
            track(0);
            cout<<'\n';
            return;
        }
        // 총쏘기
        for(int i=0;i<n;i++){
            if(!(cur^(1<<i))) continue;
            tmp = cur & ~(1<<i);
            nxt = 0;
            // 비트마스크로 경우의수 따져보기
            for(int j=n-1;j>=0;j--)
                for(int a:adj[j])
                    if((tmp>>(n-1-a)) & 1) { // a번째 비트가 1이면
                        nxt |= (1<<j);       // j번째 비트 1로 세팅
                        break;
                    }
            path[nxt]={cur,i};
            q.push({nxt,step+1});
        }
    }
    cout<<"Impossible\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(1){
        cin>>n>>m;
        if (n==0 && m==0) break;

        adj.clear(); adj.resize(1<<n);
        visited.resize(1<<n, false);
        int a,b;
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs();
        cout<<'\n';
    }

    return 0;
}
