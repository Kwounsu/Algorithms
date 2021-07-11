#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 0;
int grid[128][128] = {0};
int visited[128][128] = {0};
vector<int> v;

void bfs(int i, int j){
    if (i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 0 && !visited[i][j]) {
        cnt++;
        visited[i][j] = 1;

        bfs(i - 1, j);
        bfs(i, j - 1);
        bfs(i + 1, j);
        bfs(i, j + 1);
    }
}

int main() {
    // init
    int k, i, j, q;
    cin>>m>>n>>k;
    int r1,c1,r2,c2;
    for (i = 0; i < k; i++){
        cin>>r1>>c1>>r2>>c2;
        for (j = c1; j < c2; j++){
            for (q = r1; q < r2; q++){
                grid[j][q] = 1;
            }
        }
    }
    
    // 전체 탐색하며 bfs탐색
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            if (grid[i][j] == 0 && !visited[i][j]) {
                cnt = 0;
                bfs(i, j);
                if (cnt > 0)
                    v.push_back(cnt);
            }
        }
    }
    
    sort(v.begin(), v.end());
    
    printf("%d\n", v.size());
    for (auto x : v)
        printf("%d ", x);
    
    return 0;
}
