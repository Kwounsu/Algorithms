#include<bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define X first
#define Y second
#define INF 1000000

int n, sx, sy, ex, ey, k, m, cx, cy, nx, ny;
priority_queue<pair<int,pii>> q;  // <priority, <x,y>>
int cost[60][60];
bool visited[60][60];
int add[60][60];  // 추가비용
pii before[60][60];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
vector<pii> res;
 
void bfs(int x, int y){
    cost[x][y] = 1;
    q.push({1, {x,y}});
    while (!q.empty()){
        cx = q.top().Y.X;
        cy = q.top().Y.Y;
        if (cx==ex && cy==ey)
            return;
        q.pop();
        if (visited[cx][cy]) continue;
        visited[cx][cy] = true;
        for (int i=0; i<4; i++){
            nx = cx+dx[i], ny = cy+dy[i];
            if (nx<1 || n<nx || ny<1 || n<ny) continue;
            if (cost[cx][cy]+add[nx][ny] < cost[nx][ny]){
                cost[nx][ny] = cost[cx][cy]+add[nx][ny];
                before[nx][ny] = {cx,cy};
                q.push({-cost[nx][ny], {nx,ny}});
            }
        }
    }
}
 
int main(){
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
    cin>>n>>sx>>sy>>ex>>ey>>k>>m;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            add[i][j] = 1;
    int l, r, c;
    while(m--){
        cin>>l;
        int sr, sc;
        cin>>sr>>sc;
        while(--l){
            cin>>r>>c;
            int si,sj,ei,ej;
            if (sr<r) si = sr, ei = r;
            else      si = r, ei = sr;
            if (sc<c) sj = sc, ej = c;
            else      sj = c, ej = sc;
            if (si==ei)
                for (int j=sj; j<=ej; j++)
                    add[si][j] = k;
            else
                for (int i=si; i<=ei; i++)
                    add[i][sj] = k;
            sr = r; sc = c;
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            cost[i][j] = INF;
    bfs(sx, sy);
    cout<<cost[ex][ey]<<'\n';
 
    res.push_back({ex,ey});
    int ax = ex, ay = ey;
    while(1){
        pii val = before[ax][ay];
        if (val.X==sx && val.Y==sy) break;
        pii nxt = before[val.X][val.Y];
        if ((ax==val.X&&ax==nxt.X) || (ay==val.Y&&ay==nxt.Y)){}
        else
            res.push_back({val.X, val.Y});
        ax = val.X, ay = val.Y;
    }
    res.push_back({sx,sy});
 
    cout<<res.size()<<' ';
    while(!res.empty()){
        cout<<res.back().X<<' '<<res.back().Y<<' ';
        res.pop_back();
    }
    return 0;
}
