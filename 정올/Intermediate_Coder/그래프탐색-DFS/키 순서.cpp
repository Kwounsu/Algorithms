#include <bits/stdc++.h>
using namespace std;

int N, M, node;
int check[505], cnt[505];
vector<int> path[505];

int dfs(int s) {
    if (check[s] == node)
        return 0;

    check[s] = node;
    cnt[s]++;

    int sum = 0;
    
    for (int i : path[s])
        sum += dfs(i);

    return sum + 1;
}

void input() {
    int a, b;

    cin>>N>>M;
    for (int i = 0; i < M; ++i) {
        cin>>a>>b;
        path[a].push_back(b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int ans = 0;
    input();

    for (int i = 1; i <= N; ++i) {
        node++;
        cnt[i] += dfs(i) - 1;
    }

    for (int i = 1; i <= N; ++i)
        if (cnt[i] == N)
            ans++;

    cout<<ans;

    return 0;
}
