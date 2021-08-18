#include <bits/stdc++.h>
using namespace std;

int R, C;
char arr[25][25];
bool visited[25][25];
bool alpha[26];
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int ans;

void dfs(int r, int c, int step){
    ans = max(ans, step);
    
    int nr, nc;
    for (int i = 0; i < 4; i++){
        nr = r+dx[i]; nc = c+dy[i];
        if (nr<1 || nc<1 || R<nr || C<nc || alpha[arr[nr][nc]-'A'] || visited[nr][nc]) continue;
        visited[nr][nc] = 1;
        alpha[arr[nr][nc]-'A'] = 1;
        dfs(r+dx[i], c+dy[i], step+1);
        visited[nr][nc] = 0;
        alpha[arr[nr][nc]-'A'] = 0;
    }
}

int main()
{
    scanf("%d%d", &R, &C);
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++)
            scanf(" %c", &arr[i][j]);

    visited[1][1] = 1;
    alpha[arr[1][1]-'A'] = 1;
    dfs(1,1,1);
    printf("%d\n", ans);
    
    return 0;
}
