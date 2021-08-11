#include <bits/stdc++.h>
using namespace std;

struct change{
    int i, loc, cnt;
}fin[8], ack[8];

int ans = 8;
int goal[5][5], arr[5][5];

int diff(){
    int cnt = 0;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if(arr[i][j] != goal[i][j])
                cnt++;
    return cnt;
}

bool done(){
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= 4; j++)
            if(arr[i][j] != goal[i][j])
                return false;
    return true;
}

void rotate_row(int r){
    int tmp = arr[r][4];
    arr[r][4] = arr[r][3];
    arr[r][3] = arr[r][2];
    arr[r][2] = arr[r][1];
    arr[r][1] = tmp;
}

void rotate_col(int c){
    int tmp = arr[4][c];
    arr[4][c] = arr[3][c];
    arr[3][c] = arr[2][c];
    arr[2][c] = arr[1][c];
    arr[1][c] = tmp;
}

void dfs(int n, int r, int c){
    if (n > 7 || (diff()+3)/4 + n >= ans)
        return;
    if (done()){
        ans = n;
        for (int i = 0; i < n; i++)
            fin[i] = ack[i];
    }
    for (int i = r; i <= 4; i++){
        rotate_row(i);
        for (int j = 1; j <= 3; j++){
            ack[n] = {1, i, j};
            dfs(n+1, i+1, 1);
            rotate_row(i);
        }
    }
    for (int i = c; i <= 4; i++){
        rotate_col(i);
        for (int j = 1; j <= 3; j++){
            ack[n] = {2, i, j};
            dfs(n+1, 1, i+1);
            rotate_col(i);
        }
    }
}

void init(){
    int a = 1;
    for (int i = 1; i <= 4; i++){
        for (int j = 1; j <= 4; j++){
            goal[i][j] = a++;
            cin>>arr[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    init();
    dfs(0,1,1);
    
    cout<<ans<<'\n';
    for (int i = 0; i < ans; i++)
        cout<<fin[i].i<<' '<<fin[i].loc<<' '<<fin[i].cnt<<'\n';
    
    return 0;
}
