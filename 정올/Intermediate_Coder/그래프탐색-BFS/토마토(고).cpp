#include <bits/stdc++.h>
using namespace std;
 
struct xy {
    int x, y;
};
 
queue<xy> q;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
int n, m, ans, arr[1005][1005];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    cin>>m>>n;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            cin>>arr[i][j];
            if (arr[i][j] == 1)
                q.push({i, j});
        }
 
    int x, y;
    while (!q.empty()) {
        x = q.front().x;
        y = q.front().y;
        q.pop();
 
        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (0 < nx && nx <= n && 0 < ny && ny <= m && arr[nx][ny] == 0) {
                arr[nx][ny] = arr[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
 
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) {
            if (arr[i][j] == 0) {
                printf("-1");
                return 0;
            }
            if (ans < arr[i][j])
                ans = arr[i][j];
        }
 
    printf("%d", ans-1);
 
    return 0;
}
