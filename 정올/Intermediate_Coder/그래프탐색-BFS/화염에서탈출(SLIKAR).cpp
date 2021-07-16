#include <bits/stdc++.h>
using namespace std;
 
int R, C, arr[55][55], head, tail, sr, sc, er, ec;
int dr[4] = { 0, 0, -1, 1 }, dc[4] = { -1, 1, 0, 0 };
struct Data {
    int type, r, c, cnt;
} que[2500];
 
int push(int type, int r, int c, int cnt) {
    if (r < 0 || r >= R || c < 0 || c >= C || arr[r][c]) return 0;
    if (r == er && c == ec) return type;
    arr[r][c] = 1;
    que[tail++] = { type, r, c, cnt };
    return 0;
}
  
int bfs() {
    Data T;
    push(1, sr, sc, 0);
    while (head < tail) {
        T = que[head++];
        for (int i = 0; i < 4; i++)
            if (push(T.type, T.r + dr[i], T.c + dc[i], T.cnt + 1))
                return T.cnt + 1;
    }
    return -1;
}
  
int main() {
    cin>>R>>C;
    char c;
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) {
            cin>>c;
            if (c == 'X') arr[i][j] = 1;
            else if (c == 'S') sr = i, sc = j;
            else if (c == 'D') er = i, ec = j;
            else if (c == '*') push(0, i, j, 0);
        }
     
    int ans = bfs();
    if (ans == -1) cout<<"impossible";
    else cout<<ans;
     
    return 0;
}
