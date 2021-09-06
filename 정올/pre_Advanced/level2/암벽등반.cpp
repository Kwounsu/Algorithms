#include <bits/stdc++.h>
using namespace std;
 
struct loc{int r,c;} p;
queue<loc> q;
int board[510][510];
int visit[510][510];
int n, target;
 
int bfs(int h, int x, int y){
    q.push({x, y});
    int visited = 0;
    while (!q.empty()){
        p = q.front();
        q.pop();
        if (!visit[p.r][p.c]){
            visited++;
            visit[p.r][p.c] = 1;
            if (0 <= p.r-1 && abs(board[p.r-1][p.c]-board[p.r][p.c]) <= h)
                q.push({p.r-1, p.c});
            if (p.r+1 < n  && abs(board[p.r+1][p.c]-board[p.r][p.c]) <= h)
                q.push({p.r+1, p.c});
            if (0 <= p.c-1 && abs(board[p.r][p.c-1]-board[p.r][p.c]) <= h)
                q.push({p.r, p.c-1});
            if (p.c+1 < n  && abs(board[p.r][p.c+1]-board[p.r][p.c]) <= h)
                q.push({p.r, p.c+1});
        }
    }
    return visited;
}
 
bool success(int h){
    // reset visit
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visit[i][j] = 0;
 
    int visited = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visit[i][j]) {
                if (bfs(h, i, j) >= target) return true;
            }
    return false;
}
 
int main()
{
    scanf("%d",&n);
    target = n*n * 0.75;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &board[i][j]);
        }
    }
 
 
    int low = 0, high = 1000000, mid;
    while (low <= high){
        mid = (low + high) / 2;
        if (success(mid))
            high = mid - 1;
        else
            low = mid + 1;
    }
 
    printf("%d\n", low);
 
    return 0;
}
