#include<bits/stdc++.h>
using namespace std;

struct data{int bit, step;};
vector<int> adj[30];
queue<data> q;
int visited[1<<21], path[1<<21], pr[1<<21], n,m;

void init(){
    for(int i=0; i<30; i++) adj[i].clear();
    while(!q.empty()) q.pop();
    for(int i=0; i<(1<<21); i++) 
        visited[i] = path[i] = pr[i] = 0;
}
 
void print(int n, int a){
    if(a == (1<<n)-1) return;
    print(n, path[a]);
    printf("%d ", pr[a]);
}
 
void bfs(){
    q.push({(1<<n)-1, 1});
    visited[(1<<n)-1] = 1;
    pr[(1<<n)-1] = -1;
    while(!q.empty()){
        int cur = q.front().bit, step = q.front().step;
        q.pop();
        if(cur == 0) break;
        for(int i=0; i<n; i++){
            int tmp = cur^(1<<i);
            int temp2 = 0;
            for(int j=0; j<n; j++){
                int sz = adj[j].size();
                bool flag = false;
                for(int k=0; k<sz; k++){
                    if((tmp>>adj[j][k])%2){
                        flag = true;
                        break;
                    }
                }
                temp2 += flag<<j;
            }
            if(visited[temp2] == 0){
                q.push({temp2, step+1});
                path[temp2] = cur;
                visited[temp2] = step+1;
                pr[temp2] = i;
            }
        }
    }
    if(visited[0] == 0) printf("Impossible\n");
    else{
        printf("%d: ", visited[0]-1);
        print(n, 0);
        printf("\n");
    }
}
 
int main(){
    while(1){
        init();
        scanf("%d %d", &n, &m);
        if(n==0 && m==0) break;
        for(int i=0; i<m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bfs();
    }
    return 0;
}
