#include <bits/stdc++.h>
using namespace std;
 
#define pii pair<int, int>
#define X first
#define Y second
 
int n, k, cost_left, loc;
vector<pii> v;
int d[1010][1010];
priority_queue<pii> q;   // <cost_left, v_index>
bool visited[1010];
 
int cost(pii a, pii b){
    return ceil(sqrt(double((a.X-b.X)*(a.X-b.X) + (a.Y-b.Y)*(a.Y-b.Y)))/10);
}
 
bool possible(int m){
    // reset
    for(int i=0; i<n; i++) visited[i] = 0;
    while(!q.empty()) q.pop();
 
    // BFS
    int cnt=-1;
    q.push({-1415, 0});
    while(!q.empty()){
        cost_left = q.top().X;
        loc = q.top().Y;
        q.pop();
        if(visited[loc]) continue;
        visited[loc] = true;
        cnt++;
        if(cnt > k+1) return false;
        if(loc == n-1) return true;
        for(int i=1; i<n; i++)
            if(!visited[i] && i != loc && d[loc][i] <= m){
                q.push({-d[i][n-1], i});
            }
    }
    return false;
}
 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
    cin>>n>>k;
    n += 2;
    v.resize(n);
    v[0] = {0,0}, v[n-1] = {10000,10000};
    for (int i=1; i<n-1; i++)
        cin>>v[i].X>>v[i].Y;
 
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            d[i][j] = cost(v[i],v[j]);
 
    // binary search
    int s=1, e=1415, m;
    while(s<=e){
        m = (s+e)/2;
        if (possible(m)) e = m - 1;
        else s = m + 1;
    }
    cout<<s;
 
    return 0;
}
