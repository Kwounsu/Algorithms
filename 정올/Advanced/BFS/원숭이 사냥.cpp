#include<bits/stdc++.h>
using namespace std;

// N(1≤N≤21)과 이웃한 나무의 쌍 M(0≤M≤210)
int n, m;
vector<vector<int>> adj;
bool impossible;

void bfs(){
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    while(1){
        cin>>n>>m;
        adj.resize(1<<n);
        for(auto v:adj) v.clear();
        if (n==0 && m==0) break;
        int a,b;
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs();
    }
    
    return 0;
}
