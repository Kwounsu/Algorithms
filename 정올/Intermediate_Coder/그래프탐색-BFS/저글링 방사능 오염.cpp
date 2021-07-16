#include <bits/stdc++.h>
using namespace std;
 
int N, M, R, C, _max;
char arr[101][101];
int visit[101][101];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
 
struct DATA {
    int y=0, x=0, lev=0;
};
 
queue<DATA> q;
DATA t[101];
 
void output() {
    int cnt=0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] - '0' != visit[i][j])cnt++;
        }
    }
    printf("%d\n%d", _max, cnt);
}
 
void push(int y, int x, int step) {
    if (x < t[y].y - 1 || x > t[y].x - 1 || visit[y][x]||arr[y][x]-'0'==0)
        return;
    visit[y][x] = 1;
    _max = max(_max, step);
    q.push({y, x, step});
}
 
void bfs() {
    while (!q.empty()) {
        DATA m = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
            push(m.y + dy[i],m.x + dx[i], m.lev + 1);
    }
}
 
void input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
 
    cin>>N>>M;
    for (int i = 0; i < M; i++)
        cin>>arr[i];
    cin>>R>>C;
 
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            if (t[i].y == 0 && arr[i][j] == '1')
                t[i].y = j + 1;
            if (arr[i][j] == '1')
                t[i].x = j + 1;
        }
 
    push(C-1, R-1, 3);
}
 
int main() {
    input();
    bfs();
    output();
    return 0;
}
