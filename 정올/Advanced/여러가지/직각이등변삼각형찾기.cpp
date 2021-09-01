#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define REP(i,a,b) for (auto i=(a); i<=(b); i++)
#define debug(x) cout << #x << " is " << x << endl
#define pii pair<int,int>
#define X first
#define Y second

/*
                                       |\    /|
    ----  ----  ----    /\    /| |\    | \  / |
     \ |  \  /  | /    /  \  / | |  \  | /  \ |
      \|   \/   |/     ---- ----  ---- |/    \|
*/

int a[20][20], cnt;
vector<pii> p;

int main() {
    ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    REP(i,1,10) REP(j,1,10) {
        scanf("%1d", &a[i][j]);
        cnt+=a[i][j];
        if (cnt==1) p.push_back({i,j});
    }
    debug(p[0].X);
    debug(p[0].Y);

    bool flag = true;
    int x = p[0].X, y = p[0].Y, side;
    if (a[x][y+1]){
        while(a[x][y+1]) y++;
        p.push_back({x,y});
        side = p[1].Y - p[0].Y;
        debug(x+side/2);
        debug(p[0].Y+side/2);
        if (a[x+side][p[0].Y]){
            p.push_back({x+side,p[0].Y});
            REP(i, p[0].X, p[0].X+side)
                REP(j, p[0].Y, p[0].Y+side-i+p[0].X) {
                    if (a[i][j]) cnt--;
                    else flag = false;
                    a[i][j] = 2;
                }
        }else if (a[x+side][p[1].Y]){
            p.push_back({x+side,p[1].Y});
            REP(i, p[0].X, p[0].X+side)
                for(int j=p[0].Y+side; j>=p[0].Y+i-p[0].X; j--) {
                    if (a[i][j]) cnt--;
                    else flag = false;
                    a[i][j] = 3;
                }
        }else if (a[x+side/2][p[0].Y+side/2]){
            p.push_back({x+side,p[0].Y+side/2});
            int st = p[0].Y, ed = p[1].Y;
            REP(i, p[0].X, p[0].X+side)
                REP(j, st, ed) {
                    if (a[i][j]) cnt--;
                    else flag = false;
                    st++; ed--;
                    a[i][j] = 4;
                }
        }
    }else{
        while(a[x+1][y]) x++;
        side = p[1].X - p[0].X;
        if (a[p[1].X][p[1].Y-1] && a[p[1].X][p[1].Y+1]){
            p.push_back({x,y+side});
            p.push_back({x,y-side});
            int st = p[0].Y, ed = p[0].Y;
            REP(i, p[0].X, p[0].X+side)
                REP(j, st, ed) {
                    if (a[i][j]) cnt--;
                    else flag = false;
                    st--; ed++;
                    a[i][j] = 5;
                }
        } else if (a[p[1].X][p[1].Y-1]){
            p.push_back({x,y});
            p.push_back({x,y-side});
            REP(i, p[0].X, p[0].X+side)
                for(int j=y; j>=y-i+p[0].X; j--) {
                    if (a[i][j]) cnt--;
                    else flag = false;
                    a[i][j] = 6;
                }
        } else if (a[p[1].X][p[1].Y+1]){
            p.push_back({x,y});
            p.push_back({x,y+side});
            REP(i, p[0].X, p[0].X+side)
                REP(j, p[0].Y, p[0].Y+side+i-p[0].X) {
                    if (a[i][j]) cnt--;
                    else flag = false;
                    a[i][j] = 7;
                }
        } else if(a[p[0].X+side/2][p[0].Y+side/2]){
            p.push_back({x,y});
            p.push_back({p[0].X+side/2,p[0].Y+side/2});
            REP(i, p[0].X, p[1].X) REP(j, y, y+i-p[0].X){
                if (a[i][j]) cnt--;
                else flag = false;
            }
            REP(i, p[1].X+1, x) REP(j, y, y-i+p[1].X+1){
                if (a[i][j]) cnt--;
                else flag = false;
            }
        } else if(a[p[0].X+side/2][p[0].Y-side/2]){
            p.push_back({x,y});
            p.push_back({p[0].X+side/2,p[0].Y-side/2});
            REP(i, p[0].X, p[1].X)
                for(int j=y; j>=y; j--){
                    if (a[i][j]) cnt--;
                    else flag = false;
                }
            REP(i, p[1].X+1, x)
                for(int j=y; j>=y; j--){
                    if (a[i][j]) cnt--;
                    else flag = false;
                }
        }
    }

    if (flag && cnt==0){
        sort(p.begin(), p.end());
        REP(i,0,2) cout<<p[i].X<<' '<<p[i].Y<<endl;
    } else cout<<0<<endl;

    //REP(i,1,10) {REP(j,1,10) cout<<a[i][j]; cout<<endl;}
    return 0;
}
