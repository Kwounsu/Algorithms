#include <bits/stdc++.h>
using namespace std;
 
int N, M, visited[2<<16], ans_size;
vector<int> graph[2<<16], ans;
 
void dfs(int cur){
    if (ans_size == N) return;
    ans.push_back(cur);
    ans_size++;
    visited[cur] = true;
    for (int nxt : graph[cur]) {
        if (!visited[nxt])
            dfs(nxt);
    }
}
 
int main(){
    // c++ 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin>>N>>M;
    int a, b, i;
    for (i = 0; i < M; i++) {
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
 
    for (i = 1; i <= N; i++)
        sort(graph[i].begin(), graph[i].end());
 
    dfs(1);
 
    for(int room : ans)
        cout<<room<<" ";
 
    return 0;
}
