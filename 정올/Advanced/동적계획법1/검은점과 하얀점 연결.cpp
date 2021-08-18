#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int n;
int arr[110];
int ans[110][110];
pair<int,int> dp[110][110];  // {min_cost, height}
bool visited[110][110];

void path(int s, int e) {
    if (s > e) return;
    int k = ans[s][e];
    printf("%d %d\n", s, k);
    path(s + 1, k - 1);
    path(k + 1, e);
}

pair<int,int> dfs(int s, int e){
    if (s > e) return {0, 0};
    if (visited[s][e]) return dp[s][e];

    visited[s][e] = 1;
    int cost = 1e9 + 7, h = 0;

    for (int i = s + 1; i <= e; i += 2)
        if (arr[s] != arr[i]) {
            pair<int,int> a = dfs(s + 1, i - 1);
            if (a.x >= cost) continue;
            pair<int,int> b = dfs(i + 1, e);
            int dist = i - s;
            if (cost > a.x + b.x + dist + (a.y + 1) * 2) {
                cost = a.x + b.x + dist + (a.y + 1) * 2;
                h = max(a.y + 1, b.y);
                ans[s][e] = i;
            }
        }

    return dp[s][e] = {cost, h};
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%1d",&arr[i]);

    printf("%d\n",dfs(1, n).x);
    path(1, n);

    return 0;
}
