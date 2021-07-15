#include <bits/stdc++.h>
using namespace std;
 
int N, X, Y;
vector<pair<int, int> > graph[100001];
bool visited[100001];
int sum, maxi;
  
bool dfs(int n) {
    visited[n] = true;
    if(n == Y)
        return true;
     
    for(auto node : graph[n])
        if(!visited[node.first] && dfs(node.first)) {
                sum += node.second;
                maxi = max(maxi, node.second);
                return true;
            }
     
    return false;
}
  
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
     
    cin >> N >> X >> Y;
    for(int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
     
    dfs(X);
     
    cout << sum - maxi;
     
    return 0;
}
