#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define REP(i,a,b) for (auto i=(a); i<=(b); i++)

/*
                                       |\    /|
    ----  ----  ----    /\    /| |\    | \  / |
     \ |  \  /  | /    /  \  / | |  \  | /  \ |
      \|   \/   |/     ---- ----  ---- |/    \|
*/
  
int A[15][15], T[15][15];
  
bool check(){
    REP(i,0,9) REP(j,0,9)
        if (A[i][j] != T[i][j]) return false;
    return true;
}
  
bool valid(int x, int y){
    return (0 <= x && x < 10 && 0 <= y && y < 10);
}
  
bool f1(int x, int y, int k){
    REP(i,0,k-1) REP(j,0,i){
        int nx = i + x, ny = j + y;
        if (!valid(nx, ny)) return false;
        T[nx][ny] = 1;
    }
    return true;
}
  
bool f2(int x, int y, int k){
    REP(i,0,k-1) REP(j,0,k-i-1){
        int nx = i + x, ny = j + y;
        if (!valid(nx, ny)) return false;
        T[nx][ny] = 1;
    }
    return true;
}
  
bool f3(int x, int y, int k){
    REP(i,0,k-1)
        for (int j=0; j>i-k; j--){
            int nx = i + x, ny = j + y;
            if (!valid(nx, ny)) return false;
            T[nx][ny] = 1;
        }
    return true;
}
  
bool f4(int x, int y, int k){
    REP(i,0,k-1){
        for (int j = 0; j > -i - 1; j--){
            int nx = i + x, ny = j + y;
            if (!valid(nx, ny)) 
                return false;
            T[nx][ny] = 1;
        }
    }
    return true;
}
  
bool f5(int x, int y, int k){
    return (k % 2 == 1) && f1(x - k / 2, y, k / 2 + 1) && f2(x, y, k / 2 + 1);
}
  
bool f6(int x, int y, int k){
    return (k % 2 == 1) && f2(x, y, k / 2 + 1) && f3(x, y, k / 2 + 1);
}
  
bool f7(int x, int y, int k){
    return (k % 2 == 1) && f4(x - k / 2, y, k / 2) && f3(x, y, k / 2 + 1);
}
 
bool f8(int x, int y, int k){
    return (k % 2 == 1) && f1(x, y, k / 2 + 1) && f4(x, y, k / 2 + 1);
}
  
bool f(int p, int x, int y, int k){
    if (p == 1) return f1(x, y, k);
    if (p == 2) return f2(x, y, k);
    if (p == 3) return f3(x, y, k);
    if (p == 4) return f4(x, y, k);
    if (p == 5) return f5(x, y, k);
    if (p == 6) return f6(x, y, k);
    if (p == 7) return f7(x, y, k);
    if (p == 8) return f8(x, y, k);
    return false;
}
  
vector<pair<int, int>> point(int p, int x, int y, int k)
{
    vector<pair<int, int>> ans;
    if (p == 1) ans = { {x, y}, {x + k - 1, y}, {x + k - 1, y + k - 1} };
    if (p == 2) ans = { {x, y}, {x, y + k - 1}, {x + k - 1, y} };
    if (p == 3) ans = { {x, y}, { x + k - 1, y }, { x, y - k + 1 } };
    if (p == 4) ans = { {x, y}, {x + k - 1, y}, {x + k - 1, y - k + 1} };
    if (p == 5) ans = { {x - k / 2, y}, {x + k / 2, y}, {x, y + k / 2} };
    if (p == 6) ans = { {x, y + k / 2}, {x, y - k / 2}, {x + k / 2, y} };
    if (p == 7) ans = { {x - k / 2, y}, {x + k / 2, y}, {x, y - k / 2} };
    if (p == 8) ans = { {x, y}, {x + k / 2, y + k / 2}, {x + k / 2, y - k / 2} };
    sort(ans.begin(), ans.end());
    return ans;
}
  
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     
    REP(i,0,9) REP(j,0,9)
        scanf("%1d", &A[i][j]);
     
    REP(p,1,8) REP(i,0,9) REP(j,0,9) REP(k,2,10){
        memset(T, 0, sizeof(T));
        if (f(p, i, j, k) && check()){
            for (auto i : point(p, i + 1, j + 1, k))
                cout<<i.first <<' '<<i.second<<endl;
            return 0;
        }
    }
     
    cout << 0;
}
