#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second

struct data{int x1,y1,x2,y2;} c;

int n, sx1, sy1, ex1, ey1, sx2, sy2, ex2, ey2;
bool visited[30][30][30][30];
int grid[30][30];
int dx[9] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
int dx[9] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
queue<data> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin>>n>>sx1>>sy1>>ex1>>ey1>>sx2>>sy2>>ex2>>ey2;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cin>>grid[i][j];

    q.push({sx1, sy1, ex1, ey1});
    while(!q.empty()){
        c = q.top(); q.pop();
        if (visited[c.x1][c.y1][c.x2][c.y2]) continue;
        for (int i=0; i<5; )
    }

    return 0;
}
